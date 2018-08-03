#include <stdio.h>
#include <queue>
#include <cstring>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int a[100005];
deque <int> q1;
deque <int> q2;

int main()
{
    int i,j,n,x,y,ans,last;
    while(scanf("%d%d%d",&n,&x,&y)!=EOF)
    {
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        ans=0;
        last=-1;
        while(!q1.empty()) q1.pop_front();
        while(!q2.empty()) q2.pop_front();
        for (i=0;i<n;i++)
        {
            while(!q1.empty() && a[i]>a[q1.back()]) q1.pop_back();
            while(!q2.empty() && a[i]<a[q2.back()]) q2.pop_back();
            q1.push_back(i);
            q2.push_back(i);
            while(!q1.empty() && !q2.empty() && a[q1.front()]-a[q2.front()]>y)
            {
                //cout<<q1.front()<<" "<<q2.front()<<" "<<a[q1.front()]<<" "<<a[q2.front()]<<endl;
                if (q1.front()>q2.front())
                {
                    last=q2.front();
                    q2.pop_front();
                }
                else if (q1.front()<q2.front())
                {
                    last=q1.front();
                    q1.pop_front();
                }
                else
                {
                    last=q1.front();
                    q1.pop_front();
                    q2.pop_front();
                }
            }
            if (!q1.empty() && !q2.empty() && a[q1.front()]-a[q2.front()]>=x)
            {
                ans=max(ans,i-last);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
