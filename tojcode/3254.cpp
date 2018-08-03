#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int get(char a,char b)
{
    if(a==b)
      return 1;
    else if(a=='S'&&b=='P')
      return 2;
    else if(a=='R'&&b=='S')
      return 2;
    else if(a=='P'&&b=='R')
      return 2;
    else if(a=='P'&&b=='S')
      return 0;
    else if(a=='S'&&b=='R')
      return 0;
    else if(a=='R'&&b=='P')
      return 0;
}   
int r,n;
char ot[60][60]; 
char t[60];
int main()
{
    int ans1=0,ans2=0;int temp;int now;
    cin>>r;
    cin>>t;
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>ot[i];
    for(int j=0;j<n;j++)
    for(int i=0;i<r;i++)
      ans1+=get(t[i],ot[j][i]);
    for(int i=0;i<r;i++)
    {
       now=0;
       temp=0;
       for(int j=0;j<n;j++)
       {
           temp+=get('S',ot[j][i]);
       }
       now=max(now,temp);
       temp=0;
       for(int j=0;j<n;j++)
       {
           temp+=get('R',ot[j][i]);
       }
       now=max(now,temp);
       temp=0;
       for(int j=0;j<n;j++)
       {
           temp+=get('P',ot[j][i]);
       }
       now=max(now,temp);             
       ans2+=now;
    }  
    cout<<ans1<<endl<<ans2<<endl;
    //while(1);
} 
                  
