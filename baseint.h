

class Baseint {
  public:
    int Re;
    int Im = 0;

    Baseint(){};

    Baseint(int a){
      this->Re = a;
    }

    Baseint(const Baseint& b) {
      this->Re = b.Re;
    }
    

    int operator*(Baseint &b){
      int re = this->Re * b.Re;

      return re;
    }
    
    int operator+(Baseint &b){
      int re = this->Re + b.Re;

      return re;
    }

    int operator-(Baseint &b){
      int re = this->Re - b.Re;
      
      return re;
    }
};


ostream& operator<<(ostream& os, Baseint d) {
  os << d.Re;

  return os;
};
