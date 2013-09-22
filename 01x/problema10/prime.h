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
