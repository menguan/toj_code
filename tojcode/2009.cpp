#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int cards[1010];
int score[1010][1010];
int cn,cs;
int cas;
int i,j;
int ans;
int dp(int a,int b)
{
    int left,right;
    if(b-a<=1)
      return max(cards[a],cards[b]);
    if(score[a][b]!=-1)
      return score[a][b];
    if(cards[a+1]>=cards[b])
      left=cards[a]+dp(a+2,b);
    else
      left=cards[a]+dp(a+1,b-1);
    if(cards[a]>=cards[b-1])
      right=cards[b]+dp(a+1,b-1);
    else
      right=cards[b]+dp(a,b-2);
    score[a][b]=max(left,right);
    return score[a][b];
}
int main()
{
    cas=0;
    while(cin>>cn,cn)
    {
         cas++;
         cs=0;
         for(i=1;i<=cn;i++)
         {
            cin>>cards[i];
            cs+=cards[i];
            for(j=1;j<i;j++)
              score[j][i]=-1;
         }
         ans=dp(1,cn);
         cout<<"In game "<<cas<<", the greedy strategy might lose by as many as "<<ans-(cs-ans)<<" points."<<endl;
    }
}
                                  
