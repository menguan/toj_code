#include <stdio.h> 
#include <cstring>  
#include <iostream>
#include <algorithm>
using namespace std;
int n; 
int st[120];int visit[120];  
int sum; 
int depth;                      
int len;
bool flag;          

void dfs(int,int,int); 

void s(int dep) 
{         
   if (dep > depth) 
   { 
      flag = 1; 
      printf("%d\n", len); 
      return; 
   } 

   int i; 
   for (i = 1;i <= n;i++) 
      if (!visit[i])
       break;  

   visit[i] = 1;           
   dfs(dep,st[i],i);         
   visit[i] = 0;                   
} 

void dfs(int dep,int leng,int pos) 
{   

   if (flag)
    return; 
   if (leng == len)
   {  
       s(dep + 1);    
    return; 
   } 

   if (pos + 1 > n)
    return;   

   for (int i = pos + 1;i <= n;i++) 
      if (!visit[i]) 
          if(st[i] + leng <= len) {   
         visit[i] = 1;                    
         dfs(dep,leng + st[i],i);  
         visit[i] = 0; 
         if (flag)
          return; 
         if (st[i] + leng == len)
          return;  
       } 
} 

int main () 
{ 
   while (scanf("%d", &n) == 1) 
   {               
       if (n==0) 
         break;                            
       flag = 0;
        
    int i; int t;
    int m=n;int con=1;
    for(i=1;i<=m;i++)
    {
     scanf("%d", &t);
     if(t<=50)
     {st[con++]=t;}
     else
       n--; 
    } 
    if(n==0)
        puts("0");
    else{    
    sort(st+1,st+1+n); 
    reverse(st+1,st+1+n);             
    sum = 0;
    for(int j=1;j<=n;j++)
      sum+=st[j];                               
    for (i = st[1];i <= sum;i++)             
        if (sum % i == 0 && !flag) 
        {              
            depth = sum / i;                      
            memset(visit,0,sizeof(visit));          
            len = i;                             
            s(1);  
        } 
        }
   } 
   return 0; 
}  
