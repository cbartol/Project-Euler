/*
 *	The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
 *
 *	Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
 *
 *	NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */
 
#include <iostream>
#include <list>

#include "../../auxx/convert.h"
#include "../../auxx/prints.h"
#include "../../auxx/prime.h"

int main(){
	std::list<int> *result = new std::list<int>();
	std::list<int> *temp;
	int i, n_temp;
	i = nextPrime(true);
	while(i < 10){
		i = nextPrime(false);
	}
	for(; result->size() != 11 ; i = nextPrime(false)){
		for(temp = int_to_list(i); temp->size() != 0 ; temp->pop_front()){
			if(isPrime(list_to_int(temp)))
				continue;
			else
				break;
		}
		if(temp->size() != 0){
			delete temp;
			continue;
		}
		delete temp;
		for(n_temp = i ; n_temp != 0 ; n_temp /= 10){
			if(isPrime(n_temp))
				continue;
			else
				break;
		}
		if(n_temp != 0)
			continue;
		result->push_back(i);
	}
	print_spaced_list(result);
	int sum = 0;
	std::list<int>::iterator it;
	for(it = result->begin() ; it != result->end() ; it++){
		sum += (*it);
	}
	std::cout << "Answer: " << sum << std::endl;
	delete result;
	return 0;
}
