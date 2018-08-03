#include<iostream>
using namespace std;
int main()
{
   long long a,b,c,d,e,f,start;
   while(cin>>a>>b)
   {
     e=b%a;
     start=b;
     if(e!=1)
     for(int i=e;i>0&&start>a+1;i--)
     {
       start=start-a-1;
     }
     
     cout<<start;
     if(start+a+1<=a*a&&start%a!=a-1)
     while(1)
     {
       if(start+a+1>a*a)
       break;
       cout<<" "<<start+a+1;;
       start=start+a+1;
       if((start%a==0))
       break;
     }
     cout<<endl;  
   }
}  