#include<iostream>
#include<cstring>

using namespace std;
bool food[30][30];
char move[200];
bool map[30][30];
struct snake
{
  int x,y;
}s[500];  
int main()
{
  int n,w,h,xx,yy;
  while(cin>>n>>w>>h>>xx>>yy&&(n+w+h+xx+yy))
  {
    memset(food,0,sizeof(food));
    memset(map,0,sizeof(map));
    int slen=1;
    s[slen].x=xx-1;
    s[slen].y=yy-1;
    map[xx-1][yy-1]=1;
    while(n--)
    {
      cin>>xx>>yy;
      food[xx-1][yy-1]=1;
    }
    cin>>move;
    int i;
    bool crash=0;
    int tempx,tempy;
    for(i=0;i<strlen(move);i++)
    {
        /*for(int m=0;m<h;m++)
        {
          for(int n=0;n<w;n++)
          {
            
            if(food[m][n])
              cout<<'*';else if(map[m][n])
              cout<<1;
            else
              cout<<0;
          }
          cout<<endl;
        }
        cout<<slen<<endl;
        system("pause");
        system("cls"); */         
        if(move[i]=='L')
        {
          if(s[1].y==0)
          {
            crash=1;
              break;
          }
              
          else if(food[s[1].x][s[1].y-1])
          {
            food[s[1].x][s[1].y-1]=0;
            slen++;
            for(int j=slen;j>1;j--)
            {
              s[j].x=s[j-1].x;
              s[j].y=s[j-1].y;
            }
            s[1].y--;
            
          }
          else
          {
            map[s[slen].x][s[slen].y]=0;
            for(int j=slen;j>1;j--)
            {
              s[j].x=s[j-1].x;
              s[j].y=s[j-1].y;
            }
            s[1].y--;
          }  
                 
          if(map[s[1].x][s[1].y])
          {
            crash=1;
              break;
          }
          map[s[1].x][s[1].y]=1;
        }              
        if(move[i]=='R')
        {
          if(s[1].y==w-1)
          {
            crash=1;
              break;
          }
              
          else if(food[s[1].x][s[1].y+1])
          {
            food[s[1].x][s[1].y+1]=0;
            slen++;
            for(int j=slen;j>1;j--)
            {
              s[j].x=s[j-1].x;
              s[j].y=s[j-1].y;
            }
            s[1].y++;
            
          }
          else
          {
            map[s[slen].x][s[slen].y]=0;
            for(int j=slen;j>1;j--)
            {
              s[j].x=s[j-1].x;
              s[j].y=s[j-1].y;
            }
            s[1].y++;
          }  
                 
          if(map[s[1].x][s[1].y])
          {
            crash=1;
              break;
          }
          map[s[1].x][s[1].y]=1;
        } 
        if(move[i]=='U')
        {
          if(s[1].x==0)
          {
            crash=1;
              break;
          }
              
          else if(food[s[1].x-1][s[1].y])
          {
            food[s[1].x-1][s[1].y]=0;
            slen++;
            for(int j=slen;j>1;j--)
            {
              s[j].x=s[j-1].x;
              s[j].y=s[j-1].y;
            }
            s[1].x--;
            
          }
          else
          {
            map[s[slen].x][s[slen].y]=0;
            for(int j=slen;j>1;j--)
            {
              s[j].x=s[j-1].x;
              s[j].y=s[j-1].y;
            }
            s[1].x--;
          }  
                 
          if(map[s[1].x][s[1].y])
          {
            crash=1;
              break;
          }
          map[s[1].x][s[1].y]=1;
        } 
        if(move[i]=='D')
        {
          if(s[1].x==h-1)
          {
            crash=1;
              break;
          }
              
          else if(food[s[1].x+1][s[1].y])
          {
            food[s[1].x+1][s[1].y]=0;
            slen++;
            for(int j=slen;j>1;j--)
            {
              s[j].x=s[j-1].x;
              s[j].y=s[j-1].y;
            }
            s[1].x++;
            
          }
          else
          {
            map[s[slen].x][s[slen].y]=0;
            for(int j=slen;j>1;j--)
            {
              s[j].x=s[j-1].x;
              s[j].y=s[j-1].y;
            }
            s[1].x++;
          }  
                 
          if(map[s[1].x][s[1].y])
          {
            crash=1;
              break;
          }
          map[s[1].x][s[1].y]=1;
        } 
    }
    if(crash)
    {
      cout<<"The snake crash itself after "<<i+1<<" operations."<<endl;
    }
    else
      cout<<"The snake is "<<slen<<" unit long after A's operation."<<endl;
    }
}        
    