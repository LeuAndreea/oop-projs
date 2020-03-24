#include "product.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Product* createProduct(char name[ ], char category[ ], double quantity, char expirationDate[ ]) {
	Product* p = (Product*)malloc(sizeof(Product));
	p->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(p->name, name);
	p->category = (char*)malloc(sizeof(char)*(strlen(category) + 1));
	strcpy(p->category, category);
	p->expirationDate = (char*)malloc(sizeof(char)*strlen(expirationDate) + 1);
	strcpy(p->expirationDate, expirationDate);
	p->quantity = quantity;

	return p;
}

void destroyProduct(Product* p) {
	if (p == NULL)
		return;

	free(p->name);
	free(p->expirationDate);
	free(p->category);
	free(p);
}

Product* copyProduct(Product* p) {
	Product *newp = createProduct(getName(p), getCategory(p), getQuantity(p), getExpirationDate(p));
	//toString(newp);
	return newp;
}

char* getName(Product *p) {
	return p->name;
}

char* getCategory(Product *p) {
	return p->category;
}

double getQuantity(Product *p) {
	return p->quantity;	
}

char* getExpirationDate(Product *p) {
	return p->expirationDate;
}

void toString(Product* p) {
	printf("Name: %s , Category:  %s, quantity: %2lf expiration date: %s\n", p->name, p->category, p->quantity, p->expirationDate);
}

int compareNames(Product *p1, Product* p2) {
	if (strcmp(getName(p1), getName(p2))>=0)
		return 1;
	return 0;
}

int compareQuantity(Product *p1, Product* p2) {
	if (getQuantity(p1) > getQuantity(p2))
		return 0;
	return 1;
}

int eq(Product *p1, Product *p2){
	if (strcmp(getName(p1), getName(p2)) != 0)
		return -1;
	if (strcmp(getCategory(p1), getCategory(p2)) != 0)
		return -1;
	if (strcmp(getCategory(p1), getCategory(p2)) != 0)
		return -1;
	if (strcmp(getExpirationDate(p1), getExpirationDate(p2)) != 0)
		return -1;
	if (getQuantity(p1)!= getQuantity(p2))
		return -1;
	return 1;
}