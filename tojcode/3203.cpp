#include<iostream>
using namespace std;
int k[100010];
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>k[i];
  int now=0;
  int re=0;
  
  re+=n;
  int owe=0;
  
  for(int i=0;i<n;i++)
  {
    now+=k[i];
    if(now>=0&&now-k[i]<0)
    {
      re+=(2*(i-owe));
    }
    else if(now<0&&now-k[i]>=0)
    {
       owe=i;
    }
    
    
  }
  
  cout<<re<<endl;
  
  
}                        
