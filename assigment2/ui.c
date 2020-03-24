#include "ui.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


UI* createUI(ProductController* ctrl) {
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = ctrl;

	return ui;
}

void destroyUI(UI* ui) {
	destroyController(ui->ctrl);
	free(ui);
}

int readInteger(const char *message) {
	
	int nb,valid;
	char s[20];
	
	printf("%s\n", message);
	while (1) {
		valid = 1;
		fgets(s, 20, stdin);
		s[strlen(s) - 1] = '\0';
		for (int i = 0; i < strlen(s); i++) {
			if (!isdigit(s[i])) {
				valid = 0;
				break;
			}

		}
		if (valid) {
			nb = atoi(s);
			return nb;
		}
		else
			printf("Error reading number, try again!");		
	}
}

void readString(const char *message,char str[]) {
	printf("%s\n", message);
	fgets(str, 20, stdin);
	str[strlen(str) - 1] = '\0';
}

int readCommand() {
	int command = readInteger("Give your option: ");
	while (command < 0 || command>10) {
		printf("Invalid command! Try again");
		command= readInteger("Give your option: ");
	}
	return command;
}

void printMenu() {
	printf("1-Add a new product to the fridge\n");
	printf("2-Delele a product\n");
	printf("3-Update a product\n");
	printf("4-Find products whose name contain a given string\n");
	printf("5-Display products in reverse alphabetical order\n");
	printf("6-List all products from the fridge\n");
	printf("7-List products from a category which expires soon.\n ");
	printf("8-Undo\n");
	printf("9-Redo\n");
	printf("0-Exit\n");
}

void printProducts(ProductRepository* repo) {
	for (int i = 0; i < repo->length; i++) {
		toString(repo->products[i]);
		printf("\n");
	}
}

int addProductUI(UI* ui) {
	char name[50]="", category[20]="", expirationDate[20]="";
	double quantity;
	
	
	readString("Name:", name);
	readString("Category:", category);
	quantity = readInteger("Quantity:\n");
	readString("Expiration date:", expirationDate);
	
	return addProductController(name, category, quantity, expirationDate, ui->ctrl);
}

int deleteProductUI(UI *ui) {
	char name[50] = "", category[20] = "";
	
	
	readString("Name:", name);
	readString("Category:", category);
	;
	
	return deleteProductController(name, category, ui->ctrl);
	
}

int updateProductUI(UI *ui) {
	char name[50] = "", category[20] = "";
	int quantity;

	readString("Name:", name);
	readString("Category:", category);
	quantity = readInteger("Quantity:\n");

	return updateProductController(name, category,quantity, ui->ctrl);
}


void filterCategoryExpirationDateUI(UI *ui) {
	char category[10];
	readString("Give the name of the category: ", category);
	int nbofdays=0;
	readInteger("Give the number of days: ",nbofdays);
	ProductRepository *repo_res = filterCategoryExpirationDate(category,nbofdays,ui->ctrl);
	printProducts(repo_res);
	free(repo_res);
}

ProductRepository* filterProductsUI(UI *ui) {
	char substring[15];
	readString("Give the substring", substring);
	
	return filterBySubstringSortByQuantity(substring, ui->ctrl);
}

void startUI(UI *ui) {
	
	
	int command = -1;

	while (1) {
		printMenu();

		command = readCommand();

		switch (command) {

		case 0:
			return;

			break;
		case 1: {

			int i = addProductUI(ui);

			if (i == -1)
				printf("There was invalid data, product was not added!\n");
			else if (i == 0)
				printf("The product already existed,the quantity was updated\n");
			else
				printf("Product succesfully added!\n");

			break;
		}
		case 2: {
			int i = deleteProductUI(ui);

			if (i == -1)
				printf("The product is not in the fridge!!\n");
			else
				printf("Product succesfully deleted!\n");
			break;
		}
		case 3: {
			int i = updateProductUI(ui);

			if (i == 1)
				printf("Product succesfullyupdated\n");
			else
				printf("Product not found!\n");

			break;
		}
		case 4: {
			ProductRepository *repos = filterProductsUI(ui);
			printProducts(repos);

			free(repos);
			break;
		}
		case 5: {
			ProductRepository *repos = sortDescendingName(ui->ctrl);
			printProducts(repos);
			free(repos);
			break;
		}
		case 6: {
			printf("\n");

			ProductRepository* repos;
			repos = getAll(ui->ctrl);

			printProducts(repos);
			break;
		}
		case 7: {
			filterCategoryExpirationDateUI(ui);
			break;
		}
		case 8: {
			//printf("0");
			int i = undo(ui->ctrl);
			if (i == 1)
				printf("Undo succesful!!\n");
			else
				printf("There was no operation to undo.\n");
			break;
		}
		case 9: {
			int i = redo(ui->ctrl);
			if (i == 1)
				printf("Redo succesful!!\n");
			else
				printf("There was no operation to redo.\n");
			break;
		}
		
		}
	}
}

