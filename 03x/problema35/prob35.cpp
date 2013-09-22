/*
 *	The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 *
 *	There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 *
 *	How many circular primes are there below one million?
 */

#include <iostream>
#include "../../auxx/prime.h"
#include "../../auxx/convert.h"
#include "../../auxx/prints.h"
#include <list>

#define LIMIT 1000000

int main(){
	int i, j;
	std::list<int> lst;
	for(i = nextPrime(true) ; i < LIMIT ; i = nextPrime(false)){
		std::list<int> *temp;
		bool flag = true;
		temp = int_to_list(i);
		for(j = 1 ; flag && j < temp->size() ; j++){
			temp->push_back(temp->front());
			temp->pop_front();
			if(!isPrime(list_to_int(temp)))
				flag = false;
		}
		if(flag)
			lst.push_back(i);
		delete temp;
	}
	print_spaced_list(&lst);
	return 0;
}
