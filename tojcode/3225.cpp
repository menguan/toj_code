#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<cmath>
using namespace std;
char temp[10];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       cin>>temp;
       int h=(temp[0]-'0')*10+temp[1]-'0';
       int m=(temp[3]-'0')*10+temp[4]-'0';
       if(h>12)
         h-=12;
         
       int a1=h*60+m;
       int a2=m*12;
       int ans=abs(a1-a2);
       if(ans>360)
         ans=720-ans;
       if(ans%2)  cout<<ans<<"/"<<2<<endl;
       else cout<<ans/2<<endl;
    }
}     
             
