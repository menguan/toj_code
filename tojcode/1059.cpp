#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
string s;
int out[30];
int in[30];
int odd;
int n;
bool vis[30];
int id[30];
int find(int p)
{
    while(p!=id[p])
      p=id[p];
    return p;
}  
                   
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=0;i<30;i++) id[i]=i;
        memset(vis,0,sizeof(vis));
        cin>>n;
        while(n--)
        {
           cin>>s;
           int len=s.length();
           int x=s[0]-'a';
           int y=s[len-1]-'a';
           in[x]++;
           out[y]++;
           id[x]=id[y]=find(x);
           vis[x]=vis[y]=1;
        }
        
        bool flag=1;bool st=0,en=0;
        int count=0;
        for(int i=0;i<30;i++)
        {
            if(vis[i]&&id[i]==i)
              count++;
        }
        if(count>1)  flag=0;          
        for(int i=0;i<30;i++)
        {
            if(flag==0)
              break;
            if(in[i]==out[i])
              continue;
            else if(abs(in[i]-out[i])>1)
            {flag=0;break;}
            else 
            {
                 if(in[i]-out[i]==1)
                 {
                    if(st==0)
                      st=1;
                    else
                    {flag=0;break;};
                 }
                 else
                 {
                     if(en==0)
                       en=1;
                     else
                     {flag=0;break;};
                 }
            }
        }
        if(flag)
        cout<<"Ordering is possible."<<endl;
        else
        cout<<"The door cannot be opened."<<endl;
    }
} 

                    
                             
                                           
            
                                     
              
