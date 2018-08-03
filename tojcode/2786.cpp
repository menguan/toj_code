#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define maxn 10005
int n,m,k,now,cnt;
bool ar[maxn],bo[maxn];
int main()
{
    int i,j;
    char s[10];
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%s",s);
        if (s[0]=='B') ar[i]=1;
        else ar[i]=0;
    }
    m=2147483647;
    for (i=1;i<=n;i++)
    {
        now=cnt=0; memset(bo,0,sizeof(bo));
        for (j=1;j<i&&j<=n+1-i;j++) if (now^ar[j])
            now^=1,cnt++,bo[j]=1;
        for (;j<=n+1-i;j++,now^=j-i>0?bo[j-i]:0) if (now^ar[j])
            now^=1,cnt++,bo[j]=1;
        for (;j<=n;j++,now^=j-i>0?bo[j-i]:0) if (ar[j]^now) break;
        if (j<=n) continue;
        if (cnt<m) {m=cnt,k=i;}
    }
    printf("%d %d\n",k,m);
    return 0;
}
ntinue;
        if (cnt<m) {m=cnt,k=i;}
    }
    printf("%d %d\n",k,m);
    return 0;
}
