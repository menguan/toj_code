#include<iostream>
//。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
//此题看了bfs的讲义 虽然不知道原来咋错的
#include<queue>
#include<list>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
#include<stack>
using namespace std;
const signed maxl=20;
const unsigned hashs=400000;
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
void get()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char name1[maxl+1],name2[maxl+1];
        node *p,*q;
        scanf("%s %s",name1,name2);
        p=enhash(name1);
        q=enhash(name2);
        p->neib.push_back(q);
        q->neib.push_back(p);
    }
}
void bfs()
{
    queue<node*> q;
    q.push(enhash("Erdos"));
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
    int m;
    scanf("%d",&m);
    while(m--)
    {
        char name[maxl+1];
        int d;
        scanf("%s",name);
        d=enhash(name)->dist;
        if(d!=-1)
            printf("%d\n",d);
        else
            puts("infinity");
    }
}
int main()
{
    get();
    bfs();
    fun();
}
