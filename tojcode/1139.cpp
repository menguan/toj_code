#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string a[120];
string b[120];
string c[120];
int dp[120][120];
int d[120][120];
int main()
{
    int len1,len2;
    while(cin>>a[1])
    {
        len1=2;
        while(a[len1-1]!="#")
            cin>>a[len1++];
        len1-=2;
        cin>>b[1];
        len2=2;
        while(b[len2-1]!="#")
            cin>>b[len2++];
        len2-=2;
        memset(dp,0,sizeof(dp));
        memset(d,0,sizeof(d));
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;d[i][j]=3;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];d[i][j]=2;
            }
            else
            {
                dp[i][j]=dp[i][j-1];d[i][j]=1;
            }
        }
        int s=dp[len1][len2];
        int d1=len1,d2=len2;
        while(s)
        {
            while(d[d1][d2]!=3)
            {
                if(d[d1][d2]==2)
                    d1--;
                else
                    d2--;
            }
            s--;
            c[s]=a[d1];
            d1--;d2--;
        }
        cout<<c[0];
        for(int i=1;i<dp[len1][len2];i++) cout<<" "<<c[i];
        cout<<endl;
    }

}
