#include "OperationStack.h"
#include <stdlib.h>

Operation* createOperation(Product *p, int type) {
	Operation *o = (Operation*)malloc(sizeof(Operation));
	o->product = copyProduct(p);
	o->type = type;
	return o;
}

Operation* copyOperation(Operation *o) {
	Operation *newo = createOperation(getProduct(o), getOperationType(o));
	return newo;
}

int getOperationType(Operation* o) {
	return o->type;
}

Product* getProduct(Operation* o) {
	return o->product;
}

int getIndex(Operation *o) {
	return o->index;
}

void destroyOperation(Operation *o) {
	destroyProduct(o->product);
	free(o);
}

OperationStack* createOperationStack() {
	OperationStack* stack = (OperationStack*)malloc(sizeof(OperationStack));
	stack->length = 0;

	return stack;
}

void destroyStack(OperationStack* stack) {
	for (int i = 0; i < stack->length; i++)
		destroyOperation(stack->operations[i]);
	free(stack);
}

void push(OperationStack* s, Operation* o)
{
	if (isFull(s))
		return;

	s->operations[s->length++] = copyOperation(o);

}

Operation* pop(OperationStack* s)
{
	if (isEmpty(s))
		return NULL;
	s->length--;
	return s->operations[s->length];
}

int isEmpty(OperationStack *s)
{
	return (s->length == 0);
}

int isFull(OperationStack* s)
{
	return (s->length == 100);
}

