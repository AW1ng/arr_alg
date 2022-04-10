#include <iostream>
#include <vector>
#include <algorithm>



void QuickSort(int *Array, int Size) {
	int temp, pivot, i = 0, j = Size - 1;
	pivot = Array[Size / 2]; // Size>>1
	do {
		for(; Array[i] < pivot;) i++;
		for(; Array[j] > pivot;) j--;
		if(i <= j) {
			temp = Array[i];
			Array[i] = Array[j];
			Array[j] = temp;
			i++;
			j--;
		}
				
	}while(i <= j);
	
	if(j > 0) QuickSort(Array, j + 1); // was j
	if(Size > i) QuickSort(Array + i, Size - i); // was  Array + i 
}



void twoPointers(int *A, int Size, int Result) {
	int Begin = 0, End = Size - 1;
	for(int i = 0; A[Begin] + A[End] != Result; i++) {
		std::cout <<" " <<  A[Begin] << ' ' << A[End] << "\n";
		
		if(A[Begin] + A[End] > Result) A[End--];
		else if(A[Begin] + A[End] < Result) A[Begin++];
		if(A[Begin] + A[End] == Result) {
			std::cout <<"\n" << A[Begin] <<' ' << A[End];
		}
		if(A[End] == 0 && A[Begin] + A[End] != Result){
			std::cout << "No result";
			break;
		} 
		
	}
	
}

// a = {2, 7, 11, 15}. result = 9
//if > res end--; if < res begin++

int main() {
//	int a[] = {22, 4, 11, 15, 34, 10, 66, 0, 12, 3, 2, 4, 7, 90};
//	int a[] = {192, 31, 0, 5, 6, 88, 12, 23, 4, 2, 45, 213};
//	int a[] = {2, 7, 11, 15};
//	int a[] = {192, 31, 0, 5, 6, 88, 12, 23, 0, 2, 45, 213};
//	int a[] = {22, 1, 11, 15, 34, 10, 66, 0, 12, 3, 99, 4, 7, 90, 5, 0}; //0 0 1 3 4 5 7
	
	int Result = 9, Len = sizeof(a) / sizeof(a[0]); 
	int Begin = 0, End = Len - 1, newEnd;
	
//	std::sort(a, a + Len);
	QuickSort(a, Len);
	twoPointers(a, Len, 9);
	
}




