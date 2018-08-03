#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main(){ 
int map[21][21],dist[21]; 
bool state[21]; 
int cases=1,i,j,t,n,beg,end,v,count,min; 
while(scanf("%d",&t)!=EOF) 
{ memset(map,100,sizeof(map)); i=1;
 while(t--) { scanf("%d",&j); map[i][j]=1; map[j][i]=1; } 
 for(i=2;i<=19;i++) { scanf("%d",&t); 
 while(t--) 
 { scanf("%d",&j); map[i][j]=1; map[j][i]=1; } } 
 scanf("%d",&n); 
 printf("Test Set #%d\n",cases++); 
 while(n--) 
 { scanf("%d%d",&beg,&end); count=0; 
 for(i=1;i<=20;i++) 
 { dist[i]=map[beg][i]; state[i]=false; } 
 state[beg]=true; count++;  while(count<20)
  { min=100; for(i=1;i<=20;i++) { if(!state[i]&&dist[i]<min) 
  { min=dist[i]; v=i; } } state[v]=true; count++; 
  for(i=1;i<=20;i++) { if(!state[i]&&map[v][i]==1) 
  { if(dist[v]+1<dist[i]) dist[i]=dist[v]+1; } } } 
  printf("%d to %d: %d\n",beg,end,dist[end]); } printf("\n"); }}   