#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=1;
    while(n--)
    {
        int a=0,b=0,c=0,d=0;
        int e;
        cin>>e;
        while(25*(a+1)<=e)
            ++a;
        e=e-25*a;
        while(10*(b+1)<=e)
            ++b;
        e=e-10*b;
        while(5*(c+1)<=e)
            ++c;
        e=e-5*c;
        while(1*(d+1)<=e)
            ++d;
            
        cout<<count<<" "<<a<<" QUARTER(S), "<<b<<" DIME(S), "<<c<<" NICKEL(S), "<<d<<" PENNY(S)"<<endl;
        count++;     
    }
    return 0;
}   