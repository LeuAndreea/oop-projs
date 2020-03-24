#pragma once

typedef struct {
	char* name;
	char* category;
	double quantity;
	char* expirationDate;
} Product;

/*Creates a product
IN:name,category,quantity and date of product
OUT:the product*/
Product* createProduct(char name[ ], char category[ ], double quantity, char expirationDate[ ]);

/*Frees the memory used for storing a product *
IN: a product
OUT: -*/
void destroyProduct(Product* p);

/*Copyes a product 
IN: a product
OUT: copy of product*/
Product* copyProduct(Product* p);

/*Returns the name of a product
IN: a product p
OUT: the name of the product*/
char* getName(Product *p);

/*Returns the category of a product
IN: a product p
OUT: the category of the product*/
char* getCategory(Product *p);

/*Returns the quantity of a product
IN: a product p
OUT: the quantity of the product*/
double getQuantity(Product *p);

/*Returns the expiration date of a product
IN: a product p
OUT: the expiration date of the product*/
char* getExpirationDate(Product *p);

/*Transforms the product into a string representation
IN: the product and an empty string
OUT:the string representaion of the product in the variable str*/
void toString(Product* p);

/*Compares the name of two products.
IN: two products
OUT: positive number if the first one is greater, negative otherwise*/
int compareNames(Product *p1, Product* p2);

/*Compares the quantity of two given products
IN : two products
OUT: 1 if the first has great quantity, -1 otherwise*/
int compareQuantity(Product *p1, Product* p2);

/*Verifies if two products are equal
IN: two produtcts
OUT: 1 if they are equal,-1 otherwise*/
int eq(Product *p1, Product *p2);