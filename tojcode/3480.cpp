#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> v[110000];
int in[110000],topno[110000];
int main()
{
    int n,m1,m2,i,j,t1,t2;
    while(cin>>n>>m1>>m2){
    memset(in,0,sizeof(in));
    for (i=0; i<m1; i++)
    {
        cin>>t1>>t2;
        in[t2]++;
        v[t1].push_back(t2);
    }
    t2=0;
    t1=1;
    while (t2 != n)
    {
        for (i=1; i<=n; i++)
        {
            if (in[i] == 0)
            {
                for (j=0; j<v[i].size(); j++)
                {
                    in[v[i][j]]--;
                }
                t2++;
                in[i]=-1;
                topno[i]=t1;
                t1++;
            }
        }
    }
    for (i=0; i<m2; i++)
    {
        cin>>t1>>t2;
        if (topno[t1] > topno[t2])
            cout<<t2<<" "<<t1<<endl;
        else
            cout<<t1<<" "<<t2<<endl;
    }
    }
}
