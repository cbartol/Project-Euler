/*
 *	Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
 *
 *	1634 = 1^4 + 6^4 + 3^4 + 4^4
 *	8208 = 8^4 + 2^4 + 0^4 + 8^4
 *	9474 = 9^4 + 4^4 + 7^4 + 4^4
 *	As 1 = 1^4 is not a sum it is not included.
 *
 *	The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *
 *	Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 */
 
/* É de observar que (9^5)*6 tem 6 digitos e que (9^5)*7 também tem 6 digitos.
 *	Logo o número máximo que se pode escrever com a soma de n^5 tem 6 digitos.
 */

#include <iostream>
#include "../../auxx/extra_math.h"

int main(){
	int i, j, k, l, m, n;
	int num;
	int temp;
	int sum = 0;
	
	for(i = 0 ; i < 10 ; i++){
		for(j = 0 ; j < 10 ; j++){
			for(k = 0 ; k < 10 ; k++){
				for(l = 0 ; l < 10 ; l++){
					for(m = 0 ; m < 10 ; m++){
						for(n = 0 ; n < 10 ; n++){
							num = s_pow(i, 5) + s_pow(j, 5) + s_pow(k, 5) + s_pow(l, 5) + s_pow(m, 5) + s_pow(n, 5);
							temp = n + (m*10) + (l*100) + (k*1000) + (j*10000) + (i*100000);
							if(num == temp && num != 1){
								std::cout << num << std::endl;
								sum += num;
							}
						}
					}
				}
			}
		}
	}
	std::cout << "Answer: " << sum << std::endl;
	
	return 0;
}
