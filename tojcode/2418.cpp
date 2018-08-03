#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int t;
int a[110][110];
int x,y;
int hang[110];
int lie[110];
int sumh[110];
int suml[110];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&y,&x);
        memset(hang,0,sizeof(hang));
        memset(lie,0,sizeof(lie));
        memset(sumh,0,sizeof(sumh));
        memset(suml,0,sizeof(suml));
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                scanf("%d",&a[i][j]);
                sumh[i]+=a[i][j];
                suml[j]+=a[i][j];
            }
        }
        //for(int i=1;i<=y;i++)
           // cout<<suml[i]<<endl;

        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=x;j++)
            {
                if(j==i) continue;

                    hang[i]+=sumh[j]*abs(i-j);

            }
           // cout<<"行 "<<i<<" "<<hang[i]<<endl;
        }
        for(int i=1;i<=y;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(j==i) continue;
                lie[i]+=suml[j]*abs(i-j);
            }
            //cout<<"列 "<<i<<" "<<lie[i]<<endl;
        }
        int ans=1010101010;
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                int tmp=hang[i]+lie[j];
                ans=min(tmp,ans);
            }
        }
        printf("%d blocks\n",ans);
    }
}
