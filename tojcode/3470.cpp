#include<iostream>
using namespace std;
int main()
{
  int t,n;
  cin>>t;
  while(t--)
  {
    int max=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
      int x=1,y=n,m;
      int count=0;
      while(1)
      {
        count++;
        m=(x+y)/2;
        if(m==i)
        {
          if(count>max)
            max=count;
          break;
        }
        else if(m<i)
          x=m+1;
        else      
          y=m-1;
      }
    }
    cout<<max<<endl;
  }
}        
      
 