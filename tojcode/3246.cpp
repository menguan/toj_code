#include<iostream>
using namespace std;
int main()
{
    int t;
    int a,b,c,d;
    cin>>t;
    while(t--)
    {
         cin>>a>>b>>c>>d;
         cout<<(a*a-b)/2<<" "<<(a*a*a-3*a*b+2*c)/6<<" "<<(a*a*a*a-d-4*(a*c-d)-3*(b*b-d)-12*(b*(a*a-b)/2-a*c+d))/24<<endl;
    }
}     
