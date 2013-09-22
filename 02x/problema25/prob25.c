/*
 *	The Fibonacci sequence is defined by the recurrence relation:
 *
 *	Fn = Fn1 + Fn2, where F1 = 1 and F2 = 1.
 *	Hence the first 12 terms will be:
 *
 *	F1 = 1
 *	F2 = 1
 *	F3 = 2
 *	F4 = 3
 *	F5 = 5
 *	F6 = 8
 *	F7 = 13
 *	F8 = 21
 *	F9 = 34
 *	F10 = 55
 *	F11 = 89
 *	F12 = 144
 *	The 12th term, F12, is the first term to contain three digits.
 *
 *	What is the first term in the Fibonacci sequence to contain 1000 digits?
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMB 12
#define MAX_SIZE 1000

void somar(int a[MAX_SIZE], int b[MAX_SIZE], int buffer[MAX_SIZE]);
void printNum(int numero[MAX_SIZE]);

int * nextFibonacciNumber(int reset){
	static int *i;
	static int *j;
	int n;
	int resultado[MAX_SIZE];
	if(reset){
		i = (int *) malloc(sizeof(int)*MAX_SIZE);
		j = (int *) malloc(sizeof(int)*MAX_SIZE);
		for(n = 0 ; n < MAX_SIZE ; n++){
			i[n] = 0;
			j[n] = 0;
		}
		j[0] = 1;
		return NULL;
	}
	somar(i, j, resultado);
	for(n = 0 ; n < MAX_SIZE ; n++){
		i[n] = j[n];
		j[n] = resultado[n];
	}
	return j;
}

int main(){
	int buffer[MAX_SIZE];
	buffer[MAX_SIZE-1] = 0;
	int *i;
	int n;
	nextFibonacciNumber(1);
	for(n = 1 , i = buffer ; i[MAX_SIZE-1] == 0 ; i = nextFibonacciNumber(0), n++){
			printNum(i);
	}
	printNum(i);
	printf("solução: %d\n", n);
	return 0;
}

void somar(int a[MAX_SIZE], int b[MAX_SIZE], int buffer[MAX_SIZE]){
	int i, j;
	
	for(j = 0; j < MAX_SIZE ; j++){
		buffer[j] = 0;
		buffer[j] = a[j] + b[j];
	}
	for(j = 0 ; j < MAX_SIZE ; j++){
		while(buffer[j] >= 10){
			buffer[j] -= 10;
			buffer[j+1] += 1;
		}
	}
}

void printNum(int numero[MAX_SIZE]){
	int j;
	printf("\n[");
	for(j = MAX_SIZE-1 ; j >= 0 ; j--){
		printf("%d", numero[j]);
	}
	printf("]\n");
}
