#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct pa
{
    long long f,m;
    double a;
    int id;
}part[12000];
bool cmp(pa mm,pa nn)
{
  return mm.f*nn.m>mm.m*nn.f;
}           
long long F,M,n;double A;
int num[12000];
int main()
{
    cin>>F>>M>>n;int con=0;
    for(int i=0;i<n;i++)
    {
       cin>>part[i].f>>part[i].m;part[i].id=i+1;
       //part[i].a=part[i].f*1.0/part[i].m;
    }   
    sort(part,part+n,cmp);
    int i;
    //while(1)
    //{
    for(i=0;i<n;i++)
    {
       if(part[i].f*M>part[i].m*F)
       {
         num[con++]=part[i].id;
         F+=part[i].f;
         M+=part[i].m;
       }
    //   else
    //     break;
    }
    //if(i==n)
    //  break;
    //}  
    sort(num,num+con);
    if(con)
    for(int i=0;i<con;i++)
      cout<<num[i]<<endl;
    else
      cout<<"NONE"<<endl;
   //while(1);
}  
