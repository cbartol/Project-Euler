/*
 *	n! means n × (n − 1) × ... × 3 × 2 × 1
 *
 *	For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 *	and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 *	Find the sum of the digits in the number 100!
 */

#include <stdio.h>
#define NUM_SIZE 160
int main(){
	int numero[NUM_SIZE];
	int i, j, z;
	for(i = 0 ; i <NUM_SIZE ; i++){
		numero[i] = 0;
	}
	numero[0] = 1;
	for(z = 1; z <=100 ; z++){
		for(i = 0; i <NUM_SIZE ; i++){
			while(numero[i] >= 10){
				numero[i] -= 10;
				numero[i+1] += 1;
			}
			numero[i] *= z;
		}
	}
	for(i = 0; i <NUM_SIZE ; i++){
		while(numero[i] >= 10){
			numero[i] -= 10;
			numero[i+1] += 1;
		}
	}
	int sum = 0;
	for(i = NUM_SIZE-1 ; i >= 0 ; i--){
		sum += numero[i];
		printf("%d", numero[i]);
	}
	printf("\n%d\n", sum);
	return 0;
}
