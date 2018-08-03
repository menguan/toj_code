#include<iostream>
#include<queue>
#include<list>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
#include<stack>
#include<vector>
using namespace std;
const signed maxl=50;
const unsigned hashs=400000;
int n,m;int cas;
struct node
{
    char name[maxl+1];
    int dist;
    node *next;
    list<node*> neib;
    node(const char _name[],node* _next):dist(-1),next(_next)
    {
        strcpy(name,_name);
    }
};
node *hashtable[hashs];
unsigned elfhash(const char *key)
{
    unsigned h=0;
    while(*key!='\0')
    {
        h=(h<<4)+*key++;
        unsigned g=h&0xf0000000;
        if(g)
            h^=g>>24;
        h&=~g;
    }
    return h%hashs;
}
node* enhash(const char name[])
{
    unsigned h=elfhash(name);
    node *p=hashtable[h];
    while(p!=NULL&&strcmp(p->name,name)!=0)
        p=p->next;
    return p?p:hashtable[h]=new node(name,hashtable[h]);
}
char ss[10000000];
void bfs()
{
    queue<node*> q;
    q.push(enhash("Erdos, P."));
    q.front()->dist=0;
    while(!q.empty())
    {
        typedef list<node*>::iterator ip;
        int d=q.front()->dist+1;
        list<node*>& l=q.front()->neib;
        q.pop();
        for(ip p=l.begin();p!=l.end();p++)
        {
            if((*p)->dist==-1)
            {
                q.push(*p);
                (*p)->dist=d;
            }
        }
    }
}
void fun()
{
    printf("Database #%d\n",cas++);
    while(m--)
    {
        char name[maxl+1];
        int d;
        gets(name);
        d=enhash(name)->dist;
        printf("%s: ",name);
        if(d!=-1)
            printf("%d\n",d);
        else
            puts("infinity");
    }
    puts("");
}
int main()
{
    cas=1;
    vector<node*> v;
    while(~scanf("%d %d",&n,&m)){
    if(m==0&&n==0) return 0;
    getchar();
    while(n--)
    {
        gets(ss);
        v.clear();
        char name1[maxl+1];
        int tt=0;int cnt=0;
        int len=strlen(ss);
        node *p;
        while(ss[len]!=':')len--;
        for(int i=0;i<len;i++)
        {
            if(ss[i]==',')cnt++;
            if(cnt!=2)
               name1[tt++]=ss[i];
            else
            {
                cnt=0;
                name1[tt]='\0';
                p=enhash(name1);
                v.push_back(p);
                tt=0;
                i++;
            }

        }
        name1[tt]='\0';
        p=enhash(name1);
        v.push_back(p);
        for(int i=0;i<v.size();i++)
		{
			for(int j=0;j<v.size();j++)
			{
				if (v[i]!=v[j])
					v[i]->neib.push_back(v[j]);
			}
		}

        /*
        p->neib.push_back(q);
        q->neib.push_back(p);
        */
    }
    bfs();
    fun();
    }
}
