
using std::ostream;

template<typename T>

class Dickson {
  public:
    T Re;
    T Im;

  public:
    Dickson(){
      //cout << "new di.." << endl;
    };

    Dickson(T a, T b){
      this->Re = a;
      this->Im = b;
      //cout << "new dickson" << endl;
    };

    Dickson(const Dickson& d){
      this->Re = d.Re;
      this->Im = d.Im;
    };
  
    ~Dickson(){};

    /*void setRe(T a){
      this->Re = a;
    };

    void setIm(T b){
      this->Im = b;
    };*/

    T getRe(){
      T re = this->Re;
      return re;
    };

    T getIm(){
      T im = this->Im;
      return im;
    };

    Dickson operator*(Dickson &_B){
     /* T *c = _B.getRe();
      T *d = _B.getIm();
*/
      T c = _B.Re;
      T d = _B.Im;

      // need to be sure conjugate is being accounted for

      T A1 = this->Re * c;// - *(this->Im) * *d;
      T B1 = this->Re * d;// + *(this->Im) * *c;

      T A2 = this->Im * d;
      T B2 = this->Im * c;

      T A = A1 - A2;
      T B = B1 + B2;
    //  cout << A << "\t" << B << endl;

      Dickson res(A, B);

      return res;
    };

    Dickson operator+(Dickson &_B){

      T A = this->Re + _B.Re;
      T B = this->Im + _B.Im;

      Dickson res(A, B);

      return res;
    };

    Dickson operator-(Dickson &_B){

      T A = this->Re - _B.Re;
      T B = this->Im - _B.Im;

      Dickson res(A, B);

      return res;
    };

};

template <typename T>
    ostream& operator<<(ostream& os, Dickson<T> d) {
      os << d.Re
        << "  "
        << d.Im;

      return os;
    };
