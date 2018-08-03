#include<iostream>
#include<string>
#include<cstring>
using namespace std; 
int visit[1100006],prime[400006];
void GetPrime(){
 int cnt=0;
 memset(visit,0,sizeof(visit));
 for(int i=2;i<1100006;i++){
  if(!visit[i]){
   prime[cnt++]=i;
  }
  for(int j=0;(j<cnt)&&(i*prime[j]<1100006);j++){
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
  string s;int l;
  while(cin>>s>>l)
  {
    if(s=="0"&&l==0)
      return 0;
    int len=s.length();  
    bool flag=1;        
    for(int i=0;prime[i]<l;i++)
    {
      int m=(s[0]-'0')%prime[i];
      for(int j=1;j<len;j++)
      {
        m=(m*10+(s[j]-'0'))%prime[i];
      }
      if(m==0)
      {
        flag=0;
        cout<<"BAD "<<prime[i]<<endl;
        break;
      }
    }
    if(flag)
      cout<<"GOOD"<<endl;
  }
}      
          
      
