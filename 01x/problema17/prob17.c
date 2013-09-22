#include <stdio.h>
#include "wordNumbers.h"

int main(){
	int i;
	int sum = 0;
	for( i = 1 ; i <= 1000 ; i ++){
		printf("%s\n", numberToWord(i));
		sum += strlen( numberToWord(i));
	}
	printf("res: %d\n", sum);
	return 0;
}
