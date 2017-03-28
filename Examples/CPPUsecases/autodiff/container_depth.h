#pragma once

#include <boost/type_traits.hpp>

// container_depth<Container, Target>
// Count how many dereferences of Container::value_type are needed to find a Target.
// e.g. container_depth<list<mat<double>>, double>::depth  == 2
// e.g. container_depth<list<mat<double>>, mat<double>>::depth  == 1
// e.g. container_depth<list<mat<double>>, char*>::depth  == assert fail.


template <class Container, class Target_t>
struct container_depth {
  static Container f() {}
  typedef typename get_value_type<Container>::type value_t;
  static constexpr size_t depth = 1 + container_depth<value_t, Target_t>::depth;
};

template <class Target_t>
struct container_depth<Target_t, Target_t> {
  static constexpr size_t depth = 0;
};

template <class Target_t>
struct container_depth<const Target_t, Target_t> {
  static constexpr size_t depth = 0;
};

template <class Target_t>
struct container_depth<const Target_t&, Target_t> {
  static constexpr size_t depth = 0;
};

template <class Target_t>
struct container_depth<Target_t&, Target_t> {
  static constexpr size_t depth = 0;
};

template <class Target_t>
struct container_depth<void, Target_t> {
  static constexpr int depth = -1;
};

#define CONTAINER_DEPTH(Container, Target_t) container_depth<typename std::remove_reference<Container>::type, Target_t>::depth

#include <vector>
#include <list>

static void test_container_depth()
{
  BOOST_STATIC_ASSERT(CONTAINER_DEPTH(std::vector<double>, double) == 1);
  // BOOST_STATIC_ASSERT(CONTAINER_DEPTH(std::vector<double>, int) == 1); // This should not compile...
  BOOST_STATIC_ASSERT(CONTAINER_DEPTH(std::vector<std::list<double>>, double) == 2);
  BOOST_STATIC_ASSERT(CONTAINER_DEPTH(std::vector<std::list<double>>, std::list<double>) == 1);
  BOOST_STATIC_ASSERT(CONTAINER_DEPTH(const std::vector<std::list<double>>, double) == 2);
  BOOST_STATIC_ASSERT(CONTAINER_DEPTH(const std::vector<std::list<double>>&, double) == 2);
}

/*
template <class T>
struct container_depth {
  static const size_t depth = 0;
};

template <template <typename... Ts> class Container, typename... Ts>
struct container_depth<Container<Ts...>> {
  typedef typename Container<Ts...>::value_type inner_t;
  static const size_t depth = 1 + container_depth<inner_t>::depth;
};

template <template <typename T, int N, typename... Ts> class Container, typename T, int N, typename... Ts>
struct container_depth<Container<T, N, Ts...>> {
  typedef typename Container<T, N, Ts...>::value_type inner_t;
  static const size_t depth = 1 + container_depth<inner_t>::depth;
};

#include <vector>
#include <list>
static_assert(container_depth<std::vector<std::list<double>>>::depth == 2, "container_depth test fail");
//static_assert(container_depth<Vec<Vec<float, 3, Vec_ZE>, 2>>::depth == 2, "container_depth test fail");
//static_assert(container_depth<double>::depth == 0, "container_depth fail");
*/
