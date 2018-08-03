#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int g[12][12];
int main()
{
    int n;
    while(cin>>n,n)
    {
        n++;
        vector<int> v;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cin>>g[i][j];
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
        for(int i=1;i<n;i++)
        {
            v.push_back(i);
        }
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            ans+=g[i][i+1];
        }
        ans+=g[n-1][0];
        int temp;
        while(next_permutation(v.begin(),v.end()))
        {
                 temp=g[0][v[0]]+g[v[n-2]][0];
                 for(int i=0;i<n-2;i++)
                 {
                     temp+=g[v[i]][v[i+1]];
                 }
                  ans=min(ans,temp);
        }
        cout<<ans<<endl;
    }
}
