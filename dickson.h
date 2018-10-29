
template<typename T>

class Dickson {
  public:
    T Re;
    T Im;

  public:
    Dickson(){
      cout << "new dickson" << endl;  
    };

    Dickson(T a, T b){
      cout << "new dickson number" << endl;
      this->Re = a;
      this->Im = b;
    };
  
    Dickson(const Dickson &obj) {
      cout << "copy dickson" << endl;
    };

    ~Dickson(){
      cout << "dickson killed" << endl;
    };

    void setRe(T a){
      this->Re = a;
    };

    void setIm(T b){
      this->Im = b;
    };

    T getRe(){
      T re = this->Re;
      return re;
    };

    T getIm(){
      T im = this->Im;
      return im;
    };

    Dickson operator*(Dickson &_B){
      T c = _B.getRe();
      T d = _B.getIm();

      cout << c << endl
          << d << endl;

      T A = this->Re * c - this->Im * d;
      T B = this->Re * d + this->Im * c;

      Dickson res(A, B);

      return res;
    };
};
