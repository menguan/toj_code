#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
using namespace std;
char map[61][61];
int main()
{
    int r,c;
    cin>>r>>c;
    getchar();
    for(int i=0;i<r;i++)
    {
       gets(map[i]);     
    }
    char dir='n';
    int x,y;
    cin>>x>>y;x--;y--;
    getchar();
    char s[10000];bool flag=1;
    while(flag&&cin>>s)
    {
      for(int i=0;i<strlen(s);i++)
      {
              if(s[i]=='Q')
               {
                           flag=0;break;}
              if(s[i]=='R')
              {
                  if(dir=='n')
                  {
                    dir='e';
                    }
                    else if(dir=='e')
                    {
                         dir='s';
                         }
                         else if(dir=='s')
                         {
                              dir='w';
                              }
                              else if(dir=='w')
                              {
                                   dir='n';
                                   }
              }                                  
              else if(s[i]=='L')
              {
                  if(dir=='n')
                  {
                    dir='w';
                    }
                    else if(dir=='e')
                    {
                         dir='n';
                         }
                         else if(dir=='s')
                         {
                              dir='e';
                              }
                              else if(dir=='w')
                              {
                                   dir='ns';
                                   }
              }
              else if(s[i]=='F')
              {
                   if(dir=='n')
                   {
                      if(map[x-1][y]==' ')
                        x--;
                   }
                   else if(dir=='s')
                   {
                      if(map[x+1][y]==' ')
                        x++;
                   }
                   else if(dir=='w')
                   {
                      if(map[x][y-1]==' ')
                        y--;
                   }
                   else if(dir=='e')
                   {
                      if(map[x][y+1]==' ')
                        y++;
                   }
              }
              //cout<<x+1<<" "<<y+1<<" "<<(char)(dir-('a'-'A'))<<endl;
        }
      } 
      cout<<++x<<" "<<++y<<" "<<(char)(dir-('a'-'A'))<<endl;
      //system("pause");
}
                     
