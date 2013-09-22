/*
 *	The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
 *
 *	1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 *	By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
 *
 *	Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
 */

#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include "words.h"

bool isTermOfSeq(int x);

int main(){
	int temp_val;
	int times = 0;
	std::list<std::string> lst (words, words + sizeof(words) / sizeof(std::string));

	std::list<std::string>::iterator it;
	for(it = lst.begin() ; it != lst.end() ; it++){
		std::string::iterator it_string;
		temp_val = 0;
		for(it_string = (*it).begin() ; it_string != (*it).end() ; it_string++){
			temp_val += (*it_string) - 'A' + 1;
		}
		if(isTermOfSeq(temp_val)){
			times++;
		}
	}
	std::cout << "Answer: " << times << std::endl;
	return 0;
}

bool isTermOfSeq(int x){
	double n1;
	n1 = (-1 + sqrt(1+8*x))/2;
	return (n1 == floor(n1));
}
