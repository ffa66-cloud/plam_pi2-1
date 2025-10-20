#include <iostream>
#include <string>
using namespace std;


class Array {
protected:
   static const int MAX_SIZE = 100; 
    unsigned char data[MAX_SIZE];    
    int size;                        

public:

    Array(int s = 0, unsigned char value = 0) {
        if (s < 0 || s > MAX_SIZE) {
            cout << "Ошибка: недопустимый размер!" << endl;
            exit(1);
        }
        size = s;
        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }


    unsigned char& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс " << index << " вне диапазона!" << endl;
            exit(1);
        }
        return data[index];
    }


    virtual Array* add(Array& other) {
        cout << "Сложение в базовом классе Array" << endl;
        return new Array(0);
    }


    void display() {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << (int)data[i];
            if (i < size - 1) cout << " ";
        }
        cout << "]" << endl;
    }

    int getSize() { return size; }
};


class Decimal : public Array {
public:
    Decimal(int s = 0, unsigned char value = 0) : Array(s, value) {
      
    }


    Array* add(Array& other) override {
        cout << "Сложение десятичных чисел" << endl;
        

        int maxSize = (size > other.getSize()) ? size : other.getSize();