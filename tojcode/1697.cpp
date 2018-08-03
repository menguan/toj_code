#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[50];
int tim;
int main()
{
    int ss,ls,bs;
    int sn,ln,bn;
    int t;
    int n;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
         cin>>tim>>n;
         ss=ls=bs=sn=ln=bn=0;
         for(int i=0;i<n;i++)
         {
            cin>>a[i];
         }
         int now=0;
         for(int i=0;i<n;i++)
         {
              if(now+a[i]<=tim)
              {
                  bn++;
                  bs+=(now+a[i]);
                  now+=a[i];
              }
              else
                break;
         }
         sort(a,a+n);
         now=0;
         for(int i=0;i<n;i++)
         {
              if(now+a[i]<=tim)
              {
                  sn++;
                  ss+=(now+a[i]);
                  now+=a[i];
              }
              else
                break;
         }
         for(int i=n-1;i>=0;i--)
         {
              if(now+a[i]<=tim)
              {
                  ln++;
                  ls+=(now+a[i]);
                  now+=a[i];
              }
              else
                break;
         }
         bool sw=1,lw=1,bw=1;
         cout<<"Scenario #"<<cas<<":"<<endl;              
         if(sn>bn||(sn==bn&&ss<bs))
           bw=0;
         if(sn>ln||(sn==ln&&ss<ls))
           lw=0;
         if(bn>ln||(bn==ln&&bs<ls))
           lw=0;
         if(ln>bn||(ln==bn&&ls<bs))
           bw=0;
         if(ln>sn||(ln==sn&&ls<ss))
           sw=0;
         if(bn>sn||(bn==sn&&bs<ss))
           sw=0;        
         if(sw==1)
         {
           cout<<"Steve wins with "<<sn<<" solved problems and a score of "<<ss<<"."<<endl;
         }
         else if(bw==1)
         {
           cout<<"Bill wins with "<<bn<<" solved problems and a score of "<<bs<<"."<<endl;
         }
         else if(lw==1)
         {
           cout<<"Linus wins with "<<ln<<" solved problems and a score of "<<ls<<"."<<endl;
         }
         cout<<endl;
    }
}  
         
         
                                               
