#include <iostream>
using namespace std; template <typename T> int add(T a[], int s, T e) {a[s] = e;return s + 1;} int main(){ int s=3; int a[s]={566548,4968412,8767239};for(int i=0; i<3; i++) cout<<a[i]<<"\n"; cout<<"\nразмер "<<sizeof(a)/sizeof(a[0])<<"\n"<<"new\n"<<endl; s= add(a, s, 7); for(int i=0; i<s; i++) cout<<a[i]<<endl; cout<<"\nразмер "<<s;};
