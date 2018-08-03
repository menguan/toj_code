#include<iostream>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
int a[110000];
int next[110000];
int mp[110000];
bool vis[110000];
int main()
{
    int c,n,b;
    while(cin>>c>>n>>b)
    {
        for(int i=0;i<b;i++)
        {
            cin>>a[i];
            mp[a[i]]=1010101010;
            vis[a[i]]=0;
        }
        for(int i=b-1;i>=0;i--)
        {
            next[i]=mp[a[i]];
            mp[a[i]]=i;
        }
        int ans=0;

        priority_queue<pair<int,int> >q;
        for(int i=0;i<b;i++)
        {
            if(!vis[a[i]])
                        {
                            ans++;
                          if(c==0)

                          {


                            while(mp[q.top().second]!=q.top().first) q.pop();
                            int tt=q.top().second;
                            vis[tt]=0;
                            q.pop();
                            c++;
                        }
                        c--;
                       vis[a[i]]=1;
            }
            mp[a[i]]=next[i];

            q.push(make_pair(next[i],a[i]));
        }
        cout<<ans<<endl;
    }
}
