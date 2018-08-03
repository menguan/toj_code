#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a,b,c;
    kk:while(cin>>a>>b>>c)
    {
      if(a==0&&b==0&&c==0)
        return 0;
      
      char map[a][b];
      bool m[a][b];
      bool n[a][b];
      string s;
      for(int i=0;i<a;i++)
      {
          cin>>s;
          for(int j=0;j<b;j++)
          {map[i][j]=s[j];
           m[i][j]=0;
           n[i][j]=0;
          }  
      }      
      int step=0;
      int loop=1000000;
      int heng=0;
      int shu=c-1;
      m[heng][shu]=1;
      
      while(1)
      {
          while(map[heng][shu]=='W')
          {
              shu--;
              step++;
              
              if(shu<0)
              {
                cout<<step<<" step(s) to exit"<<endl;
                goto kk;
              }  
              
              
                  if(m[heng][shu]==1&&n[heng][shu]==0)
                  {
                      n[heng][shu]=1;
                      if(loop>step)
                      loop=step;
                  }    
                      
                  else if(m[heng][shu]==1&&n[heng][shu]==1)
                  {
                      cout<<2*loop-step<<" step(s) before a loop of "<<step-loop<<" step(s)"<<endl;
                      goto kk;
                  }
               
               m[heng][shu]=1;
           }    
          while(map[heng][shu]=='E')
          {
              shu++;
              step++;
              
              if(shu>b-1)
              {
                cout<<step<<" step(s) to exit"<<endl;
                goto kk;
              }  
              
                  if(m[heng][shu]==1&&n[heng][shu]==0)
                  {
                      n[heng][shu]=1;
                      if(loop>step)
                      loop=step;
                  }    
                      
                  else if(m[heng][shu]==1&&n[heng][shu]==1)
                  {
                      cout<<2*loop-step<<" step(s) before a loop of "<<step-loop<<" step(s)"<<endl;
                      goto kk;
                  }
               
               m[heng][shu]=1;
           }    
           while(map[heng][shu]=='N')
          {
              heng--;
              step++;
              
              if(heng<0)
              {
                cout<<step<<" step(s) to exit"<<endl;
                goto kk;
              }  
              
                  if(m[heng][shu]==1&&n[heng][shu]==0)
                  {
                      n[heng][shu]=1;
                      if(loop>step)
                      loop=step;
                  }    
                      
                  else if(m[heng][shu]==1&&n[heng][shu]==1)
                  {
                      cout<<2*loop-step<<" step(s) before a loop of "<<step-loop<<" step(s)"<<endl;
                     goto kk;
                  }
               
               m[heng][shu]=1;
           }    
           while(map[heng][shu]=='S')
          {
              heng++;
              step++;
              
              
              if(heng>a-1)
              {
                cout<<step<<" step(s) to exit"<<endl;
                goto kk;
              }  
              
                  if(m[heng][shu]==1&&n[heng][shu]==0)
                  {
                      n[heng][shu]=1;
                      if(loop>step)
                      loop=step;
                  }    
                      
                  else if(m[heng][shu]==1&&n[heng][shu]==1)
                  {
                      cout<<2*loop-step<<" step(s) before a loop of "<<step-loop<<" step(s)"<<endl;
                    
                    goto kk;
                 }
               
               m[heng][shu]=1;
           }                    
             
        }
    }
    return 0;
}