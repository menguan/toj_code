#include<iostream>
#include<algorithm>
using namespace std;
struct hotel
{
  int price;
  int w[20];
}h[20];
bool cmp(hotel a,hotel b)
{
  return a.price<b.price;
} 
int main()
{
  int n,b,hh,ww;
  cin>>n>>b>>hh>>ww;
  for(int i=0;i<hh;i++)
  {
       cin>>h[i].price;
       for(int j=0;j<ww;j++)
       {
         cin>>h[i].w[j];
       }
       sort(h[i].w,h[i].w+ww);
  }
  sort(h,h+hh,cmp);
  for(int i=0;i<hh;i++)
  {
    if(h[i].w[ww-1]>=n&&n*h[i].price<=b)
    {
      cout<<n*h[i].price<<endl;
      //while(1);
      return 0;
    }
  }
  cout<<"stay home"<<endl;
  //while(1);
  return 0;
}      
        