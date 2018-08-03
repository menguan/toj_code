#include<iostream>
using namespace std;
int main()
{
    double f0,f1,f2;
    while(cin>>f0>>f1>>f2)
    {
        double c=f0;
        double a=(f2-2*f1+f0)*0.5;
        double b=f1-a-c;
        
        cout<<(int)(9*a+3*b+c)<<" "<<(int)(16*a+4*b+c)<<" "<<(int)(25*a+5*b+c)<<endl;
    }
    return 0;
}   