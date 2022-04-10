#include <iostream>
#include <algorithm>
#include <cmath>


int main() {
	int a[] {-100, -50, -5, 1, 10, 15};
	int Size = sizeof(a) / sizeof(a[0]);
	std::sort(a, a + Size, [](int a, int b) {return abs(a) < abs(b); }); // using lambda
	
	std::cout <<"Srorted by abs: ";
	for(int i = 0; i < Size; i++) {
		std::cout << a[i] << ' ';
	}
	
}
