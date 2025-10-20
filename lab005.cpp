#include <iostream>
#include <string>
using namespace std;

class Triad {
protected:
    int first, second, third;

public:
    Triad() : first(0), second(0), third(0) {}
    
    Triad(int f, int s, int t) {
        if (f < 0 || s < 0 || t < 0) {
            cout << "Ошибка: числа не могут быть отрицательными!" << endl;
            exit(1);
        }
        first = f;
        second = s;
        third = t;
    }
    
  
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    int getThird() const { return third; }
    

    void setFirst(int f) { 
        if (f < 0) {
            cout << "Ошибка: число не может быть отрицательным!" << endl;
            return;
        }
        first = f; 
    }
    
    void setSecond(int s) { 
        if (s < 0) {
            cout << "Ошибка: число не может быть отрицательным!" << endl;
            return;
        }
        second = s; 
    }
    
    void setThird(int t) { 
        if (t < 0) {
            cout << "Ошибка: число не может быть отрицательным!" << endl;
            return;
        }
        third = t; 
    }