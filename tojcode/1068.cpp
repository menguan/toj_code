#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char key[100],let[100];
int dp[91][91];int fre[100];int pre[100][100];
int ans[100][100];
int k,l;
void f(int a,int b,int c)
{
    if(b==0) return ;
    f(ans[b-1][a],b-1,a);
    cout<<key[b-1]<<": ";
    for(int i=a;i<c;i++)
        cout<<let[i];
    cout<<endl;
}
int main()
{
    int t;
    int cas=1;
    cin>>t;
    while(t--)
    {
        memset(pre,0,sizeof(pre));
        for(int i=0;i<91;i++)
            for(int j=0;j<91;j++)
               dp[i][j]=1010101010;
        cin>>k>>l;
        cin>>key>>let;
        for(int i=1;i<=l;i++)
            cin>>fre[i];
        dp[0][0]=0;
        for(int i=1;i<=l;i++)//从 i到 j 在一个键上的 花费
        {
            for(int j=i;j<=l;j++)
            {
                pre[i][j]=pre[i][j-1]+(j-i+1)*fre[j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            for(int j=i;j<=l-k+i;j++)
            {
                for(int m=i;m<=j;m++)
                {
                    if(dp[i][j]>dp[i-1][m-1]+pre[m][j])
                    {
                        dp[i][j]=dp[i-1][m-1]+pre[m][j];
                        ans[i][j]=m-1;
                    }
                }
            }
        }
        cout<<"Keypad #"<<cas++<<":"<<endl;
        f(ans[k][l],k,l);
        cout<<endl;
    }
}
