#include<iostream>
#include<string>
#include<cmath>

using namespace std;
char s[1000000];
void f(int low,int high)
{
     if(low==high)
     return  ;
     int t=(high-low+1)/3;
     for(int i=low+t;i<low+2*t;i++)
     {
         s[i]=' ';
         
     }    
     f(low,low+t-1);
     f(low+2*t,high);    
}
   
int main()
{
    int order;
    while(cin>>order)
    {
        int sum=(int)pow(3,order*1.0);
         
        for(int i=0;i<sum;i++)
            s[i]='-';
        f(0,sum-1);
        for(int i=0;i<sum;i++)
            cout<<s[i];
            
        cout<<endl;    
        
    }
    
    return 0;
}  