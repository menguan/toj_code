#include<iostream>
using namespace std;
int main()
{
    int f[10];
    f[0] = 1; 
    for(int i = 1; i < 11; i++) 
        f[i] = f[i-1] * i; 
 
    int a;
    kk:while(cin>>a)
    {
        if(a<0)
          return 0;
        
        if(a==0)
        {
          cout<<"NO"<<endl;
          continue;
        }
        
        for(int i=9;i>=0;i--)
        {
            if(a-f[i]>=0)
              a-=f[i];
              
            
        }
        if(a==0)
            {
              cout<<"YES"<<endl;
              
            }
            else  
        cout<<"NO"<<endl;
    }
    return 0;
}    