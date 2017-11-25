#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_types.h"

int INSERTION_SORT(ELEMENT data[], int left, int right)
{
	// must return 1 if the function finishes normally or return 0 otherwise
	//	return 0;
	int i, j;
	ELEMENT *temp;
	temp = (ELEMENT *)malloc(sizeof(ELEMENT));
	for (i = left; i <= right; i++) {
		j = i;
		memcpy(temp, data + i, sizeof(ELEMENT));
		while ((j > left) && (ELEMENT_KEY(temp) < ELEMENT_KEY(data + j - 1))) {
			memcpy(data + j, data + (j - 1), sizeof(ELEMENT));
			j--;
		}
		memcpy(data + j, temp, sizeof(ELEMENT));
	}
	free(temp);
	return 1;	
}