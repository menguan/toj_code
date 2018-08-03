#include<iostream>
using namespace std;
int main()
{
    int a;
    while(cin>>a,a)
    {   
        int i=1;
        while(1)
        {
        if(a==1)
        {
            cout<<i<<endl;
            break;
        }
        if(a%2==0)
        {
            a/=2;
            i++;
            
            
        }
        if(a%2==1&&a!=1)
        {
            a=3*a+1;
            i++;
            
        }    
        }
    }
    return 0;
}   