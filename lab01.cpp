#include <iostream>
#include <cmath>
using namespace std;
struct Pair
{ int first=4; double second=4.4; };

void power(Pair)
{
    cout<<pow(first, second) << endl;
}
int main()
{


    power(first, second);
}