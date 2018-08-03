#include<iostream>
using namespace std;
int dp[110][10100];
int main()
{
  dp[1][0]=2;
  int tempmax;
  for(int i=1;i<101;i++)
  {
    dp[i][0]=i+1;
    tempmax=(i+1)*i/2;
    for(int j=0;j<=tempmax;j++)
    {
      if(dp[i][j]==0)
        continue;
      int cross=0;
      int add=i+1;  
      int temp=0;  
      for(int k=1;k+i<101;k++)
      {
        cross+=i;
        temp+=add;
        if(temp+dp[i][j]>dp[i+k][j+cross])
          dp[i+k][j+cross]=temp+dp[i][j];
      }
    }
  }  
  int n,m,count=1;
  while(cin>>n>>m)
  {
    if(n==0&&m==0)
      return 0;
    if(dp[n][m])
      cout<<"Case "<<count++<<": "<<n<<" lines with exactly "<<m<<" crossings can cut the plane into "<<dp[n][m]<<" pieces at most."<<endl;
    else
      cout<<"Case "<<count++<<": "<<n<<" lines cannot make exactly "<<m<<" crossings."<<endl;
  }
}  

    
              
           
     