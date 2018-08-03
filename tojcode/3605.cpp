#include <stdio.h>//又挫了
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long LL;
using namespace std;
const LL inf=1000000000000000000ll;
const int MAXN=100000;
int N;
LL C[MAXN+1];
LL A[MAXN-1],B[MAXN-1],L[MAXN-1];
vector<LL> children[MAXN+1],length[MAXN+1];
LL total_cow;
LL cow[MAXN+1];
LL cost[MAXN+1];
LL answer;

void dfs1(int root,int fa)
{
     total_cow+=C[root];
     cow[root]+=C[root];
     for (int i=0;i<children[root].size();i++)
         if (children[root][i]!=fa)
         {
            dfs1(children[root][i],root);
            cow[root]+=cow[children[root][i]];
            cost[root]+=cost[children[root][i]]
                        +cow[children[root][i]]*length[root][i];
         }
}
void dfs2(int root,int fa)
{
     if (cost[root]<answer) answer=cost[root];
     for (int i=0;i<children[root].size();i++)
         if (children[root][i]!=fa)
         {
            cost[children[root][i]]=cost[root]+(total_cow-cow[children[root][i]])*length[root][i]-cow[children[root][i]]*length[root][i];
            dfs2(children[root][i],root);
         }
}
int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++)
        scanf("%d",&C[i]);
    for (int i=0;i<N-1;i++)
        scanf("%d %d %d",&A[i],&B[i],&L[i]);

    for (int i=0;i<N-1;i++)
    {
        children[A[i]].push_back(B[i]);
        children[B[i]].push_back(A[i]);
        length[A[i]].push_back(L[i]);
        length[B[i]].push_back(L[i]);
    }
    int leaf;
    for (int i=1;i<=N;i++)
        if (children[i].size()==1)
        {
           leaf=i;
           break;
        }
    dfs1(leaf,-1);
    answer=inf;
    dfs2(leaf,-1);
    printf("%lld\n",answer);
}
