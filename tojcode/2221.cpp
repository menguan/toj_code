#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int num[6];
bool dp[1200];
int sum;
void pack(int c)
{
     for(int i=sum;i>=c;i--)
     {
         if(dp[i-c])
           dp[i]=1;
     }
}
void f(int v,int c)
{
     int k=1;
     while(k<c)
     {
           pack(k*v);
           c-=k;
           k*=2;
     }
     pack(c*v);
}
int main()
{
    while(cin>>num[0]>>num[1]>>num[2]>>num[3]>>num[4]>>num[5])
    {
         memset(dp,0,sizeof(dp));
         dp[0]=1;
         sum=num[0]+2*num[1]+3*num[2]+5*num[3]+10*num[4]+20*num[5];
         f(1,num[0]);
         f(2,num[1]);
         f(3,num[2]);
         f(5,num[3]);
         f(10,num[4]);
         f(20,num[5]);
         int ret=0;
         for(int i=0;i<=sum;i++)
           if(dp[i])
             ret++;
         cout<<ret<<endl;
    }
}    
                                                              
                   
