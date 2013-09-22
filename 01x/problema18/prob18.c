#include <stdio.h>
#include "piramide.h"

#define PIR_LVLS 15

#define PIR_SIZE (levelToPosition(PIR_LVLS + 1))


int main(){
	int *lista;

	lista = makePiramide(PIR_SIZE);
	printPiramide(lista, PIR_LVLS);

	printf("%d\n", calculateRoute(lista, PIR_LVLS));
	return 0;
}
