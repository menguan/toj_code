#include<iostream>
using namespace std;
int main()
{   
    long double a,b,sum1,sum2,answer;
    while((cin>>a>>b)&&(a!=0||b!=0))
    { 
      if(b>a/2)
      b=a-b;
      if(b==0)
      {
          cout<<1<<endl;
          continue;
      }
      sum1=1;
      sum2=1;
      for(long i=b;i>0;i--)
      {
          sum1*=a;
          a--;
      }
      
      for(long i=b;i>0;i--)
      {
          sum2*=b;
          b--;
      }
      answer=sum1/sum2;
      
      cout<<(int)answer<<endl;   
        
    }
    return 0;
}