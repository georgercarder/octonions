
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


    Dickson operator*(Dickson &_B){

      T c = _B.Re;
      T d = _B.Im;

      // need to be sure conjugate is being accounted for

      T A1 = this->Re * c;
      T B1 = d * this->Re; 

      T cconj = ~c;
      T dconj = ~d; 

      T A2 = dconj * this->Im;
      T B2 = this->Im * cconj;

      //cout << "(" << this->Re << ")(" << c << ")-(" << this->Im << ")(" << dconj << ") + (" << this->Re << ")(" << d << ")+(" << this->Im << ")(" << cconj << ")\n" ;

      T A = A1 - A2;
      T B = B1 + B2;

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

    Dickson operator-(){
      T A = -this->Re;
      T B = -this->Im;

      Dickson res(A, B);

      return res; 
    }

    Dickson operator~(){ // this is conjugate operator

      T A = ~this->Re;
      T B = -this->Im;
      
      Dickson res(A, B);
      return res;
    };

    int first(){
      int first = this->Re.first(); 

      return first;     
    };
};

template<typename T>
int normSqrd(Dickson<T> d){
  Dickson<T> conj = ~d;
  Dickson<T> prod = d * conj;
  int norm = prod.first();

  return norm;
};


template <typename T>
    ostream& operator<<(ostream& os, Dickson<T> d) {
      os << d.Re
        << "  "
        << d.Im;

      return os;
};
