#include <iostream>

using namespace std;

#include "dickson.h"
#include "complex.h"
#include "quaternion.h"
#include "octonion.h"

int main() {

  int ent[8] = {3,1,5,2,1,4,3,2};

  Complex com(&ent[0], &ent[1]), com2(&ent[2], &ent[3]),
          com3(&ent[4], &ent[5]), com4(&ent[6], &ent[7]);

  int* comr = com.getRe();
  int* comi = com.getIm();
  int* com2r = com2.getRe();
  int* com2i = com2.getIm();

  cout << *comr << "\t" << *comi << endl;
  cout << *com2r << "\t" << *com2i << endl;

  ////
  
  Quaternion qua(&com, &com2),
             qua2(&com3, &com4);

  Complex *c1, *c2;
  c1 = qua.getRe();
  c2 = qua.getIm();

  Complex a1, a2;
  a1 = *c1;
  a2 = *c2;

  int *a1r, *a1i, *a2r, *a2i;
  a1r = a1.getRe();
  a1i = a1.getIm();
  a2r = a2.getRe();
  a2i = a2.getIm();
  
  cout << "quat.. entries" << endl;
  cout << *a1r << "\t" << *a1i << endl
    << *a2r << "\t" << *a2i << endl;
  
  // up to this point.. built and dissassembled quaternion.
  // now test complex mult

  Complex comm = com * com2;
  int commr = *comm.getRe();
  int commi = *comm.getIm();

  cout << commr << "\t" << commi << endl;
  // up to this point.. complex multiplication appears to work.

  Complex csum = com + com2;
  int csumr = *csum.getRe();
  int csumi = *csum.getIm();

  cout << csumr << "\t" << csumi << endl;
  //
  Complex csub = com - com2;
  int csubr = *csub.getRe();
  int csubi = *csub.getIm();

  cout << csubr << "\t" << csubi << endl;
  // up to this point.. complex subtraction appears to work.

  // now need to test Quaternion +, -, and *

  Quaternion quaa = qua + qua2;
  Quaternion quas = qua - qua2;
  /// works up to this point
  
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
  // quaternion mult compiles.. but now need to look at entries to see if correct 

  cout << *am1r << "\t" << *am1i << endl
    << *am2r << "\t" << *am2i << endl;
  /*
  Octonion oct(quat1, quat2);
*/
  return 0;
}


