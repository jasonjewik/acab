#include <limits>
#include <stdexcept>
#include <string>

#include "bounded_value.h"

template <typename T>
BoundedValue<T>::BoundedValue() {
  val = std::numeric_limits<T>::min();
  minVal = std::numeric_limits<T>::min();
  maxVal = std::numeric_limits<T>::max();
};

template <typename T>
BoundedValue<T>::BoundedValue(const T min_, T val_, const T max_) {
  if (val_ < min_ || val_ > max_)
    throw std::invalid_argument(
      std::to_string(val_) + " is not in [" +
      std::to_string(min_) + ", " + std::to_string(max_)
    );
  val = val_;
  minVal = min_;
  maxVal = max_;
};

template <typename T>
void BoundedValue<T>::operator = (const BoundedValue<T>& other) {
  val = other.value();
  minVal = other.min();
  maxVal = other.max();
};

template <typename T>
T BoundedValue<T>::value(T val_) {
  if (val_ < minVal) {
    val = minVal;
    return val_ - minVal;
  } else if (val_ > maxVal) {
    val = maxVal;
    return val_ - maxVal;
  } else {
    val = val_;
    return 0;
  }
};

template class BoundedValue<short>;
template class BoundedValue<int>;
template class BoundedValue<long>;
template class BoundedValue<float>;
template class BoundedValue<double>;