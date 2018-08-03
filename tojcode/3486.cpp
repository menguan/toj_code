#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long dice[110][660];

int main()
{
   memset(dice,0,sizeof(dice));
   dice[1][1]=1;
   dice[1][2]=1;
   dice[1][3]=1;
   dice[1][4]=1;
   dice[1][5]=1;
   dice[1][6]=1;
   int k;
   for(int i=2;i<101;i++)
   {
     for(int j=i;j<=6*i;j++)
     {
       for(int k=1;k<=6;k++)
       {
         if(j-k>0)
         if(dice[i-1][j-k])
         {
           dice[i][j]+=dice[i-1][j-k];
         }
       }     
        
      
     }
   } 
   
   int t;
   cin>>t;
   int n,m;
   while(t--)
   {
       cin>>n>>m;
       
       cout<<setprecision(2)<<fixed<<dice[n][m]*1.0/(pow(6,n*1.0))<<endl;
   }
 }      
    