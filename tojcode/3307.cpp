#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct zombie
{
      int v,d,id;
}zom[120];
bool cmp(zombie mm,zombie nn)
{
   return mm.v<nn.v;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {  
       bool flag=1;
       vector<int> vv;
       for(int i=0;i<n;i++)
       {
         cin>>zom[i].v>>zom[i].d;
         zom[i].id=i+1;
       }sort(zom,zom+n,cmp);
       int now=m;
       for(int i=0;i<n;i++)
       {
         if(now+zom[i].d>zom[i].v)
         {
            flag=0;
            break;
         }
         else
         {
           now+=m;
           vv.push_back(zom[i].id);
         }
       }
       if(!flag)
         cout<<"The zombies eat your brains!"<<endl;
       else
       {
           for(int i=0;i<n;i++)
           {
                if(i)
                 cout<<" ";
                cout<<vv[i];
                }
            cout<<endl;
       }
    }
}               
                                                      
