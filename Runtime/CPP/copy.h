#pragma once

// variadic copy functions

template <typename Iter, typename T>
void vcopy(Iter p, T t)
{
  *p = t;
}

template <typename Iter, typename T, typename... Ts>
void vcopy(Iter p, T t, Ts... ts)
{
  *p++ = t;
  vcopy(p, ts...);
}

