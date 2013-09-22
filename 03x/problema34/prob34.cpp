/*
 *	145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 *	Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 *
 *	Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */
#include <iostream>
#include "../../auxx/convert.h"
#include "../../auxx/extra_math.h"
#include "../../auxx/prints.h"
#include <vector>
#include <list>

#define MAX_FACT (7*fact_1_to_9(9))

int main(){
	std::vector<int> *temp;
	std::list<int> *nums = new std::list<int>();
	int i;
	for(i = 10; i <= MAX_FACT ; i++){
		temp = int_to_vector(i);
		std::vector<int>::iterator it;
		int sum = 0;
		for(it = temp->begin() ; it != temp->end() ; it++){
			sum += fact_1_to_9(*it);
		}
		if(sum == i){
			nums->push_back(i);
		}
		delete temp;
	}
//	print_spaced_list(nums);
	int ans_sum = 0;
	std::list<int>::iterator it;
	for(it = nums->begin() ; it != nums->end() ; it++){
		ans_sum += *it;
	}
	delete nums;
	std::cout << "Answer: " << ans_sum << std::endl;
	return 0;
}
