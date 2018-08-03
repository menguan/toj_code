/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaa                 aaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaa  aaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaa   aaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaa   aaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaa   aaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaa    aaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaa   aaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaa   aaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaa                aaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
#include<iostream>
#include<string.h>
#include<cmath>
#include<stdio.h>
using namespace std;

int n,m,cas;

char a[40][50];

int loc(char t[])
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(strcmp(t,a[i])==0)
        {
            return i;
        }
    }
}

void floyd(double b[][50])
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                if(b[j][k]<b[j][i]+b[i][k])
                {
                    b[j][k]=b[j][i]+b[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
      if(pow(10,b[i][i])>1)
      {
        cout<<"Case "<<cas<<": Yes"<<endl;
        return;
      }
    }      
    cout<<"Case "<<cas<<": No"<<endl;
}

int main()
{
    int i,j;cas=0;
    char c[50],d[50];
    double w;
    while(cin>>n,n!=0)
    {
        double b[50][50]={0};
        cas++;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        cin>>m;
        for(i=1;i<=m;i++)
        {
            cin>>c>>w>>d;
            b[loc(c)][loc(d)]=log10(w);
        }
        floyd(b);
    }
    return 0;
} 
