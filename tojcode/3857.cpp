#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
char a[100][100];
int main()
{
  int m,n;
  while(cin>>m>>n)
  {
    getchar();
    memset(a,'0',sizeof(a));
    for(int i=0;i<m;i++)
      gets(a[i]);
    
    int re=0;  
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(a[i][j]=='+')
        {  
           if((a[i][j]=='+'&&a[i][j+1]=='-'&&a[i][j+2]=='-'&&a[i][j+3]=='-'&&a[i][j+4]=='-'&&a[i][j+5]=='-'&&a[i][j+6]=='-'&&a[i][j+7]=='-'&&a[i][j+8]=='-'&&a[i][j+9]=='+')
             &&(a[i+1][j]=='|'&&a[i+1][j+1]==' '&&a[i+1][j+2]=='/'&&a[i+1][j+3]==' '&&a[i+1][j+4]==' '&&a[i+1][j+5]==' '&&a[i+1][j+6]==' '&&a[i+1][j+7]=='\\'&&a[i+1][j+8]==' '&&a[i+1][j+9]=='|')
             &&(a[i+2][j]=='|'&&a[i+2][j+1]=='/'&&a[i+2][j+2]==' '&&a[i+2][j+3]=='+'&&a[i+2][j+4]=='-'&&a[i+2][j+5]=='-'&&a[i+2][j+6]=='+'&&a[i+2][j+7]==' '&&a[i+2][j+8]=='\\'&&a[i+2][j+9]=='|')
             &&(a[i+3][j]=='|'&&a[i+3][j+1]==' '&&a[i+3][j+2]==' '&&a[i+3][j+3]=='|'&&a[i+3][j+4]==' '&&a[i+3][j+5]==' '&&a[i+3][j+6]=='|'&&a[i+3][j+7]==' '&&a[i+3][j+8]==' '&&a[i+3][j+9]=='|')
             &&(a[i+4][j]=='+'&&a[i+4][j+1]=='-'&&a[i+4][j+2]=='-'&&a[i+4][j+3]=='+'&&a[i+4][j+4]=='-'&&a[i+4][j+5]=='-'&&a[i+4][j+6]=='+'&&a[i+4][j+7]=='-'&&a[i+4][j+8]=='-'&&a[i+4][j+9]=='+'))
          {
            re++;
            continue;
          }
        }
      }
    }
    cout<<re<<endl;
  }
}                   
  