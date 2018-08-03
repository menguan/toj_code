#include<iostream>
#include<cmath>
#include<cstring>
#define eps 1e-8
using namespace std;
struct po
{
   int x;int y;
}poo[3];
double sidea,sideb,sidec;  
double side(po m,po n)
{
      return hypot(m.x-n.x,m.y-n.y);
}  
int f()
{
    if(fabs(sidea*sidea+sideb*sideb-sidec*sidec)<eps||
       fabs(sidea*sidea-sideb*sideb+sidec*sidec)<eps||
       fabs(-sidea*sidea+sideb*sideb+sidec*sidec)<eps)
       {  return 2;
       }
    if(sidea*sidea+sideb*sideb-sidec*sidec<0||
       sidea*sidea-sideb*sideb+sidec*sidec<0||
       -sidea*sidea+sideb*sideb+sidec*sidec<0)
       {
          return 1;
       }
    return 3;
}
                                              
int main()
{
   int t;
   cin>>t;
   for(int i=1;i<=t;i++)
   {
      
      for(int j=0;j<3;j++)
        cin>>poo[j].x>>poo[j].y;
      cout<<"Case #"<<i<<": ";
      sidea=side(poo[0],poo[1]);
      sideb=side(poo[1],poo[2]);
      sidec=side(poo[0],poo[2]);
      //cout<<sidea<<" "<<sideb<<" "<<sidec<<endl;
      bool isis=0;
      if(fabs(sidea)<eps||fabs(sideb)<eps||fabs(sidec)<eps)
      {
         cout<<"not a triangle"<<endl;
         continue;
      }
      if(fabs(sidea+sideb-sidec)<eps||fabs(sidea+sidec-sideb)<eps||fabs(sidec+sideb-sidea)<eps)    
      {
         cout<<"not a triangle"<<endl;
         continue;
      }
      if(fabs(sidea-sideb)<eps||fabs(sidea-sidec)<eps||fabs(sidec-sideb)<eps)
      {
          isis=1;
      }                                                                       
      int lei=f();
      if(isis)
      {
       cout<<"isosceles ";
      }
      else
        cout<<"scalene ";
      if(lei==1)
      {
          cout<<"obtuse triangle"<<endl;
      }
      else if(lei==2)
      {
          cout<<"right triangle"<<endl;
      }
      else
          cout<<"acute triangle"<<endl;
   }
}                             
                                                                 
