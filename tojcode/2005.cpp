/*
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int n,m;int ans;int knum,pnum,qnum;
bool vis[1010][1010];
int map[1010][1010];int px,py;
int dir[8][2]={2,1,1,2,-2,1,2,-1,-1,-2,-2,-1,1,-2,-1,2};
struct q
{
       int x,y;
}q[1010];
struct k
{
   int x,y;
}k[1010];
int main()
{
    int cas=1;
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
       memset(vis,0,sizeof(vis));
       memset(map,0,sizeof(map));
       memset(q,0,sizeof(q));
       memset(k,0,sizeof(k));
       ans=n*m;
       scanf("%d",&qnum);
       for(int i=0;i<qnum;i++)
       {
         scanf("%d%d",&q[i].x,&q[i].y);
         map[q[i].x][q[i].y]=1;
         vis[q[i].x][q[i].y]=1;
         ans--;
       }
       scanf("%d",&knum);
       for(int i=0;i<knum;i++)
       {
         scanf("%d%d",&k[i].x,&k[i].y);
         map[k[i].x][k[i].y]=1;
         vis[k[i].x][k[i].y]=1;
         ans--;
       }
       scanf("%d",&pnum);
       for(int i=0;i<pnum;i++)
       {
          scanf("%d%d",&px,&py);
          map[px][py]=1;
          vis[px][py]=1;
          ans--;
       }
       //cout<<ans<<endl;
       for(int i=0;i<qnum;i++)
       {
          for(int j=q[i].x+1,l=q[i].y+1;j<=n&&l<=m;j++,l++)
          {
              if(map[j][l]==1)
                break;
              if(!vis[j][l])
              {
                vis[j][l]=1;
                ans--;
              }
          }                  
          for(int j=q[i].x-1,l=q[i].y+1;j>=1&&l<=m;j--,l++)
          {
              if(map[j][l]==1)
                break;
              if(!vis[j][l])
              {
                vis[j][l]=1;
                ans--;
              }
          } 
          for(int j=q[i].x+1,l=q[i].y-1;j<=n&&l>=1;j++,l--)
          {
              if(map[j][l]==1)
                break;
              if(!vis[j][l])
              {
                vis[j][l]=1;
                ans--;
              }
          } 
          for(int j=q[i].x-1,l=q[i].y-1;j>=1&&l>=1;j--,l--)
          {
              if(map[j][l]==1)
                break;
              if(!vis[j][l])
              {
                vis[j][l]=1;
                ans--;
              }
          } 
          for(int j=q[i].x,l=q[i].y+1;l<=m;l++)
          {
              if(map[j][l]==1)
                break;
              if(!vis[j][l])
              {
                vis[j][l]=1;
                ans--;
              }
          } 
          for(int j=q[i].x+1,l=q[i].y;j<=n;j++)
          {
              if(map[j][l]==1)
                break;
              if(!vis[j][l])
              {
                vis[j][l]=1;
                ans--;
              }
          }                   
          for(int j=q[i].x-1,l=q[i].y;j>=1;j--)
          {
              if(map[j][l]==1)
                break;
              if(!vis[j][l])
              {
                vis[j][l]=1;
                ans--;
              }
          } 
          for(int j=q[i].x,l=q[i].y-1;l>=1;l--)
          {
              if(map[j][l]==1)
                break;
              if(!vis[j][l])
              {
                vis[j][l]=1;
                ans--;
              }
          }
       }
       for(int i=0;i<pnum;i++)
       {
          for(int j=0;j<8;j++)
          {
              px=k[i].x+dir[j][0];
              py=k[i].y+dir[j][1];
              if(px>n||py>m||px<1||py<1)
                continue;
              if(map[px][py])  continue;
              if(!vis[px][py])
              {
                vis[px][py]=1;
                ans--;
              }                  
          }
       }                   
       cout<<"Board "<<cas++<<" has "<<ans<<" safe squares."<<endl;
    }
}
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int v[1500][1500];
int b[1500][1500];
int kdr[8]={-1,-1,1,1,2,2,-2,-2};
int kdc[8]={-2,2,-2,2,1,-1,1,-1};
int qdr[8]={-1,-1,-1,1,1,1,0,0};
int qdc[8]={-1,1,0,-1,1,0,1,-1};
int qr[150];
int qc[150];
int kr[150];
int kc[150];
int pr[150];
int pc[150];
int main()
{
    int r,c,q,k,p;
    int bb=1;
    while(cin>>r>>c)
    {
        if(r==0&&c==0)break;
        for(int i=0;i<1500;i++)
        for(int j=0;j<1500;j++)
        {
                v[i][j]=0;
                b[i][j]=0;
        }
        cin>>q;
        for(int i=0;i<q;i++)  
        { 
            cin>>qr[i]>>qc[i]; 
            b[qr[i]][qc[i]]= 1; 
            v[qr[i]][qc[i]]= 1; 
        }
        cin>>k;
        for(int i=0;i<k;i++) 
        {  
            cin>>kr[i]>>kc[i]; 
            v[kr[i]][kc[i]]= 1; 
            b[kr[i]][kc[i]]= 1; 
        } 
        cin>>p;
        for(int i=0;i<p;i++)   
        {  
            cin>>pr[i]>>pc[i]; 
            b[pr[i]][pc[i]]= 1; 
            v[pr[i]][pc[i]]= 1; 
        }
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<8;j++)
            {   
                int x=kr[i]+kdr[j];
                int y=kc[i]+kdc[j];  
                if(x>r||x<=0||y>c||y<=0)continue;
                v[x][y]=1;           
            }
        }
        for(int i=0;i<q;i++)
        {
            for(int j=0;j<8;j++)
            {
                int kk=1;
                while(1)
                {
                    int x=qr[i]+qdr[j]*kk;
                    int y=qc[i]+qdc[j]*kk;
                    if(x<=0||x>r||y<=0||y>c)break;
                    if(b[x][y])break;
                    v[x][y]=1;
                    kk++;
                }
            }
        }
        int n=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                      if(v[i][j]==0)n++;
            }
        }
        cout<<"Board "<<bb<<" has "<<n<<" safe squares."<<endl;
        bb++;
    }
    return 0;
}
