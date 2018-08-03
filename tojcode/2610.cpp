#include<iostream>
#include<cstring>
using namespace std;
int dp[1201][15];
int visit[1000006],prime[400006];
void GetPrime(){
 int cnt=0;
 memset(visit,0,sizeof(visit));
 for(int i=2;i<1000006;i++){
  if(!visit[i]){
   prime[cnt++]=i;
  }
  for(int j=0;(j<cnt)&&(i*prime[j]<1000006);j++){
   visit[i*prime[j]]=1;
   if(i%prime[j]==0){
    break;
   }
  }
 }
}
int main()
{
  GetPrime();
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  for(int i=0;prime[i]<=1200;i++)
  {
    for(int j=1200;j>=prime[i];j--)
    {
      for(int k=14;k>0;k--)
      {
        dp[j][k]+=dp[j-prime[i]][k-1];
      }
    }
  }
  int a,b;
  while(cin>>a>>b&&(a+b))
  {
    cout<<dp[a][b]<<endl;
  }
}             
   