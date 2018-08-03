#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
struct Node{
     int num,id;  
     Node(){}
     Node(int a,int b){
         num = a,id = b;
     }
     friend bool operator<(const Node &x,const Node &y){
         return x.num>y.num;
     }
}node[100010];
int res[100010];
bool cmp(const Node &x,const Node &y){
     return x.num > y.num;
}
int main(){
     int t,n,m;
     scanf("%d",&t);
     while(t--){
         priority_queue<Node> que;
         scanf("%d%d",&n,&m);
         for(int i = 0;i<n;i++){
              scanf("%d",&node[i].num);
              node[i].id = i;
         }
         sort(node,node+n,cmp);
         for(int i = 0;i<n;i++){
              if(i<m){
                   que.push( Node(node[i].num,i) );
                   res[node[i].id] = i;
              }else{
                   Node tmp = que.top();
                   res[node[i].id] = tmp.id;
                   que.pop();
                   que.push( Node(tmp.num+node[i].num,tmp.id) );
              }
         }
         printf("%d\n",n);
         for(int i = 0;i<n;i++){
              printf("%d ",res[i]);
         }
         puts("");
     }
}
