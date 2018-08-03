#include<iostream>
using namespace std;
long long ans[100010];
const long long mod=1000000007;
int main()
{
   ans[1]=2;
   for(int i=2;i<=100000;i++)
   {
       ans[i]=((ans[i-1]*3+2))%mod;
   }
   int n;
   while(cin>>n,n)
     cout<<ans[n]<<endl;
   return 0;
}
