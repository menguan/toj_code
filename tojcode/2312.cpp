#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctype.h>
using namespace std;
char map[20][40];
struct black
{
    char lei;
    char c;
    int r;
}b[50];       
struct white
{
    char lei;
    char c;
    int r;
}w[50];
bool cmpw(white m,white n)
{
   if(m.lei==n.lei)
   {
       if(m.r==n.r)
         return m.c<n.c;
       return m.r<n.r;
   }                  
   if(m.lei=='K'&&n.lei!='K')
     return 1;
   if(m.lei!='K'&&n.lei=='K')
     return 0;
   if(m.lei=='Q'&&n.lei!='Q')
     return 1;
   if(m.lei!='Q'&&n.lei=='Q')
     return 0;
   if(m.lei=='R'&&n.lei!='R')
     return 1;
   if(m.lei!='R'&&n.lei=='R')
     return 0; 
   if(m.lei=='B'&&n.lei!='B')
     return 1;
   if(m.lei!='B'&&n.lei=='B')
     return 0;  
   if(m.lei=='N'&&n.lei!='N')
     return 1;
   if(m.lei!='N'&&n.lei=='N')
     return 0;
} 
bool cmpb(black m,black n)
{
   if(m.lei==n.lei)
   {
       if(m.r==n.r)
         return m.c<n.c;
       return m.r>n.r;
   }                  
   if(m.lei=='K'&&n.lei!='K')
     return 1;
   if(m.lei!='K'&&n.lei=='K')
     return 0;
   if(m.lei=='Q'&&n.lei!='Q')
     return 1;
   if(m.lei!='Q'&&n.lei=='Q')
     return 0;
   if(m.lei=='R'&&n.lei!='R')
     return 1;
   if(m.lei!='R'&&n.lei=='R')
     return 0; 
   if(m.lei=='B'&&n.lei!='B')
     return 1;
   if(m.lei!='B'&&n.lei=='B')
     return 0;  
   if(m.lei=='N'&&n.lei!='N')
     return 1;
   if(m.lei!='N'&&n.lei=='N')
     return 0;
}           
int main()
{
    int bnum=0;int wnum=0;
    for(int i=0;i<17;i++)
      cin>>map[i];
    for(int i=0;i<17;i++)
    {
      for(int j=2;j<33;j+=4)
      {
         if(isupper(map[i][j]))
         {
            w[wnum].lei=map[i][j];
            if(w[wnum].lei=='P')
              w[wnum].lei='*';          
            w[wnum].r=9-(i+1)/2;
            w[wnum].c=(j-2)/4+'a';
            wnum++;
         }
         else if(islower(map[i][j]))
         {
            b[bnum].lei=toupper(map[i][j]);
            if(b[bnum].lei=='P')
              b[bnum].lei='*';          
            b[bnum].r=9-(i+1)/2;
            b[bnum].c=(j-2)/4+'a';
            bnum++;
         }
      }
    }
    sort(w,w+wnum,cmpw);
    sort(b,b+bnum,cmpb);
    cout<<"White: ";
    for(int i=0;i<wnum;i++)
    {
       if(i)
         cout<<",";
       if(w[i].lei!='*')cout<<w[i].lei; 
       cout<<w[i].c<<w[i].r;
    }
    cout<<endl;
    cout<<"Black: ";
    for(int i=0;i<bnum;i++)
    {
       if(i)
         cout<<",";
       if(b[i].lei!='*')cout<<b[i].lei; 
       cout<<b[i].c<<b[i].r;
    }
    cout<<endl;
    //while(1);
}         
    
                                  
              
                  
