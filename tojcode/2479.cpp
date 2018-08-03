#include<stdio.h>
#include<iostream>
#include<cstring>
#include<stack> 
using namespace std;
const int MAXN=120;
int sta[MAXN];
char str[MAXN];
int p,q,r,s,t;
stack<int> st;
bool judge()
{
    int top=0;int t1,t2;
    while(!st.empty())st.pop();
    int len=strlen(str);
    for(int i=len-1;i>=0;i--)
    {
        if(str[i]=='p') st.push(p);
        else if(str[i]=='q') st.push(q);
        else if(str[i]=='r') st.push(r);
        else if(str[i]=='s') st.push(s);
        else if(str[i]=='t') st.push(t);
        else if(str[i]=='K')
        {
            t1=st.top();st.pop();
            t2=st.top();st.pop();
            st.push((t1&&t2));
        }
        else if(str[i]=='A')
        {
            t1=st.top();st.pop();
            t2=st.top();st.pop();
            st.push((t1||t2));
        }
        else if(str[i]=='N')
        {
            t1=st.top();st.pop();
            st.push((!t1));
        }
        else if(str[i]=='C')
        {
            t1=st.top();st.pop();
            t2=st.top();st.pop();
            if(t1==1&&t2==0)st.push(0);
            else st.push(1);
        }
        else if(str[i]=='E')
        {
            t1=st.top();st.pop();
            t2=st.top();st.pop();
            st.push((t1==t2));
        }
    }
    if(st.top()==0)
      return 0;
    return 1;  
}
bool solve()
{
    for(p=0;p<2;p++)
      for(q=0;q<2;q++)
        for(r=0;r<2;r++)
           for(s=0;s<2;s++)
              for(t=0;t<2;t++)
              {
                  if(!judge())
                    return 0;
              }
    return 1;
}

int main()
{
    while(cin>>str)
    {
        if(strcmp(str,"0")==0)
          break;
        if(solve())
          cout<<"tautology"<<endl;
        else 
          cout<<"not"<<endl;
    }
}
