#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
using namespace std;
const string week[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
const string month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
const int cnt[2][12]=
{
31,28,31,30,31,30,31,31,30,31,30,31,
   31,29,31,30,31,30,31,31,30,31,30,31
};
bool isleap(int p)
{
     return ((p%4==0&&p%100!=0)||p%400==0);
}  
int getd(int m,int d,int y)
{
    if(m==1||m==2)
    {
      m+=12;
      y--;
    }
    if((y<1752)||(y==1752&&m<9)||(y==1752&&m==9&&d<3))
      return (d+2*m+3*(m+1)/5+y+y/4+5)%7;
    else
      return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;//容斥
}              
bool judge(int m,int d,int y)
{
    if(m<1||m>=13)  return 0;
    if(!(d>=1&&d<=cnt[isleap(y)][m-1]))  return 0;
    if(y==1752&&m==9&&d>2&&d<14)  return 0;
    return 1;
} 
int main()
{
    int m,d,y;
    while(cin>>m>>d>>y&&(m+d+y))
    {
        if(judge(m,d,y))
          cout<<month[m-1]<<" "<<d<<", "<<y<<" is a "<<week[getd(m,d,y)]<<endl;
        else
          cout<<m<<"/"<<d<<"/"<<y<<" is an invalid date."<<endl;
    }
}
                               
    
