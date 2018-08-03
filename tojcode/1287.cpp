#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
 int s,p,y,j;
    int a,b,c;
 int age1,age2,age3;
 int flag;
 while(scanf("%d%d%d%d",&s,&p,&y,&j)!=EOF){
  flag=0;
  for(a=0;a<100;++a){
   age3=a;
   for(b=p;b<=p+1;++b){
    age2=age3+b;
    for(c=s;c<=s+1;++c){
     age1=age2+c;
     if((age1-age3==y||age1-age3==y+1)&&(age1+age2+age3==12+j)){
      flag=1;
      break;
     }
    }
    if(flag)
     break;
   }
   if(flag)
    break;
  }
  if(flag)
   printf("%d %d %d\n",age1,age2,age3);


 }
}

