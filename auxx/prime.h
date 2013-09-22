#ifndef __PRIME_H__
#define __PRIME_H__

#include <math.h>
bool isPrime(int p){
	int i, n;
	n = sqrt(p);
	if(p <= 1)
	 	return false;
	for(i = 2 ; i <= n ; i++){
		if(p % i == 0)
			return false;
	}
	return true;
}

int nextPrime(bool reset){
	static int p = 1;
	if(reset)
		p=1;
	p++;
	while(1){
		if(isPrime(p))
			return p;
		p++;
	}	
}
#endif
