#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int a,b;
    int n;int cas=1;
    while(cin>>n>>a>>b)
    {
     vector<int> v;
     int bas=b;
     int ret=bas;
     int temp;
     while(n)
     {
         temp=n%bas;
         n/=bas;
         if(temp<a)
         {
            temp+=ret;
            n--;
         }
         v.push_back(temp);
     }
     cout<<"Case "<<cas++<<":";
     for(int i=v.size()-1;i>=0;i--)
       cout<<" "<<v[i];
     cout<<endl;
    }
}                                   
    
