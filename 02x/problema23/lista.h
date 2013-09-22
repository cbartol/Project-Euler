#include <stdlib.h>
#include <stdio.h>

typedef struct my_struct {
	int num;
	struct my_struct *next;
} *list;

list add_element(list head, list el){
	if(head != NULL)
		el->next = head;
	return el;
}

list new_element(int numb){
	list new_el = (list) malloc(sizeof(*new_el));
	new_el->num = numb;
	new_el->next = NULL;
	return new_el;
}

int find_element(list head, int el){
	list travel;
	for(travel = head ; travel != NULL ; travel = travel->next){
		if(travel->num == el){
			return 1;
		}
	}
	return 0;
}

void print_list(list head){
	if(head != NULL){
		print_list(head->next);
		printf("%d\n", head->num);
	}
}

int get_element(list head, bool reset){
	static list element = NULL;
	int el;
	if(reset){
		element = head;
	}
	if(element == NULL)
		return -1;
	el = element->num;
	element = element->next;
	return el;
}

void delete_list(list head){
	list travel;
	for(travel = head ; travel != NULL ; ){
		head = travel;
		travel = travel->next;
		head->next = NULL;
		free(head);
	}
}
