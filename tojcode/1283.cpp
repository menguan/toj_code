#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char a[300];
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    cin>>a;
    int len=strlen(a);
    int  mid;
    int leftnum(0),leftx(0),rightnum(0),rightx(0);
    for(int i=0;i<len;i++)
    if(a[i]=='=')
      mid=i;
    int k,wei,xi;  
    for(int i=mid-1;i>=0;i--)
    {
      if(a[i]=='x'&&i>=0)
      {
        k=1;wei=1;xi=0;
        i--;
        while(1)
        {
           
          
          if(a[i]=='-')
          {
            k=-k;
            if(xi!=0)
            k*=xi;
            break;
          }
          else if(a[i]=='+')
          {
            if(xi!=0)
            k*=xi;
            break;
          } 
          else
          {
            xi+=((a[i]-'0')*wei);
            wei*=10;
            
            
          }
          if(i==0)
            k*=xi;
          i--;
          if(i<0)
          {
              break;
          }
        }
        leftx+=k;
        
      }
      if(a[i]!='x'&&a[i]!='-'&&a[i]!='+'&&i>=0)
      {
        k=1;wei=1;xi=0;
        
        while(1)
        {
          
          if(a[i]=='-')
          {
            k=-k;
            if(xi!=0)
            k*=xi;
            break;
          }
          else if(a[i]=='+')
          {
            if(xi!=0)
            k*=xi;
            break;
          }  
          else
          {
            xi+=((a[i]-'0')*wei);
            wei*=10;
            
            
          }
          if(i==0)
            k*=xi;
          i--;
          
          if(i<0)
          {
              break;
          }
        }
        leftnum+=k;
        
      }
    }
    for(int i=len-1;i>=mid+1;i--)
    {
      if(a[i]=='x'&&i>=mid+1)
      {
        k=1;wei=1;xi=0;
        i--;
        while(1)
        {
           
          
          if(a[i]=='-')
          {
            k=-k;
            if(xi!=0)
            k*=xi;
            break;
          }
          else if(a[i]=='+')
          {
            if(xi!=0)
            k*=xi;
            break;
          } 
          else
          {
            xi+=((a[i]-'0')*wei);
            wei*=10;
            
            
          }
          if(i==mid+1)
            k*=xi;
          i--;
          if(i<mid+1)
          {
              break;
          }
        }
        rightx+=k;
        
      }
      if(a[i]!='x'&&a[i]!='-'&&a[i]!='+'&&i>=mid+1)
      {
        k=1;wei=1;xi=0;
        
        while(1)
        {
          
          if(a[i]=='-')
          {
            k=-k;
            if(xi!=0)
            k*=xi;
            break;
          }
          else if(a[i]=='+')
          {
            if(xi!=0)
            k*=xi;
            break;
          }  
          else
          {
            xi+=((a[i]-'0')*wei);
            wei*=10;
            
            
          }
          if(i==mid+1)
            k*=xi;
          i--;
          
          if(i<mid+1)
          {
              break;
          }
        }
        rightnum+=k;
        
      }
    }
    
    if(leftx==rightx)
    {
      if(leftnum==rightnum)
      {
        cout<<"IDENTITY"<<endl;
      }
      else
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
      int re=(int)floor((leftnum-rightnum)*1.0/(rightx-leftx)*1.0);
      cout<<re<<endl;
    }        
    
   }}