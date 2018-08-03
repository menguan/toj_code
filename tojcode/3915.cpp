#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int a[100000][60];
int temp[60];
int b[60];
int n,l,r;
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
         int cir=0;
         for(int i=1;i<=52;i++)
           a[0][i]=i;
         for(int i=1;i<=52;i++)
           cin>>b[i];
         cin>>n>>l>>r;
         while(1)
         {
            for(int i=l;i<=r;i++)
            {
               temp[i]=a[cir][i];
            }
            cir++;
            for(int i=1;i<=1+r-l;i++)
            {
               a[cir][i]=temp[i+l-1];
            }
            for(int j=1+r-l+1,k=1;k<=l-1;j++,k++)
            {
               a[cir][j]=a[cir-1][k];
            }
            for(int j=r+1;j<=52;j++)
            {
                a[cir][j]=a[cir-1][j];
            }
            int jj;
            for(jj=1;jj<=52;jj++)
            {
                if(a[cir][jj]!=a[0][jj])
                  break;
            }
            if(jj==53)
              break;
         }
         //cout<<"kk"<<cir<<endl;
         cout<<"Case #"<<cas<<":";
         int ttt=n%cir;
         for(int i=1;i<=52;i++)
         {
            cout<<" "<<b[a[ttt][i]];
         }
         cout<<endl;     
    }
}        
                                             
