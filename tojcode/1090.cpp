#include<iostream>
#include<string> 
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    bool wall[m+2][n];
    int kk[m+1];
    for(int i=0;i<m+1;i++)
        kk[i]=0;
    for(int i=0;i<n;i++)
    {
        wall[0][i]=1;
        wall[m+1][i]=1;
    }
    for(int i=1;i<m+1;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='0')
                wall[i][j]=0;
            else if(s[j]=='1')
                wall[i][j]=1;
        }            
        
    }
       
    for(int i=0;i<m+2;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(wall[i][j]==1&&i!=m+1)
            {
                for(int l=i+1;l<m+2;l++)
                {
                    
                    if(wall[l][j]==1)
                    {
                        kk[l-i-1]++;
                        
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<m+1;i++)
    {
        if(kk[i]!=0)
            cout<<i<<" "<<kk[i]<<endl;
    }
                                
    return 0;
                    
          
} 