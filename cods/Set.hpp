template <typename T>
template <bool IS_CONST>
Set<T>::_Iterator<IS_CONST>::_Iterator(IterType it)
  : it(it)
{ }

template <typename T>
template <bool IS_CONST>
Set<T>::_Iterator<IS_CONST>::_Iterator(const _Iterator<false> &other)
  : it(other.it)
{ }

template <typename T>
template <bool IS_CONST>
typename Set<T>::template _Iterator<IS_CONST>::ValueType
Set<T>::_Iterator<IS_CONST>::operator*() const {
  return it.key();
}

template <typename T>
template <bool IS_CONST>
typename Set<T>::template _Iterator<IS_CONST>&
Set<T>::_Iterator<IS_CONST>::operator++() {
  ++it;
  return *this;
}

template <typename T>
template <bool IS_CONST>
typename Set<T>::template _Iterator<IS_CONST>
Set<T>::_Iterator<IS_CONST>::operator++(int) {
  ++it;
  return *this;
}

template <typename T>
template <bool IS_CONST>
typename Set<T>::template _Iterator<IS_CONST>&
Set<T>::_Iterator<IS_CONST>::operator--() {
  --it;
  return *this;
}

template <typename T>
template <bool IS_CONST>
typename Set<T>::template _Iterator<IS_CONST>
Set<T>::_Iterator<IS_CONST>::operator--(int) {
  --it;
  return *this;
}

template <typename T>
template <bool IS_CONST>
bool Set<T>::_Iterator<IS_CONST>::operator==(const _Iterator &other) const {
  return it == other.it;
}

template <typename T>
template <bool IS_CONST>
bool Set<T>::_Iterator<IS_CONST>::operator!=(const _Iterator &other) const {
  return !(*this == other);
}

template <typename T>
Set<T>::Set() : map() { }

template <typename T>
bool Set<T>::isEmpty() const {
  return map.isEmpty();
}

template <typename T>
int Set<T>::size() const {
  return map.size();
}

template <typename T>
int Set<T>::capacity() const {
  return map.capacity();
}

template <typename T>
void Set<T>::clear() {
  map.clear();
}

template <typename T>
typename Set<T>::Iterator
Set<T>::insert(const T &value) {
  map[value] = true;
  return map.find(value);
}

template <typename T>
bool Set<T>::remove(const T &value) {
  if (map.contains(value)) {
    map.remove(value);
    return true;
  }
  return false;
}

template <typename T>
void Set<T>::reserve(int capacity) {
  map.reserve(capacity);
}

template <typename T>
void Set<T>::shrinkToFit() {
  map.shrinkToFit();
}

template <typename T>
bool Set<T>::contains(const T &value) const {
  return map.contains(value);
}

template <typename T>
bool Set<T>::contains(const Set &other) const {
  for (const auto &elm : other) {
    if (!contains(elm)) {
      return false;
    }
  }
  return true;
}

template <typename T>
Vector<T> Set<T>::values() const {
  return map.keys();
}

template <typename T>
Vector<T> Set<T>::toVector() const {
  return values();
}

template <typename T>
typename Set<T>::Iterator Set<T>::begin() {
  return Iterator(map.begin());
}

template <typename T>
typename Set<T>::ConstIterator Set<T>::begin() const {
  return ConstIterator(map.begin());
}

template <typename T>
typename Set<T>::ConstIterator Set<T>::cbegin() const {
  return ConstIterator(map.cbegin());
}

template <typename T>
typename Set<T>::Iterator Set<T>::end() {
  return Iterator(map.end());
}

template <typename T>
typename Set<T>::ConstIterator Set<T>::end() const {
  return ConstIterator(map.end());
}

template <typename T>
typename Set<T>::ConstIterator Set<T>::cend() const {
  return ConstIterator(map.cend());
}

template <typename T>
typename Set<T>::Set& Set<T>::operator<<(const T &value) {
  insert(value);
  return *this;
}
