#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_types.h"

void adjust(ELEMENT list[], int root, int n);
//void swap(ELEMENT list[], int A, int B, ELEMENT *temp);
//void swap2(void *A, void *B);
void h_swap(ELEMENT *A, ELEMENT *B);


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
	/*////
	ELEMENT *ptr = data;
	fprintf(stdout, "*** %s: Output data\n", "heap_sort_test");
	for (int i = 0; i < length; i++, ptr++)
		fprintf(stdout, "  i = %6d: (%11u, %5.1f, %17.14f, %s)\n", i, ELEMENT_KEY(ptr), ptr->score, ptr->other, ptr->name);
	fprintf(stdout, "\n");
	/////*/
	for (i = length - 1; i > 0; i--) {
		//swap(data, 1, i + 1, temp);
		//swap2(data + left, data + right);
		h_swap(data + left, data + right);
		adjust(data, 1, i);
	}
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

/*
void swap(ELEMENT list[], int A, int B, ELEMENT *temp)
{
	memcpy(temp, list + A, sizeof(ELEMENT));
	memcpy(list + A, list + B, sizeof(ELEMENT));
	memcpy(list + B, temp, sizeof(ELEMENT));
}
*/
/*void swap(void *A, void *B) {
	void *temp;
	int size = sizeof(ELEMENT);
	temp = malloc(size);
	memcpy(temp, A, size);
	memcpy(A, B, size);
	memcpy(B, temp, size);
	free(temp);
}*/

void h_swap(ELEMENT *A, ELEMENT *B)
{
	ELEMENT temp;
	memcpy(&temp, A, sizeof(ELEMENT));
	memcpy(A, B, sizeof(ELEMENT));
	memcpy(B, &temp, sizeof(ELEMENT));
}
