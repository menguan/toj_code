#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;

int main(){
 int k,c;
 char s[100][5],cou[100][5];
 int i,j,l,flag,n,condition,num;

 while(scanf("%d",&k)&&k){
  scanf("%d",&c);
  flag=0;
  for(i=0;i<k;++i)
   scanf("%s",s[i]);
  for(i=0;i<c;++i){
   scanf("%d%d",&n,&condition);
   num=0;
   for(j=0;j<n;++j)
    scanf("%s",cou[j]);
   for(j=0;j<n;++j){
    for(l=0;l<k;++l){
     if(strcmp(cou[j],s[l])==0)
      num++;
    }
   }
   if(num<condition){
    flag=1;
   }
  }
  if(flag)
   puts("no");
  else
   puts("yes");

 }
}
