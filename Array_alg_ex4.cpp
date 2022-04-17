#include <iostream>
#include <algorithm>
#include <cmath>
#include <time.h>

using namespace std;


void Print(int *Data, int N) {
	cout <<"\nYour Data: ";
	for(int i = 0; i < N; i++) cout << Data[i] <<", ";
}

int GetRandom(int from, int to, bool NeedInit = false) {
	int result;
	if(NeedInit)srand((unsigned)time(0));
	result = rand()%(to - from + 1) + from;
	return result;
	
}

void SetRandom(int* Data, int N) {
	GetRandom(0, 10, true);
	for(int i = 0; i < N; i++) {
		Data[i] = GetRandom(-10, 10);
	}
}


int BinarySearch(int *Data, int N) {
	int Mid, Left = 0, Right = N - 1;
	do {
		Mid = (Right + Left) / 2;
//		cout << "\n L = " <<Left << " R = " <<Right <<" M = " <<Mid;
		if(Data[Mid] < 0) Left = Mid;
		else Right = Mid;
	} while((Right - Left) > 1);
	if(Data[Left] >= 0) return Left;
	else return Right;
}


bool TakeNextR(int *Array, int N, int *Prev, int *Elem) {
	if((*Prev) + 1 >= N) return false;
	(*Prev)++;
	(*Elem) = Array[*Prev];
	return true;
}

bool TakeNextL(int *Array, int N, int *Prev, int *Elem) {
	if((*Prev) - 1 < 0) return false;
	(*Prev)--;
	(*Elem) = Array[*Prev];
	return true;
}


void LRPrint(int *Data, int N, int CutPoint) {
	cout << "\nLeft data: ";
	int LPrev = CutPoint, LElem;
	while(TakeNextL(Data, N, &LPrev, &LElem)) cout <<LElem << ", ";
	cout << "\nRight data: ";
	int RPrev = CutPoint - 1, RElem;
	while(TakeNextR(Data, N, &RPrev, &RElem)) cout <<RElem << ", ";
}


void CombineLR(int *Data, int N, int CutPoint, int **Combined) {
	(*Combined) = new int[N];
	int LHand, RHand, LPrev = CutPoint, RPrev = CutPoint -1, Cursor = 0;
	bool GotR, GotL;
	GotL = TakeNextL(Data, N, &LPrev, &LHand);
	GotR = TakeNextR(Data, N, &RPrev, &RHand);
	while(Cursor < N && GotL && GotR) {
		if(abs(LHand) < RHand) {
			(*Combined)[Cursor] = LHand;
			GotL = TakeNextL(Data, N, &LPrev, &LHand);
		}
		else {
			(*Combined)[Cursor] = RHand;
			GotR = TakeNextR(Data, N, &RPrev, &RHand);
		}
		Cursor++;
	}
	if(!GotL) {
		while(GotR && Cursor < N) {
			(*Combined)[Cursor] = RHand;
			Cursor++;
			GotR = TakeNextR(Data, N, &RPrev, &RHand);
		}
	}
	else {
		while(GotL && Cursor < N) {
			(*Combined)[Cursor] = LHand;
			Cursor++;
			GotL = TakeNextL(Data, N, &LPrev, &LHand);
		}
	}

}



void ModuleSort(int *Data, int N) {
	sort(Data, Data + N);
	Print(Data,N);
	int Mid = BinarySearch(Data, N);
	LRPrint(Data, N, Mid);
	int *Combined;
	
	CombineLR(Data, N, Mid, &Combined);
	for(int i = 0; i < N; i++) Data[i] = Combined[i];
	delete[] Combined;
	
}



int main() {
	int N = 10;
	int *Data;
	Data = new int[N];
	SetRandom(Data, N);
	Print(Data, N);
	ModuleSort(Data, N);
	Print(Data, N);
	delete[] Data;
	
	return 0;
}




	
