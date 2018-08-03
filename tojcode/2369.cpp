#include<stdio.h>//x*y*n的复杂度都可以过 网上的

#include<math.h>

int x[1000],y[1000],R[1000],b[10000],z[1000][1000];

int main()

{

       int i,j,k,N,X,Y;

       while(scanf("%d%d%d",&X,&Y,&N)!=EOF)

       {

              for(i=0;i<=Y;i++)

                     for(j=0;j<=X;j++)

                            z[i][j]=0;//先把数组归零//

              for(i=0;i<N;i++)

                     scanf("%d%d%d%d",&x[i],&y[i],&R[i],&b[i]);

              k=0;

              for(k=0;k<N;k++)

              {

                     for(i=0;i<=Y;i++)

                            for(j=0;j<=X;j++)

                            {

                                   if((i-x[k])*(i-x[k])+(j-y[k])*(j-y[k])<=R[k]*R[k])//满足这个条件就输入对应的颜色，后面的可以覆盖前面的//

                                          z[j][i]=b[k];

                            }            

              }

              for(i=0;i<Y;i++)

              {

                     for(j=0;j<X;j++)

                            printf("%d",z[i][j]);//注意输出时不能够有空格//

                     printf("\n");

              }

       }

       return 0;

}

