#include<iostream>//记忆话搜索
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 40;
int n;
int graph[N][N];
int dp[N][N][N];
int dfs(int a, int b, int c)
{
    if(c == n)
        return 0;
    if(dp[a][b][c] > 0)
        return dp[a][b][c];
    if(dp[a][b][c + 1] == 0) dp[a][b][c + 1] = dfs(a, b, c + 1);
    if(dp[a][c][c + 1] == 0) dp[a][c][c + 1] = dfs(a, c, c + 1);
    if(dp[c][b][c + 1] == 0) dp[c][b][c + 1] = dfs(c , b, c + 1);
    dp[a][b][c] = min(dp[a][b][c + 1] + graph[c][c + 1], dp[a][c][c + 1] + graph[b][c + 1]);
    dp[a][b][c] = min(dp[a][b][c], dp[c][b][c + 1] + graph[a][c + 1]);
    return dp[a][b][c];
}
int main()
{
    int T;
    int i, j, k;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(i = 1; i <= n; i++)
        {
            graph[i][i] = 0;
            for(j = i + 1; j <= n; j++)
            {
                cin>>graph[i][j];
                graph[j][i] = graph[i][j];
            }
        }
        memset(dp,0,sizeof(dp));
        cout<<dfs(1, 1, 1)<<endl;
    }
    return 0;
}

