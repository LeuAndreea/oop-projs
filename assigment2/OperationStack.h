#include "product.h"
#pragma once


typedef struct {
	int type,index;
	Product *product;
} Operation;


typedef struct {
	Operation* operations[100];
	int length;

}OperationStack;


/*Creates an operation 
IN: the product, the type of the operation
OUT: operation*/
Operation* createOperation(Product *p, int type);

/*Copyes an operation
IN: an operation
OUT: copy of the operation*/
Operation* copyOperation(Operation* o);

/*Gets the type of an opeation
IN: an operation
OUT: the type of the operation*/
int getOperationType(Operation* o);

/*Returns the product from the operation
IN: an operation
OUT:a product */
Product* getProduct(Operation* o);

/*Destroys an operation
IN: an operation
OUT: - */
void destroyOperation(Operation *o);

//void toStringO(Operation *o);

/*Creates an operation stack
IN: -
OUT: an operation stack*/
OperationStack* createOperationStack();

/*Destroys an object of type oepration stack.
IN: the stack
OUT: -*/
void destroyStack(OperationStack* stack);

/*Adds a new operation to the stack.
IN: a stack and an operation
OUT: -*/
void push(OperationStack* stack, Operation* o);

/*Returns the last operation from a stack and then deletes it.
IN: operation stack
OUT: last oepration from stack*/
Operation* pop(OperationStack* s);

/*Checks if the stack is empty
IN: 1 if the stack is empty,0 otherwise*/
int isEmpty(OperationStack *s);

/*Checks if the stack is full
IN: 1 if the stack is full,0 otherwise*/
int isFull(OperationStack *s);

//void toStringStack(OperationStack* stack);
