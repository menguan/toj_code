#include<iostream>
#include<cstring>
#include<stdio.h>
#include<ctype.h>
using namespace std;
char word[102][102];
char s[102];
int stx,sty,enx,eny,N,len;
int dire[8][2]={0,1,0,-1,-1,0,1,0,-1,-1,-1,1,1,-1,1,1};
bool DFS(int i,int j,int dir,int pos)
{
 if(pos==len-1)
 {
  if(word[i][j]==s[pos])
  {
   enx=i+1;
   eny=j+1;
   return true;
  }
  else
  return false;
 }
 if(word[i][j]!=s[pos])return false;
 else if(i+dire[dir][0]<0||i+dire[dir][0]>=N||j+dire[dir][1]<0||j+dire[dir][1]>=N) 
 return false;
 else
 return DFS(i+dire[dir][0],j+dire[dir][1],dir,pos+1);
}
int main()
{
 int i,j,k;
 while(scanf("%d",&N)!=EOF)
 {
  getchar();
  for(i=0;i<N;i++)
   gets(word[i]);
  while(scanf("%s",&s)!=EOF&&strcmp(s,"0")!=0)
  {
   len=strlen(s);
   int flag=0;
   for(i=0;i<N&&!flag;i++)
    for(j=0;j<N&&!flag;j++)
     for(k=0;k<8&&!flag;k++)
     {
      if(DFS(i,j,k,0))
      {
       stx=i+1;
       sty=j+1;
       flag=1;
       break;
      }
     }
   if(!flag)printf("Not found\n");
   else cout<<stx<<","<<sty<<" "<<enx<<","<<eny<<endl;
  }
 }
 return 0;
}
  
