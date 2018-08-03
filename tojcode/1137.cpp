#include<iostream>
#include<cstring>
using namespace std;
int ans[120];
int tmp[120];
int n;
int cnt;
void dfs(int pos)
{
    if(pos>=cnt) return ;
    for(int i=0;i<pos;i++)
    {

        int tt=tmp[i]+tmp[pos-1];
        if(tt==n)
        {
            cnt=pos;
            for(int i=1;i<pos;i++)
            {
                ans[i]=tmp[i];
            }
            return ;
        }
        else if(tt<n)
        {
            tmp[pos]=tt;
            dfs(pos+1);
        }
    }
}
int main()
{
    while(cin>>n,n)
    {

        if(n==1){cout<<1<<endl;continue;}
        memset(tmp,0,sizeof(tmp));
        memset(ans,0,sizeof(ans));
        tmp[0]=1;
        ans[0]=1;
        cnt=10101010;
        dfs(1);
        for(int i=0;i<cnt;i++)
        {
            if(i)cout<<" ";
            cout<<ans[i];
        }
        cout<<" "<<n<<endl;
    }

}

