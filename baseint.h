

class Baseint {
  public:
    int Re;
    int Im = 0;
    

    Baseint(){};

    Baseint(int a){
      this->Re = a % MDLS;
    }

    Baseint(const Baseint& b) {
      this->Re = b.Re;
    }

    int scale(int s){
      int sRe = s * this->Re;
      
      return sRe;
    };

    int operator*(Baseint &b){
      int re = (this->Re * b.Re) % MDLS;

      return re;
    }
    
    int operator+(Baseint &b){
      int re = (this->Re + b.Re) % MDLS;

      return re;
    }

    int operator-(Baseint &b){
      int re = (this->Re - b.Re) % MDLS;
      
      return re;
    }

    int operator-(){
      int re = -this->Re;

      return re;
    }

    int operator~(){ // this is conjugate operator.. which is terminal here

      int re = this->Re;

      return re;
    }

    int first(){
      int first = this->Re; 

      return first;     
    };
};


ostream& operator<<(ostream& os, Baseint d) {
  os << d.Re;

  return os;
};
