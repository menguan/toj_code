#include<iostream>
using namespace std;
int a[15]={0};
void f()
{
  for(int i=1;i<15;i++)
  {
    
    
    int re=i;    
    while(re++)
    {
       int sum=2*i;
       int num=0;
       int t=i;
       while(t>0)
       {
         t--;
         num=(num+re)%sum--;
         if(num<i)
           t=-1;
       }
       if(t==0)
       {
        a[i]=re+1;
        break;
       }
     }
   }
}
int main()
{
  f();
  a[1]=2;//我想骂街 
  int n;
  while(cin>>n,n)
  {
    cout<<a[n]<<endl;
  }
} 