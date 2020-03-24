#include "DynamicVector.h"

DynamicVector::DynamicVector(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& v) {
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}
DynamicVector::~DynamicVector()
{
	delete[] this->elems;
}


DynamicVector& DynamicVector::operator=(const DynamicVector& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new TElement[this->capacity];

	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

DynamicVector DynamicVector::operator+(TElement e) {
	if (this->size == this->capacity)
		this->resize();

	this->elems[this->size++] = e;
	return *this;
}

DynamicVector operator+(const TElement e, const DynamicVector &v) {
	DynamicVector vect = v;
	vect + e;
	return vect;
}

void DynamicVector::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

int DynamicVector::getSize() const { return this->size; }

TElement DynamicVector::getElementAtIndex(const int index)const { return this->elems[index]; }

TElement* DynamicVector::getAllElems() const { return this->elems; }

void DynamicVector::add(TElement& e) {
	if (this->size == this->capacity)
		this->resize();

	this->elems[this->size++] = e;
}

void DynamicVector::deleteElement(int index)
{
	int length = this->size;
	for (int i = index; i < length - 1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}

void DynamicVector::modifyElem(int index, TElement e) {
	this->elems[index] = e;
}






