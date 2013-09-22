#include <stdio.h>
#define MAX_NUMB 4000000


int nextFibonacciNumber(){
	static int i = 0;
	static int j = 1;
	int resultado = i + j;
	i = j;
	j = resultado;
	return resultado;
}

int main(){
	int i;
	int sum = 0;
	for(i = 0 ; i < MAX_NUMB ; i = nextFibonacciNumber()){
		if(i % 2 == 0)
			sum += i;
	}
	printf ("sum: %d\n", sum);
	return 0;
}
