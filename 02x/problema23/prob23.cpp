/*
 *	A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 *	A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 *
 *	As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 *
 *	Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

#include <stdio.h>
#include "lista.h"

#define MAXIMO 28123

int d(int n);
bool isAbundant(int n);

int main(){
	int i, sum;
	int num, el;
	list abundant = NULL;
	list travel;
	int * array = (int *) malloc(sizeof(int)*(MAXIMO+1));
	for(i = 0 ; i <= MAXIMO ; i++){
		array[i] = i;
	}

	for(i = 0 ; i <= MAXIMO ; i++){
		if(isAbundant(i)){
			abundant = add_element(abundant, new_element(i));
		}
	}
	for(travel = abundant ; travel != NULL ; travel = travel->next){
		num = get_element(travel, true);
		for(el = num ; el != -1 ; el = get_element(travel, false)){
			if(num + el <= MAXIMO)
				array[num+el] = -1;
		}
	}

//	print_list(abundant);
//	for(i = 0, sum = 0 ; i <= MAXIMO ; i++){
//		printf("%d\n", array[i]);
//	}

	for(i = 0, sum = 0 ; i <= MAXIMO ; i++){
		if(array[i] != -1)
			sum += array[i];
	}
	printf("Answer: %d\n", sum);

	delete_list(abundant);
	free(array);
	return 0;
}

int d(int n){
	int sum = 0;
	int i;
	int p = (n/2);
	for(i = 1 ; i <= p ; i++){
		if(n % i == 0){
			sum += i;
		}
	}
	return sum;
}

bool isAbundant(int n){
	return (n < d(n));
}
