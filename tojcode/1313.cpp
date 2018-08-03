#include <iostream>//不需要考虑重合 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

struct Node
{
   int x,y;
}node[1010],mid[1001000];
int T,n,ans,num;

int cmp(const Node &a,const Node &b)
{
    if (a.x==b.x) return a.y<b.y; else return a.x<b.x;
}
int main()
{
    cin >> T;
    while (T--)
    {
        ans=0;
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
          {
              scanf("%d%d",&(node[i].x),&(node[i].y));
          }
        num=0;
        for (int i=1; i<=n; i++)
        {
            for (int j=i+1; j<=n; j++)
              {
                  mid[num].x=node[i].x+node[j].x;
                  mid[num].y=node[i].y+node[j].y;
                  num++;
              }
        }
        sort(mid,mid+num,cmp);
        Node temp;
        int k;
        k=1;
        for (int i=0; i<num; i++)
        {
            if (mid[i].x==mid[i+1].x && mid[i].y==mid[i+1].y) k++;
                else
                {
                    ans+=(k*(k-1)/2);
                    k=1;
                }
        }
        cout << ans << endl;

    }
}


