#include <iostream>

using namespace std;

#include "dickson.h"
#include "complex.h"
#include "quaternion.h"
#include "octonion.h"

int main() {

  Complex comp[4];

  for (int i = 0; i < 4; i++) {
    int a = rand();
    int b = rand();
    comp[i] = Complex(a, b);
  };

  Quaternion quat[2];

  for (int i = 0; i < 2; i++) {
    quat[i] = Quaternion(comp[i], comp[i+1]);
  };

  Octonion oct(quat[0], quat[1]);
  
  return 0;
}


