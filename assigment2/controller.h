#pragma once
#include "repository.h"
#include "OperationStack.h"
typedef int(*sortingCondition)(Product *p1, Product *p2);

typedef struct {
	ProductRepository *repo;
	OperationStack *undoStack, *redoStack;
} ProductController;

/*Creates a controller
IN: the repository that the controller will use
OUT:the controller*/
ProductController* createController(ProductRepository *repo);

/*Frees the memory occupied by the controller
IN: a controller
OUT: -*/
void destroyController(ProductController* ctrl);

/*Returns the whole repository from a controller
IN: a controller
OUT: its repository*/
ProductRepository* getAll(ProductController *ctrl);

/*Adds a product to a repository through a controller
IN: the product and the controller
OUT: -*/
int addProductController(char name[], char category[], double quantity, char expirationDate[], ProductController *ctrl);

/*Delets a product from a repository through a controller
IN: name and category of the product the user want deleted
OUT: 0 if the product was deleted, -1 if it was not in the repository*/
int deleteProductController(char name[], char category[], ProductController *ctrl);

/*Updates a product from a repository through a controller
IN: name and category og the product the user wants to update, the new quantity
OUT: 0 if the product was succesfully updates,-1 if it was not in the repository*/
int updateProductController(char name[], char category[], double quantity, ProductController *ctrl);

/*Sorts a list by descending name
IN: a controller
OUT: a sorted list*/
ProductRepository* sortDescendingName(ProductController* ctrl);

/* Filters products by searching for a given substring in a name
returns the list sorted by quantity
IN: a substring and a controller
OUT:filtered & sorted repository*/
ProductRepository* filterBySubstringSortByQuantity(char substring[], ProductController *ctrl);

/*Undoes an operation
IN: Product controller
OUT: 1 if undo was succesful, 0 if there were no undoes to be made.*/
int undo(ProductController* ctrl);

/*Redoes an operation
IN:product controller
OUT:1 if the redo was succesful, 0 if there were not redoes to be made. */
int redo(ProductController *ctrl);

ProductRepository* filterCategoryExpirationDate(char category[ ], int nbOfDays, ProductController *ctrl);