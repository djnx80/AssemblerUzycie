// AssemblerUzycie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>

void ShowDecHexBin(int);
int mathAdd(int, int);
int mathSub(int, int);
int mathMul(int, int);
int mathDiv(int, int);

using namespace std;

int main()
{
	ShowDecHexBin(mathAdd(5, 10));
	ShowDecHexBin(mathAdd(5, 100));
	ShowDecHexBin(mathAdd(5, 1000));

	ShowDecHexBin(mathSub(5, 10));
	ShowDecHexBin(mathSub(5, 100));
	ShowDecHexBin(mathSub(5, 1000));

	ShowDecHexBin(mathMul(5, 10));
	ShowDecHexBin(mathMul(5, 100));
	ShowDecHexBin(mathMul(5, 1000));

	ShowDecHexBin(mathDiv(20, 10));
	ShowDecHexBin(mathDiv(20, 4));
	ShowDecHexBin(mathDiv(50, 0));

	getchar();
	return 0;
}

void ShowDecHexBin(int number) {
	cout << dec << number;
	cout << "\tHex:" << hex << number;
	cout << "\tBin:" << bitset<16>(number) << endl;
}

int mathAdd(int a, int b) {
	int result;
	cout << dec << a << "+" << dec << b << "=";
	__asm {
		mov eax, a
		mov ebx, b
		add eax, ebx
		mov result, eax
	}
	return result;
}

int mathSub(int a, int b) {
	int result;
	cout << dec << a << "-" << dec << b << "=";
	__asm {
		mov eax, a
		mov ebx, b
		sub eax, ebx
		mov result, eax
	}
	return result;
}

int mathDiv(int a, int b) {
	int result;
	cout << dec << a << "/" << dec << b << "=";
	__asm {
		mov eax, a
		mov ebx, b
		cmp ebx,0		// sprawdz czy b=0; jak tak to nie dziel
		jz Zero_NoDiv
		mov edx, 0	// przed dzieleniem trzeba wyzerowac rejestr edx
		div ebx
		mov result, eax
		jmp endHere

		Zero_NoDiv:
		mov result, 0
		endHere:
	}
	return result;
}

int mathMul(int a, int b) {
	int result;
	cout << dec << a << "*" << dec << b << "=";
	__asm {
		mov eax, a
		mov ebx, b
		mul ebx
		mov result, eax
	}
	return result;
}
