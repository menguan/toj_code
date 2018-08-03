#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
    int p;int num;
    friend bool operator<(node aa,node bb)
    {
        return aa.p<bb.p;
    }
    friend bool operator>(node aa,node bb)
    {
        return aa.p>bb.p;
    }
}now,next;
priority_queue<node> buy;
priority_queue<node,vector<node>,greater<node> > sel;
int main()
{
    int n,t;int x,y;int ask,bid,sto;
    cin>>t;
    char s1[10],s2[10];
    while(t--)
    {
        cin>>n;
        while(!buy.empty())buy.pop();
        while(!sel.empty())sel.pop();
        sto=-1;
        for(int i=0;i<n;i++)
        {
            cin>>s1>>x>>s2>>s2>>y;
            if(s1[0]=='b')
            {
                now.p=y;now.num=x;
                buy.push(now);
            }
            else
            {
                now.p=y;now.num=x;
                sel.push(now);
            }
            int tmp;
            while(!buy.empty())
            {
                now=buy.top();buy.pop();
                tmp=now.num;
                while(!sel.empty())
                {
                    next=sel.top();sel.pop();
                    if(next.p<=now.p&&now.num!=0)
                    {
                        sto=next.p;
                        if(next.num<=now.num)
                        {
                            now.num-=next.num;
                            next.num=0;
                        }
                        else
                        {
                            next.num-=now.num;
                            now.num=0;
                        }
                    }
                    if(next.num!=0)
                    {
                        sel.push(next);
                        break;
                    }
                }
                if(now.num!=0)
                    buy.push(now);
                if(now.num==tmp)
                    break;

            }
            if(!sel.empty())cout<<sel.top().p;
            else cout<<"-";
            cout<<" ";
            if(!buy.empty())cout<<buy.top().p;
            else cout<<"-";
            cout<<" ";
            if(sto!=-1)cout<<sto;
            else cout<<"-";
            cout<<endl;

        }
    }

}
