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
int wholePart4(int numerator, int denominator) noexcept {
    if (denominator == 0) {
        // В noexcept функциях нельзя бросать исключения
        // Просто возвращает ошибку каким-то другим способом
        return -1; // значение для ошибки
    }
    return numerator / denominator;
}

// С собственным исключением (независимый класс)
int wholePart5(int numerator, int denominator) {
    if (denominator == 0) {
        throw FractionException(numerator, denominator, "Деление на ноль запрещено!");
    }
    return numerator / denominator;
}

// С собственным исключением (наследник стандартного)
int wholePart6(int numerator, int denominator) {
    if (denominator == 0) {
        throw MyFractionException(numerator, denominator, "Ошибка в дроби!");
    }
    return numerator / denominator;
}

int main() {
    cout << "=== ЛАБОРАТОРНАЯ РАБОТА: ИСКЛЮЧЕНИЯ ===" << endl;
    
    int num, den;
    
    cout << "\n1. БЕЗ СПЕЦИФИКАЦИИ ИСКЛЮЧЕНИЙ:" << endl;
    try {
        num = 10; den = 3;
        cout << "Целая часть " << num << "/" << den << " = " << wholePart1(num, den) << endl;
        
        num = 10; den = 0;
        cout << "Целая часть " << num << "/" << den << " = " << wholePart1(num, den) << endl;
    }
    catch (const char* error) {
        cout << "Поймано исключение: " << error << endl;
    }
    
    cout << "\n2. ВТОРАЯ ВЕРСИЯ БЕЗ СПЕЦИФИКАЦИИ:" << endl;
    try {
        num = 15; den = 4;
        cout << "Целая часть " << num << "/" << den << " = " << wholePart2(num, den) << endl;
        
        num = 15; den = 0;
        cout << "Целая часть " << num << "/" << den << " = " << wholePart2(num, den) << endl;
    }
    catch (const char* error) {
             cout << "Поймано исключение: " << error << endl;
    }
    
    cout << "\n3. СО СТАНДАРТНЫМ ИСКЛЮЧЕНИЕМ:" << endl;
    try {
        num = 20; den = 6;
        cout << "Целая часть " << num << "/" << den << " = " << wholePart3(num, den) << endl;
        
        num = 20; den = 0;
        cout << "Целая часть " << num << "/" << den << " = " << wholePart3(num, den) << endl;
    }
    catch (invalid_argument& e) {
        cout << "Поймано invalid_argument: " << e.what() << endl;
    }
    
    cout << "\n4. С noexcept (НЕ кидает исключения):" << endl;
    num = 25; den = 7;
    cout << "Целая часть " << num << "/" << den << " = " << wholePart4(num, den) << endl;