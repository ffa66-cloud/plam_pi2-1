#include <iostream>
#include <stdexcept>
using namespace std;

class EmptyException {};

class FractionException {
public:
    int numerator;
    int denominator;
    string message;
    
    FractionException(int num, int den, string msg) 
        : numerator(num), denominator(den), message(msg) {}
};

class MyFractionException : public runtime_error {
public:
    int numerator;
    int denominator;
    
    MyFractionException(int num, int den, string msg) 
        : runtime_error(msg), numerator(num), denominator(den) {}
};

// ВАРИАНТ Без спецификации исключений (просто функция)
int wholePart1(int numerator, int denominator) {
    if (denominator == 0) {
        throw "Деление на ноль!";
    }
    return numerator / denominator;
}

// Без спецификации (noexcept false)
int wholePart2(int numerator, int denominator) {
    if (denominator == 0) {
        throw "Деление на ноль!";
    }
    return numerator / denominator;
}

// Со стандартным исключением
int wholePart3(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument("Знаменатель не может быть нулем!");
    }
    return numerator / denominator;
}

// С noexcept (не кидает исключений)