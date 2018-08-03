#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
struct trie
{
    int ch[2];
    int e,p;
    trie(){ch[0]=ch[1]=-1;e=p=0;}
}tree[1000000];
int m,n;
int root;int ro;
int rootnum;
int main()
{
    //cin>>m>>n;
    scanf("%d%d",&m,&n);
    root=1;
    rootnum=1;
    int len;
    int num;
    for(int i=1;i<=m;i++)
    {
        //cin>>len;
        scanf("%d",&len);
        ro=root;
        for(int j=1;j<=len;j++)
        {
            //cin>>num;
            scanf("%d",&num);
            if(tree[ro].ch[num]<0)
                tree[ro].ch[num]=++rootnum;
            ro=tree[ro].ch[num];
            tree[ro].p++;
        }
        tree[ro].e++;
    }
    for(int i=1;i<=n;i++)
    {

        //cin>>len;
        scanf("%d",&len);
        int ans=0;
        ro=root;
        bool flag=0;
        for(int j=1;j<=len;j++)
        {
            //cin>>num;
            scanf("%d",&num);
            if(flag) continue;
            if(tree[ro].e)  ans+=tree[ro].e;
            if(tree[ro].ch[num]<0)
            {
                flag=1;
            }
            ro=tree[ro].ch[num];
        }
        if(!flag)  ans+=tree[ro].p;
        //cout<<ans<<endl;
        printf("%d\n",ans);
    }

}
