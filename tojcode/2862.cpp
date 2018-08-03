#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100010];
int main()
{
    int t;int n;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
          scanf("%d",&a[i]);
        sort(a,a+n);
        int maxn=10101010;
        int pos;
        for(int i=0;i<n-4;i++)
        {
           if(1+a[i+4]-a[i]<maxn)
            {
                 maxn=1+a[i+4]-a[i];
                 pos=i;
            }
        }
        cout<<"Scenario #"<<cas<<":"<<endl;
        cout<<maxn<<":";
        for(int i=pos;i<pos+5;i++)
          cout<<" "<<a[i];
        cout<<endl<<endl;  
        }}              
    
