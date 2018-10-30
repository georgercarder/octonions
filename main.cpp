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
  
  Quaternion qua(com, com2),
             qua2(com3, com4);

  cout << "Quaternion " << qua << endl;
  
  // up to this point.. built and dissassembled quaternion.
  // now test complex mult

  Complex comm = com * com2;
  
  cout << comm << endl;
  // up to this point.. complex multiplication appears to work.

  Complex csum = com + com2;
  
  cout << csum << endl;
  //
  Complex csub = com - com2;
  cout << csub << endl;
  // up to this point.. complex subtraction appears to work.

  // now need to test Quaternion +, -, and *
/*
  Quaternion quaa = qua + qua2;
  Quaternion quas = qua - qua2;
 */ /// works up to this point
  /*
  Quaternion quam = qua * qua2;

  Complex *cm1, *cm2;
  cm1 = quam.getRe();
  cm2 = quam.getIm();

  Complex am1, am2;
  am1 = *cm1;
  am2 = *cm2;

  int *am1r, *am1i, *am2r, *am2i;
  am1r = am1.getRe();
  am1i = am1.getIm();
  am2r = am2.getRe();
  am2i = am2.getIm();
 */ // quaternion mult compiles.. but now need to look at entries to see if correct 

 /* cout << *am1r << "\t" << *am1i << endl
    << *am2r << "\t" << *am2i << endl;
 */ /*
  Octonion oct(quat1, quat2);
*/
  return 0;
}


