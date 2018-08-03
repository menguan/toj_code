#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double h,l,v;
    while(cin>>h>>l>>v&&(h+l+v))
    cout<<setprecision(2)<<fixed<<0.5*v*v/9.8-0.5*9.8*l*l/(v*v)+h<<endl;
}