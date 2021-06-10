#pragma once
#include <iostream>
using namespace::std;
class Iterator;

template <typename T> 
class MyVector
{
	T* arr;
	int arr_size;
public:
	class Iterator
	{
		T* it;
	public:
		Iterator() { it = nullptr; }
		Iterator(T* it) { this->it = it; }
		Iterator& operator++(int) 
		{
			Iterator itr(it);
			this->it++;
			return itr;
		}
		Iterator& operator--(int) 
		{
			Iterator itr(it);
			this->it--;
			return itr;
		}
		Iterator& operator++() 
		{
			this->it++;
			return *this;
		}
		Iterator& operator--() 
		{
			this->it--;
			return *this;
		}
		T& operator*() { return *it; }
		friend bool operator==(const Iterator& it1, const Iterator& it2)
		{
			if (it1.it == it2.it)
				return true;
			else return false;
		}
		friend bool operator!=(const Iterator& it1, const Iterator& it2)
		{
			if (it1.it != it2.it)
				return true;
			else return false;
		}
	};
	Iterator begin()
	{
		Iterator ptr(arr);
		return arr;
	}
	Iterator end() 
	{
		Iterator ptr(arr + arr_size);
		return ptr;
	}
	MyVector();
	~MyVector();
	void push(T);
	void push(T, int);
	T pop(int);
	T get_first();
	T get_last();
	bool empty();
	int size() { return arr_size; }
	void swap(int, int);
	void clear();
	T& operator[](const int& i)
	{
			return arr[i];
	};
};

template<typename T>
inline MyVector<T>::MyVector()
{
	arr = nullptr;
	arr_size = 0;
}

template<typename T>
inline MyVector<T>::~MyVector()
{
	delete[] arr;
	arr = nullptr;
	arr_size = 0;
}

template<typename T>
inline void MyVector<T>::push(T data)
{
	
	T* new_arr = new T[++arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		if (i != arr_size - 1)
		{
			new_arr[i] = arr[i];
		}
		else
		{
			new_arr[i] = data;
			break;
		}
	}
	delete[] arr;
	arr = new_arr;
}

template<typename T>
inline void MyVector<T>::push(T data, int pos)
{

	T* new_arr = new T[++arr_size];
	int j = -1;
	for (int i = 0; i < arr_size; i++)
	{
		j++;
		if (i != pos - 1)
		{
			new_arr[i] = arr[j];
		}
		else
		{
			new_arr[i] = data;
			new_arr[++i] = arr[j];
		}
	}
	delete[] arr;
	arr = new_arr;
}

template<typename T>
inline T MyVector<T>::pop(int a)
{
	if (!empty())
	{
		int i;
		for (i = 0; i < a - 1; i++);
		return arr[i];
	}
}

template<typename T>
inline T MyVector<T>::get_first()
{
	if(!empty())
		return arr[0];
}

template<typename T>
inline T MyVector<T>::get_last()
{
	if(!empty())
		return arr[arr_size - 1];
}

template<typename T>
inline bool MyVector<T>::empty()
{
	if (arr_size != 0)
		return false;
	else 
		return true;
}

template<typename T>
inline void MyVector<T>::clear()
{
	delete[] arr;
	arr_size = 0;
	arr = nullptr;
}

template<typename T>
inline void MyVector<T>::swap(int pos1, int pos2)
{
	T element = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = element;
}