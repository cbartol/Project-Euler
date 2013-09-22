/*
 *	The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
 *
 *	Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
 *
 *	d2d3d4=406 is divisible by 2
 *	d3d4d5=063 is divisible by 3
 *	d4d5d6=635 is divisible by 5
 *	d5d6d7=357 is divisible by 7
 *	d6d7d8=572 is divisible by 11
 *	d7d8d9=728 is divisible by 13
 *	d8d9d10=289 is divisible by 17
 *	Find the sum of all 0 to 9 pandigital numbers with this property.
 *

	Resultado:
	1406357289+1430952867+1460357289+4106357289+4130952867+4160357289
	= 16695334890
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "../../auxx/prints.h"
#define N_NUMS 10

std::list<std::vector<int> > * make_permutations(void);

int main(){
	std::list<std::vector<int> > *lst;
	std::list<std::vector<int> > *magic_lst = new std::list<std::vector<int> >();
	lst = make_permutations();
	std::list<std::vector<int> >::iterator it;
	for(it = lst->begin() ; it != lst->end() ; it++){
		if( ((*it)[1]*100 + (*it)[2]*10 + (*it)[3]) % 2 == 0 && ((*it)[2]*100 + (*it)[3]*10 + (*it)[4]) % 3 == 0 && ((*it)[3]*100 + (*it)[4]*10 + (*it)[5]) % 5 == 0 && ((*it)[4]*100 + (*it)[5]*10 + (*it)[6]) % 7 == 0 && ((*it)[5]*100 + (*it)[6]*10 + (*it)[7]) % 11 == 0 && ((*it)[6]*100 + (*it)[7]*10 + (*it)[8]) % 13 == 0 && ((*it)[7]*100 + (*it)[8]*10 + (*it)[9]) % 17 == 0){
			magic_lst->push_back(*it);
			std::cout << ((*it)[1]*100) << std::endl;
		}	
	}
	delete lst;
	for(it = magic_lst->begin() ; it != magic_lst->end() ; it++){
		print_vector(&(*it));
	}
	delete magic_lst;
	return 0;
}

std::list<std::vector<int> > * make_permutations(void){
	int i, j, k, l;
	std::list<std::vector<int> > *permut = new std::list<std::vector<int> >();
	std::list<std::list<int> > permutations;
	std::list<std::list<int> > temp1;
	std::list<std::list<int> > temp2;
	std::list<int> base;
	base.push_back(0);
	permutations.push_front(base);
	for(i = 1 ; i < N_NUMS  ; i++){
		temp1 = permutations;
		permutations.clear();
		for(j=i, temp2 = temp1 ; j >= 0 ; j--, temp2 = temp1){
			std::list<std::list<int> >::iterator it;
			for(it = temp2.begin() ; it != temp2.end() ; it++){
				std::list<int>::iterator it2;
				for(k = j, it2 = (*it).begin() ; k >= 0 ; it2++, k--);
				(*it).insert(it2, i);
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
