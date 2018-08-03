#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct Cow
{
    int t,d;
}cow[100010]; 
bool cmp(Cow mm,Cow nn)
{
     return mm.d*nn.t>nn.d*mm.t;
}
int main()
{
    int n;long long sum=0; 
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
          scanf("%d%d",&cow[i].t,&cow[i].d);
          sum+=cow[i].d;
    }
    sort(cow,cow+n,cmp);
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=(sum-cow[i].d)*cow[i].t*2;
        sum-=cow[i].d;
    }
    printf("%lld\n",ans);
    //while(1);
}
           
