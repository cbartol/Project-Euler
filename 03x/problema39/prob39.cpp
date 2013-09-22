/*
 *	If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
 *
 *	{20,48,52}, {24,45,51}, {30,40,50}
 *
 *	For which value of p <= 1000, is the number of solutions maximised?
 */

#include <iostream>
#include <vector>
#include <list>
#include "../../auxx/prints.h"

int main(){
	int max = 0;
	int max_size = 0;
	std::list<std::vector<int> *> *table[1001];
	int c1, c2, h;
	for(h = 0 ; h < 1001 ; h++){
		table[h] = new std::list<std::vector<int> *>();
	}
	for(c1 = 1; c1 <= 1000 ; c1++){
		for(c2 = c1; c2 <= 1000 ; c2++){
			for(h = c2 ; h <= 1000 ; h++){
				if(c1*c1+c2*c2 == h*h && c1+c2+h <= 1000){
					std::vector<int> *temp = new std::vector<int>();
					temp->push_back(c1);
					temp->push_back(c2);
					temp->push_back(h);
					(table[c1+c2+h])->push_back(temp);
				}
			}
		}
	}
	for(h = 0 ; h < 1001 ; h++){
/*		std::cout << "i[" << h << "]" << std::endl;
		std::list<std::vector<int> *>::iterator it;
		for(it = table[h]->begin(); it != table[h]->end() ; it++){
			print_spaced_vector(*it);		
		}
*/		if(table[h]->size() > max_size){
			max_size = table[h]->size();
			max = h;
		}
	}
	std::cout << "Answer: " << max << std::endl;
	return 0;
}
