#include<iostream>
#include<cstring>
using namespace std;
char s[30];
int vis[30];
int num[30];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       cin>>s;
       memset(vis,0,sizeof(vis));
       memset(num,0,sizeof(num));
       for(int i=0;i<26;i++)
       {
           if(vis[i]==0)
           {
              int j=0;
              int k=i;
              while(s[k]-'A'!=i)
              {
                 j++;
                 vis[s[k]-'A']=1;
                 k=s[k]-'A';
              }
              num[j+1]++;
              vis[i]=1;
           }
       }
       bool flag=1;
       for(int i=2;i<=26;i+=2)
       {
           //cout<<i<<" "<<num[i]<<endl;
           if(num[i]&1)
             flag=0;
       }
       if(flag)
         cout<<"Yes"<<endl;
       else 
         cout<<"No"<<endl;
    }
}                                      
                      
