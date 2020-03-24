#include "validator.h"
#include <string.h>



int validCategory(char category[]) {
	if (strcmp(category, "dairy") == 0)
		return 1;
	if (strcmp(category, "sweets") == 0)
		return 1;
	if (strcmp(category, "meat") == 0)
		return 1;
	if (strcmp(category, "fruit") == 0)
		return 1;
	return -1;
}

int validExpirationDate(char expirationDate[]) {
	if (expirationDate[0]<'0' || expirationDate[0]>'9')
		return -1;
	if (expirationDate[1]<'0' || expirationDate[1]>'9')
		return -1;
	if (expirationDate[2] != '/')
		return -1;
	if (expirationDate[3]<'0' || expirationDate[3]>'9')
		return -1;
	if (expirationDate[4]<'0' || expirationDate[4]>'9')
		return -1;
	if (expirationDate[5] != '/')
		return -1;
	if (expirationDate[6]<'0' || expirationDate[6]>'9')
		return -1;
	if (expirationDate[7]<'0' || expirationDate[7]>'9')
		return -1;

	return 1;
}

int validProduct(Product* p) {
	if (validCategory(getCategory(p)) == 1 && validExpirationDate(getExpirationDate(p)) == 1)
		return 1;
	return -1;
}