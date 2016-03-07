#include <iostream>
using namespace std;

#include "cods/Vector.h"
using namespace cods;

int main(int argc, char **argv) {
  Vector<int, 3> vec;

  cout << "Vector: capacity: " << vec.capacity()
       << ", size: " << vec.size() << endl;
  vec.print();

  cout << endl << "Appending 10" << endl;
  vec.append(10);
  cout << "Vector: capacity: " << vec.capacity()
       << ", size: " << vec.size() << endl;
  vec.print();

  cout << endl << "Prepending 9, 8" << endl;
  vec.prepend(9);
  vec.prepend(8);
  cout << "Vector: capacity: " << vec.capacity()
       << ", size: " << vec.size() << endl;
  vec.print();

  cout << endl << "Inserting 3 at 1" << endl;
  vec.insert(1, 3);
  cout << "Vector: capacity: " << vec.capacity()
       << ", size: " << vec.size() << endl;
  vec.print();

  cout << endl << "Shrink to fit" << endl;
  vec.shrinkToFit();
  cout << "Vector: capacity: " << vec.capacity()
       << ", size: " << vec.size() << endl;
  vec.print();

  cout << endl << "Clearing" << endl;
  vec.clear();
  cout << "Vector: capacity: " << vec.capacity()
       << ", size: " << vec.size() << endl;
  vec.print();

  cout << endl << "Appending 20, 30, 30, 50" << endl;
  vec.append(20);
  vec.append(30);
  vec.append(30);
  vec.append(50);
  cout << "Vector: capacity: " << vec.capacity()
       << ", size: " << vec.size() << endl;
  vec.print();

  int pos = 2;
  cout << endl << "Value at position = " << pos << " is: " << vec[pos] << endl;

  cout << endl << "Removing 30" << endl;
  vec.remove(30);
  cout << "Vector: capacity: " << vec.capacity()
       << ", size: " << vec.size() << endl;
  vec.print();

  pos = 1;
  cout << endl << "Remove at position = " << pos << endl;
  vec.removeAt(pos);
  cout << "Vector: capacity: " << vec.capacity()
       << ", size: " << vec.size() << endl;
  vec.print();

  return 0;
}
