#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void)
{
	int n = 0;
	int primes = 1;
	int t = 1024576;

	
	while(primes <= 476850)
	{
		if(is_prime(n))
		{
			printf("The %d primenumber is %d\n", primes, n);
			primes = primes + 1;
		}
		n++;
	}
	
	return 0;
}