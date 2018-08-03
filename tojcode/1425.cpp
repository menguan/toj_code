#include<iostream>
using namespace std;
int main()
{
  int a,b,c,d;
  while(cin>>a>>b>>c>>d)
  {
      if(a==0&&b==0&&c==0&&d==0)
      {
        return 0;
      }
      
      int sum=0;
      sum+=720;
      if(a!=b)
      {
          if(a-b<0)
          sum+=((a-b+40)*9);
          else 
          sum+=((a-b)*9); 
      }else sum+=360;
      
      sum+=360;
      
      if(b!=c)
      {
          if(c-b>0)
          sum+=((c-b)*9);
          else 
          sum+=((c-b+40)*9);
      }else sum+=360;
      
      if(c!=d)
      {
          if(c-d<0)
          sum+=((c-d+40)*9);
          else 
          sum+=((c-d)*9); 
      }else sum+=360; 
      
      cout<<sum<<endl;
   }
   return 0;
}