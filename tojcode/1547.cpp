#include<iostream>
#include<string>
using namespace std;
int main()
{
    int c;
    while(cin>>c,c)
    {
        string s;
        cin>>s;
        int l=s.length();
        int t=l/c;
        char ch[t][c];
        int ww=0,uu=0;
        for(int i=0;i<l;i++)
        {
            if((ww+1)%2==1)
            {
              ch[ww][uu]=s[i];
              uu++;
              if(uu==c)
              {
                uu-=1;
                ww++;
              }  
            }
            else
            {
              ch[ww][uu]=s[i];
              uu--;
              if(uu==-1)
              {
                uu+=1;
                ww++;
              }  
            }   
        }
        
        for(int i=0;i<c;i++)
        {
          for(int j=0;j<t;j++)
          {
            cout<<ch[j][i];
          }  
        }
        cout<<endl;
    }
    
    return 0;
} 