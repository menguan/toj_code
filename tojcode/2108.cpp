#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int ans[ 1201 ];
int bit[ 10 ];

void countbit( int f, int v )
{
	if ( !f ) {
		while ( v ) {
			bit[v%10] ++;
			v /= 10;
		}	
	}else {
		for ( int i = 0 ; i < 4 ; ++ i ) {
			bit[v%10] ++;
			v /= 10;
		}
	}
}

int main()
{
	int N;
	while ( scanf("%d",&N) && N ) {
		memset( ans, 0, sizeof(ans) );
		memset( bit, 0, sizeof(bit) );
		ans[0] = 1;
		for ( int i = 2 ; i <= N ; ++ i ) {
			for ( int j = 0 ; j < 200 ; ++ j )
				ans[j] *= i;
			for ( int j = 0 ; j < 200 ; ++ j )
				if ( ans[j] >= 10000 ) {
					ans[j+1] += ans[j]/10000;
					ans[ j ] %= 10000;
				}
		}
		
		int end = 200;
		while ( end > 0 && !ans[end] ) -- end;
		countbit( 0, ans[end --] );
		while ( end >= 0 ) 
			countbit( 1, ans[end --] );
		
		printf("%d! --\n",N);
		for ( int i = 0 ; i < 10 ; ++ i ) {
			printf("   (%d)%5d",i,bit[i]);
			if ( i%5 == 4 ) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
