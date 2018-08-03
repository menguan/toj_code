#include<iostream>
#include<cstring>
using namespace std;
int mark[1000];
int a[2000];
int c1[1000],c2[1000];
int n,F;
void f()
{
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    c1[0]=1;
    int tp;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<F;j++)
       {
           if(c1[j])
           {
              c2[j%F]=(c2[j%F]+c1[j])%100000000;
              c2[(j+a[i])%F]=(c2[(j+a[i])%F]+c1[j])%100000000;
             
           }
       }
       for(int j=0;j<F;j++)
       {
           c1[j]=c2[j];
           c2[j]=0;
       }    
    }
}
int main()
{
    int tp;
    while(cin>>n>>F)
    {
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
       }
       f();
       c1[0]--;
       
       cout<<c1[0]<<endl;
       //while(1);
    }
}
