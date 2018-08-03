#include<iostream>
using namespace std;
int xmin[10000], xmax[10000],ymin[10000],ymax[10000];
int main()
{
  int t;
  while(cin>>t)
  {
    for(int i=1;i<=t;i++)
    {
      cin>>xmin[i]>>xmax[i]>>ymin[i]>>ymax[i];
    }
    int count=0;
    for(int j=1;j<=t;j++)
    {
      for(int i=1;i<=t;i++)
      {
        if(i==j)
          continue;
        else if(xmin[i]<=xmin[j]&&xmax[i]>=xmax[j]&&ymin[i]<=ymin[j]&&ymax[i]>=ymax[j])
        {
          count++;
          break;
        }  
      }
    }
    cout<<count<<endl;
 }
}          
   