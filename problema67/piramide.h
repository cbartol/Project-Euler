#include <stdio.h>
#include <stdlib.h>


int levelToPosition(int lvl){
	int i, sum = 0;
	for(i = 1 ; i < lvl ; i++)
		sum += i;
	return sum;
}

void printLevel(int *list, int lvl){
	int pos;
	int i;
	pos = levelToPosition(lvl);
	for(i = pos ; i < lvl+pos ; i++){
		printf("%2d ", list[i]);
	}
	printf("\n");
	return;
}

int * makePiramide(int size){
	int * list = (int *) malloc(sizeof(int)*size);
	int i;
	for(i = 0; i < size ; i++){
		scanf("%d", &(list[i]));
	}
	return list;
}

void printPiramide(int * list, int lvls){
	int i;
	for(i = 1 ; i <= lvls ; i++){
		printLevel(list, i);
	}
}

int nextRoot(int *list, int sum, int pos, int lvl, int lvls){
	int left, right;
	sum += list[pos+levelToPosition(lvl)];
	if(lvl < lvls){
		left = nextRoot(list, sum, pos, lvl + 1, lvls);
		right = nextRoot(list, sum, pos + 1, lvl + 1, lvls);
	}
	else{
		return sum;
	}
	if(le{
		return right;
	}
}

int calculateRoute(int * list, int lvls){
	return nextRoot(list, 0, 0, 1, lvls);
}ft > right){
		return left;
	}
	else {
		return right;
	}
}

int calculateRoute(int * list, int lvls){
	return nextRoot(list, 0, 0, 1, lvls);
}
