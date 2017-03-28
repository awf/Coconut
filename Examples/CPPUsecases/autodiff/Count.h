


template <typename T, typename... Ts>
struct Count {
  static const size_t count = 1 + Count<Ts...>::count;
};

template <typename T>
struct Count<T> {
  static const size_t count = 1;
};

