#include<iostream>
using namespace std;
int a[110];
int main()
{
   int n;
   while(cin>>n,n)
   {
     for(int i=0;i<n;i++)
     {
       cin>>a[i];
     }
     int now=n;
     int count=0;
     for(int i=0;i<n;i++)
     {
       if(a[i]<now&&now)
       {  
         count++;
         now=a[i]-1;
       }
       else if(a[i]>=now&&now)
       {
         count++;
         now-=1;
       }
       else if(!now)
       {}     
       
     }
     cout<<n-count<<endl;
   }
}      