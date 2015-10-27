#include "numSort.h"


/*
 * print: print an array to the stdout 
 *
 * @param A: array to be printed
 * @param length: length of the array
 */
void print(unsigned short *A, int length)
{
	for (int i = 0; i < length; i++)
		cout << A[i] << endl;
}

/*
 * countingSort: the naive version of counting sort
 *
 * @param A: the array need to be sort
 * @param B: the result
 * @param lengh: the length of the array
 */
void countingSort(unsigned short* A, unsigned short *B, int length)
{
	unsigned short *temp = new unsigned short[(1 << 16) - 1];

	memset(temp, 0, ((1 << 16) - 1) * sizeof(unsigned short));

	for (int i = 0; i < length; i++) temp[A[i]]++;
	for (int i = 1; i < ((1 << 16) - 1); i++) temp[i] += temp[i - 1];
	for (int i = 0; i < 0xffff - 1; i++) temp[i]--;
	for (int i = length - 1; i >= 0; i--)
	{
		B[temp[A[i]]] = A[i];
		temp[A[i]]--;
	}
	delete[] temp;
}

/*
 * countingSort: a more general version of counting sort, sort the number by the bits between begin and end
 *
 * @param A: the array need to be sort
 * @param B: the result
 * @param lengh: the length of the array
 * @param begin: the begin'th bit in the array
 * @param end: the end'th bit in the array
 */
void countingSort(unsigned short* A, unsigned short *B, int length, int begin, int end)
{
	int k = 1 << (end - begin), index;
	int *temp = new int[k];
	const unsigned short a = (0xffff >> (16 - end + begin)) << begin;

	memset(B, 0, length * sizeof(unsigned short));
	memset(temp, 0, k * sizeof(int));

	for (int i = 0; i < length; i++) temp[(A[i] & a) >> begin]++;
	for (int i = 1; i < k; i++) temp[i] += temp[i - 1];
	for (int i = 0; i < k; i++) temp[i]--;
	for (int i = length - 1; i >= 0; i--)
	{
		index = (A[i] & a) >> begin;
		B[temp[index]] = A[i];
		temp[index]--;
	}

	delete[] temp;
}

/*
 * radixSort: implementation of radix sort, which use counting sort to sort 4 bits for 4 times 
 * 
 * @param A: array to be sort
 * @param B: result
 * @param length: length of array
 */
void radixSort(unsigned short* A, unsigned short *B, int length)
{
	int gap = 4, begin, end;
	unsigned short *temp = new unsigned short[length];
	unsigned short *mid;

	memcpy(B, A, length * sizeof(unsigned short));
	memcpy(temp, B, length * sizeof(unsigned short));
	for (begin = 0, end = begin + gap; end <= 16; end += gap, begin += gap)
	{
		countingSort(B, temp, length, begin, end);
		mid = temp;
		temp = B; 
		B = mid;
	}
}

/*
 * merge: merge for array
 * 
 * @param A: array to be merged
 * @param begin: begin index
 * @param mid: mid index
 * @param end: end index
 */
void merge(unsigned short* A, int begin, int mid, int end)
{
	int size_1 = mid - begin + 1;
	int size_2 = end - mid;
	int i = 0, j = 0;
	
	unsigned short *L = new unsigned short[size_1], \
		*R = new unsigned short[size_2];

	for (int i = 0; i < size_1; i++)
		L[i] = A[begin + i];

	for (int i = 0; i < size_2; i++)
		R[i] = A[mid + i + 1];

	for (int k = begin; k <= end; k++)
	{
		if (i == size_1)
		{
			while (j < size_2)
			{
				A[k] = R[j];
				j++; k++;
			}
			break;
		}
		if (j == size_2)
		{
			while (i < size_1)
			{
				A[k] = L[i];
				i++; k++;
			}
			break;
		}
		if (L[i] >= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else 
		{
			A[k] = R[j];
			j++;
		}
	}

}

/*
 * mergeSort: merge sort for array
 *
 * @param A: array to be sort
 * @param begin: begin index
 * @param end: end index
 */
void mergeSort(unsigned short* A, int begin, int end)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		mergeSort(A, begin, mid);
		mergeSort(A, mid + 1, end);
		merge(A, begin, mid, end);
	}
}

