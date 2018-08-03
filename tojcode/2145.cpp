#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int a[1200];
int b[1200];
int n,r,q;int p;
int main()
{
    int cas=1;
    while(cin>>n,n)
    {
       cout<<"Genome "<<cas++<<endl;

       cin>>r;
       for(int i=0;i<r;i++)
         cin>>a[i]>>b[i];
      cin>>q;
      while(q--)
      {
        cin>>p;
        for(int i=0;i<r;i++)
        {
           if(p>=a[i]&&p<=b[i])
             p=a[i]+b[i]-p;
        }
        cout<<p<<endl;
      }
    }
}                                 
