#pragma once

template <class T>
struct counting_iterator {
  typedef counting_iterator<T> this_t;
  size_t count;
  T retval;
  counting_iterator(size_t n, T retval) : count(n), retval(retval) {}
  this_t & operator++(int) { this_t ret = *this;  ++count; return ret; }
  this_t & operator++() { ++count; return *this; }

  template <class U>
  bool operator==(const U& that) const { return count == that.count; }

  template <class U>
  bool operator!=(const U& that) const { return count != that.count; }

  typedef std::forward_iterator_tag iterator_category;
  typedef int difference_type;
  typedef difference_type distance_type;	// retained

  T operator*() { return retval; }

  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
};

