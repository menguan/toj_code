#include<iostream> //这种题bfs  借鉴一下  
#include<cstdio>
#include<cstring>
using namespace std; 
int dir[3][2]={{1,1},{1,-1},{2,0}}; 
int N,K,a[1000000],vis[1000000],step[1000000]; 

void bfs(int i) 
{ 
     int front,end,x,k; 
     front=0;end=0; 
     a[end++]=i; 
     vis[i]=1; 
     step[i]=0; 
     while(front<end) 
     { 
       i=a[front++]; 
       for(k=0;k<3;k++) 
       { 
         x=i*dir[k][0]+dir[k][1]; 
         if(!vis[x]&&x>=0&&x<=100000) 
          { 
             if(x==K) 
             { 
              step[x]=step[i]+1; 
              return; 
             } 
             else 
             { 
              vis[x]=1; 
              a[end++]=x; 
              step[x]=step[i]+1; 
             } 
          } 
       } 
     } 
} 
int main() 
{ 
                                   cin>>N>>K; 
                                   memset(vis,0,sizeof(vis)); 
                                   memset(step,0,sizeof(step)); 
                                   memset(a,0,sizeof(a)); 
                                   bfs(N); 
                                   printf("%d\n",step[K]); 
                                   //system("pause"); 
} 
