// AUTHOR - AUSTIN RAFULS
#include "MySet.h"

// Default Constructor
template<class T>
MySet<T>::MySet()
{
	empty();
}

// Custom Constructor
//	Use to instantiate a new set with pre-existing values.
template<class T>
MySet<T>::MySet(std::vector<T> elems)
{
	empty();

	typename std::vector<T>::iterator itr;
	for (itr = elems.begin(); itr != elems.end(); itr++)
	{
		elements.push_back(*itr);
	}
}

// Add Method
//	Use to add a unique element to the set
template<class T>
void MySet<T>::add(T item)
{
	if (exists(item))
	{
		std::cout << "[WARNING] Element (" << item << ") already exists and will be ignored." << std::endl;
	}
	else
	{
		elements.push_back(item);
	}
	return;
}

// Remove Method
//	Removes an element by searching for the value (NOT THE INDEX).
template<class T>
void MySet<T>::remove(T item)
{
	if (exists(item))
	{
		elements.erase( std::remove(elements.begin(),elements.end(),item), elements.end() );
	}
	else
	{
		std::cout << "[WARNING] Could not remove element (" << item << ") as it does not exist." << std::endl;
	}
	return;
}

// Size Method
//	Returns the numbers of elements within the set.
//	Also displays the result to stdout.
template<class T>
int MySet<T>::size()
{
	// Optional feature
	std::cout << "[SIZE] " << elements.size() << std::endl;

	return elements.size();
}

// Exists Method
//	Returns a boolean representing if the passed valued already
//	exists within the set.
template<class T>
bool MySet<T>::exists(T item)
{
	if (std::find(elements.begin(), elements.end(), item) != elements.end())
	{
		return true;
	}
	return false;
}

// _union Method
//	Starts with an underscore to avoid the 'union' reserved word.
//	Returns a vector representing the unioned set of the calling set
//	and the set passed by value.
template<class T>
std::vector<T> MySet<T>::_union(MySet object)
{
	std::vector<T> tmp;
	
	typename std::vector<T>::iterator itr;
	for (itr = elements.begin(); itr != elements.end(); itr++)
	{
		tmp.push_back(*itr);
	}

	for (itr = object.elements.begin(); itr != object.elements.end(); itr++)
	{
		if (!exists(*itr))
		{ 
			tmp.push_back(*itr);
		}
	}

	return tmp;
}

// Intersection Method
//	Returns a vector representing the intersected set from the calling
//	set and the set passed by value.
template<class T>
std::vector<T> MySet<T>::intersect(MySet object)
{
	std::vector<T> tmp;

	typename std::vector<T>::iterator itr;
	for (itr = object.elements.begin(); itr != object.elements.end(); itr++)
	{
		if (std::find(elements.begin(), elements.end(), *itr) != elements.end())
		{
			tmp.push_back(*itr);
		}
	}

	return tmp;
}

// Empty Method
//	Empties out all values of the set.
template<class T>
void MySet<T>::empty()
{
	elements.clear();
}

// Display Method
//	Displays the contents of the set to stdout.
template<class T>
void MySet<T>::display()
{
	std::cout << "[DISPLAY] ";
	std::copy(elements.begin(), elements.end(), std::ostream_iterator<T>(std::cout, " "));
	std::cout << '\n';
}