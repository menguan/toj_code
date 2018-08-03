#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int a[50][50];
bool b[50][50];
int word[10];
char s[1000];
int d=0;
void f()
{
  int ans=0;
  for(int i=4,j=1;i>=0;i--,j*=2)
  {
    //cout<<word[i];
    ans+=(word[i]*j);
  }
  //cout<<ans<<endl;
  if(!ans)
    s[d++]=' ';
  else
    s[d++]=(char)(ans+64);
}    
        
int main()
{
  int t,r,c,count=1;
  cin>>t;
  while(t--)
  {
    d=0;
    for(int i=0;i<50;i++)
    for(int j=0;j<50;j++)
    {
      a[i][j]=-1;
      b[i][j]=0;
    }  
    cin>>r>>c;  
    string ss;
    cin>>ss;
    int u=0;
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
    {
      
      a[i][j]=ss[u++]-'0';
    }
    /*for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
    {
      cout<<a[i][j];
    }*/
    cout<<count++<<" ";
    int nowr=1,nowc=1;
    int p=2;
    int cc=(r*c)/5;
             
    while(cc--)
    {  for(int j=0;j<5;j++)
      {
        if(p==2)
        {b[nowr][nowc]=1;
          if(nowc+1>c||b[nowr][nowc+1])
          {
            
            word[j]=a[nowr++][nowc];
            p=3;
            continue;
          }
          else
          {
            
            word[j]=a[nowr][nowc++];
            continue;
          }
        }
        if(p==3)
        {b[nowr][nowc]=1;
          if(nowr+1>r||b[nowr+1][nowc])
          {
            word[j]=a[nowr][nowc--];
            p=4;
            continue;
          }
          else
          {
            word[j]=a[nowr++][nowc];
            continue;
          }
        }
        if(p==4)
        {b[nowr][nowc]=1;
          if(nowc-1<1||b[nowr][nowc-1])
          {
            word[j]=a[nowr--][nowc];
            p=1;
            continue;
          }
          else
          {
            word[j]=a[nowr][nowc--];
            continue;
          }
        }
        if(p==1)
        {b[nowr][nowc]=1;
          if(nowr-1<1||b[nowr-1][nowc])
          {
            word[j]=a[nowr][nowc++];
            p=2;
            continue;
          }
          else
          {
            word[j]=a[nowr--][nowc];
            continue;
          }
        }
      }
      f();
    }
    if(d)
    {
    int dd=d;
    for(int i=d-1;i>=0;i--)
    {
      if(s[i]!=' ')
        break;
      else
      {
        dd--;
      }
    }
    
    for(int i=0;i<dd;i++)
    cout<<s[i];
    }       
    cout<<endl;
  }
 }     