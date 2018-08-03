#include<iostream>
#include<cstring>
#include<stdio.h>
#include<ctype.h>
using namespace std;
char a[100000];
char bas[100000];
int f(char c)
{
    if(isdigit(c))
      return c-'0';
    else
      return c-'A'+10;
}
int main()
{
    int n;long long ans=0;
    while(cin>>n)
    {ans=0;
    for(int i=0;i<n;i++)
    {
       cin>>bas[i];
    }
    cin>>a;
            int len=strlen(a);
    for(int i=0;i<len;i++)
    {
       ans=ans*f(bas[n+i-len])+f(a[i]);
    }
    cout<<ans<<endl;
}
}
