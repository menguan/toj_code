#include<iostream>
using namespace std;
bool a[1000010];
void f()
{
  for(int i=0;i<1000010;i++)
    a[i]=1;
  a[0]=0;
  a[1]=0;
  for(int i=2;i<1000010;i++)
  {
    if(a[i])
    {
      for(int j=2*i;j<1000010;j+=i)
      {
        a[j]=0;
      }
    }
  }
}        
      
    
int main()
{
   f();
   int ka,b,c;
   while(cin>>ka>>b>>c)
   {
     if(ka==0&&b==0&&c==0)
       return 0;
     int i,j;  
     for(i=ka,j=c;c>0;i+=b)
     {
       if(a[i])
         c--;
     }    
     cout<<i-b<<endl;
   }
}           
       
       