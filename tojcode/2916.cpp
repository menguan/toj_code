#include<iostream>
using namespace std;
int f(int m,int n)
{
    
    int r=m%n;
    while(r)
    {
        m=n;
        n=r;
        r=m%n;
    }
    return n;
}        
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(m%n==0)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<n/f(m,n)<<endl;
        }
    }            
    
    return 0;
}