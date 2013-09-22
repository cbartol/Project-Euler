/*
 *	Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 *
 *	21 22 23 24 25
 *	20  7  8  9 10
 *	19  6  1  2 11
 *	18  5  4  3 12
 *	17 16 15 14 13
 *
 *	It can be verified that the sum of the numbers on the diagonals is 101.
 *
 *	What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 */

#include <iostream>
#include <vector>
#include "../../auxx/prints.h"
#define TABLE_SIZE 1001

std::vector<int> *gera_sup_dir();
std::vector<int> *gera_sup_esq();
std::vector<int> *gera_inf_dir();
std::vector<int> *gera_inf_esq();

int main(){
	int i;
	int sum;
	std::vector<int> *sup_dir;
	std::vector<int> *sup_esq;
	std::vector<int> *inf_dir;
	std::vector<int> *inf_esq;
	
	sup_dir = gera_sup_dir();
	sup_esq = gera_sup_esq();
	inf_dir = gera_inf_dir();
	inf_esq = gera_inf_esq();
	
	for(i = 0, sum = 0 ; i < sup_dir->size() ; i++){
		sum += sup_dir->at(i) + sup_esq->at(i) + inf_dir->at(i) + inf_esq->at(i);
	}
	sum += 1;
	
	std::cout << "Answer: " << sum << std::endl;
	
	delete sup_dir;
	delete sup_esq;
	delete inf_dir;
	delete inf_esq;
	return 0;
}

std::vector<int> *gera_sup_dir(){
	std::vector<int> *lst = new std::vector<int>();
	int i;
	for(i = TABLE_SIZE ; i != 1 ; i -= 2){
		lst->push_back(i*i);
	}
	return lst;
}
std::vector<int> *gera_sup_esq(){
	std::vector<int> *lst = new std::vector<int>();
	int i, j;
	for(i = TABLE_SIZE, j = TABLE_SIZE-1 ; i != 1 ; i -= 2, j -= 2){
		lst->push_back((i*j)+1);
	}
	return lst;
}
std::vector<int> *gera_inf_dir(){
	std::vector<int> *lst = new std::vector<int>();
	int i, j;
	for(i = TABLE_SIZE, j = TABLE_SIZE-3 ; i != 1 ; i -= 2, j -= 2){
		lst->push_back((i*j)+3);
	}
	return lst;
}
std::vector<int> *gera_inf_esq(){
	std::vector<int> *lst = new std::vector<int>();
	int i, j;
	for(i = TABLE_SIZE, j = TABLE_SIZE-2 ; i != 1 ; i -= 2, j -= 2){
		lst->push_back((i*j)+2);
	}
	return lst;
}
