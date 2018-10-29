

class Octonion {
  private: 
    //int e[8];
    int *pe;

  public:
    Octonion() {
      cout << "new octonion" << endl;
    };

    Octonion(class Octonion &obj) {
      cout << "copy constructory" << endl;
      Octonion();
    };

    ~Octonion() {
      cout << "killing octonion" << endl;
    };

    void setEntries(int * ent) {
      this->pe = ent;
      cout << "entries set" << endl;
    }; 

    int getEntry(int ind) {
      if (ind < 8) {
        int ret = *(pe + ind); 
        return ret;
      } else {
        return 0;
      };
    };

    int operator*(Octonion oct1) {
      return 7;
    };

};

