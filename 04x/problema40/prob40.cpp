/*
 *	An irrational decimal fraction is created by concatenating the positive integers:
 *
 *	0.12345678910 1 112131415161718192021...
 *
 *	It can be seen that the 12th digit of the fractional part is 1.
 *
 *	If dn represents the nth digit of the fractional part, find the value of the following expression.
 *
 *	d1 x d10 x d100 x d1000 x d10000 x d100000 x d1000000
 */

#include <iostream>
#include <vector>
#include "../../auxx/prints.h"
#include "../../auxx/convert.h"
#define DECIMAL_SIZE 1000000

int main(){
	std::vector<int> decimal;
	int mult;
	int i;
	for(i = 1 ; decimal.size() <= DECIMAL_SIZE ; i++){
		std::vector<int> *temp;
		temp = int_to_vector(i);
		std::vector<int>::iterator it;
		for(it = temp->begin() ; it != temp->end() ; it++){
			decimal.push_back(*it);
		}
		delete temp;
	}
	for(mult = 1, i = 1 ; i <= DECIMAL_SIZE ; i *= 10){
		mult *= decimal[i-1];
	}
	std::cout << "Answer: " << mult << std::endl;
	return 0;
}
