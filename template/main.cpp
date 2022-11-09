#include "MyArray.h"
#include "Fraction.h"

int main()
{
	int arr[5] = { 5, -8, -3, 2 , 4 };
	MyArray<int> array;
	array.setArray(arr, 5);
	array.print();

	cout << array[1] << "\n";
	
	array[1] = 10;
	array.print();

	array.sort();
	array.print();

	Fraction arr2[5] = { {1,2}, {3,4}, {5,6}, {7,8}, {9,10} };
	MyArray<Fraction> array2;
	array2.setArray(arr2, 5);
	array2.print();

	cout << array2.getAt(2) << "\n";

	array2[2] = Fraction(1, 1);
	array2.print();

	array2.sort();
	array2.print();



	return 0;
}