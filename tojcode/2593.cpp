#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdlib>
using namespace std;
int pre[65536];
int prer[65536];
int prec[65536];
//bool vis[65536];
int main()
{
    int n=0;char ch[10];
    for(int i=0;i<4;i++)
    {
        cin>>ch;
        for(int j=0;j<4;j++)
        {
          n<<=1;
          if(ch[j]=='+')n++;
        }
    }
    //memset(vis,0,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    memset(prer,-1,sizeof(prer));
    memset(prec,-1,sizeof(prec));
    queue<int> q;
    //vis[n]=1;
    pre[n]=n;
    q.push(n);
    int now,nowstep,tmp;
    while(!q.empty())
    {
       now=q.front();q.pop();
       for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
       {
              tmp=now;
              tmp^=1<<(15-4*i-j);
              tmp^=1<<(15-j);
              tmp^=1<<(15-j-4);
              tmp^=1<<(15-j-8);
              tmp^=1<<(15-j-12);
              tmp^=1<<(15-4*i);
              tmp^=1<<(15-4*i-1);
              tmp^=1<<(15-4*i-2);
              tmp^=1<<(15-4*i-3);
              if(pre[tmp]==-1)
              {
                  pre[tmp]=now;
                  prer[tmp]=i+1;
                  prec[tmp]=j+1;
                  q.push(tmp);
              }
              if(tmp==0)
              {
                  stack<int> st;
                  while(pre[tmp]!=tmp)
                  {
                      //cout<<tmp<<endl;
                      st.push(prec[tmp]);
                      st.push(prer[tmp]);
                      tmp=pre[tmp];
                  }
                  cout<<st.size()/2<<endl;
                  while(!st.empty())
                  {
                      cout<<st.top()<<" ";st.pop();
                      cout<<st.top()<<endl;st.pop();
                  }
                  return 0;
              }
       }
    }

}
