/*
 * This file is a reduced version of the original present at
 * https://github.com/oktal/pistache/.
 */

/* router.h
   Mathieu Stefani, 05 janvier 2016

   Simple HTTP Rest Router
*/

#pragma once

#include <string>
#include <tuple>

#include "flags.h"
#include "http.h"

#include <functional>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace polycube {
namespace service {

namespace Rest {

namespace details {
template <typename T>
struct LexicalCast {
  static T cast(const std::string &value) {
    std::istringstream iss(value);
    T out;
    if (!(iss >> out))
      throw std::runtime_error("Bad lexical cast");
    return out;
  }
};

template <>
struct LexicalCast<std::string> {
  static std::string cast(const std::string &value) {
    return value;
  }
};
}

class TypedParam {
 public:
  TypedParam(const std::string &name, const std::string &value)
      : name_(name), value_(value) {}

  template <typename T>
  T as() const {
    return details::LexicalCast<T>::cast(value_);
  }

  std::string name() const {
    return name_;
  }

 private:
  std::string name_;
  std::string value_;
};

class Request;

struct Route {
  enum class Result { Ok, Failure };

  typedef std::function<Result(const Request &, HttpHandleResponse &)> Handler;

  Route(std::string resource, Http::Method method, Handler handler)
      : resource_(std::move(resource)),
        method_(method),
        handler_(std::move(handler)),
        fragments_(Fragment::fromUrl(resource_)) {}

  std::tuple<bool, std::vector<TypedParam>, std::vector<TypedParam>> match(
      const HttpHandleRequest &req) const;

  std::tuple<bool, std::vector<TypedParam>, std::vector<TypedParam>> match(
      const std::string &req) const;

  template <typename... Args>
  void invokeHandler(Args &&... args) const {
    handler_(std::forward<Args>(args)...);
  }

 private:
  struct Fragment {
    explicit Fragment(std::string value);

    bool match(const std::string &raw) const;
    bool match(const Fragment &other) const;

    bool isParameter() const;
    bool isSplat() const;
    bool isOptional() const;

    std::string value() const {
      return value_;
    }

    static std::vector<Fragment> fromUrl(const std::string &url);

   private:
    enum class Flag {
      None = 0x0,
      Fixed = 0x1,
      Parameter = Fixed << 1,
      Optional = Parameter << 1,
      Splat = Optional << 1
    };

    void init(std::string value);

    void checkInvariant() const;

    Flags<Flag> flags;
    std::string value_;
  };

  std::string resource_;
  Http::Method method_;
  Handler handler_;
  /* @Performance: since we know that resource_ will live as long as the vector
   * underneath,
   * we would benefit from std::experimental::string_view to store fragments.
   *
   * We could use string_view instead of allocating strings everytime. However,
   * string_view is
   * only available in c++17, so I might have to come with my own lightweight
   * implementation of
   * it
   */
  std::vector<Fragment> fragments_;
};

class Router {
 public:
  enum class Status { Match, NotFound };

  void get(std::string resource, Route::Handler handler);
  void post(std::string resource, Route::Handler handler);
  void put(std::string resource, Route::Handler handler);
  void patch(std::string resource, Route::Handler handler);
  void del(std::string resource, Route::Handler handler);
  void options(std::string resource, Route::Handler handler);

  void addCustomHandler(Route::Handler handler);

  Status route(const HttpHandleRequest &request, HttpHandleResponse &response);

 private:
  void addRoute(Http::Method method, std::string resource,
                Route::Handler handler);
  std::unordered_map<Http::Method, std::vector<Route>> routes;

  std::vector<Route::Handler> customHandlers;
};

class Request : public HttpHandleRequest {
 public:
  friend class Router;

  bool hasParam(std::string name) const;
  TypedParam param(std::string name) const;

  TypedParam splatAt(size_t index) const;
  std::vector<TypedParam> splat() const;

 private:
  explicit Request(const HttpHandleRequest &request,
                   std::vector<TypedParam> &&params,
                   std::vector<TypedParam> &&splats);

  std::vector<TypedParam> params_;
  std::vector<TypedParam> splats_;
};

namespace Routes {

void Get(Router &router, std::string resource, Route::Handler handler);
void Post(Router &router, std::string resource, Route::Handler handler);
void Put(Router &router, std::string resource, Route::Handler handler);
void Patch(Router &router, std::string resource, Route::Handler handler);
void Delete(Router &router, std::string resource, Route::Handler handler);
void Options(Router &router, std::string resource, Route::Handler handler);

namespace details {
template <class... Args>
struct TypeList {
  template <size_t N>
  struct At {
    static_assert(N < sizeof...(Args), "Invalid index");
    typedef typename std::tuple_element<N, std::tuple<Args...>>::type Type;
  };
};

template <typename... Args>
void static_checks() {
  static_assert(sizeof...(Args) == 2, "Function should take 2 parameters");
  typedef details::TypeList<Args...> Arguments;
// Disabled now as it
// 1/ does not compile
// 2/ might not be relevant
#if 0
            static_assert(std::is_same<Arguments::At<0>::Type, const Rest::Request&>::value, "First argument should be a const Rest::Request&");
            static_assert(std::is_same<typename Arguments::At<0>::Type, Http::Response>::value, "Second argument should be a Http::Response");
#endif
}
}

template <typename Result, typename Cls, typename... Args, typename Obj>
Route::Handler bind(Result (Cls::*func)(Args...), Obj obj) {
  details::static_checks<Args...>();

#define CALL_MEMBER_FN(obj, pmf) ((obj)->*(pmf))

  return [=](const Rest::Request &request, HttpHandleResponse &response) {
    // CALL_MEMBER_FN(obj, func)(request, std::move(response));
    CALL_MEMBER_FN(obj, func)(request, response);
    return Route::Result::Ok;
  };

#undef CALL_MEMBER_FN
}

template <typename Result, typename... Args>
Route::Handler bind(Result (*func)(Args...)) {
  details::static_checks<Args...>();

  return [=](const Rest::Request &request, HttpHandleResponse &response) {
    func(request, response);

    return Route::Result::Ok;
  };
}

}  // namespace Routing

}  // namespace Rest

}  // namespace service
}  // namespace polycube
