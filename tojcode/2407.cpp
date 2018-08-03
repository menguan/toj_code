#include<iostream>//题目已改为2407 
#include<algorithm>
using namespace std;
int n;
int a[4][4000];
int s1[16000000];
int s2[16000000];
int count=0;
int f1()
{
  int num=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      s1[num++]=a[0][i]+a[1][j];
    }
  }
  sort(s1,s1+num);
  
  return num;
}          
int f2()
{
  int num=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      s2[num++]=a[2][i]+a[3][j];
    }
  }
  sort(s2,s2+num);
  
  return num;
}       
int main()
{
  
  
  
    cin>>n;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<4;j++)
      {
        cin>>a[j][i];
      }
    } 
    int w1=f1();
    int w2=f2();
    int count=0;
    
    for(int i=0;i<w1;i++)
    {
      int mid;
      int low=0;
      int high=w1-1;
      while(1)
      {
        mid=(high+low)/2;
        if(s2[mid]+s1[i]>0)
        {
          high=mid-1;
        }
        if(s2[mid]+s1[i]<0)
        {
          low=mid+1;
        }
        if(low>high)
          break;
        if(s2[mid]+s1[i]==0)
        {
          count++;
          for(int j=mid-1;j>=0;j--)
          {
            if(s2[j]==s2[mid])
            {
              count++;
            }
            else
              break;
          }
          for(int j=mid+1;j<w1;j++)
          {
            if(s2[j]==s2[mid])
            {
              count++;
            }
            else
              break;
          }
          break;
        }
      }            
    }        
      
      
        
      
    
    
      cout<<count<<endl;
      //while(1);
  
}              
   