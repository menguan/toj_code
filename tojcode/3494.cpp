#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char s[5010][20];
char t[1010];
bool has[20][30];
int main()
{
    int cas=1;
    int l,d,n;
    cin>>l>>d>>n;
    for(int i=0;i<d;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
    {
        cin>>t;
        memset(has,0,sizeof(has));
        int ans=0;
        int now=0,pos=0;
        while(now<l)
        {
            if(t[pos]!='(')
            {
                has[now][t[pos]-'a']=1;
                now++;
                pos++;
            }
            else
            {
                while(t[++pos]!=')')
                {
                    has[now][t[pos]-'a']=1;
                }
                now++;
                pos++;
            }
        }
        bool flag;
        for(int i=0;i<d;i++)
        {
            flag=1;
            for(int j=0;j<l;j++)
            {
               if(has[j][s[i][j]-'a']==0)
               {
                   flag=0;
                   break;
               }
            }
            if(flag)
                ans++;
        }
        cout<<"Case #"<<cas++<<": "<<ans<<endl;

    }
}
