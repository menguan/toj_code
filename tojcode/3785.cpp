#include<iostream>
#include<cstring>
using namespace std;
struct f
{
  int x,y;
  int num;
}a[1000];
int main()
{
  int n;
  while(cin>>n,n)
  {      
      memset(a,0,sizeof(a));
      int maxx=-300;int maxy=-300;
      int minx=300;int miny=300;
      if(a[0].x>maxx)maxx=a[0].x;
      if(a[0].x<minx)minx=a[0].x;
      if(a[0].y>maxy)maxy=a[0].y;
      if(a[0].y<miny)miny=a[0].y;
      int number,dir;
      int count=1;
      for(int i=1;i<n;i++)
      {
         cin>>number>>dir;
         a[i].num=i;
         for(int j=0;j<i;j++)
         {
           if(a[j].num==number)
           {
             
             
     if(dir == 0)
     {
      a[i].y = a[j].y-1;
      a[i].x = a[j].x;
     }
     else if(dir == 1)
     {
      a[i].y = a[j].y;
      a[i].x = a[j].x+1;
     }
     else if(dir == 2)
     {
      a[i].y = a[j].y+1;
      a[i].x = a[j].x;
     }
     else if(dir == 3)
     {
      a[i].y = a[j].y;
      a[i].x = a[j].x-1;
     }
      if(a[i].x>maxx)maxx=a[i].x;
      if(a[i].x<minx)minx=a[i].x;
      if(a[i].y>maxy)maxy=a[i].y;
      if(a[i].y<miny)miny=a[i].y;
      
      break;
    }
  }
  }
  //cout<<maxx<<" "<<minx<<endl;
  cout<<maxy-miny+1<<" "<<maxx-minx+1<<endl;
  }
}      

  