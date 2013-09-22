/*
 *	The following iterative sequence is defined for the set of positive integers:
 *
 *	n -> n/2 (n is even)
 *	n -> 3n + 1 (n is odd)
 *
 *	Using the rule above and starting with 13, we generate the following sequence:
 *
 *	13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *	It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 *	Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 *	Which starting number, under one million, produces the longest chain?
 *
 *	NOTE: Once the chain starts the terms are allowed to go above one million.
 *
 * Solution: MAX-> num: 837799, chain: 525
 */
#include <stdio.h>
#include <math.h>

double nextNumber(double i);

int main(){
	double starting_n, n;
	double chain = 0;
	double max[2] = {0,0};
	for(starting_n = 2 ; starting_n < 1000000 ; starting_n++, chain = 0){
		printf("%.0f -> ", starting_n);
		chain++;
		for(n = nextNumber(starting_n) ; n != 1 ; n = nextNumber(0)){
			printf("%.0f -> ", n);
			chain++;
		}
		printf("%.0f\n", n);
		chain++;
		if(max[1] < chain){
			max[0] = starting_n;
			max[1] = chain;
		}
	}
	printf("MAX-> num: %.0f, chain: %.0f\n", max[0], max[1]);
	return 0;
}

double nextNumber(double i){
	static double numb = 0;
	double temp;
	if(i != 0)
		numb = i;
	if(modf(numb/2, &temp) == 0)
		numb = numb/2;
	else
		numb = 3*numb + 1;
	return numb;

}
