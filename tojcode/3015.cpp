#include<iostream>
using namespace std;
int fb[25];
void f()
{
  fb[1]=1;
  fb[2]=2;
  for(int i=3;i<25;i++)
    fb[i]=fb[i-1]+fb[i-2];
}
    
int main()
{
   f();
   int n,m;
   cin>>n;
   while(n--)
   {
     cin>>m;
     int re=0;
     for(int i=24;i>1;i--)
     {
       if(m>=fb[i])
       {
         m-=fb[i];
         re+=fb[i-1];
       }
       if(m==0)
       break;
     }
     cout<<re<<endl;
   }
}         