
template<typename T>

class Dickson {
  public:
    T Re;
    T Im;

  public:
    Dickson();

    Dickson(T a, T b){
      this->Re = a;
      this->Im = b;
    };
  
    Dickson(const Dickson &obj);

    ~Dickson();

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

      T A = this->Re * c - this->Im * d;
      T B = this->Re * d + this->Im * c;

      Dickson res(A, B);

      return res;
    };

    Dickson operator+(Dickson &_B){
      T c = _B.getRe();
      T d = _B.getIm();

      T A = this->Re + c;
      T B = this->Im + d;

      Dickson res(A, B);

      return res;
    };

    Dickson operator-(Dickson &_B){
      T c = _B.getRe();
      T d = _B.getIm();

      T A = this->Re - c;
      T B = this->Im - d;

      Dickson res(A, B);

      return res;
    };
};
