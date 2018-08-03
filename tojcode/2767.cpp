#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int visit[4000006],prime[400006];
void GetPrime(){
 int cnt=0;
 memset(visit,0,sizeof(visit));
 for(int i=2;i<4000006;i++){
  if(!visit[i]){
   prime[cnt++]=i;
  }
  for(int j=0;(j<cnt)&&(i*prime[j]<4000006);j++){
   visit[i*prime[j]]=1;
   if(i%prime[j]==0){
    break;
   }
  }
 }
}
bool find(int m,int d)
{
  while(m)
  {
    if(m%10==d)
      return 1;
    m/=10;
  }
  return 0;
}      
int main()
{
  GetPrime();
  int a,b,d;
  int count=0;
  cin>>a>>b>>d;
  for(int i=0;prime[i]<=b;i++)
  {
    if(prime[i]<a)
       continue;
    
    if(find(prime[i],d))
      count++;
  }
  cout<<count<<endl;
  //while(1);
}            
  
  
