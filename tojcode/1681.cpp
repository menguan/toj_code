#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct Node
{
    int px, dx;
}arr[10010];
bool cmp(Node mm,Node nn)
{
     return mm.dx>nn.dx;
}
priority_queue<int,vector<int>,less<int> >q;

int n;

int main()
{
    while(cin>>n)
    {
        int maxTime=0;
        for(int i=0; i<n; ++i)
        {
            cin>>arr[i].px>>arr[i].dx;
            if(arr[i].dx>maxTime) maxTime = arr[i].dx;
        }
        sort(arr,arr+n,cmp);
        int ans = 0, pos=0;;
        while(!q.empty()) q.pop();
        for(int t=maxTime;t>=1;t--)
        {
            while(pos<n&&arr[pos].dx>=t)
            {
                q.push(arr[pos++].px);
            } 
            if(!q.empty())
            {
                ans += q.top();
                q.pop();
            }
        }
        cout<<ans<<endl;
    }
}
