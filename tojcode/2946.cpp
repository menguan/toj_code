#include<iostream>
#include<cstring>
using namespace std;
char a[5][100];
char b[100];
int main()
{
  cin>>b;
  int len=strlen(b);
  for(int i=0;i<len*5;i++)
  for(int j=0;j<5;j++)
    a[j][i]='.';
  int now=0;  
  int length=len*4+1;
  for(int i=0;i<length-1;i++)
  {
    if(i%4==0)
    {
      if(now!=0&&(now-1)%3==2)
      {
        a[2][i]='*';
        continue;
      }  
      
      if(now%3!=2)
      a[2][i]='#';
      else
      a[2][i]='*';
    }
    if(i%4==1)
    {
      if(now%3!=2)
      a[1][i]=a[3][i]='#';
      else
      a[1][i]=a[3][i]='*';
    }
    if(i%4==2)
    {
      if(now%3!=2)
      {a[0][i]=a[4][i]='#';a[2][i]=b[now];}
      else
      {a[0][i]=a[4][i]='*';a[2][i]=b[now];}
    }
    if(i%4==3)
    {
      if(now%3!=2)
      a[1][i]=a[3][i]='#';
      else
      a[1][i]=a[3][i]='*';
      
      now++;
    }
  }
  if((now-1)%3==2)
  {
    a[2][length-1]='*';
  }
  else
    a[2][length-1]='#';
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<length;j++)
    {
      cout<<a[i][j];
    }
    cout<<endl;
  }    
  //while(1);
}    