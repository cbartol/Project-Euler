#ifndef __PRINTS_H__
#define __PRINTS_H__

#include <iostream>
#include <list>
#include <vector>

template <class T>
void print_vector(std::vector<T> *vect){
	typename std::vector<T>::iterator it;
	for(it = vect->begin() ; it != vect->end(); it++){
		std::cout << (*it);
	}
	std::cout << std::endl <<"size: "<<vect->size() << std::endl;
}

template <class T>
void reverse_print_vector(std::vector<T> *vect){
	typename std::vector<T>::reverse_iterator it;
	for(it = vect->rbegin() ; it != vect->rend(); it++){
		std::cout << (*it);
	}
	std::cout << std::endl <<"size: "<<vect->size() << std::endl;
}

template <class T>
void print_list(std::list<T> *lst){
	typename std::list<T>::iterator it;
	for(it = lst->begin() ; it != lst->end(); it++){
		std::cout << (*it);
	}
	std::cout << std::endl <<"size: "<<lst->size() << std::endl;
}

template <class T>
void print_spaced_vector(std::vector<T> *vect){
	typename std::vector<T>::iterator it;
	for(it = vect->begin() ; it != vect->end(); it++){
		std::cout << (*it) << " ";
	}
	std::cout << std::endl <<"size: "<<vect->size() << std::endl;
}

template <class T>
void print_spaced_list(std::list<T> *lst){
	typename std::list<T>::iterator it;
	for(it = lst->begin() ; it != lst->end(); it++){
		std::cout << (*it) << " ";
	}
	std::cout << std::endl <<"size: "<<lst->size() << std::endl;
}

#endif
