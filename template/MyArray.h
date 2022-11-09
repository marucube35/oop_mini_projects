#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
private:
	T* _array;
	int _size;

public:
	MyArray() {
		_array = nullptr;
		_size = 0;
	}
	MyArray(int size)
	{
		_array = new T[size];
		_size = 0;
	}
	~MyArray()
	{
		if (_array != nullptr)
		{
			delete[] _array;
		}
	}

	T& getAt(int index) { return _array[index]; }
	T& operator[](int index) { return getAt(index); }

public:
	void setArray(T* array, int size)
	{
		if (_array != nullptr)
			delete[] _array;

		_size = size;
		_array = new T[size];

		for (int i = 0; i < size; i++)
		{
			try { _array[i] = array[i]; }
			catch (exception ex)
			{
				cout << ex.what() << "\n";
			}
		}
	}
	void print()
	{
		cout << "\n";
		for (int i = 0; i < _size; i++)
		{
			cout << _array[i] << " ";
		}
		cout << "\n";
	}
	void sort()
	{
		for (int i = 1; i < _size; i++)
		{
			T key = _array[i];
			int j = i - 1;

			while (j >= 0 && _array[j] > key)
			{
				_array[j + 1] = _array[j];
				j = j - 1;
			}
			_array[j + 1] = key;
		}
	}
};

