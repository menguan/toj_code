#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int find(int);
int n;
int id[110];
struct f
{
    int st,en;
    int len;
} bian[101010];
void unio(int p,int q)
{
    int pp=find(p);
    int qq=find(q);
    if(pp==qq)
      return ;
    else
      id[pp]=qq;
}        
void init()
{
     for(int i=0;i<1010;i++)
       id[i]=i;
}     
int find(int p)
{
    while(p!=id[p])
    {
         id[p]=id[id[p]];
         p=id[p];
    }
    return p;
}  
bool cmp(f mm,f nn)
{
     return mm.len<nn.len ;
}           
int jud;   int bnum;
int main()
{
     while(cin>>n)
     {
        int temp=0;bnum=0;
        long long ans=0;
        init();
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++)
          {
             cin>>jud;
             if(i==j)
               continue;
             if(jud==0)
             {
               if(find(i)!=find(j))
               {
                 temp++;
                 unio(i,j);
               }
             }
             else if(jud==-1)
             {  
                continue;
             }
             else 
             {
                bian[bnum].st=i;
                bian[bnum].en=j;
                bian[bnum].len=jud;
                bnum++;
             } 
          }
        } 
        sort(bian,bian+bnum,cmp);
        for(int i=0;i<bnum;i++)
        {
           if(find(bian[i].st)!=find(bian[i].en))
           {
              unio(bian[i].st,bian[i].en);
              ans+=bian[i].len;
           }
        }
        cout<<ans<<endl;
     }
}                                        
                                                
                        
                          
                  
                     
