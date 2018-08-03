#include<iostream>
#include<cstring>

using namespace std;
int board[21][21];
void f(int &wini,int &winj,int i,int j)
{
    if(j<winj)
    {    wini=i;
         winj=j;
    }
}             
int main()
{
    int t;
    memset(board,0,sizeof(board));
    cin>>t;
    while(t--)
    {
        
        bool blackwin=0;
        bool whitewin=0;
        bool blackcon=0;
        bool whitecon=0;
        int wini=20,winj=20;
        for(int i=1;i<20;i++)
        {
            for(int j=1;j<20;j++)
            {
                cin>>board[i][j];
            }
        }
        
        for(int i=1;i<20;i++)
        {
            for(int j=1;j<20;j++)
            {
                if(board[i][j]==1)
                {
                    
                    int con=1;bool e1=0,e2=0;
                    for(int k=1;;k++)
                    {
                        
                        if(e1==0)
                        {    if(board[i][j-k]==1)con++;
                        else
                        e1=1;
                        }     
                        if(e2==0)
                        {    if(board[i][j+k]==1)con++;
                        else
                        e2=1;
                        }
                        if(e1==1&&e2==1)
                        {
                           if(con==5)                                                         
                           {  blackwin=1;
                              
                              f(wini,winj,i,j); 	con=1;break;}
                           
                             
                           else
                           {  con=1;  break;}
                                                         
                        } 
                    }e1=0,e2=0;                
                    for(int k=1;;k++)
                    {
                        
                        if(e1==0)
                        {    if(board[i-k][j]==1)con++;
                        else
                        e1=1;
                        }     
                        if(e2==0)
                        {    if(board[i+k][j]==1)con++;
                        else
                        e2=1;
                        }
                        if(e1==1&&e2==1)
                        {
                           if(con==5)                                                         
                           {  blackwin=1;
                           f(wini,winj,i,j); con=1;break;}
                           
                             
                           else
                           {  con=1;  break;}
                                                         
                        } 
                    }e1=0,e2=0; 
                    for(int k=1;;k++)
                    {
                        
                        if(e1==0)
                        {    if(board[i-k][j-k]==1)con++;
                        else
                        e1=1;
                        }     
                        if(e2==0)
                        {    if(board[i+k][j+k]==1)con++;
                        else
                        e2=1;
                        }
                        if(e1==1&&e2==1)
                        {
                           
                           if(con==5)                                                         
                           {  blackwin=1;
                           
                           f(wini,winj,i,j);con=1; break;}
                           
                           
                             else
                           {  con=1;  break;}
                                                         
                        } 
                    }e1=0,e2=0;
                    for(int k=1;;k++)
                    {
                        
                        if(e1==0)
                        {    if(board[i-k][j+k]==1)con++;
                        else
                        e1=1;
                        }     
                        if(e2==0)
                        {    if(board[i+k][j-k]==1)con++;
                        else
                        e2=1;
                        }
                        if(e1==1&&e2==1)
                        {
                           if(con==5)                                                         
                           {  blackwin=1;
                           f(wini,winj,i,j); con=1;break;}
                           
                           else
                           {  con=1;  break;}
                                                         
                        } 
                    }
                }
              }
            }                       
            for(int i=1;i<20;i++)
        {
            for(int j=1;j<20;j++)
            {
                if(board[i][j]==2)
                {
                    
                    int con=1;bool e1=0,e2=0;
                    for(int k=1;;k++)
                    {
                        
                        if(e1==0)
                        {    if(board[i][j-k]==2)con++;
                        else
                        e1=1;
                        }     
                        if(e2==0)
                        {    if(board[i][j+k]==2)con++;
                        else
                        e2=1;
                        }
                        if(e1==1&&e2==1)
                        {
                           if(con==5)                                                         
                           {  whitewin=1;
                           f(wini,winj,i,j);con=1; break;}
                           
                           else
                           {  con=1;  break;}
                                                         
                        } 
                    }e1=0,e2=0;                
                    for(int k=1;;k++)
                    {
                        
                        if(e1==0)
                        {    if(board[i-k][j]==2)con++;
                        else
                        e1=1;
                        }     
                        if(e2==0)
                        {    if(board[i+k][j]==2)con++;
                        else
                        e2=1;
                        }
                        if(e1==1&&e2==1)
                        {
                           if(con==5)                                                         
                           {  whitewin=1;
                           f(wini,winj,i,j);con=1; break;}
                           
                           else
                           {  con=1;  break;}
                                                         
                        } 
                    }e1=0,e2=0; 
                    for(int k=1;;k++)
                    {
                        
                        if(e1==0)
                        {    if(board[i-k][j-k]==2)con++;
                        else
                        e1=1;
                        }     
                        if(e2==0)
                        {    if(board[i+k][j+k]==2)con++;
                        else
                        e2=1;
                        }
                        if(e1==1&&e2==1)
                        {
                           if(con==5)                                                         
                           {  whitewin=1;
                           f(wini,winj,i,j);con=1; break;}
                           
                           
                             else
                           {  con=1;  break;}
                                                         
                        } 
                    }e1=0,e2=0;
                    for(int k=1;;k++)
                    {
                        
                        if(e1==0)
                        {    if(board[i-k][j+k]==2)con++;
                        else
                        e1=1;
                        }     
                        if(e2==0)
                        {    if(board[i+k][j-k]==2)con++;
                        else
                        e2=1;
                        }
                        if(e1==1&&e2==1)
                        {
                           if(con==5)                                                         
                           {  whitewin=1; 
                           f(wini,winj,i,j);con=1;break;}
                           
                           else
                           {  con=1;  break;}
                                                         
                        } 
                    }
                }
              }
            } 
                 
            if(blackwin==1&&blackcon==0)
            {   cout<<1<<endl;
                cout<<wini<<" "<<winj<<endl;}          
            else if(whitewin==1&&whitecon==0)
            {   cout<<2<<endl;
                cout<<wini<<" "<<winj<<endl;}
            else
               cout<<0<<endl;    
        }
        
        return 0;
}  