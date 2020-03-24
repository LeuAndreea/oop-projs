#pragma once
#include "controller.h"

typedef struct {
	ProductController* ctrl;
} UI;

/*Creates an UI.
IN: a controller
OUT:a UI*/
UI* createUI(ProductController* ctrl);

/*Frees the memory occupied by the ui
IN: UI
OUT: -*/
void destroyUI(UI* ui);

/*Reads an integer number
IN: message
OUT: integer*/
int readInteger(const char *message);

/*Reads a string
IN: message and an empty string
OUT: the string in the str variable*/
void readString(const char *message, char str[]);

/*Reads a command
IN:-
OUT: a command*/
int readCommand();

/*Prints the main menu
IN: -
OUT: -*/
void printMenu();

/*Print all the products contained in a repository
IN: a product repository
OUT -*/
void printProducts(ProductRepository* repo);

/*Submenu for adding a product
IN : the ui
OUT: 1 if product was added, 0 if it was updated and -1 if there was an error reading data*/
int addProductUI(UI* ui);

/*Submenu for deleting a product
IN: the ui
OUT : 1 if it was deleted,-1 if it was not in the repository.*/
int deleteProductUI(UI *ui);

/*Submenu for updating a product
IN: an ui
OUT: 1 if it was succesfully updated, -1 if it didn't exist.*/
int updateProductUI(UI *ui);

void filterCategoryExpirationDateUI(UI *ui);

/*Submenu for filtering products
IN: an ui
OUT: a filtered product repository*/
ProductRepository* filterProductsUI(UI *ui);

/*Starts the application
IN: a UI
OUT: -*/
void startUI(UI* ui);

