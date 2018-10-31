#include <iostream>
#include <typeinfo>

using namespace std;

#include "baseint.h"
#include "dickson.h"
#include "complex.h"
#include "quaternion.h"
#include "octonion.h"

int main() {

  int ent[8] = {3,1,5,2,1,4,3,2};

  // had to define baseint to generically define conjugate
  // so that generalized multiplication would work.

  Baseint ba(ent[0]), ba2(ent[1]), ba3(ent[2]), ba4(ent[3]),
          ba5(ent[4]), ba6(ent[5]), ba7(ent[6]), ba8(ent[7]);

  Complex com(ba.Re, ba2.Re), com2(ba3.Re, ba4.Re),
          com3(ba5.Re, ba6.Re), com4(ba7.Re, ba8.Re);

  cout << "Complex " << com << endl
        << "Complex " << com2 << endl;  


  Complex conj = ~com;

  cout << "complex conjugate " << conj << endl;
  ////
  // now test complex mult

  Complex comm = com * com2;
  
  cout << "Complex mult " << comm << endl;
  // up to this point.. complex multiplication appears to work.

  Complex csum = com + com2;
  
  cout << "com1 + com2 " << csum << endl;
  //
  Complex csub = com - com2;
  //cout << "com1 - com2 " << csub << endl;
  // up to this point.. complex subtraction appears to work.

  // now need to test Quaternion +, -, and *

  
  Quaternion qua(com, com2),
             qua2(com3, com4);

  cout << "Quaternion1 " << qua << endl
    << "Quaternion2 " << qua2 << endl;
  
  Quaternion quaconj = ~qua;

  cout << "Quaternion conjugate " << quaconj << endl;

  // up to this point.. built and dissassembled quaternion.
  Quaternion quaa = qua + qua2;
  Quaternion quas = qua - qua2;
  
  cout << "Qua1 + Qua2 " << quaa << endl
    << "Qua1 - Qua2 " << quas << endl;

  /// works up to this point
  
  Quaternion quam = qua * qua2;

  cout << "Qua1 * Qua2 " << quam << endl;
  // quaternion mult compiles.. but now need to look at entries to see if correct 

  Octonion oct(qua, qua2);
  
  //cout << "Octonion " << oct << endl;


  return 0;
}


