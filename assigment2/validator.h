#pragma once
#include "product.h"


/*Checks if the category is valid.
IN: the string representing the category, given by the user
OUT: 1 if it's valid, -1 otherwise*/
int validCategory(char category[]);

/*Checks if the expiration date is valid.
IN: the string representing the expiration date, given by the user
OUT: 1 if it's valid, -1 otherwise*/
int validExpirationDate(char expirationDate[]);

/*Checks if the Product is valid.
IN: the string representing the expiration date and the category, given by the user
OUT: 1 if it's valid, -1 otherwise*/
int validProduct(Product* p);