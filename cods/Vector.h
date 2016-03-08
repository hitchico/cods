#include <cassert>
#include <cstring> // memcpy
#include <utility> // swap

#include "cods/Global.h"
#include "cods/Utility.h"

CODS_BEGIN_NAMESPACE

/// Implementation of a container class similar to the std::vector.
template <typename T,        ///< Item type.
          int INIT_CAP = 64, ///< Initial capacity size.
          int CAP_MULT = 2>  ///< Capacity multiplier.
class Vector {
public:
  /// Create empty vector with no capacity.
  Vector();

  /// Create vector filled with \p size elements of value \p val.
  Vector(int size, T val);

  /// Create vector from the values of raw array \p values.
  Vector(int size, T *values);

  /// Create vector from iterator range.
  template <typename Iterator>
  Vector(Iterator first, Iterator last);

  ~Vector();

  bool isEmpty() const;
  int size() const;
  int capacity() const;

  /// Insert value at the end.
  void append(const T &val);

  /// Insert value at the beginning.
  void prepend(const T &val);

  void insert(int pos, const T &val);

  void print() const;

  void clear();

  void shrinkToFit();

  T operator[](int pos);
  const T &operator[](int pos) const;

  void remove(const T &val);
  void removeAt(int pos);

private:
  void fillDefault(T *ptr, int n);
  void alloc(int size);
  void checkAlloc();

  /// Appends value but only checks capacity if check is set.
  /** This saves processing time when appending very many items. */
  void _append(const T &val, bool check = true);

  void shiftRight(int pos);
  void shiftLeft(int pos);

  void removeFrom(const T &val, int pos = 0);

  int items, cap;
  T *data;
};

#include "cods/Vector.hpp"

CODS_END_NAMESPACE
