#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<map>

using namespace std;
char s[1000010];
int a[150];
//map<char,int> mapp;
//map<char,int> ::iterator it;
int main()
{
    int t;int len;int maxn=0;
    scanf("%d",&t);
    while(t--)
    {
      //mapp.clear();
      memset(a,0,sizeof(a));
      scanf("%s",s);
      len=strlen(s);
      for(int i=0;i<len;i++)
      {
        a[s[i]]++;
      }    
      maxn=0;    
      for(int i=0;i<150;i++)
       if(maxn<a[i])
         maxn=a[i];
      for(int i=0;i<150;i++)
        if(maxn==a[i])
        {
            printf("%c\n",i);
            break;
        }                  
      //  mapp[s[i]]++;
      //maxn=0;
      //for(it=mapp.begin();it!=mapp.end();it++)
      //{
      //  if(it->second>maxn)
      //    maxn=it->second;
      //}
      //for(it=mapp.begin();it!=mapp.end();it++)
      //{
      //  if(it->second==maxn)
      //  {
      //      printf("%c\n",it->first);
      //      break;
      //  }                
      //}
    }
}                                            
        
                
    
