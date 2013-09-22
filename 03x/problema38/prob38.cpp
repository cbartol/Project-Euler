/*
Take the number 192 and multiply it by each of 1, 2, and 3:

192 x 1 = 192
192 x 2 = 384
192 x 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
 */
#include <iostream>
#include <vector>
#include <list>

#include "../../auxx/convert.h"
#include "../../auxx/extra_math.h"
#include "../../auxx/prints.h"


int main(){
	int i, n;
	bool flag = true;
	std::list<std::vector<int> *> *number = new std::list<std::vector<int> *>();
	std::vector<int> *temp1;
	std::vector<int> *temp2;
	for(i = 9876 ; i > 900 ; i--){
		if(!isPandigital(int_to_vector(i)))
			continue;
		temp1 = new std::vector<int>();
		n=1;
		while(temp1->size() < 9){
			temp2 = int_to_vector(i*n);
			std::vector<int>::iterator it;
			for(it = temp2->begin() ; it != temp2->end() ; it++){
				temp1->push_back(*it);
			}
			n++;
		}
		if(isPandigital(temp1))
			number->push_back(temp1);
	}
	number->sort();
	std::list<std::vector<int> *>::iterator itt;
	for(itt = number->begin(); itt != number->end(); itt++){
		print_vector(*itt);
	}
	return 0;
}
