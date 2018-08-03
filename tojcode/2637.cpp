#include<iostream>
using namespace std;
int result;
int _a,_b;
char map[21][21]={'\0'};
void f(int a,int b)
{
    if(a>=0&&b>=0&&a<_b&&b<_a&&(map[a][b]=='.'||map[a][b]=='@'))
    {
        result++;
        map[a][b]='#';
        f(a+1,b);
        f(a-1,b);
        f(a,b+1);
        f(a,b-1);
    }
    else
     return ;
}
int main()
{
   
   while(cin>>_a>>_b)
   {
     if(!_a&&!_b)
       return 0;
        
     result=0;
     for(int i=0;i<_b;i++)
     {
       for(int j=0;j<_a;j++)
       {
         cin>>map[i][j];
       }  
     }
     
     for(int i=0;i<_b;i++)
     {
       for(int j=0;j<_a;j++)
       {
         if(map[i][j]=='@')
         f(i,j);
       }
     }
     
     cout<<result<<endl;
   }
   
   return 0;
}  