#include <stdio.h>
#include <stdlib.h>
#include "my_types.h"

//Todo: memory ũ�� �ø���
int median_of_5(ELEMENT data[], int length);

int SELECTION_REC(ELEMENT data[], int left, int right, int k, int *index) {
	// must return 1 if the function finishes normally or return 0 otherwise
	//	return 0;
	//*index = 3; ??
	int selected_median;
	int i;
	int s1 = 0; int s2 = 0; int s3 = 0;
	int length = right - left + 1;
	//�� �� �Ǹ� �׳� sort
	if (length < 50) {
		INSERTION_SORT(data, left, right);	//Todo: quick_sort �����Ұ�
		*index = ELEMENT_KEY(data + k);
		return 1;
	}
	else {
		selected_median = median_of_5(data, length);
		/////////s1, s2, s3�� selected_median�� �������� ����
		for (i = 0; i < length; i++) {
			if (ELEMENT_KEY(data + i) < selected_median) s1++;
			else if (ELEMENT_KEY(data + i) == selected_median) s2++;
			else s3++;
		}
		if (s1 >= k) {
			*index = SELECTION_REC(data, left, s1 - 1, k, index);
			return 1;
		} 
		else if (s1 + s2 >= k) {
			*index = selected_median;
			return 1;
		} 
		else {
			*index = SELECTION_REC(data, s2, right, k - s1 - s2, index);
			return 1;
		}
	}
}

int median_of_5(ELEMENT data[], int length)
{
	int *index;
	ELEMENT **temp_array;
	int selected_median;
	ELEMENT *temp;
	int i, j;
	temp_array = (ELEMENT **)malloc(sizeof(ELEMENT*)*(length / 5));	// �����Ӱ� ���ص� �Ƿ���
	for (i = 0, j = 0 ; i + 4 <= length; i += 5, j++){
		if (length - i + 1 < 5) {	// ���� ������ 5�� ������ ���
			temp = (ELEMENT *)malloc(sizeof(ELEMENT));
			INSERTION_SORT(data, i, length - 1);
			temp->key = ELEMENT_KEY(data + i + ((length - i + 1) / 2));
			temp_array[j] = temp;
			break;
		}
		temp = (ELEMENT *)malloc(sizeof(ELEMENT));
		//SELECTION_REC(data, i, i + 4, 3, index);
		INSERTION_SORT(data, i, i + 4);
		temp->key = ELEMENT_KEY(data + i + 2);
		temp_array[j] = temp;
	}
	SELECTION_REC(*temp_array, 0, j, j / 2, index);
	selected_median = *index;
	for (i = 0; i < length / 5; i++) {
		free(temp_array[i]);
	}
	free(temp_array);
	return selected_median;
}
