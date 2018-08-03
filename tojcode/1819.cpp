#include<stdio.h>//网上的 bsearch 用法 
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
typedef struct
{
 char str[200];
}dictionary;

int cmp(const void * a,const void *b)
{
    return strcmp(((dictionary*)a)->str, ((dictionary*)b)->str);
}

int cmp2(const void* a, const void* b)
{
    return strcmp((char*)a, ((dictionary*)b)->str);
}

dictionary dict[51000];
char word[200];

int main()
{
 int t,l,i,flag;
 dictionary *p;
 scanf("%d",&t);
 for(i=0;i<t;i++)
  scanf("%s",dict[i].str);
 scanf("%d",&l);
 qsort(dict,t,sizeof(dictionary),cmp);
 for(i=1;i<=l;i++)
 {
  flag=1;
  while(scanf("%s",word) && strcmp(word,"-1")!=0)
  {
   p=(dictionary *)bsearch(word,dict,t,sizeof(dictionary),cmp2);
   if(!p)
   {
    if(flag==1)
    {
     printf("Email %d is not spelled correctly.\n",i);
     flag=0;
    }
    puts(word);
   }
  }
  if(flag)
    printf("Email %d is spelled correctly.\n",i);
 }
 puts("End of Output");
}

 

