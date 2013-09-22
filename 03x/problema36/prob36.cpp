/*
 *	The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
 *
 *	Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 *
 *	(Please note that the palindromic number, in either base, may not include leading zeros.)
 */
 
#include "../../auxx/convert.h"
#include "../../auxx/prints.h"
#include "../../auxx/extra_math.h"
#include <vector>
#include <iostream>

#define LIMIT 1000000

int main(){
	int sum, i;
	
	for(sum = 0, i=0; i < LIMIT ; i++){
		if(isPalindromic(int_to_vector(i)) && isPalindromic(to_binary(i)) )
			sum += i;
	}
	std::cout << "Answer: " << sum << std::endl;
	return 0;
}

