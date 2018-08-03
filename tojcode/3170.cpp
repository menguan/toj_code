#include<iostream>
using namespace std;
int a[20000];
int main()
{
    int n,q;
    cin>>n>>q;
    int now=0;
    int temp;
    for(int i=1;i<=n;i++)
    {
       cin>>temp;
       while(temp--)
         a[now++]=i;
    }
    while(q--)
    {
              cin>>temp;
              cout<<a[temp]<<endl;
              }}            
    
    
