#include <iostream>//dfs那点算是新学的 
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

bool app[30];
char res[1005][26];
int in[30], out[30], deg[30], father[30], adj[30];
int n, ant, odd, begin, end;

struct edge
{
    bool vis;
    char sh[25];
    int y, next;
}a[1005];

bool cmp(edge a, edge b)
{
    return strcmp(a.sh, b.sh) > 0;
}

void init()
{
    int i;
    ant = odd = 0;
    memset(app, false, sizeof(app));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(deg, 0, sizeof(deg));
    memset(adj, -1, sizeof(adj));
    for(i = 0; i < 1005; i++) a[i].vis = false;
    for(i = 0; i < 26; i++) father[i] = i;
}

int find(int x)
{
    if(x != father[x])
    {
        father[x] = find(father[x]);
    }
    return father[x];
}

void Union(int x, int y)
{
    father[x] = y;
}

int judge()     
{
    int i, k;
    for(i = 0; i < 26; i++)    
    {
        if(!app[i]) continue;
        deg[i] = in[i] - out[i];
        if(abs(deg[i]) > 1) return 0;
        if(deg[i] > 0) begin = i;  
        if(deg[i] < 0) end = i;     
        if(deg[i]%2) odd++;
        if(odd > 2) return 0;
    }
    for(i = 0; i < 26; i++) if(app[i]) break;
    k = find(i);
    for(i = k+1; i < 26; i++)   
    {
        if(!app[i]) continue;
        if(k != find(i)) return 0;
    }
    if(odd == 0)    
    {
        for(i = 0; i < 26; i++)
            if(app[i]) break;
        begin = i;
        return 1;
    }
    return 2;
}

void dfs(int x, int id)
{
    int i;
	for(i = adj[x]; i != -1; i = a[i].next)
	{
		if(!a[i].vis)
		{
			a[i].vis = true;
			dfs(a[i].y, i);
		}
	}
	if(id != -1) strcpy(res[ant++], a[id].sh);  
}

int main()
{
    int i, x, y, fx, fy, t, len, tar;
    cin>>t;
    while(t--)
    {
        init();
        cin>>n;
        for(i = 0; i < n; i++)
        {
            cin>>a[i].sh;
        }
        sort(a, a+n, cmp);  
        for(i = 0; i < n; i++)
        {
            len = strlen(a[i].sh);
            x = a[i].sh[0] - 'a';
            y = a[i].sh[len-1] - 'a';
            in[x]++;
            out[y]++;
            app[x] = true;
            app[y] = true;
            a[i].y = y;
            a[i].next = adj[x];
            adj[x] = i;
            fx = find(x);
            fy = find(y);
            if(fx != fy) Union(fx, fy);
        }
        tar = judge();
        if(tar == 0)
        {
            cout<<"***"<<endl;
            continue;
        }
        dfs(begin, -1);
        cout<<res[ant-1];
        for(i = ant-2; i >= 0; i--)
        {
            cout<<"."<<res[i];
        }
        cout<<endl;
    }
}
