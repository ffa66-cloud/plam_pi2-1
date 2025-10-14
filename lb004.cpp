#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        minutes += seconds / 60;
        seconds = seconds % 60;
        if (seconds < 0) {
            seconds += 60;
            minutes -= 1;
        }
        
        hours += minutes / 60;
        minutes = minutes % 60;
        if (minutes < 0) {
            minutes += 60;
            hours -= 1;
        }
        
        hours = hours % 24;
        if (hours < 0) {
            hours += 24;
        }
    }

public:
    Time() : hours(0), minutes(0), seconds(0) {}
    
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }
    
    Time(const string &timeStr) {
        char colon;
        stringstream ss(timeStr);
        ss >> hours >> colon >> minutes >> colon >> seconds;
        normalize();
    }
    
    Time(int totalSeconds) {
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
        normalize();
    }
    
    void read() {
        cout << "Введите время (часы минуты секунды): ";
        cin >> hours >> minutes >> seconds;
        normalize();
    }
    
    void display() const {
        cout << *this;
    }
    
    string toString() const {
        stringstream ss;
        ss << *this;
        return ss.str();
    }
    
    int differenceInSeconds(const Time &other) const {
        int sec1 = toSeconds();
        int sec2 = other.toSeconds();
        return abs(sec1 - sec2);
    }
