#include <iostream>
#include <algorithm>
#include <cmath>


int main() {
	int a[] {-100, -50, -5, 1, 10, 15};
//	int a[] {-99, 2, 1, -23, 4, -1};
	int Size = sizeof(a) / sizeof(a[0]);
//	std::sort(a, a + Size, [](int a, int b) {return abs(a) < abs(b); }); // using lambda
	int L, R;
	std::sort(a, a + Size);
	std::cout <<"Sorted by abs: ";
	
	for(int i = 0; i < Size; i++) {
		if(a[i] > 0) {
			L = i - 2;
			R = i - 1;
		}
	}
	
	for(int i = 0; i < Size - 1; i++) {
//		std::cout << " a[L]" <<a[L] << ' ' << "a[R] " << a[R];
		if(abs(a[L]) < abs(a[R])) {
			std::cout << a[L] <<" ";
			a[L--];
		} 
		if(abs(a[L]) > abs(a[R])){
			std::cout << a[R] <<" ";
			a[R++];
		} 
		
	}	
	
}
