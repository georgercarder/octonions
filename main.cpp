#include <iostream>

using namespace std;

#include "dickson.h"
#include "complex.h"
#include "quaternion.h"
#include "octonion.h"

int main() {

  int ent[8] = {3,1,5,2,1,4,3,2};

  Complex com(ent[0], ent[1]), com2(ent[2], ent[3]),
          com3(ent[4], ent[5]), com4(ent[6], ent[7]);

  cout << "Complex " << com << endl
        << "Complex " << com2 << endl;  

  ////
  // now test complex mult

  Complex comm = com * com2;
  
  cout << comm << endl;
  // up to this point.. complex multiplication appears to work.

  Complex csum = com + com2;
  
  cout << "com1 + com2 " << csum << endl;
  //
  Complex csub = com - com2;
  cout << "com1 - com2 " << csub << endl;
  // up to this point.. complex subtraction appears to work.

  // now need to test Quaternion +, -, and *

  
  Quaternion qua(com, com2),
             qua2(com3, com4);

  cout << "Quaternion1 " << qua << endl
    << "Quaternion2 " << qua2 << endl;
  
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
  
  cout << "Octonion " << oct << endl;

  return 0;
}


