/*
 *	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 *	What is the 10 001st prime number?
 */
#include <stdio.h>
#include <math.h>
 
int isPrime(double p);

int main(){
	int n;
	double i;
	for(i = 1, n = 1 ; n != 10001 ;){
		i++;
		if(isPrime(i))
			n++;
	}
	printf("num: %.0f\n", i);
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
