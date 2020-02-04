// Abdulsamet AKTAS cs300 Hw2 Enjoy :)
#ifndef HASHMAP_H_
#define HASHMAP_H_

#include<iostream>
#include<string>
#define SIZE 4096

using namespace std;


template <class Key, class Value>
struct Node
{
	Key k;
	Value v;
	Node::Node()
	{
		v = -1;
	}

};
template<class Key, class Value>
class HashMap
{

public:
	HashMap(); // hashmap constructor
	int function(const Key & k); // hash function
	void insertion(Key & k, Value value); // inserting into the map
	int getValue(const Key & k); 
	bool ifexist(const Key & k);


private:
	Node <Key, Value> table_array[SIZE];
	int size;
};

template<class Key, class Value>
HashMap<Key, Value>::HashMap()
{
	size = 4096;
	Node<Key, Value> temp;

	for (int i = 0; i < size; i++)
	{
		table_array[i] = temp;
	}
}

template<class Key, class Value>
int HashMap<Key, Value>::function(const Key & k)
{
	int index = (k[1]) * 11 + 17; // random index, I multiplied by prime number
	if (index < 0)
		index = index + size;
	index = index % size;
	return(index);
}

template<class Key, class Value>
bool HashMap<Key, Value>::ifexist(const Key & key)
{
	int x = 0;
	while (x < size)
	{
		if (table_array[x].k == key)
			return true;
		x++;
	}
	return false;
}

template<class Key, class Value>
void HashMap<Key, Value>::insertion(Key & k, Value value)
{
	Node<Key, Value> temp;
	int index1 = function(k);
	temp.k = k;
	temp.v = value;
	while (index1 < size && table_array[index1].k != k && table_array[index1].v != -1)
	{
		index1++;
	}
	table_array[index1] = temp;
}



template<class Key, class Value>
int HashMap<Key, Value>::getValue(const Key & k)
{
	int x = function(k);
	while (x < (size - 1) && table_array[x].k != k)
		x++;
	return table_array[x].v;
}

#endif