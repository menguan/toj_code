#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int dir[8][2]={-1,-2,1,-2,-2,-1,2,-1,-2,1,2,1,-1,2,1,2};
struct f
{
         int x;int y;
};
bool flag=0; bool used[100][100];char ans[10000];
int r ,c;
int dfs(int m,int n,int step)
{
    
    if(step==r*c)
      return 1;
    for(int i=0;i<8;i++)
    {
            int mm=m+dir[i][0];
            int nn=n+dir[i][1];
            if (mm>r||mm<1||nn>c||nn<1||used[mm][nn]==1)
              continue;
            used[mm][nn]=1;
            ans[step*2]=nn+'A'-1;
            ans[step*2+1]=mm+'0';
            if(dfs(mm,nn,step+1)) return 1;
              used[mm][nn]=0; 
    }
    
    return 0;
}
int main()
{
      int t;
      
      cin>>t;
      for(int i=1;i<=t;i++)
      {
         cin>>r>>c;
         cout<<"Scenario #"<<i<<":"<<endl;
         memset(used,0,sizeof(used));
         used[1][1]=1;
         memset(ans,0,sizeof(ans));
         ans[0]='A';
         ans[1]='1';
         
       if(dfs(1,1,1))
         {
            cout<<ans<<endl<<endl;   
         }
         else
         cout<<"impossible"<<endl<<endl;
       
      }
} 
                                                         
                  
