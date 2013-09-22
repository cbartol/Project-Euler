/*
 *	It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
 *
 *	9 = 7 + 2×1²
 *	15 = 7 + 2×2²
 *	21 = 3 + 2×3²
 *	25 = 7 + 2×3²
 *	27 = 19 + 2×2²
 *	33 = 31 + 2×1²
 *
 *	It turns out that the conjecture was false.
 *
 *	What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 */
#include <iostream>
#include "prime.h"

int main(){
	int i, p ,n;
	
	for(i = 33 ; true ; i += 2){
		for(p = nextPrime(true); p < i ; p = nextPrime(false)){
			for(n = 1 ; i < p + (2*n*n) ; n++);
			if(i == p + (2*n*n)){
				std::cout << i << "=" << p << " + " << "2x" << n << "²" << std::endl;
			}
			else{
				std::cout << "Answer: " << i << std::endl;
				return 0;
			}
		}
	}
	return 0;
}
