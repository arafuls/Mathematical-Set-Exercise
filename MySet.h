// AUTHOR - AUSTIN RAFULS
#pragma once
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

template <class T>
class MySet
{
public:
	MySet();
	MySet(std::vector<T> elems);
	void add(T item);
	void remove(T item);
	int size();
	bool exists(T item);
	std::vector<T> _union(MySet object);
	std::vector<T> intersect(MySet object);
	void empty();
	void display();

private:
	std::vector<T> elements;
};
