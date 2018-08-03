#include<iostream>
#include<cmath>
using namespace std;
int f(int a)
{
    int i=0;
    while(1)
    {
        if(pow(10,i*1.0)>a)
          break;
        else
          i++;
    }
    int sum=0;
    
    i--;
    
    int j=0;
    while(1)
    {   
        
        int c=(a/(int)(pow(10,i*1.0)));
        sum+=(int)(c*pow(10,j*1.0));
        a=a-(a/(int)(pow(10,i*1.0)))*((int)(pow(10,i*1.0)));
        i--;
        j++;
        if(i==-1)
        break;
    }
    return sum;
}              
    
int main()
{
    int a;
    cin>>a;
   while(a--)
   {
       int m,n;
       cin>>m>>n;
       
       cout<<f(f(m)+f(n))<<endl;
   }
   
   return 0;
} 