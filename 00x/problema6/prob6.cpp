/*
 *	The sum of the squares of the first ten natural numbers is,
 *
 *	1^2 + 2^2 + ... + 10^2 = 385
 *	The square of the sum of the first ten natural numbers is,
 *
 *	(1 + 2 + ... + 10)^2 = 55^2 = 3025
 *	Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
 *
 *	Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */
#include <stdio.h>

int main(){
	int sum_sqr, sum_nat, i;

	for(sum_sqr = 0, sum_nat = 0, i = 1; i <= 100 ; i++){
		sum_nat += i;
		sum_sqr += i*i;
	}
	sum_nat *= sum_nat;
	
	printf("res: %d\n", sum_nat - sum_sqr);
	return 0;
}
