#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int KIND=26;
const int MAXN=15000;
int cnt_node;
vector<int> g[10];
char input[105];
char ans[105];
int num,Max;
bool flag;
struct node
{
    int prefix;
    node *next[KIND];
    void init()
    {
        prefix=0;
        memset(next,0,sizeof(next));
    }
}Heap[MAXN];
inline node *newNode()
{
    Heap[cnt_node].init();
    return &Heap[cnt_node++];
}
void insert(node *root,char *str,int n)
{
    for(char *p=str;*p;++p)
    {
        int ch=*p-'a';
        if(root->next[ch]==NULL)
            root->next[ch]=newNode();
        root=root->next[ch];
        root->prefix+=n;
    }
}
void dfs(node *root,char *str,int pos)
{
    if(root==NULL) return ;
    if(pos>=num)
    {
        if(root->prefix>Max)
        {
            strcpy(ans,str);
            Max=root->prefix;
        }
        flag=1;
        return;
    }
    int u=input[pos]-'0';
    for(int i=0;i<g[u].size();++i)
    {
        str[pos]=g[u][i]+'a';
        dfs(root->next[g[u][i]],str,pos+1);
        str[pos]=0;
    }
}
int main(){
     int T,n,p,cas=1;
     char str[105];
     for(int i=0; i<10; ++i) g[i].clear();
     g[2].push_back(0), g[2].push_back(1), g[2].push_back(2);
     g[3].push_back(3), g[3].push_back(4), g[3].push_back(5);
     g[4].push_back(6), g[4].push_back(7), g[4].push_back(8);
     g[5].push_back(9), g[5].push_back(10), g[5].push_back(11);
     g[6].push_back(12), g[6].push_back(13), g[6].push_back(14);
     g[7].push_back(15), g[7].push_back(16), g[7].push_back(17),g[7].push_back(18);
     g[8].push_back(19), g[8].push_back(20), g[8].push_back(21);
     g[9].push_back(22), g[9].push_back(23), g[9].push_back(24), g[9].push_back(25);

     scanf("%d",&T);
     while(T--){
         scanf("%d",&n);
         printf("Scenario #%d:\n", cas++);

         cnt_node=0;
         node *root = newNode();

         for(int i=0; i<n; ++i){
             scanf("%s %d",str,&p);
             insert(root, str, p);
         }

         scanf("%d",&n);
         for(int i=0; i<n; ++i){
             scanf("%s", input);
             for(int j=0; j<strlen(input)-1; ++j){
                 memset(str, 0, sizeof(str));
                 Max=-1;
                 num=j+1;
                 flag=false;
                 dfs(root, str, 0);
                 if(flag) puts(ans);
                 else puts("MANUALLY");
             }
             puts("");
         }
         puts("");
     }
     return 0;
 }
