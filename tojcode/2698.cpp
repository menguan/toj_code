#include<iostream>
using namespace std;
bool prime(int a)
{
    if(a==2||1==3||a==5||a==7)
      return 1;
    else if(a%2==0)
      return 0;  
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
    
    while(cin>>a,a)
    {
        int count=0;
        for(int i=2;i<=a/2;i++)
        {
            int j=a-i;
            if(prime(i)==1&&prime(j)==1)
                count++;
            
        }
        cout<<count<<endl;
    }
    return 0;
} 