#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{

    int len;
    int a,b;
    friend bool operator<(edge aa,edge bb)
    {
        return aa.len<bb.len;
    }
}e[1000];
int id[30];
char s[1000];
int get(int u)
{
    cin>>s;
    int res=0;
    int len=strlen(s);
    for(int i=0;i<len-(u!=1);i++)
    {
        res*=10;
        res+=s[i]-'0';
    }
    return res;
}
int find(int p)
{
    while(p!=id[p])p=id[p];
    return p;
}
int main()
{
    int t;int n;
    int te;int cas=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<30;i++)id[i]=i;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                te=get(n-j);
                if(te==0) continue;
                e[cnt].a=i;
                e[cnt].b=j;
                if(e[cnt].a>e[cnt].b)swap(e[cnt].a,e[cnt].b);
                e[cnt].len=te;
                cnt++;
            }
        }
        cout<<"Case "<<cas++<<":"<<endl;
        sort(e,e+cnt);
        int ff=0;
        for(int i=0;i<cnt;i++)
        {
            if(ff==n-1) break;
            int aa=find(e[i].a);
            int bb=find(e[i].b);
            if(aa!=bb)
            {
                id[aa]=bb;
                ff++;
                cout<<(char)(e[i].a+'A')<<"-"<<(char)(e[i].b+'A')<<" "<<e[i].len<<endl;
            }
        }
    }

}
