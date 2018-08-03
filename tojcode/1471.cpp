#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<cstring>
using namespace std;
char s1[110];
char s2[110];
int a[30][30];
int dp[310][310];
void init()
{
    a[0][0]=5;
    a[0]['C'-'A']=a['C'-'A'][0]=-1;
    a[0]['G'-'A']=a['G'-'A'][0]=-2;
    a[0]['T'-'A']=a['T'-'A'][0]=-1;
    a[0]['H'-'A']=a['H'-'A'][0]=-3;
    a['C'-'A']['G'-'A']=a['G'-'A']['C'-'A']=-3;
    a['C'-'A']['T'-'A']=a['T'-'A']['C'-'A']=-2;
    a['C'-'A']['H'-'A']=a['H'-'A']['C'-'A']=-4;
    a['G'-'A']['T'-'A']=a['T'-'A']['G'-'A']=-2;
    a['G'-'A']['H'-'A']=a['H'-'A']['G'-'A']=-2;
    a['T'-'A']['H'-'A']=a['H'-'A']['T'-'A']=-1;
    a['C'-'A']['C'-'A']=a['G'-'A']['G'-'A']=a['T'-'A']['T'-'A']=5;
}
int main()
{
    int t;
    int n1,n2;
    init();
    cin>>t;
    while(t--)
    {
        cin>>n1;
        cin>>s1;
        cin>>n2;
        cin>>s2;
        for(int i=0;i<=n1;i++)
        for(int j=0;j<=n2;j++)
        dp[i][j]=-1010101010;
        dp[0][0]=0;
        for(int i=1;i<=n1;i++)
        dp[i][0]=dp[i-1][0]+a[s1[i-1]-'A']['H'-'A'];
        for(int j=1;j<=n2;j++)
        dp[0][j]=dp[0][j-1]+a['H'-'A'][s2[j-1]-'A'];
        for(int i=1;i<=n1;i++)
        for(int j=1;j<=n2;j++)
        {
           dp[i][j]=max(dp[i-1][j-1]+a[s1[i-1]-'A'][s2[j-1]-'A'],dp[i][j]);
           dp[i][j]=max(dp[i][j-1]+a['H'-'A'][s2[j-1]-'A'],dp[i][j]);
           dp[i][j]=max(dp[i-1][j]+a[s1[i-1]-'A']['H'-'A'],dp[i][j]);
        }
        cout<<dp[n1][n2]<<endl;
    }
}
