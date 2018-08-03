#include<iostream>
#include<algorithm>
using namespace std;
int a[100001];
int main()
{
  int t,n,s;
  cin>>t;
  while(t--)
  {
     cin>>n>>s;
     for(int i=0;i<n;i++)
       cin>>a[i];
     
     int sum(0),high,low(0),re(100001);
     for(high=0;high<n;)
     {
       if(low<=high)
       {
         sum+=a[high++];
         while(sum>=s)
         {
           re=min(high-low,re);
           sum-=a[low++];
         }    
         
       }
     }
     if(re==100001)
       cout<<"0"<<endl;
     else
       cout<<re<<endl;
   }
}           
  