#include<iostream>
using namespace std;
int main()
{
  int n,u,d;
  while((cin>>n>>u>>d)&&(n!=0&&u!=0&&d!=0))
  {
    int time=0;
    int n_=n;
    while(n_>0)
    {
      if(n_<=u)
        {
          time++;
          break;
        }
      n_=n_-(u-d);
      time+=2;
     }
     cout<<time<<endl;
   } 
  return 0;
}  