#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int t;char ci[3];void solve();
struct man
{
   int n[3];
   char c[3];
   int lei;
   int tong;
   int ot;
}yao,yu;  
int f(char tmp)
{
    if(tmp=='A')  return 14;
    else if(tmp=='J')  return 11;
    else if(tmp=='Q')  return 12;
    else if(tmp=='K')  return 13;
    else if(tmp=='1')  return 10;
    else return tmp-'0';
} 
int judge(man &ma)
{
   sort(ma.n,ma.n+3);
   if(ma.n[0]==ma.n[1]&&ma.n[0]==ma.n[2])
      return 0;
   if(ma.c[0]==ma.c[1]&&ma.c[0]==ma.c[2])
   {
      if(ma.n[2]-ma.n[1]==1&&ma.n[1]-ma.n[0]==1)
        return 1;
      else
        return 2;
   }
   if(ma.n[2]-ma.n[1]==1&&ma.n[1]-ma.n[0]==1)
        return 3; 
   if(ma.n[0]==ma.n[1]||ma.n[0]==ma.n[2]||ma.n[2]==ma.n[1])
   {
      if(ma.n[0]==ma.n[1]) ma.tong=ma.n[0],ma.ot=ma.n[2];
      if(ma.n[2]==ma.n[1]) ma.tong=ma.n[2],ma.ot=ma.n[0];
      if(ma.n[0]==ma.n[2]) ma.tong=ma.n[0],ma.ot=ma.n[1];                                                       
      return 4;
   }   
   return 5;
}
void solve()
{
   bool istie=0;bool isyao=0;bool isyu=0;
   yao.lei=judge(yao);
   yu.lei=judge(yu);
   if(yao.lei<yu.lei) isyao=1;
   else if(yu.lei<yao.lei) isyu=1;
   else
   {
      //if(yao.lei!=4)
      //{
         int i;
         for(i=2;i>=0;i--)
         {
           if(yao.n[i]>yu.n[i])
           {
              isyao=1;
              break;
           }
           else if(yao.n[i]<yu.n[i])
           {
              isyu=1;
              break;
           }
         }
         if(i==-1)
           istie=1;
      //}
      /*else
      {
         
         if(yao.tong>yu.tong)
           isyao=1;
         else if(yao.tong<yu.tong)
           isyu=1;
         else
         {
             if(yao.ot>yu.ot)
               isyao=1;
             else if(yao.ot<yu.ot)
               isyu=1;
             else
               istie=1;
         }
      }*/
   }                                                    
   if(isyao)cout<<"Win"<<endl;                          
   else if(isyu)cout<<"Lose"<<endl;                                       
   else cout<<"Tie"<<endl;
}   
int main()
{
    
    while(cin>>ci)
    {
       yao.n[0]=f(ci[1]);yao.c[0]=ci[0];
       cin>>ci;yao.n[1]=f(ci[1]);yao.c[1]=ci[0];
       cin>>ci;yao.n[2]=f(ci[1]);yao.c[2]=ci[0];
       cin>>ci;yu.n[0]=f(ci[1]);yu.c[0]=ci[0];
       cin>>ci;yu.n[1]=f(ci[1]);yu.c[1]=ci[0];
       cin>>ci;yu.n[2]=f(ci[1]);yu.c[2]=ci[0];
       solve();
    }
}   
