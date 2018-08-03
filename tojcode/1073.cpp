#include <iostream>
using namespace std;
bool prime(int n)
{
	int i;
	for (i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int f(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int f2(int n)
{
	int sum = 0;
	int i = 2;
	while (1) 
	{
		if (n % i == 0)
		{
			sum += f(i);
			if (prime(n /= i))
			{
				break;
			}
		}
		else
		{
			i++;
		}
	}
	return sum + f(n);
}

int main()
{
	int n;
	
	while (cin>>n,n)
	{
		
		int i;
		for (i = n+1; ; i++)
		{
			if (prime(i)==0) 
			{
				if (f(i) == f2(i))
				{
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
  
    while(cin>>n,n)
    {
        for(int i=n+1;;i++)
        {
            if(prime(i)==0)
            if(f(i)==f2(i))
            {
               cout<<i<<endl;
               break;
               }
               }                                           
               }
               } 