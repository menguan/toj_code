#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int city[50010];
int main()
{
	int mid,ncases,n,i;
	//scanf("%d",&ncases);
	//while(ncases--)
	//{
		scanf("%d",&n);
		for(i=2; i<=n; i++)
			scanf("%d",&city[i]);
		city[1] = 0;
		mid = -1;
		int minn =1010101010;
		for(i=n-2; i>1; i--)
			if( city[n] - city[i] + city[i+1] - city[1] < minn )
			{
				minn = city[n] - city[i] + city[i+1] - city[1];
				mid = i;
			}
		if( mid == -1 || n <= 3 )
			printf("0\n\n");
		else
			printf("%d\n%d %d %d %d\n",minn,mid+1,1,n,mid);
	//}
    // while(1);
}
