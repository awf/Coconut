#pragma once

#include <boost/mpl/has_xxx.hpp>

BOOST_MPL_HAS_XXX_TRAIT_DEF(value_type)

#define ASSERT_SAME_TYPE(A,B) static_assert(std::is_same<A, B>::value, "FAIL")

template <class T>
struct is_container {
  static constexpr bool value = has_value_type<T>::value;
};

#include <vector>
static_assert(is_container<std::vector<int>>::value, "FAIL");
static_assert(!is_container<int>::value, "FAIL");

// FUNGROUP: get_value_type<T>::type returns T::value_type or void if T is not a container
template <class Container, bool is_compound>
struct get_value_type_aux {
};

template <class Container>
struct get_value_type_aux<Container, true> {
  typedef typename std::remove_reference<decltype(*std::declval<Container>().begin())>::type type;
};

template <class Container>
struct get_value_type_aux<Container, false> {
  typedef void type;
};

template <class Container>
struct get_value_type {
  typedef typename get_value_type_aux<Container, is_container<Container>::value>::type type;
};

ASSERT_SAME_TYPE(get_value_type<double>::type, void);
ASSERT_SAME_TYPE(get_value_type<std::vector<double>>::type, double);
ASSERT_SAME_TYPE(get_value_type<const std::vector<double>>::type, double const);

// ENDGROUP: get_value_type

template <class Container>
struct get_iterator_type {
  typedef decltype(std::declval<Container>().begin()) type;
};

ASSERT_SAME_TYPE(get_iterator_type<std::vector<double>>::type, std::vector<double>::iterator);
ASSERT_SAME_TYPE(get_iterator_type<const std::vector<double>>::type, std::vector<double>::const_iterator);
