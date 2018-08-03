#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
  int a,b,c;
}f[30010];
bool cmp(node aa,node bb)
{
  return aa.b<bb.b;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,q;
      int tmp;
      cin>>n>>q;
      for(int i=1;i<=n;i++)
         cin>>f[i].a>>f[i].b>>f[i].c;
      sort(f+1,f+n+1,cmp);
      for(int j=0;j<q;j++)
      {
        cin>>tmp;
        for(int i=1;i<=n;i++)
        {
            if(tmp==f[i].a)
            {
              tmp=i;
              break;
            }
        }
        int dd=0;
        for(int i=tmp-1;i>=1;i--)
        {
            if(f[i].c<=f[tmp].c)
              dd++;
            else break;  
        }
        if(tmp==n)
        {
            cout<<"0 ";
        }
        else
        for(int i=tmp+1;i<=n;i++)
        {
           if(f[i].b>f[tmp].b&&f[i].c>=f[tmp].c)
           {
             cout<<f[i].a<<" ";
             break;
           }
        }
        cout<<dd<<endl;
      }
    }
}
