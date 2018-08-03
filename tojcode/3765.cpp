/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaa                 aaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaa  aaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaa   aaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaa   aaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaa   aaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaa    aaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaa   aaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaa   aaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaa                aaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
    int a[120];
    int b[120];
    int n,m;
    int p,q;
    int ans;int hal;
    int ns,ms;
    int sum=0;
    while(cin>>n>>m&&(n+m))
    {
         ns=0;ms=0;
         for(int i=0;i<n;i++)
         {  cin>>a[i];ns+=a[i];}
         for(int j=0;j<m;j++)
         {  cin>>b[j];ms+=b[j];}
         if((ns+ms)%2) { cout<<-1<<endl;continue;}
         hal=(ns+ms)/2;
         p=1000;q=1000;
         for(int i=0;i<n;i++)
         {
              for(int j=0;j<m;j++)
              {
                 if(ns+b[j]-a[i]==ms+a[i]-b[j])
                 {
                      if(p+q>a[i]+b[j])
                      {
                         p=a[i];
                         q=b[j];
                      }              
                 }
              }
         }
         if(p==1000)
           cout<<-1<<endl;
         else
           cout<<p<<" "<<q<<endl;
    }
}                                  
                               
