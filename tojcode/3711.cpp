#include<iostream>
#include<cmath>
using namespace std;
const int Max=50000;
int sum[Max];
int res[Max];
 
void solve()
{
     for(int i=3;i<Max;++i)
     {
         int tot=1;
         for(int j=2;j<=sqrt((double)(i));++j)
         {
             if(i%j==0)
             {
                 tot+=j;
                 if(i!=j*j)
                 {
                     tot+=(i/j);
                 }
             }
         }
         sum[i]=tot;
     }
     for(int i=6;i<=18000;++i)
     {
         int t=sum[i];
         if(i==sum[t]&&i!=t)
         {
             res[i]=t;
             res[t]=i;
         }
     }
 }
 
 int main(void)
 {
     solve();
     int S;
     while(cin>>S)
     {
         for(int i=S;;++i)
         {
             if(res[i])
             {
                 cout<<i<<' '<<res[i]<<endl;
                 break;
             }
         }
     }
     return 0;
 }