#include <cmath>

#define MDLS 5

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

int normInv(int n){

  int normInv = (int)pow(n, MDLS - 2) % MDLS;
  
  return normInv;
};

ostream& operator<<(ostream& os, Baseint d) {
  os << d.Re;

  return os;
};
