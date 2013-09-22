#include <stdio.h>

int main(){
	int sum = 0;
	int i;
	for(i = 0; i < 1000 ; i++){
		if(i % 3 == 0 || i % 5 == 0){
			printf("i: %d; ", i);
			sum += i;
		}
	}
	printf("\n");
	printf("Sum: %d\n", sum);
	return 0;
}
