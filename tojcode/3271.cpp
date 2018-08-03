#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int cnt;
int bef[1010];
int las[1010];
int a[1010];
int b[1010];
bool vis[1010];int n;
map<int ,int > pos;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        pos.clear();
        cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
            pos[a[i]]=i;
        for(int i=0;i<n;i++)
        {
            bool flag=0;
            for(int j=0;j<cnt;j++)
            {
                if(pos[bef[j]]-pos[b[i]]==1)
                {
                    bef[j]=b[i];
                    flag=1;
                    break;
                }
                else if(pos[b[i]]-pos[las[j]]==1)
                {
                    las[j]=b[i];
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                bef[cnt]=b[i];
                las[cnt]=b[i];
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}
