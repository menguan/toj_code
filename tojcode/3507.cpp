#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int year[4000];
int f(int y,int m,int d)
{
  if((y%400==0)||((y)%100!=0&&(y)%4==0))
  {
    switch(m)
    {
      case 1:return d;
      case 2:return d+31;
      case 3:return d+60;
      case 4:return d+91;
      case 5:return d+121;
      case 6:return d+152;
      case 7:return d+182;
      case 8:return d+213;
      case 9:return d+244;
      case 10:return d+274;
      case 11:return d+305;
      case 12:return d+335;
    }
  }
  else
    switch(m)
    {
      case 1:return d;
      case 2:return d+31;
      case 3:return d+59;
      case 4:return d+90;
      case 5:return d+120;
      case 6:return d+151;
      case 7:return d+181;
      case 8:return d+212;
      case 9:return d+243;
      case 10:return d+273;
      case 11:return d+304;
      case 12:return d+334;
    }
}        
int main()
{
  year[1000]=0;
  for(int i=1001;i<3010;i++)
  {
    if((i-1)%400==0)
      year[i]=year[i-1]+366;
    else  if((i-1)%100!=0&&(i-1)%4==0)
      year[i]+=year[i-1]+366;
    else
      year[i]=year[i-1]+365;
  }
  int t;
  cin>>t;
  string s1,s2;
  while(t--)
  {
     int year1=0,year2=0,month1=0,month2=0,day1=0,day2=0;
     cin>>s1>>s2;
     for(int i=0,j=1000;i<4;i++,j/=10)
     {
       year1+=(s1[i]-'0')*j;
       year2+=(s2[i]-'0')*j;
     }
     for(int i=5,j=10;i<7;i++,j/=10)
     {
       month1+=(s1[i]-'0')*j;
       month2+=(s2[i]-'0')*j;
     }
     for(int i=8,j=10;i<10;i++,j/=10)
     {
       day1+=(s1[i]-'0')*j;
       day2+=(s2[i]-'0')*j;
     }
     //cout<<year1<<" "<<month1<<" "<<day1<<endl;
     int days1=year[year1],days2=year[year2];
     days1+=f(year1,month1,day1);
     days2+=f(year2,month2,day2);
     cout<<abs(days1-days2)<<endl;
   }
 }    
   