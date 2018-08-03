#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;

const int KIND = 26;
const int MAXN = 500000;
int cnt_node;
int cnt;
int n;

struct node{
    bool isword;
    int cnt;
    node* next[KIND];
    void init(){
        cnt=0;
        isword=false;
        memset(next, 0, sizeof(next));
    }
}Heap[MAXN];

inline node* new_node(){
    Heap[cnt_node].init();
    return &Heap[cnt_node++];
}

void insert(node* root, char *str){
    for(char *p=str; *p; ++p){
        int ch=*p-'a';
        if(root->next[ch]==NULL)
            root->next[ch] = new_node();
        root = root->next[ch];
    }
    root->isword = true;
    ++root->cnt;
}
void dfs(node *root){
    for(int v=0; v<26; ++v){
        if(root->next[v]!=NULL){
            ++cnt;
            dfs(root->next[v]);
        }
    }
}

int main(){
    char str[55];
    while(~scanf("%d",&n)){
        cnt_node=0;
        node* root = new_node();
        int Max=0;
        for(int i=0; i<n; ++i){
            scanf("%s",str);
            int len=strlen(str);
            if(len>Max)Max=len;
            insert(root, str);
        }
        cnt=0;
        dfs(root);
        printf("%d\n",cnt*2+n-Max);
    }
}