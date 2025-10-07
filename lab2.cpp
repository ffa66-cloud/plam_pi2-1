#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void init(Time &t, int h, int m, int s) {
    if (s >= 60) {
        m += s / 60;
        s = s % 60;
    }
    if (m >= 60) {
        h += m / 60;
        m = m % 60;
    }
    if (h >= 24) 
        h = h % 24;
    
    
    t.hours = h;
    t.minutes = m;
    t.seconds = s;
}

void read(Time &t) {
    cout << "Введите время (часы минуты секунды): ";
    cin >> t.hours >> t.minutes >> t.seconds;
    init(t, t.hours, t.minutes, t.seconds);
}

void display(const Time &t) {
    cout << (t.hours < 10 ? "0" : "") << t.hours << ":"
         << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
         << (t.seconds < 10 ? "0" : "") << t.seconds;
}

string toString(const Time &t) {
    stringstream ss;
    ss << (t.hours < 10 ? "0" : "") << t.hours << ":"
       << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
       << (t.seconds < 10 ? "0" : "") << t.seconds;
    return ss.str();
}

void initFromSeconds(Time &t, int totalSeconds) {
    int h = totalSeconds / 3600;
    int m = (totalSeconds % 3600) / 60;
    int s = totalSeconds % 60;
    init(t, h, m, s);
}

void initFromString(Time &t, const string &timeStr) {
    char colon;
    stringstream ss(timeStr);
    int h, m, s;
    ss >> h >> colon >> m >> colon >> s;
    init(t, h, m, s);
}

int differenceInSeconds(const Time &t1, const Time &t2) {
    int sec1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int sec2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    return abs(sec1 - sec2);
}

void addSeconds(Time &t, int secondsToAdd) {
    int totalSeconds = t.hours * 3600 + t.minutes * 60 + t.seconds + secondsToAdd;
    initFromSeconds(t, totalSeconds);
}

int compare(const Time &t1, const Time &t2) {
    int sec1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int sec2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    if (sec1 < sec2) return -1;
    if (sec1 > sec2) return 1;
    return 0;
}

int toSeconds(const Time &t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

int toMinutes(const Time &t) {
    return round((t.hours * 3600 + t.minutes * 60 + t.seconds) / 60.0);
}
int main()
{
    
    
    
    
}

