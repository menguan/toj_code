#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int map[50][50][50];
//int temp[50][50][50];
int main()
{
    int n;int st;bool gg=0;
    while(cin>>n,n)
    {
       if(gg)  cout<<endl<<endl;
       gg=1;
       memset(map,0,sizeof(map));
       for(int i=0,j=0;i<n;)
       {
           cin>>st;
           if(st==0)
           {  i++;
             j=0;}
           else
           {
               for(int k=0;k<st;k++)
                 map[i][j][k]=1;
               j++;
           }
       }
       for(int i=0;i<50;i++)
       {
           for(int j=0;j<50;j++)
           {
              st=0;
              for(int k=0;k<50;k++)
              {
                   if(map[j][k][i]==1)
                     st++;
              }
              if(st==0&&j==0)
              {
                 i=50;
                 break;
              }
              if(st==0)
                break;
              if(j!=0)
                cout<<" ";
              cout<<st;
           }
           if(i!=50)
             cout<<endl;
       }
       cout<<endl;
       for(int i=0;i<50;i++)
       {
           for(int j=0;j<50;j++)
           {
              st=0;
              for(int k=0;k<50;k++)
              {
                   if(map[k][i][j]==1)
                     st++;
              }
              if(st==0&&j==0)
              {
                 i=50;
                 break;
              }
              if(st==0)
                break;
              if(j!=0)
                cout<<" ";
              cout<<st;
           }
           if(i!=50)
             cout<<endl;
       }
                                   
                 
      
                                       
               
    }
}         
                
                 
