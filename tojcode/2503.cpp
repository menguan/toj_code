#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
//100 5 0001011011 3 6
using namespace std;
struct Node
{
    int fa;
    int fi,la;
}node[4010];
char tr[8020];
int is[4020];
int n;
int a,b;
int ans;
bool vis[8010];
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d",&n);
      scanf("%s",tr);
      scanf("%d%d",&a,&b);
      if(a>b)
        swap(a,b);
      stack<int> st;
      stack<int> st2;
      while(!st.empty()) st.pop();
      while(!st2.empty()) st2.pop();
      memset(node,-1,sizeof(node));
      memset(is,-1,sizeof(is));
      memset(vis,0,sizeof(vis));
      int now=0;
      int cnt=1;
      ans=-1;
      bool flag=1;
      for(int i=0;i<strlen(tr);i++)
      {
          //cout<<(char)(now+'a'-1)<<endl;
          if(i==a-1&&tr[i]=='1')
          {


              while(!st.empty())
              {
                  vis[st.top()]=1;
                  st2.push(st.top());
                  st.pop();
              }
              while(!st2.empty())
              {
                  st.push(st2.top());
                  st2.pop();
              }

          }
          if(i==b-1&&tr[i]=='1')
          {
             while(!st.empty())
              {
                    if(vis[st.top()]==1)
                    {

                        ans=st.top();
                        flag=0;
                        break;
                    }
                    st.pop();
              }

          }
          if(tr[i]=='0')
          {
              node[cnt].fi=i+1;
              node[cnt].fa=now;
              if(flag)
              st.push(cnt);
              now=cnt++;
          }
           if(tr[i]=='1')
          {
              node[now].la=i+1;
              now=node[now].fa;
              if(flag)
              st.pop();
          }
          if(i==a-1&&tr[i]=='0')
          {


              while(!st.empty())
              {
                  vis[st.top()]=1;
                  st2.push(st.top());
                  st.pop();
              }
              while(!st2.empty())
              {
                  st.push(st2.top());
                  st2.pop();
              }

          }
          if(i==b-1&&tr[i]=='0')
          {
             while(!st.empty())
              {

                    if(vis[st.top()]==1)
                    {

                        ans=st.top();
                        flag=0;
                        break;
                    }
                    st.pop();
              }

          }


      }
      if(ans==-1) ans=1;
      printf("%d %d\n",node[ans].fi,node[ans].la);
  }
}
