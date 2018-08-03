#include<iostream>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
const double pi=acos(-1.0);
const double r=6378.0;
const double c=pi*r;
struct f
{
  //string name;
  int id;
  double ja,wa;
}city[110];
map<string,int> name;
map<string,int>::iterator it1,it2;
int main()
{
  // cout<<sqrt(1.0/180/180+1.0/180/180)*c<<endl;
  name.clear();
  memset(city,0,sizeof(city));
  int cnt=0;
  string s,s1,s2;
  while(1)
  {
    cin>>s;
    if(s=="#")
      break;
    name[s]=cnt;
    cin>>city[cnt].wa>>city[cnt].ja;
    city[cnt].ja*=pi/180;
    city[cnt].wa*=pi/180;
    cnt++;
  }
  while(cin>>s1>>s2)
  {
     if(s1=="#"&&s2=="#")
       break;
     int id1,id2;
     it1=name.find(s1);
     it2=name.find(s2);
     if(it1==name.end()||it2==name.end())
     {
       cout<<s1<<" - "<<s2<<endl<<"Unknown"<<endl<<endl;
       continue;
     }
     id1=name[s1];//it1->second;
     id2=name[s2];//it2->second; 
      cout<<s1<<" - "<<s2<<endl;
     double ans=r*acos(cos(city[id1].wa)*cos(city[id2].wa)*cos(city[id1].ja-city[id2].ja)+sin(city[id1].wa)*sin(city[id2].wa));
     printf("%.0lf km\n\n",ans);
  }    
  // while(1);84
}