#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int in[30];
bool vis[30];
int go[30][30];
vector<char>ans;
int main()
{
    int n;char a,b;
    while(cin>>n)
    {
       memset(go,0,sizeof(go));
       memset(in,0,sizeof(in));          
       memset(vis,0,sizeof(vis));
       ans.clear();
       while(n--)
       {
           cin>>a>>b;
           in[b-'A']++;
           go[a-'A'][b-'A']=1;
           
       }
       
       while(1)
       {
         bool flag=1;
         for(int i=0;i<26;i++)
         {
            if(!vis[i]&&in[i]==0)
            {
               //cout<<(char)(i+'A')<<" "<<in[i]<<endl;
               vis[i]=1;
               flag=0;
               ans.push_back(i+'A');
               for(int j=0;j<26;j++)
               {
                  if(go[i][j]){//cout<<(char)(i+'A')<<" "<<(char)(j+'A')<<" "<<go[a-'A'][b-'A']<<endl;
                    in[j]--;}
               }
               break;
            }
         }
         if(flag)
           break;
       }
       //cout<<ans.size()<<endl;
       if(ans.size()<26)
         cout<<"Stupid Ant!";
       else
         for(int i=0;i<26;i++)
         {
            cout<<ans[i];
         }            
       cout<<endl;
    }
}  
                                         
