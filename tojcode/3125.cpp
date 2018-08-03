#include<stdio.h>
 int parent[50005],id[10005];
 int ans1,ans2,a,b,i,n;
 char c;
 int find_parent(int a)
{
    int temp;
    temp=a;
    while(parent[temp]!=temp)
    {
        parent[temp]=parent[parent[temp]];
        temp=parent[temp];
    }
    return temp;
}
void merge(int a,int b)
{
    int x,y;
    x=find_parent(id[a]);
    y=find_parent(id[b]);
    parent[x]=y;
}
void ques(int a,int b)
{
    int x,y;
    x=find_parent(id[a]);
    y=find_parent(id[b]);
    if (x==y)
        ans1++;
    else ans2++;
}
void discon(int a)
{
    id[a]=++n;
    parent[n]=n;
}
void work()
{
    for (i=1;i<=n;i++)
    {
        id[i]=i;
        parent[i]=i;
    }
    ans1=0;
    ans2=0;
    while (1)
    {
        scanf("%c",&c);
        switch (c)
        {
        case 'e':printf("%d , %d\n",ans1,ans2);return;
        case 'c':scanf("%d%d",&a,&b);merge(a,b);break;
        case 'q':scanf("%d%d",&a,&b);ques(a,b);break;
        case 'd':scanf("%d",&a);discon(a);break;
        }
    }
}
int main()
{
    while (scanf("%d",&n)!=EOF)
        work();
    return 0;
}
