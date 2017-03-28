#pragma once

// The additive identity for all types.
struct Zero {
  operator double() { return 0.0; }
  operator float() { return 0.0f; }
  operator int() { return 0;  }
  operator unsigned int () { return 0; }
};

// GROUP: Add
template <class T>
T operator+(Zero, T&& t)
{
  return t;
}

template <class T>
T operator+(T&& t, Zero)
{
  return t;
}
// ENDGROUP: Add

// GROUP: Mul
template <class T>
Zero operator*(Zero, T&& t)
{
  return t;
}

template <class T>
Zero operator*(T&& t, Zero)
{
  return t;
}
// ENDGROUP: Mul
