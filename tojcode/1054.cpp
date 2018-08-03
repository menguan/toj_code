#include<iostream>
#include<cstring>
using namespace std;
int ans[110];
int cnt;
bool flag;
int b;int xr,xi,br,bi;
void dfs(int dep)
{
    if(flag) return ;
    if(dep>100)return ;
    int x,y;
    if(xr==0&&xi==0)
    {
        flag=1;
        cnt=dep;
        return ;
    }
    for(int i=0;i*i<b;i++)
    {
        if(flag) return ;
        x=(xr-i)*br+xi*bi;
        y=xi*br-(xr-i)*bi;
        ans[dep]=i;
        if(x%b==0&&y%b==0)
        {
            xr=x/b;
            xi=y/b;
            dfs(dep+1);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>xr>>xi>>br>>bi;
        flag=0;
        b=br*br+bi*bi;
        dfs(0);
        if(flag)
        {
            cout<<ans[cnt-1];
            for(int i=cnt-2;i>=0;i--)
                cout<<','<<ans[i];
            cout<<endl;
        }
        else
        {
            cout<<"The code cannot be decrypted."<<endl;
        }
    }
}
