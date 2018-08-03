#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
const int mod=10007;
int ret[3][3];
int t[3][3];
int ans[5]={0,0,0,2,6};
void mut(int a[3][3],int b[3][3])
{
     int c[3][3];
     memset(c,0,sizeof(c));
     for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
     for(int k=0;k<3;k++)
     {
        c[i][j]+=(a[i][k]*b[k][j])%mod;
     }
     for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
        a[i][j]=c[i][j];
}
void f(int x)
{
     t[0][0]=t[0][1]=t[0][2]=1;
     t[1][0]=1;t[1][1]=t[1][2]=0;
     t[2][0]=t[2][1]=0;t[2][2]=2;
     for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
       ret[i][j]=(i==j)?1:0;
     while(x)
     {
         if(x&1)
         {
              mut(ret,t);
              x--;
         }
         else
         {
             mut(t,t);
             x/=2;
         }
     }
}
                             
int main()
{
    int n;
    while(cin>>n)
    {
       if(n<=4)
       cout<<ans[n]<<endl;
       else
       {
          f(n-4);
          cout<<(ret[0][0]*6+ret[0][1]*2+ret[0][2]*8)%mod<<endl;
       }
    }
} 
                 
