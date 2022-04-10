#include <iostream>
#include <vector>
#include <algorithm>

void *sorted(int *A, int *T, int Size) {
	for(int i = 0; i < Size; i++) {
		for(int j = 0; j < Size - i - 1; j++) {
			if(T[j] > T[j + 1] ) {
				int temp = T[j];
				T[j] = T[j + 1];
				T[j + 1] = temp;
			}
		}
	}
		
}


int main() {
	int *A, *T;
	int Value, Size = 0, LastPos = -1, Step = 1, count = 0;
	A = new int[Size];
	
	while(Value != -2) {
		std::cin >> Value;
		Size += Step;
//		std::cout << "\nSize = " << Size <<'\n';
		T = new int[Size + Step]; 
		LastPos++;
		A[LastPos] = Value;
		if(Value == -1 || Value == -2) {
			count++;
		}
		for(int i = 0; i < Size; i++) {
			T[i] = A[i];
		}
			
		delete []A;
		A = T;
		
		sorted(A, T, Size);

//		std::sort(T, T + LastPos)
		if(Value == -1) {
			std::cout << "Sorted Array: ";
		for(int i = count; i < Size; i++) {
			std::cout << T[i] <<" ";
		}
			std::cout <<"\n" << T[4 + count];
		}
				
	}	
	
}



//int main() {
//	int Value;
//	std::vector<int> vec;
//	
//	for(; Value != -2;) {
//		std::cin >> Value;
//		vec.push_back(Value);
//
//		if(Value == -1) {
//			std::sort(vec.begin(), vec.end());
//			std::cout << vec[5];
//		}	
//	}
//	
//}
	
