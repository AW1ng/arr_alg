#include <iostream>
#include <vector>
#include <algorithm>


int main() {
//	int a[] = {-2, 1, 12, 1, 34, 4, 56, 78, 9, 4, 1, 3, -3, 4, -1, 243, 1, -54, 4,5};
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	int b[2];
	int max = 0;
	int Len = sizeof(a) / sizeof(a[0]);
	

	
	for(int i = 0; i < Len; i++) {
		for(int j = i + 1; j < Len; j++) {
			int temp = a[i] + a[j];
			if(temp > max && a[i] != a[j] && temp != max) {
				max = temp;
				b[0] = i; b[1] = j + 1;
			}	
		}
	}
	
	std::cout << b[0] <<' ' << b[1];
	
}
