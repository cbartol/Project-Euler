/*
 *	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 *	What is the sum of the digits of the number 2^1000?
 */

#include <stdio.h>

int main(){
	int numero[305];
	int i, j, z;
	for(i = 0 ; i <305 ; i++){
		numero[i] = 0;
	}
	numero[0] = 1;
	for(z = 0; z <1000 ; z++){
		for(i = 0; i <305 ; i++){
			if(numero[i] >= 20){
				numero[i] -= 20;
				numero[i+1] += 2;
			}
			else if(numero[i] >= 10){
				numero[i] -= 10;
				numero[i+1] += 1;
			}
			numero[i] *= 2;
		}
	}
	for(i = 0; i <305 ; i++){
		if(numero[i] >= 20){
			numero[i] -= 20;
			numero[i+1] += 2;
		}
		else if(numero[i] >= 10){
			numero[i] -= 10;
			numero[i+1] += 1;
		}
	}
	int sum = 0;
	for(i = 304 ; i >= 0 ; i--){
		sum += numero[i];
		printf("%d", numero[i]);
	}
	printf("\n%d\n", sum);
	return 0;
}
