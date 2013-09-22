#include <stdio.h>
#include <math.h>
#define NUM_PEDIDO 600851475143.0


int isPrime(double p);

int main(){
	double max = 0;
	double temp;
	double n;
	double i;
	modf(sqrt(NUM_PEDIDO), &n);
	for(i = 2.0 ; i <= n ; i++){
		if(!isPrime(i))
			continue;
		//printf("num prime factor: %f\n", i);
		if(modf(NUM_PEDIDO / i, &temp) == 0)
			max = i;
	}
	printf("max: %.0f\n", max);
	return 0;
}



/* FUNÇÕES AUXILIARES */
int isPrime(double p){
	double i;
	double temp;
	double n;
	sqrt(p);
	modf(sqrt(p), &n);
	n+=1;
	if(p == 1)
	 	return 0;
	for(i = 2 ; i <= n ; i++){
		if(modf(p / i, &temp) == 0)
			return 0;
	}
	return 1;
}
