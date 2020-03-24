#include <stdlib.h>
#include <stdio.h>
#include "repository.h"
#include "validator.h"
#include <string.h>
#include <time.h>

ProductRepository* createRepository() {
	ProductRepository *repo = (ProductRepository*)malloc(sizeof(ProductRepository));
	repo->length = 0;
	return repo;
}

ProductRepository* copyRepository(ProductRepository* repo) {
	//printf("Addres of repo param in copy: %p\n", (void*)repo);

	ProductRepository* repo_res = createRepository();
	//printf("Repo res: %p\n", (void*)repo_res);

	for (int i = 0; i < repo->length; i++)
		addProduct(repo->products[i], repo_res);

	/*for (int i = 0; i < repo->length; i++) {
	printf("Repo product: %p\n", (void*)repo->products[i]);
	printf("Repores product: %p\n", (void*)repo_res->products[i]);
	}*/
	return repo_res;

}

void destroyRepository(ProductRepository* repo) {
	for (int i = 0; i < repo->length; i++) 
		destroyProduct(repo->products[i]);
	
		
		
	free(repo);
}

int getLength(ProductRepository *repo) {
	return repo->length;
}

int findProduct(char name[], char category[], ProductRepository *repo) {
	for (int i = 0; i < repo->length; i++)
		if ((strcmp(name, getName(repo->products[i])) == 0) && (strcmp(category, getCategory(repo->products[i])) == 0))
			return i;
	return -1;
}

Product* getProductRepo(char name[], char category[], ProductRepository *repo) {
	int i = findProduct(name, category, repo);
	if (i != -1)
		return copyProduct(repo->products[i]);

	return NULL;
}

int addProduct(Product* p, ProductRepository *repo) {
	if (validProduct(p) == 1) {
		int i = findProduct(getName(p), getCategory(p), repo);
		if (i == -1) {
			repo->products[repo->length] = p;
			repo->length += 1;

			return 1;

		}
		else {
			repo->products[i]->quantity = p->quantity;
						
			return 0;
		}
	}
	else 
		destroyProduct(p);
	return -1;
}

int deleteProduct(char name[], char category[],ProductRepository *repo) {
	int i = findProduct(name, category, repo);
	if (i == -1)
		return -1;
	Product *p = repo->products[i];
	destroyProduct(p);
	int length=getLength(repo);
	for (int index = i; i<repo->length-1; index++) 
		repo->products[index] = repo->products[index + 1];	
	repo->length = length - 1;
	return 1;
}

int updateProduct(char name[], char category[],double quantity, ProductRepository *repo) {
	int i = findProduct(name, category, repo);
	if (i == -1)
		return - 1;
	repo->products[i]->quantity = quantity;
	return 1;
}

ProductRepository* filterBySubstring(char substring[], ProductRepository* repo) {
	if (substring == NULL)
		return repo;

	ProductRepository* repo_res = createRepository();
	for (int i = 0; i <repo->length; i++)
		if (strstr(getName(repo->products[i]), substring))
			addProduct(repo->products[i], repo_res);

	return repo_res;
}

void quickSort(int i, int j, ProductRepository* repo, sortingCondition c) {
	int low = i, high = j, dir = 1;
	Product *p;

	if (i == j)
		return;
	while (i != j) {
		if (!c(repo->products[i], repo->products[j])) {
			p = repo->products[i];
			repo->products[i] = repo->products[j];
			repo->products[j] = p;

			dir *= -1;
		}
		if (dir == 1)
			j--;
		else
			i++;
	}
	if (j>low)
		quickSort(low, j - 1, repo, c);
	if (j<high)
		quickSort(j + 1, high, repo, c);
}

ProductRepository* sortProducts(sortingCondition c, ProductRepository* repo) {
	//printf("Addres of repository param sort: %p\n", (void*)repo);
	ProductRepository* repo_res = copyRepository(repo);
	//printf("Addres of repo_res sort: %p\n", (void*)repo_res);
	quickSort(0, repo_res->length - 1, repo_res, c);

	return repo_res;
}



ProductRepository* filterByCategory(char category[],ProductRepository *repo) {
	if (category == NULL)
		return repo;

	ProductRepository* repo_res = createRepository();
	for (int i = 0; i <repo->length; i++)
		if (strcmp(getCategory(repo->products[i]), category)==0)
			addProduct(repo->products[i], repo_res);

	return repo_res;
}


int calculateDifference(int day1, int month1, int day2, int month2) {
	if (month1 > month2) {
		return -1;
	}
	if (month1 == month2)
		if (day1 > day2)
			return -1;
	return 1;
}

ProductRepository* filterByExpirationDate(int nbOfDays,ProductRepository* repo) {
	int day, month;
	time_t rawtime;
	struct tm *curent_time;
	
	time(&rawtime);
	curent_time = gmtime(&rawtime);
	curent_time->tm_mday;
	curent_time->tm_mon+=1;
	ProductRepository* repo_res = createRepository();
	
	curent_time->tm_mday+= nbOfDays;
	if (curent_time->tm_mday > 30) {
		curent_time->tm_mday -= 30;
		curent_time->tm_mon += 1;
	}

	char buffer[3];
	int expday,expmonth;
	for (int i = 0; i < repo->length; i++) {
		
		sprintf(buffer, "%.2s", getExpirationDate(repo->products[i]));
		expday = atoi(buffer);
		sprintf(buffer, "%.2s", getExpirationDate(repo->products[i]) + 3);
		expmonth = atoi(buffer);
		
		if (calculateDifference(curent_time->tm_mday, curent_time->tm_mon, expday, expmonth)==1)
			addProduct(repo->products[i], repo_res);
	}
	return repo_res;
}


