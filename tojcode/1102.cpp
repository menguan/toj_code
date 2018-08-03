#include<iostream>
#include<stdio.h>
#include<cstring>
int space[20];
char a[25];
using namespace std;
int main()
{
  int t;
  while(cin>>t,t)
  {
    getchar();
    memset(space,0,sizeof(space));
    int minn=30;
    int tt=t;
    while(t--)
    {
      gets(a);
      
      for(int i=0;i<25;i++)
      {
        if(a[i]==' ')
          space[t]++;
      }
      if(space[t]<minn)
        minn=space[t];
    }
    int sum=0;
    for(int i=0;i<tt;i++)
    {
      sum+=(space[i]-minn);
    }
    cout<<sum<<endl;
  }
}      
        
          
    
    

 