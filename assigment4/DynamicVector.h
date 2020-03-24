#pragma once

#pragma once
#include "Event.h"

typedef Event TElement;

class DynamicVector
{
private:
	TElement * elems;
	int size;
	int capacity;
public:
	/*Creates a vector taking the capactity of the parameter
	IN: the capacity
	OUT: a vector*/
	DynamicVector(int capacity = 10);
	/*Creates a vector by copying the vector given as parameter
	IN: a dynamic vector
	OUT: a new vector*/
	DynamicVector(const DynamicVector& v);
	/*Destroys the vector*/
	~DynamicVector();
	DynamicVector operator+(const TElement e);
	DynamicVector& operator=(const DynamicVector& v);
	/*Adds a new element to the vector
	IN: an element*/
	void add(TElement& e);
	/*Deletes the element from the given index.
	IN: an index*/
	void deleteElement(int index);
	/*Returns the element at a given index
	IN: an index*/
	TElement getElementAtIndex(const int index) const;
	/*Gets the size of the vector.
	IN: -
	OUT: the size of the vector*/
	int getSize() const;
	/*Returns all the elements from the vector
	IN: -
	OUT: the list of elements*/
	TElement* getAllElems() const;
	/*Modifies an element at  a given index.
	IN: an index and an element
	OUT: -*/
	void modifyElem(int index, TElement e);
private:
	/*Resizes the capacity of the vector if the size its exceeded
	IN:-
	OUT: -*/
	void resize(double factor = 2);
};

DynamicVector operator+(const TElement e, const DynamicVector &v);