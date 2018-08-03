#include<stdio.h>

struct
{
    int x,y;
}a[200001];

int main()
{
    int N;
    while(scanf("%d",&N)&&N)
    {
        int i,s=0,o=0;
        for(i=0;i<N;i++)
         scanf("%d%d",&a[i].x,&a[i].y);
         int x=a[N/2].x,y=a[N/2].y;
         for(i=0;i<N;i++)
         {
             if((a[i].x>x&&a[i].y>y)||(a[i].x<x&&a[i].y<y))
                 s++;
             else if((a[i].x>x&&a[i].y<y)||(a[i].x<x&&a[i].y>y))
                 o++;
         }
         printf("%d %d\n",s,o);
    }
    return 0;
}