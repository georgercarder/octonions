
using std::ostream;

template<typename T>

class Dickson {
  public:
    T Re;
    T Im;
    int coef = -1;
    /* note: when building quaternionic algebra, 
     *  (a,b)_F is division ring iff 
     *  ax^2+by^2=1 has no solution (x,y) in F
     *
     * when 1,u,v,w is basis of algebra 
     * with u^2=a and v^2=p and w:=uv=-vu
     * .. the 'coef' changes the values a, p
     */

  public:
    Dickson(){
      //cout << "new di.." << endl;
    };

    Dickson(T a, T b, int cf = -1){

      this->Re = a;
      this->Im = b;

      this->coef = cf;

      //cout << "new dickson" << endl;
    };

    Dickson(const Dickson& d){
      this->Re = d.Re;
      this->Im = d.Im;
    };
  
    ~Dickson(){};

    Dickson scale(int s){
      T sRe = this->Re.scale(s);
      T sIm = this->Im.scale(s);

      Dickson res(sRe, sIm);

      return res;
    };

    Dickson operator*(Dickson &_B){

      T c = _B.Re;
      T d = _B.Im;

      T A1 = this->Re * c;
      T B1 = d * this->Re; 

      T cconj = ~c;
      T dconj = ~d; 

      T A2 = dconj * this->Im;
      T B2 = this->Im * cconj;

      //T A = A1 - A2;
      
      T _A2 = A2.scale(this->coef);

      T A = A1 + _A2;
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

int modPow(int n, int itr, int modls){ // needed for accuracy

  if (itr > 0) {

    return (n * modPow(n, itr - 1, modls)) % modls;
  
  } else {
  
    return 1;
  
  };
};

int normInv(int n){

  int normInv = modPow(n, MDLS - 2, MDLS);
  //int normInv = (int)pow(n, MDLS - 2) % MDLS;
  
  return normInv;
};

template<typename T> 
Dickson<T> dicksonInv(Dickson<T> d){
  Dickson<T> conj = ~d;

  cout << "inverse conj " << conj << endl;
  int norm = normSqrd(d);
  int nrmInv = normInv(norm);

  cout << "norm " << norm << endl;
  cout << "inverse norm " << nrmInv << endl;

  Dickson<T> inv = conj.scale(nrmInv);

  return inv;
};

template <typename T>
    ostream& operator<<(ostream& os, Dickson<T> d) {
      os << d.Re
        << "  "
        << d.Im;

      return os;
};
