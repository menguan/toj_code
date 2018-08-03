#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long a[5][300];
long long s1[90000];
long long s2[90000];
long long temp[90000];
int f1()
{
  int num=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      temp[num++]=a[0][i]+a[1][j];
    }
  }
  sort(temp,temp+num);
  s1[0]=temp[0];
  int w1=1;
  for(int i=1;;)
  {
    if(temp[i]!=temp[i-1])
    {
      s1[w1++]=temp[i];
      i++;
    }
    else
    {
      i++;
    }
    if(i==num)
      break;
  }
  return w1;
}          
int f2()
{
  int num=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      temp[num++]=a[2][i]+a[3][j];
    }
  }
  sort(temp,temp+num);
  s2[0]=temp[0];
  int w2=1;
  for(int i=1;;)
  {
    if(temp[i]!=temp[i-1])
    {
      s2[w2++]=temp[i];
      i++;
    }
    else
    {
      i++;
    }
    if(i==num)
      break;
  }
  return w2;
}       
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=0;i<5;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin>>a[i][j];
      }
    } 
    int w1=f1();
    int w2=f2();
    bool flag=0;
    for(int i=0;i<n;i++)
    {
      int p1=0,p2=w2-1;
      
      while(p1<w1&&w2>=0)
      {
        if(s1[p1]+s2[p2]+a[4][i]==0)
        {
          flag=1;
          break;
        }
        if(s1[p1]+s2[p2]+a[4][i]<0)
          p1++;
        else
          p2--;
            
      }
      if(flag)
      break;
    }
    if(flag)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
}      