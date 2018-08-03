#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a,b,s[110][110];
int main()
{
    while(cin>>a>>b)
    {
        int la=a.length();
        int lb=b.length();
        for(int i=0;i<=la;i++)s[i][0]=a.substr(0,i);
        for(int i=0;i<=lb;i++)s[0][i]=b.substr(0,i);
        for(int i=1;i<=la;i++)
        {
            for(int j=1;j<=lb;j++)
            {
                if(s[i][j-1].length()>s[i-1][j].length()) s[i][j]=s[i-1][j]+a[i-1];
                else s[i][j]=s[i][j-1]+b[j-1];
                if(a[i-1]==b[j-1]) s[i][j]=s[i-1][j-1]+a[i-1];
                //cout<<i<<" "<<j<<" "<<s[i][j]<<endl;
            }
        }
        cout<<s[la][lb]<<endl;
    }
}
