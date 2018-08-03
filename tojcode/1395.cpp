#include<stdio.h>//就是欧拉函数啊 一点变化都没有 
#include<cmath>
unsigned euler(unsigned x)
{
    unsigned i, res=x,tmp;
    tmp= (int)sqrt(x * 1.0) + 1;
    for (i = 2; i <tmp; i++)
        if(x%i==0)
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i; 
        }
        if (x > 1) res = res / x * (x - 1);
	return res;
}

int main()
{
	int t;
	while(scanf("%d",&t) && t)
	{
		printf("%d\n",euler(t));
	}
	return 0;
}
