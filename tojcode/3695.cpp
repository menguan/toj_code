#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 1010
int sg[maxn][maxn];
int mex[maxn];
int step[maxn][maxn];
int k;
void init()
{
     int temp;
     for(int i=0;i<maxn;i++)
     {
         sg[i][0]=sg[0][i]=0;
         sg[i][1]=sg[1][i]=i;
         step[i][0]=step[0][i]=0;
         step[i][1]=step[1][i]=1;
     }
     for(int i=2;i<maxn;i++)
     {
        for(int j=i;j<maxn;j++)
        {
             step[i][j]=-1;
             mex[0]=0;
             temp=j-j/i*i;
             for(k=1;k<maxn;k++)
             {
                if(temp>=j)  break;
                mex[k]=sg[i][temp];
                if(mex[k]==0)
                {
                    step[i][j]=step[j][i]=step[i][temp]+1;
                }
                temp+=i;
             }
             if(step[i][j]==-1)
                 step[i][j]=step[j][i]=step[i][j-i]+1;
             sort(mex+1,mex+k);
             int minn=0;
             for(int l=1;l<k;l++)
             {
                if(minn>=mex[l])
                  minn=mex[l]+1;
             }
             sg[i][j]=sg[j][i]=minn;
        }
     }
} 
int main()
{
    int t;
    init();
    while(cin>>t)
    {
        int mm=0;         
        int gg=0;
        int p,q;
        for(int i=0;i<t;i++)
        {
            cin>>p>>q;
            if(sg[p][q]>0)
            {
                 mm=max(mm,step[p][q]);
            }
            else
            {
                 gg=max(gg,step[p][q]);
            }
        }
        if(mm>gg)
          cout<<"MM"<<endl;
        else
          cout<<"GG"<<endl;
    }
}  
                               
                
                               
                          
                                 
    
