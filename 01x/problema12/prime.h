#include <math.h>
int isPrime(double p){
	double i, n, temp;
	modf(sqrt(p), &n);
	if(p == 1)
	 	return 0;
	for(i = 2 ; i <= n ; i++){
		if(modf(p / i, &temp) == 0)
			return 0;
	}
	return 1;
}

double nextPrime(bool reset){
	static double p = 1;
	if(reset)
		p=1;
	p++;
	while(1){
		if(isPrime(p))
			return p;
		p++;
	}	
}

double closestDivisiblePrime(double p){
	double n;
	double temp;
	for(n = p ; !isPrime(n) || !(modf(p/n , &temp) == 0) ; n--){
		if(n == 1)
			break;
	}
	return n;
}
