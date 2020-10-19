/*
	Filename: MyIntVector.h
	2019203016 Chulmin Park
	
	Prototypes and specifications for the functions are in this file.
*/

#pragma once
#define Default_Capacity 30
#define uint unsigned int

class MyIntVector
{
public:
	/** Constructors **/

	// Default Constructor: Initialize private members.
	MyIntVector(size_t init_capacity = Default_Capacity)
		:v_capacity(init_capacity), used(0)
	{data = new int[v_capacity];}

	// Copy Constructor: Creates a new instance by deep coping a source object.
	// The code is in 'MyIntVector.cpp'.
	MyIntVector(const MyIntVector& v);

	// Destructor: Frees dynamic memory.
	~MyIntVector() { delete [] data; }
	

	/** Member Functions **/

	// Pop back: Removes the last element in the vector and reduce the vector size by one.
	// Precondition: The vector should have at least one element. (If zero, just return)
	// Postcondition: The last element of the vector will be deleted, also size will be reduced by one.
	void pop_back();

	// Push back: Adds a new element 'x' at the end of the vector, after its current last element.
	// Precondition: The new element is integer type. And, MyIntVector's memory is available.
	// Postcondition: 'x' will be the last element and increases vector's used by 1. If the vector was full, it gains 30 more capacity.
	void push_back(int x);

	// Returns the size of the allocated storage space for the elements of the vector container.
	// Precondition: 'MyIntVector' should be constructed successfully.
	// Postcondition: Return the size of container's allocated space. 
	size_t capacity() const;

	// Returns the number of elements in the vector container.
	// Precondition: 'MyIntVector' should be constructed successfully.
	// Postcondition: Return the number of elements.
	size_t size() const;

	// Reserve: Increase or decrease the capacity of vector container.
	// Precondition: parameter 'n' must bigger than 'used' value.
	// Postcondition: The capacity of the vector is increased or decreased to 'n'
	void reserve(size_t n);

	// Is empty: Returns whether the vector container is empty, i.e., whether or not its size is 0.
	// Precondition: MyIntVector's memory is available.
	// Postcondition: If it is empty, 1 is returned. If not, 0 is returned.
	bool is_empty() const;

	// Clear: All the elements of the vector are removed.
	// Precondition: MyIntVector's memory is available.
	// Postcondition: The vector will lose all data, and it's capacity will be initialized.
	void clear();


	/** Operators **/
	
	// Operator '=': Deep copy RHS to LHS.
	// Precondition: Two vectors in RHS and LHS are available.
	// Postcondition: RHS is copied to LHS. Chaning assignment is able.
	MyIntVector& operator = (const MyIntVector& v);

	// Operator '+=': Appends RHS object to LHS one.
	// Precondition: Two vectors in RHS and LHS are available.
	// Postcondition: RHS vector is appended to LHS. If empty sapce is not enough, it is reserved automatically.
	void operator += (MyIntVector& v);

	// Operator '[]': Returns (idx)th element of the vector container. (Start with index zero)
	// Precondition: 'idx' is a non-negative integer and less than vector's used size.
	// Postcondition: Return (idx)th element.
	int operator [] (uint idx);

	// Binary Operator '+': Returns an object that is a vector-sum of the two operand objects.
	// Precondition: Two vectors have same size of elements.
	// Postcondition: Returns vector that is vector-sum of each element.
	MyIntVector operator + (const MyIntVector& v);

	// Binary Operator '-': Returns an object that is a vector-difference of the two operand objects.
	// Precondition: Two vectors have same size of elements.
	// Postcondition: Returns vector that is vector-difference of each element.
	MyIntVector operator - (const MyIntVector& v);

	// Binary Operator '*': Returns the scalar product (or dot product) value of the two operand objects.
	// Precondition: Two vectors have same size of elements.
	// Postcondition: Returns the scalar product value.
	int operator * (const MyIntVector& v);

	// Binary Operator '==': Returns whether or not the two operand vectors are the same.
	// Precondition: Two vectors are available.
	// postcondition: Returns 1 when all of each element are same, and returns 0 if not.
	bool operator == (const MyIntVector& v);
	
	// Unary Operator '-': Returns an object of which each element is the unary negation of the operand object.
	// Precondition: The vector is available.
	// Postcondition: Returns an object of which each element is the unary negation.
	MyIntVector operator - ();

	// Unary Operator '()': Makes every element of this object be 'x'.
	// Precondition: A vector is available. And, x is an integer.
	// Postcondition: Returns a vector which elements are all x.
	MyIntVector operator () (int x);


	/** The Others **/

	// This function prints the whole vector. (for the test code)
	void show_vector() const;

private:
	int *data;
	size_t used;
	size_t v_capacity;   // means 'variable_capacity'
};
