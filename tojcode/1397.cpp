#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
char chest[3][3];
int main()
{
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    
    getchar();
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        
        cin>>chest[i][j];
      }
       
    }
     
    int blacknum=0,whitenum=0;
    int blackwin=0,whitewin=0;
    bool yes=1;
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        if(chest[i][j]=='O')
          whitenum++;
        else if(chest[i][j]=='X')
          blacknum++;
      }
    }
    if((blacknum<whitenum)||(blacknum-whitenum>1))
      yes=0;
             bool &found=yes;//最后还是用了别人的枚举方法 
             int &x=blacknum;
             int &o=whitenum;
             int j,i;
                if(x==o)
                {
                   for(j=0;j<3;j++)
                   if((chest[j][0]=='X'&&chest[j][1]=='X'&&chest[j][2]=='X')||(chest[0][j]=='X'&&chest[1][j]=='X'&&chest[2][j]=='X'))
                   {
                       found=0;
                       break;
                   }
                   if((chest[0][0]=='X'&&chest[1][1]=='X'&&chest[2][2]=='X')||(chest[0][2]=='X'&&chest[1][1]=='X'&&chest[2][0]=='X'))
                   found=0;
                }
                else if(x==4&&o==3)
                {
                   for(j=0;j<3;j++)
                   if((chest[j][0]=='O'&&chest[j][1]=='O'&&chest[j][2]=='O')||(chest[0][j]=='O'&&chest[1][j]=='O'&&chest[2][j]=='O'))
                   {
                       found=0;
                       break;
                   }
                    if((chest[0][0]=='O'&&chest[1][1]=='O'&&chest[2][2]=='O')||(chest[0][2]=='O'&&chest[1][1]=='O'&&chest[2][0]=='O')) 
                    found=0;
                }
                for(i=0;i<3;i++)
                {
                   j=(i+1)%3;
                   if((chest[i][0]=='O'&&chest[i][1]=='O'&&chest[i][2]=='O'&&chest[j][0]=='X'&&chest[j][1]=='X'&&chest[j][2]=='X')||(chest[i][0]=='X'&&chest[i][1]=='X'&&chest[i][2]=='X'&&chest[j][0]=='O'&&chest[j][1]=='O'&&chest[j][2]=='O')
                   ||(chest[0][i]=='O'&&chest[1][i]=='O'&&chest[2][i]=='O'&&chest[0][j]=='X'&&chest[1][j]=='X'&&chest[2][j]=='X')||(chest[0][i]=='X'&&chest[1][i]=='X'&&chest[2][i]=='X'&&chest[0][j]=='O'&&chest[1][j]=='O'&&chest[2][j]=='O'))
                   {
                        found=0;
                        break;
                   }
                  
                }
            if(!yes)printf("no\n");
            else printf("yes\n");
         }
     }

                   
