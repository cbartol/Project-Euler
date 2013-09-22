/*
 *	We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
 *
 *	What is the largest n-digit pandigital prime that exists?
 */

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "../../auxx/prime.h"
#include "../../auxx/convert.h"
#include "../../auxx/prints.h"

#define N_NUMS 7

std::list<std::vector<int> > *make_permutations(void);
void print_permutations(std::list<std::vector<int> > *permut);

int main(){
	int max = 0;
	int p;
	std::list<std::vector<int> > *lst;
	lst = make_permutations();
	std::list<std::vector<int> >::reverse_iterator it;
	for(it = lst->rbegin() ; max == 0 && it != lst->rend(); it++){
		p = vector_to_int(&(*it));
		if(isPrime(p))
			max = p;
	}

	std::cout << "Answer: " << max << std::endl;
	delete lst;
	return 0;
}

std::list<std::vector<int> > * make_permutations(void){
	int i, j, k, l;
	std::list<std::vector<int> > *permut = new std::list<std::vector<int> >();
	std::list<std::list<int> > permutations;
	std::list<std::list<int> > temp1;
	std::list<std::list<int> > temp2;
	std::list<int> base;
	base.push_back(1);
	permutations.push_front(base);
	for(i = 1 ; i < N_NUMS  ; i++){
		temp1 = permutations;
		permutations.clear();
		for(j=i, temp2 = temp1 ; j >= 0 ; j--, temp2 = temp1){
			std::list<std::list<int> >::iterator it;
			for(it = temp2.begin() ; it != temp2.end() ; it++){
				std::list<int>::iterator it2;
				for(k = j, it2 = (*it).begin() ; k >= 0 ; it2++, k--);
				(*it).insert(it2, i+1);
			}
			permutations.merge(temp2);
		}
		permutations.sort();
	}
	std::list<std::list<int> >::iterator it;
	for(it = permutations.begin() ; it != permutations.end() ; it++){
		permut->push_back((std::vector<int>((*it).begin(), (*it).end())));
	}
	return permut;
}
