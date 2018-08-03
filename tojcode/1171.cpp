#include<iostream>
using namespace std;
int oprime(int a)
{
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        return 0;        
    }
    return 1;
}

int main()
{
    int a;
    while(cin>>a&&a)
    {
        
        
        for(int i=3;i<=a/2;i+=2)
        {
            int x;
            x=a-i;
            if(oprime(i)==1&&oprime(x)==1)
            {
                cout<<a<<" = "<<i<<" + "<<x<<endl;
                break;
            }       
                
        }
    }
return 0;
}        