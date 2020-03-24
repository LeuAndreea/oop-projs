#include "OperationStack.h"
#include "controller.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ProductController* createController(ProductRepository *repo) {
	ProductController *ctrl=(ProductController*)malloc(sizeof(ProductController));
	ctrl->repo = repo;
	ctrl->redoStack = createOperationStack();
	ctrl->undoStack = createOperationStack();
	return ctrl;
}

void destroyController(ProductController* ctrl) {
	destroyRepository(ctrl->repo);
	destroyStack(ctrl->undoStack);
	destroyStack(ctrl->redoStack);
	free(ctrl);
}

ProductRepository* getAll(ProductController *ctrl) {
	return ctrl->repo;
}

int addProductController(char name[], char category[], double quantity, char expirationDate[], ProductController *ctrl) {
	int i = findProduct(name, category, ctrl->repo);
	if (i == -1) {
		Product* p = createProduct(name, category, quantity, expirationDate);
		i = addProduct(p, ctrl->repo);
		if (i != -1) {
			Operation *o = createOperation(p, 1);
			
			push(ctrl->undoStack, o);
			destroyOperation(o);
		}
	}
	else {
		i = 0;
		updateProductController(name, category, quantity, ctrl);
	}
	return i;

}
		



int deleteProductController(char name[], char category[], ProductController *ctrl) {
	Product *p = getProductRepo(name, category, ctrl->repo);
	int i = deleteProduct(name, category, ctrl->repo);
	
	if (i == 1) {
		Operation *o = createOperation(p, 2);
		push(ctrl->undoStack, o);
		destroyOperation(o);
	}
	destroyProduct(p);
	return i;
}

int updateProductController(char name[], char category[], double quantity, ProductController *ctrl) {
	Product *p = getProductRepo(name, category, ctrl->repo);
	int i = updateProduct(name, category, quantity, ctrl->repo);
	if (i==1){
		Operation *o = createOperation(p, 3);
		push(ctrl->undoStack, o);
		destroyOperation(o);
	}
	destroyProduct(p);
	return i;
}

ProductRepository* sortDescendingName(ProductController* ctrl) {
	return sortProducts(compareNames, ctrl->repo);
}

ProductRepository* filterBySubstringSortByQuantity(char substring[], ProductController *ctrl) {
	ProductRepository* repo_res_f,*repo_res;
	repo_res_f = filterBySubstring(substring, ctrl->repo);
	repo_res = sortProducts(compareQuantity, repo_res_f);
	free(repo_res_f);
	return repo_res;
}

int undo(ProductController* ctrl){
	
	if (isEmpty(ctrl->undoStack))
		return 0;

	Operation* operation = pop(ctrl->undoStack);

	if (getOperationType(operation) == 1) {
		push(ctrl->redoStack, operation);
		int i = deleteProduct(getName(getProduct(operation)), getCategory(getProduct(operation)), ctrl->repo);
	}
	else if (getOperationType(operation) == 2){
		push(ctrl->redoStack, operation);
		Product *p = copyProduct(getProduct(operation));
		addProduct(p, ctrl->repo);
	}
	else {
		updateProductController(getName(getProduct(operation)), getCategory(getProduct(operation)), getQuantity(getProduct(operation)), ctrl);
		Operation *operation = pop(ctrl->undoStack);
		push(ctrl->redoStack, operation);
	}
	destroyOperation(operation);

	return 1;
}

int redo(ProductController* ctrl)
{

	if (isEmpty(ctrl->redoStack))
		return 0;
	
	Operation* operation = pop(ctrl->redoStack);

	if (getOperationType(operation) == 1){
		Product *p = copyProduct(getProduct(operation));
		push(ctrl->undoStack, operation);
		addProduct(p, ctrl->repo);
	}
	else if (getOperationType(operation) == 2) {
		deleteProduct(getName(getProduct(operation)), getCategory(getProduct(operation)), ctrl->repo);
		push(ctrl->undoStack, operation);
	}
	else
		updateProductController(getName(getProduct(operation)), getCategory(getProduct(operation)), getQuantity(getProduct(operation)), ctrl);
	destroyOperation(operation);

	return 1;
}

ProductRepository* filterCategoryExpirationDate(char category[ ],int nbOfDays,ProductController *ctrl) {
	ProductRepository *repo_res = filterByCategory(category,ctrl->repo);
	//printf("repo after filt\n");
	ProductRepository *repo_res2 = filterByExpirationDate(nbOfDays, repo_res);
	//printf("repo after filt2\n");
	free(repo_res);
	return repo_res2;
}


