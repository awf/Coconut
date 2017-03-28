#pragma once

// flat_view: Take a container [of container]* of leaf_type, and iterate through all the leaves.

#include "template_utils.h"
#include "container_depth.h"

template <class Iter, class SubIter>
struct nested_iterator {
  typedef nested_iterator<Iter, SubIter> this_t;

  typedef std::forward_iterator_tag iterator_category;
  typedef typename SubIter::value_type value_type;
  typedef size_t difference_type;
  typedef value_type* pointer;
  typedef value_type& reference;

  Iter i;
  Iter end;  // Need this in order to check whether to ripple subiter

  // SubIter should be constructible from i->begin();
  // typedef decltype(std::declval<Iter>()->begin()) subiter_t;

  SubIter subiter;
  SubIter subiter_end;

  nested_iterator() {}

  nested_iterator(Iter i, Iter end) :i(i), end(end)
  {
    reset_subiter();
  }

  void reset_subiter()
  {
    if (i != end) {
      subiter = SubIter{ i->begin(), i->end() };
      subiter_end = SubIter{ i->end(), i->end() };
    }
  }

  // prefix
  this_t operator++()
  {
    ++subiter;
    if (subiter == subiter_end) {
      ++i;
      reset_subiter();
    }
    return *this;
  }

  decltype(*subiter) operator*() { return *subiter; }

  bool operator==(const this_t& that) const
  {
    return i == that.i && (i == end || subiter == that.subiter);
  }
  bool operator!=(const this_t& that) const
  {
    return !(*this == that);
  }
  bool operator<(const this_t& that) const
  {
    if (that.i < i || i == end) return false;
    return i < that.i || subiter < that.subiter;
  }
};

template <class Container, size_t depth>
struct define_flat_view;

template <class T>
struct define_flat_view<T, 0> {
  T& t;
  template <class U>
  define_flat_view(U&& t) :t(t) {}
  T* begin() { return &t; }
  T* end() { return 1+&t; }
};

template <class Container>
struct define_flat_view<Container, 1> {
  typedef typename get_iterator_type<Container>::type container_iter_t;
  // Adapt container iter to add a 2-argument constructor
  struct iterator : public container_iter_t {
    iterator() {}

    template <class U>
    iterator(U&& value, U&& end) :container_iter_t(value) {}
  };

  iterator begin_;
  iterator end_;

  template <class T>
  define_flat_view(T&& that) :
    begin_(that.begin(), that.end()),
    end_(that.end(), that.end())
  {
  }

  iterator begin() { return begin_; }
  iterator end() { return end_; }
};

template <class Container, size_t depth>
struct define_flat_view {
  typedef typename get_iterator_type<Container>::type container_iterator;
  typedef typename get_value_type<Container>::type value_t;
  typedef typename define_flat_view<value_t, depth - 1>::iterator subiter_t;
  typedef nested_iterator<container_iterator, subiter_t> iterator;

  iterator begin_;
  iterator end_;

  template <class T>
  define_flat_view(T&& that) :
    begin_(that.begin(), that.end()),
    end_(that.end(), that.end())
  {
  }

  iterator begin() { return begin_; }
  iterator end() { return end_; }
};


#include <list>
#include <vector>

BOOST_AUTO_TEST_CASE(test_nested_iterator)
{
  boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::log_successful_tests);

  std::list<int> a = { 1, 2 };
  std::list<int> b = { 3,4,5 };
  typedef std::vector<std::list<int>> veclist;
  auto c = veclist{ a,b };
  auto d = veclist{ b,a };
  typedef std::list<veclist> A;
  A l = { c,d };

  define_flat_view<A, 3> fv{ l };

  std::vector<int> all;
  for (auto i : fv)
    all.push_back(i);

  std::cout << "test [";
  for (auto i : fv)
    std::cout << i << " ";
  std::cout << "] == [ 1 2 3 4 5 3 4 5 1 2 ]\n";

  std::vector<int> expected{ 1, 2, 3, 4, 5, 3, 4, 5, 1, 2 };
  BOOST_CHECK_EQUAL_COLLECTIONS(all.begin(), all.end(), expected.begin(), expected.end());

}

template <class Leaf, class Container>
auto flat_view(Container&& c) ->
  typename define_flat_view<typename std::remove_reference<Container>::type, CONTAINER_DEPTH(Container, Leaf)>
{
  return typename define_flat_view<typename std::remove_reference<Container>::type, CONTAINER_DEPTH(Container, Leaf)>{ c };
}


#include <iostream>
#include "Vec.h"
#include "Mat.h"

template <class T, size_t d>
std::string tostring(define_flat_view<T, d>& c)
{
  return std::string{ c.begin(), c.end() };
}

BOOST_AUTO_TEST_CASE(test_deep_iterator)
{
  static_assert(container_depth<Vec<char, 2>, char>::depth == 1, "OIK");
  static_assert(container_depth<const Vec<Vec<char, 2>, 2>, char>::depth == 2, "OIK");

  auto a = vec('i', 't');
  auto b = vec('e', 'r');
  auto const& c = vec(a, b);

  define_flat_view<std::remove_reference<decltype(c)>::type, 2>::iterator i{ c.begin(), c.end() };

  BOOST_CHECK_EQUAL(tostring(flat_view<char>(c)), "iter");
  BOOST_CHECK_EQUAL(tostring(flat_view<char>(b)), "er");

//  std::cout << "TEST DEEP ITER: d=";
//  char d = 'd';
//  for (auto p : flat_view<char>(d))
//    std::cout << p;
//  std::cout << std::endl;
//  BOOST_CHECK_EQUAL(tostring(fv), "d");

  // xxfixme
  Vec<Vec<Vec<Real,4>,3>,2> f;
  double v = 1.1;
  for (auto& a : flat_view<Real>(f))
    a = (v += .3);

  std::cout << "4x3x2:";
  for (auto a : flat_view<Real>(f))
    std::cout << " " << a ;
  std::cout << std::endl;
}

