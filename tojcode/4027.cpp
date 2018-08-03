#include<iostream>
#include<cstring>
using namespace std;
int dp[1010][1010];
char s[1010];
int main()
{
  int t;
  cin>>t;
  int count=1;
  while(t--)
  {
    cin>>s;
    int len=strlen(s);
    for(int i=0;i<len;i++)
      dp[i][i]=1;
    for(int j=len-2;j>=0;j--)
    {
      for(int i=j+1;i<len;i++)
      {
        dp[j][i]=(dp[j+1][i]+dp[j][i-1]-dp[j+1][i-1]+10007)%10007;
        if(s[i]==s[j])
          dp[j][i]=(dp[j][i]+dp[j+1][i-1]+10008)%10007;
      }
   }
   cout<<"Case "<<count++<<": "<<dp[0][len-1]<<endl;
  }//
}   
    