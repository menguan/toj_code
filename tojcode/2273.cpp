#include<iostream>//回去好好研究
#include<string>
#include<stdio.h> 
#include<algorithm>
using namespace std;
int num[4],tmp[4],result[4];
int total,money;
bool success;

void DFS(int dep,int remained)
{
     if(dep==4)
      {
          if(remained==0)
          { 
              int sum=tmp[0]+tmp[1]+tmp[2]+tmp[3];
              if(sum<total)                                                                  
              {
                 for(int i=0;i<4;i++)
                     result[i]=tmp[i];
                 total=sum;
              } 
              success=true;                                                                                 
          }
          return;
      }
      for(int j=0;j<=num[dep];j++)
      {
          tmp[dep]=j;
          if(dep==0) 
             DFS(dep+1,remained-25*j);
          else if(dep==1)
             DFS(dep+1,remained-10*j);
          else if(dep==2)
             DFS(dep+1,remained-5*j);
          else if(dep==3) 
             DFS(dep+1,remained-j); 
      } 
} 
int main()
{
    while(scanf("%d%d%d%d%d",&num[0],&num[1],&num[2],&num[3],&money)&&(num[0]||num[1]||num[2]||num[3]||money))         
    {
        total=100000;
        success=false; 
        DFS(0,money);
        if(success) 
            printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n",result[0],result[1],result[2],result[3]);
        else
          printf("Cannot dispense the desired amount.\n"); 
    } 
    return 0; 
}