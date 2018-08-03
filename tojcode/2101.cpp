#include<iostream>
#include<cmath>
using namespace std;
int main()
{ 
  double r1,r2;
  while(1)
  {
    int sum1=0,sum2=0;
    int k=3;
    while(k--)
    {
      cin>>r1>>r2;
      if(r1==-100)
        return 0;
      double t=hypot(r1,r2);
      if(t<=3)
        sum1+=100;
      else if(t>3&&t<=6)
        sum1+=80;
      else if(t>6&&t<=9)
        sum1+=60;
      else if(t>9&&t<=12)
        sum1+=40;
      else if(t>12&&t<=15)
        sum1+=20;
    }
    k=3;
    while(k--)
    {
      cin>>r1>>r2;
      
      double t=hypot(r1,r2);
      if(t<=3)
        sum2+=100;
      else if(t>3&&t<=6)
        sum2+=80;
      else if(t>6&&t<=9)
        sum2+=60;
      else if(t>9&&t<=12)
        sum2+=40;
      else if(t>12&&t<=15)
        sum2+=20;
    }
    if(sum1>sum2)
    {
      cout<<"SCORE: "<<sum1<<" to "<<sum2<<", PLAYER 1 WINS."<<endl;
    }
    else if(sum2>sum1)
    {
      cout<<"SCORE: "<<sum1<<" to "<<sum2<<", PLAYER 2 WINS."<<endl;
    }
    else
    {
      cout<<"SCORE: "<<sum1<<" to "<<sum2<<", TIE."<<endl;
    }
  }
}  