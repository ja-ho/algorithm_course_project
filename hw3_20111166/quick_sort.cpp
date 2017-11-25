#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "my_types.h"

int partition(ELEMENT data[], int left, int right);
void swap(ELEMENT list[], int A, int B, ELEMENT *temp);

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
	int i, pivot;
	int mid, median;
	ELEMENT *temp;
	temp = (ELEMENT *)malloc(sizeof(ELEMENT));
	mid = (left + right) / 2;
    //left, right, mid를 비교해서 median 값을 pivot으로 partition
	if (ELEMENT_KEY(data + left) <= ELEMENT_KEY(data + mid) &&
		ELEMENT_KEY(data + mid) <= ELEMENT_KEY(data + right))
		median = ELEMENT_KEY(data + mid);
	else if (ELEMENT_KEY(data + left) <= ELEMENT_KEY(data + right) &&
		ELEMENT_KEY(data + right) <= ELEMENT_KEY(data + mid))
		median = ELEMENT_KEY(data + right);
	else median = ELEMENT_KEY(data + left);

	swap(data, right, median, temp);

	pivot = left;

	for (i = left; i < right; i++) {
		if (ELEMENT_KEY(data + i) < ELEMENT_KEY(data + right)) {
			swap(data, i, pivot, temp);
			pivot++;
		}
	}
	swap(data, right, pivot, temp);
	free(temp);
	return pivot;
}

/*
void swap(ELEMENT list[], int A, int B, ELEMENT *temp)
{
	memcpy(temp, list + A, sizeof(ELEMENT));
	memcpy(list + A, list + B, sizeof(ELEMENT));
	memcpy(list + B, temp, sizeof(ELEMENT));
}
*/