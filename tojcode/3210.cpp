#include<iostream>
#include<cstring>
#include<stdio.h>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<ctype.h>
#include<iomanip>
#include<vector>
using namespace std;
//priority_queue<long long,vector<long long>,greater<long long> > q; 
const int maxn=4100010;
long long n1[8100010];
//long long n2[4100010];
int main()
{
    long long c,temp,n,a1,b1,d1,a2,b2,d2,t1,t2,p1,p2;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&c,&n,&a1,&b1,&d1,&a2,&b2,&d2);
    //cin>>c>>n>>a1>>b1>>d1>>a2>>b2>>d2;
    p1=1;
    p2=1;
    //n1[1]=a1*c/d1+b1;
    //n2[1]=a2*c/d2+b2;
    t1=1;
    t2=1;
    n1[1]=c;
    int num=2;
    while(num<=n)
    {
         t1=a1*n1[p1]/d1+b1;
         t2=a2*n1[p2]/d2+b2;
         if(t1<t2)
         {
            if(n1[num-1]!=t1)
             n1[num++]=t1;
           p1++;
         }
         else  
         {
            if(n1[num-1]!=t2)
              n1[num++]=t2;
            p2++;
         }
    }                      
    /*
    for(long long i=2;i<=n;++i)
    {
        while((n1[t1]==c)&&(t1<=p1)){++t1;if(t1>=maxn)  t1-=maxn;}
        while((n2[t2]==c)&&(t2<=p2)){++t2;if(t2>=maxn)  t2-=maxn;}
        if((n1[t1]<=n2[t2]))
        {
            c=n1[t1];
            ++t1;
            if(t1>=maxn)
              t1-=maxn;
        }
        else
        {
            c=n2[t2];
            ++t2;
            if(t2>=maxn)
              t2-=maxn;
        }
        ++p1;//if(p1>=maxn)  p1-=maxn;
        ++p2;//if(p2>=maxn)  p2-=maxn;
        n1[p1%maxn]=a1*c/d1+b1;
        n2[p2%maxn]=a2*c/d2+b2;
    }*/
    printf("%lld\n",n1[num-1]);
   //while(1);
}

