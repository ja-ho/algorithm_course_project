#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_types.h"

void adjust(ELEMENT list[], int root, int n);
void swap(ELEMENT list[], int A, int B, ELEMENT *temp);
void swap2(void *A, void *B);

int HEAP_SORT(ELEMENT data[], int left, int right) {
	// must return 1 if the function finishes normally or return 0 otherwise
	//	return 0;
	int i;
	//ELEMENT *temp;
	//temp = (ELEMENT *)malloc(sizeof(ELEMENT));
	int length = right - left + 1;

	for (i = (length / 2); i > 0; i--) {
		adjust(data, i, length);
	}
	for (i = length - 1; i > 0; i--) {
		//swap(data, 1, i + 1, temp);
		swap2(data + 1, data + i + 1);
		adjust(data, 1, i);
	}
	//free(temp);
	return 1;
}

void adjust(ELEMENT list[], int root, int n)
{
	int child;
	unsigned int rootkey;
	rootkey = ELEMENT_KEY(list + root);
	child = 2 * root;
	while (child <= n) {
		if (child < n && (ELEMENT_KEY(list + child) < ELEMENT_KEY(list + child + 1))) {
			child++;
		}
		if (rootkey > ELEMENT_KEY(list + child))
			break;
		else {
			memcpy(list + child, list + root, sizeof(ELEMENT));
			child *= 2;
		}
	}
	memcpy(list + child / 2, list + root, sizeof(ELEMENT));
}

void swap(ELEMENT list[], int A, int B, ELEMENT *temp)
{
	memcpy(temp, list + A, sizeof(ELEMENT));
	memcpy(list + A, list + B, sizeof(ELEMENT));
	memcpy(list + B, temp, sizeof(ELEMENT));
}

void swap2(void *A, void *B) {
	void *temp;
	int size = sizeof(ELEMENT);
	temp = malloc(size);
	memcpy(temp, A, size);
	memcpy(A, B, size);
	memcpy(B, temp, size);
	free(temp);
}
