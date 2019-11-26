// Expand.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "windows.h"
using namespace std;
int main()
{
	HMODULE hDLL = LoadLibrary(L"D:\\c++文件\\Expand\\Debug\\MathLibrary.dll");

	if (hDLL == NULL)
	{
		cout << "失败";
		return 0;
	}
	typedef void (*PINIT)(const unsigned long long a, const unsigned long long b);
	PINIT fibonacci_init = (PINIT)GetProcAddress(hDLL, "fibonacci_init");
	typedef unsigned (*P)();
	P fibonacci_index = (P)GetProcAddress(hDLL, "fibonacci_index");
	typedef unsigned long long (*P1)();
	P1 fibonacci_current = (P1)GetProcAddress(hDLL, "fibonacci_current");
	typedef bool (*P2)();
	P2 fibonacci_next = (P2)GetProcAddress(hDLL, "fibonacci_next");
	// Initialize a Fibonacci relation sequence.
	fibonacci_init(1, 1);
	// Write out the sequence values until overflow.
	do {
		std::cout << fibonacci_index() << ": "
			<< fibonacci_current() << std::endl;
	} while (fibonacci_next());
	// Report count of values written before overflow.
	std::cout << fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << std::endl;

	FreeLibrary(hDLL);
}
