/*
 *	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 *	What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */
#include <stdio.h>
#include <math.h>

int main(){
	double i, j;
	int flag = 0;
	for(i = 1 ; 1 ; i++, flag = 0){
		for(j = 1 ; j <= 20 ; j++){
			if(fmod(i,j) != 0){
				flag = 1;
				break;
			}
		}
		if(!flag)
			break;
	}
	printf("val: %f\n", i);
}
