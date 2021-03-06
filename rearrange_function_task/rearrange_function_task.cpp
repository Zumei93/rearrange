// rearrange_function_task.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

// Complete rearrange function
// DO NOT MODIFY anything outside the below function
vector<int> rearrange(vector<int> elements) {
	stable_sort(elements.begin(), elements.end());

	struct elem
	{
		int decimalBaseOfElem;
		int numbersOf1;
	};
	vector<elem> tmpElems;
	unsigned elementsSize = elements.size();
	tmpElems.reserve(elementsSize);

	int numberOf1, tmpElem;
	for (const int elem : elements)
	{
		numberOf1 = 0;
		tmpElem = elem;
		do
		{
			if (tmpElem & 1)
				++numberOf1;
		} while (tmpElem >>= 1);
		tmpElems.push_back({ elem, numberOf1 });
	}
	stable_sort(tmpElems.begin(), tmpElems.end(), [](const elem& a, const elem& b) { return a.numbersOf1 < b.numbersOf1; });
	//
	vector<int> res;
	res.reserve(elementsSize);

	for (const elem& e : tmpElems)
		res.push_back(e.decimalBaseOfElem);
	return res;
}
// DO NOT MODIFY anything outside the above function

int main() {
	/* Read input from STDIN. Print output to STDOUT */
	unsigned int n;
	cin >> n;

	vector<int> elements;
	elements.reserve(n);

	for (unsigned int i = 0; i < n; ++i) {
		int element;
		cin >> element;
		elements.push_back(element);
	}

	// call rearrange function
	vector<int> sorted_elements = rearrange(elements);

	for (unsigned int i = 0; i < n; ++i) {
		cout << sorted_elements[i] << endl;
	}

	system("pause");
	return 0;
}

