#include<iostream>
#include<algorithm>
using namespace std;
int a[2000];
int f(int n,int wei)
{
  
  for(int i=0;i<wei-1;i++,n/=10);
  
  
  return n%10;
}    
  
  
  
int main()
{
  int t;int count=1;//cout<<f(1,1)<<endl;
  while(cin>>t,t)
  {
    for(int i=0;i<t;i++)
      cin>>a[i];
     
    sort(a,a+t);
    
    int len=0;
    int temp=a[t-1];
    while(temp)
    {
      len++;
      temp/=10;
    } 
    int co;
    //for(int i=0;i<t;i++)
      //cout<<a[i]<<endl;
    cout<<"Case "<<count++<<":"<<endl;
    for(int i=0;i<len;i++)
    { co=0;
      for(int k=0;k<10;k++)
      {
        
        for(int m=0;m<t;m++)
        {
          //cout<<f(a[m],i+1)<<endl;
          if(f(a[m],i+1)==k)
          {
            
            if(co!=t-1)
            cout<<a[m]<<" ";
            else
            cout<<a[m]<<endl;
            co++;
          }
        }  
      }
    } 
  }
}          
      
       