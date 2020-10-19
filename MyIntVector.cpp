/*
	Filename: MyIntVector.cpp
  2019203016 Chulmin Park

	Implementations of the member functions are in this file.
*/

#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>         // To use 'size_t'
#include <algorithm>       // To use 'copy' function
#include "MyIntVector.h"

#define uint unsigned int
using namespace std;

MyIntVector::MyIntVector(const MyIntVector& v)
// Copy constructor: Creates a new instance by deep coping a source object.
{
	data = new int[(v.v_capacity)];
	v_capacity = v.v_capacity;
	used = v.used;
	std::copy(v.data, v.data + used, data);
}

/** Member Functions **/

void MyIntVector::pop_back()
// Pop back: Removes the last element in the vector and reduce the vector size by one.
{
	if (size() == 0) return;   // Return if vector is empty.

	data[(this->used) - 1] = NULL;
	this->used--;
}

void MyIntVector::push_back(int x)
// Adds a new element 'x' at the end of the vector, after its current last element.
{
	if (this->used == v_capacity)
		reserve(capacity() + Default_Capacity);
		
	data[this->used] = x;
	this->used++;
}

size_t MyIntVector::capacity() const
// Returns the size of the allocated storage space for the elements of the vector container.

{
	return this->v_capacity;
}

size_t MyIntVector::size() const
// Returns the number of elements in the vector container.
{
	return this->used;
}

void MyIntVector::reserve(size_t n)
// Reserve: Increase or decrease the capacity of vector container.
{
	int *larger_array;
	if (n == v_capacity)
		return;
	if (n < used)   // Minimum size of vector is 'used'.
	{
		n = used;
		cout << "reserve info! Entered value is less than the size being used." << endl;
		cout << "Capacity was reduced to " << this->size() << endl;
	}
	larger_array = new int[n];
	copy(data, data + used, larger_array);
	delete[] data;
	data = larger_array;
	v_capacity = n;
}

bool MyIntVector::is_empty() const
// Is empty: Returns whether the vector container is empty.
{
	if (size() == 0)
		return 1;
	else
		return 0;
}

void MyIntVector::clear()
// Clear: All of the elements in the container are removed.
{
	for (uint i = 0; i < used; i++)
		data[i] = NULL;
	this->used = 0;
	this->v_capacity = Default_Capacity;
}

/** Operators **/

MyIntVector& MyIntVector::operator= (const MyIntVector& v)
// Deep copy RHS to LHS.
{
	if (this == &v)
		return *this;
	if (v_capacity != v.v_capacity)
	{
		delete[] data;
		data = new int[v.v_capacity];
		v_capacity = v.v_capacity;
	}
	used = v.used;
	copy(v.data, v.data + this->size(), this->data);
	return *this;
}

void MyIntVector::operator+=(MyIntVector& v)
// Appends RHS object to LHS one.
{
	if (v.is_empty())   // No work for empty vector.
		return;
	while (this->size() + v.size() > this->capacity())   // Reserve until the space be enough.
		this->reserve(this->v_capacity + Default_Capacity);

	copy(v.data, v.data+v.size(), this->data+this->size());
	used += v.used;
}

int MyIntVector::operator[] (uint idx)
// Returns (idx)th element of the vector container.

{
	if (idx < 0)
	{
		cout << "[] operator Error! Can't use a negative index." << endl;
		exit(1);
	}
	if (idx >= this->size())
	{
		cout << "[] operator Error! There is no value in this index." << endl;
		exit(1);
	}
	return data[idx - 1];
}

MyIntVector MyIntVector::operator+ (const MyIntVector& v)
// Returns an object that is a vector-sum of the two operand objects.
{
	if (this->size() != v.size())
		cout << "+ operator Error! Two vectors must have same size." << endl;

	MyIntVector temp = *this;
	for (uint i = 0; i < this->size(); i++)
		temp.data[i] += v.data[i];

	return temp;
}

MyIntVector MyIntVector::operator- (const MyIntVector& v)
// Returns an object that is a vector-difference of the two operand objects.
{
	if (this->size() != v.size())
		cout << "- operator Error! Two vectors must have same size." << endl;

	MyIntVector temp = *this;
	for (uint i = 0; i < this->size(); i++)
		temp.data[i] -= v.data[i];

	return temp;
}

int MyIntVector::operator* (const MyIntVector& v)
// Returns the scalar product value of the two operand objects.
{
	if (this->size() != v.size())
		cout << "* operator Error! Two vectors must have same size." << endl;

	int pdt = 0;
	for (uint i = 0; i < this->size(); i++)
		pdt += (this->data[i] * v.data[i]);

	return pdt;
}

bool MyIntVector::operator== (const MyIntVector& v)
// Returns whether or not the two operand vectors are the same.
{
	if (this->size() != v.size())
		return false;

	for (uint i = 0; i < this->size(); i++)
		if (this->data[i] != v.data[i])
			return false;

	return true;
}

MyIntVector MyIntVector::operator- ()
// Returns an object of which each element is the unary negation.
{
	if (this->is_empty())   // return 'this' object if it's empty.
		return *this;

	MyIntVector temp = *this;
	for (uint i = 0; i < temp.size(); i++)
		temp.data[i] *= (-1);

	return temp;
}

MyIntVector MyIntVector::operator() (int x)
// Makes every element of this object be 'x'.
{
	MyIntVector temp = *this;
	for (uint i = 0; i < this->size(); i++)
		temp.data[i] = x;

	return temp;
}

void MyIntVector::show_vector() const
// Prints the whole vector.
{
	cout << "[ ";
	for (uint i = 0; i < this->size(); i++)
		cout << this->data[i] << ", ";
	cout << "]" << endl;
}
