#include <iostream>
#include <cmath>

using namespace std;

#define MDLS 13 

#include "dickson.h"
#include "baseint.h"
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
  
  Complex comInv = dicksonInv(com);

  cout << "com inverse " << comInv << endl;
  ////
  // now test complex mult

  Complex comm = com * com2;
  
  cout << "Complex mult " << comm << endl;
  
  Complex ab = com * conj;

  cout << "Complex mult com * ~com " << ab << endl; 
  
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
  // quaternion mult is validated
  
  Octonion oct(qua, qua2);
  Octonion octconj = ~oct;
  
  cout << "Octonion oct " << oct << endl;
  cout << "Octonion conjugate ~oct " << octconj << endl;

  Octonion octp = oct * octconj;

  cout << "oct * ~oct " << octp << endl;

  int octpFirst = octp.first();

  cout << "first " << octpFirst << endl;

  int octNorm = normSqrd(oct);

  cout << "normSqrd(oct) " << octNorm << endl;

  /*int nrmInv = normInv(octNorm);

  cout << "normInv " << nrmInv << endl;
*/
  Octonion soct = oct.scale(3);

  cout << "scaled oct by 3 : " << soct << endl;

  // define second octonion to check mult
  int _ent[8] = {2,3,7,3,9,4,5,7};
  
  Baseint _ba(_ent[0]), _ba2(_ent[1]), _ba3(_ent[2]), _ba4(_ent[3]),
          _ba5(_ent[4]), _ba6(_ent[5]), _ba7(_ent[6]), _ba8(_ent[7]);

  Complex _com(_ba.Re, _ba2.Re), _com2(_ba3.Re, _ba4.Re),
          _com3(_ba5.Re, _ba6.Re), _com4(_ba7.Re, _ba8.Re);

  Quaternion _qua(_com, _com2),
             _qua2(_com3, _com4);

  Octonion _oct(_qua, _qua2);

  cout << "Octonion _oct " << _oct << endl;
  
  Octonion octm = oct * _oct;
  
  // octonion product not yet validated .. need to find good
  // validating resource.. wolfram alpha was of no help
  cout << "Octonion product oct * _oct " << octm << endl;

  Octonion octm2 = _oct * oct;

  cout << "Octonion product _oct * oct " << octm2 << endl;

  return 0;
}


