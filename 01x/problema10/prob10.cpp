/*
 *	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *	
 *	Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include "prime.h"
#define NUM_MAX 2000000

int main(){
	int i;
	double sum = 0;
	for(i = 1 ; i < NUM_MAX ; i++){
		if(isPrime(i))
			sum += i;
	}
	printf("res: %.0f\n", sum);
	return 0;
}
