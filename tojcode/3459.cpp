#include<iostream>
#include<cmath>
using namespace std;
struct f
{
  int id;
  int x,y;
}c[3000];
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>c[i].x>>c[i].y;
    c[i].id=i+1;
  }
  double minn=100000000;
  int ans1,ans2;
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
        double temp=hypot(c[i].x-c[j].x,c[i].y-c[j].y);
        if(temp<minn)
        {
          minn=temp;
          ans1=c[i].id;
          ans2=c[j].id;
        }
    }
  }
  cout<<ans1<<" "<<ans2<<endl;
  //while(1);
}          
         