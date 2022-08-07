#ifndef BOUNDED_VALUE
#define BOUNDED_VALUE

template <typename T>
class BoundedValue {
  public:
    BoundedValue();
    BoundedValue(const T min_, T val_, const T max_);

    void operator = (const BoundedValue<T>& other);

    T value() const { return val; };
    T value(T val_);
    T min() const { return minVal; };
    T max() const { return maxVal; };

    bool isMin() { return (val == minVal); }
    bool isMax() { return (val == maxVal); }
  
  private:
    T val;
    T minVal;
    T maxVal;
};

#endif