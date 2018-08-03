#include<iostream>
#include<cstring>
using namespace std;
int a[60000];
int main()
{
   int n;
   while(cin>>n)
   {
       a[1]=1;
       for(int i=2;i<=n;i++)
       {
           int now=i-1;
           while(now)
           {
               a[now]=a[now/2];
               now/=2;
           }
           a[i]=1;
           a[1]=i;
       }
       cout<<a[1];
       for(int i=2;i<=n;i++)  cout<<" "<<a[i];
       cout<<endl;
   }
}
