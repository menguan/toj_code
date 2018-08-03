#include<iostream>//照网上的代码打了一遍  没啥难度
#include<cstdio>
#include<cstring>
using namespace std;

const int KIND = 26;
const int MAXN = 500000;
int cnt_node;
double width[8];

struct node{
    int cnt;
    node* next[KIND];
    void init(){
        cnt = 0;
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
        ++root->cnt;
    }
}

int count(node* root, char *str){
    for(char *p=str; *p; ++p){
        int ch=*p-'a';
        if(root->next[ch]==NULL)
            return 0;
        root=root->next[ch];
    }
    return root->cnt;
}

int main(){
    int n,m,q;
    char str[40];
    while(cin>>n>>m)
        {
        cnt_node=0;
        node *root = new_node();
        for(int i=0; i<n; ++i){
            cin>>str;
            insert(root, str);
        }

        int ans=0;
        while(m--){
            cin>>q;
            int p=0;
            for(int k=0; k<q; ++k){
                double x;
                double sum=0;
                for(int i=0; i<8; ++i){
                    cin>>width[i];
                    sum += width[i];
                }
                sum /= 8.0;
                int ch=0;
                for(int i=7, d=1; i>=0; --i){
                    if(width[i] > sum){
                        ch += d;
                    }
                    d <<= 1;
                }
                if(ch>='a' && ch<='z')
                    str[p++] = (char)ch;
            }
            str[p]='\0';
            ans += count(root, str);
        }
        cout<<ans<<endl;
    }
}
