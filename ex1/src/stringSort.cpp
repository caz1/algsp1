#include "stringSort.h"


/*
 * bubbleSort: implementation of bubble sort
 *
 * @param A: vector to be sorted
 */
void bubbleSort(vector<string> &A)
{
	bool isSwitched = false;

	for (size_t i = 0; i < A.size(); i++)
	{
		isSwitched = true;
		for (size_t j = A.size() - 1; j > i; j--)
		{
			if (compare(A[j - 1], A[j]) == -1)
			{
				swap(A[j - 1], A[j]);
				isSwitched = false;
			}
		}
		if (isSwitched) return;
	}
}



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
 * shellSort: implementation of shell sort
 *
 * @param A: vector to be sorted
 */
void shellSort(vector<string>& A){
	const int gap[] = { 19, 13, 7, 3, 1 };

	for (int i = 0; i < 5; i++){
		mySort<vector<string> >::insertSort(A, A.size(), gap[i]);
	}
}

/*
 * merge: merge for vector
 * 
 * @param A: vector to be merged
 * @param begin: begin index
 * @param mid: mid index
 * @param end: end index
 */
void merge(vector<string>& A, int begin, int mid, int end){
	int size_1 = mid - begin + 1;
	int size_2 = end - mid;
	int i = 0, j = 0;

	vector<string> L(size_1), R(size_2);

	for (int i = 0; i < size_1; i++)
		L[i] = A[begin + i];

	for (int i = 0; i < size_2; i++)
		R[i] = A[mid + i + 1];

	for (int k = begin; k <= end; k++){
		if (i == size_1){
			while (j < size_2){
				A[k] = R[j];
				j++; k++;
			}
			break;
		}
		if (j == size_2){
			while (i < size_1)
			{
				A[k] = L[i];
				i++; k++;
			}
			break;
		}
		if (L[i] <= R[j])
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
 * mergeSort: merge sort for vector
 *
 * @param A: vector to be sort
 * @param begin: begin index
 * @param end: end index
 */
void mergeSort(vector<string>& A, int begin, int end)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		mergeSort(A, begin, mid);
		mergeSort(A, mid + 1, end);
		merge(A, begin, mid, end);
	}
}

/*
 * maxHeapify: build a max heap with a root of i
 *
 * @param A: vector to be build
 * @param i: root of the heap
 * @param length: max valid elements length in vector 
 */
void maxHeapify(vector<string>& A, int i, int length){
	int left = ((i + 1) << 1) - 1;
	int right = ((i + 1) << 1);
	int largest = i;

	if (left < length && compare(A[largest], A[left]) == -1)
		largest = left;
	if (right < length && compare(A[largest], A[right]) == -1)
		largest = right;

	if (largest != i){
		swap(A[i], A[largest]);
		maxHeapify(A, largest, length);
	}
}

/*
 * buildMaxHeap: build a max heap
 *
 * @param A: vector to be build
 */
void buildMaxHeap(vector<string>& A){
	for (int i = A.size() / 2; i >= 0; i--)
		maxHeapify(A, i, A.size() - 1);
}
/*
 *
 * heapSort: implementation of heap sort
 * 
 * @param A: vector to be sort
 */
void heapSort(vector<string>& A){
	int length = A.size();

	buildMaxHeap(A);
	
	for (int i = A.size() - 1; i > 0; i--){
		swap(A[0], A[i]);
		maxHeapify(A, 0, --length);
	}
}
