#pragma once
#include <string.h>
#include "product.h"

typedef int(*sortingCondition)(Product *p1, Product *p2);
typedef struct {
	Product *products[100];
	int length;
} ProductRepository;

/*Create product repository
IN: -
OUT: an empty product repository*/
ProductRepository* createRepository();

/* Makes  a copy of a repository
IN: a repository
OUT: a copy of the repository*/
ProductRepository* copyRepository(ProductRepository* repo);

/*Frees the memoy occupied by the repository
IN: a product repository
OUT: -*/
void destroyRepository(ProductRepository* repo);

/*Returns the length of the repository/
IN: a product repository
OUT: the length of the repository*/
int getLength(ProductRepository* repo);

/*Searches for a product in the repository
IN: the name and the category of the product we want to find and the repoistory
OUT: returns the index of the product in the repository, -1 if it wasn't there*/
int findProduct(char name[], char category[], ProductRepository *repo);

/*Returns a product from the repository if it exists
IN: name,category of the wished product and a repository
OUT: the product or null if it is not in the repository*/
Product* getProductRepo(char name[], char category[], ProductRepository *repo);

/*Adds a product to the repository
IN: a product and the repository
OUT: the repository with the product added, if it wasn't already there*/
int addProduct(Product* p, ProductRepository *repo);

/*Delets a product from the repository.
IN: the name and category of the prodcut the user wants to delete
OUT: 1 if it was succesful deleted, -1 if ti was not in the repository*/
int deleteProduct(char name[], char category[], ProductRepository *repo);

/*Updates data of a product.
IN: name and category of the product, new quantity
OUT: 1 if it was succesful updated,-1 if it was not there.*/
int updateProduct(char name[], char category[],double quantity, ProductRepository *repo);

/*Filters product which contains a given substring
IN: a substring, a repository
OUT: the filtered repository*/
ProductRepository* filterBySubstring(char substring[], ProductRepository* repo);

/*Sorts elements of an array of a repository using quick sort method
IN: Starting and finishing position, a repository, and a sorting condition
OUT : -*/
void quickSort(int i, int j, ProductRepository* repo, sortingCondition c);

/*Makes a copy of a repository and then sorts it.
IN: the sorting condition a repository
OUT : a sorted repository*/
ProductRepository* sortProducts(sortingCondition c, ProductRepository* repo);


ProductRepository* filterByCategory(char category[],ProductRepository *repo);

ProductRepository* filterByExpirationDate(int nbOfDays,ProductRepository* repo_res);