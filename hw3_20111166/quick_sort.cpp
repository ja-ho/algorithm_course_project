#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_types.h"

bool is_less(int a, int b);
void q_swap(ELEMENT *A, ELEMENT *B);
void compare_swap(ELEMENT *A, ELEMENT *B);
int partition(ELEMENT data[], int left, int right);


int QUICK_SORT(ELEMENT data[], int left, int right) {
	// must return 1 if the function finishes normally or return 0 otherwise
	//	return 0;
	int pivot;
	if (right - left > 0) {
		pivot = partition(data, left, right);
		QUICK_SORT(data, left, pivot - 1);
		QUICK_SORT(data, pivot + 1, right);	
	}	
	return 1;
}

int partition(ELEMENT data[], int left, int right)
{
	int i = left - 1;
	int j = right;
	ELEMENT temp;
	memcpy(&temp, data + right, sizeof(ELEMENT));
	for (;;) {
		while (is_less(ELEMENT_KEY(data + (++i)), ELEMENT_KEY(&temp)));
		while (is_less(ELEMENT_KEY(&temp), ELEMENT_KEY(data + (--j)))) {
			if (j == left) break;
		}
		if (i >= j) break;
		q_swap(data + i, data + j);
	}
	q_swap(data + i, data + right);
	return i;
}

void q_swap(ELEMENT *A, ELEMENT *B)
{
	ELEMENT temp;
	memcpy(&temp, A, sizeof(ELEMENT));
	memcpy(A, B, sizeof(ELEMENT));
	memcpy(B, &temp, sizeof(ELEMENT));
}

void compare_swap(ELEMENT *A, ELEMENT *B)
{
	if (is_less(ELEMENT_KEY(B), ELEMENT_KEY(A))) {
		q_swap(A, B);
	}
}

bool is_less(int a, int b)
{
	return (a < b);
}