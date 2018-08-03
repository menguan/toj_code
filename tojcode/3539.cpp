#include<iostream>
#include<cstring>
#include<map>
#include<set>
using namespace std;
int main()
{
    int n,m,k;
    int goods[50];
    set<int,greater<int> >mp,mp1;
    map<int,int>bag;
    while(cin>>n>>m)
    {
        cin>>k;
        for(int i=0;i<k;i++)
          cin>>goods[i];
        mp.clear();
        bag.clear();
        mp.insert(0);
        bag[0]=0;
        mp1=mp;
        int w;
        set<int,greater<int> >::iterator it;
        for(int i=0;i<k;i++)
        {
            it=mp.begin();
            while(it!=mp.end())
            {
                w=*it;
                if(w+goods[i]<=m&&bag[w]<n)
                {
                     mp1.insert(w+goods[i]);
                     bag[w+goods[i]]=bag[w]+1;
                }
                it++;
            }
            mp=mp1;
        }
        it=mp.begin();
        cout<<*it<<endl;
    }
}                                                       
