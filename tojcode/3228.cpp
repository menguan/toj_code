#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
double a[100010];
int b[100010];
double l,r;double nowl,nowr;
int main()
{
    int t;
    int n;
    cin>>t;
    while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++)
       {
           cin>>a[i];
       }
       for(int i=1;i<n;i++)
        cin>>b[i];
       l=a[1]+b[1];r=a[1]+b[1]+a[2];
       nowl=l;nowr=r;
       for(int i=3;i<=n;i++)
       {
           nowl+=a[i-1]+b[i-1];
           nowr+=a[i]+b[i-1];
           l=max(l,nowl/(i-1));
           r=min(r,nowr/(i-1));
       }
       if(l<=r) cout<<setprecision(2)<<fixed<<l<<endl;
       else  cout<<"impossible"<<endl;

   }

}

