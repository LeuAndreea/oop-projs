#include <string.h>
#include <assert.h>
#include <stdio.h>


#include "validator.h"
#include "OperationStack.h"
#include "product.h"
#include "repository.h"
#include "controller.h"


void test_validCategoryOK() {
	assert(validCategory("fruit") == 1);
	assert(validCategory("dairy")==1);
	assert(validCategory("sweets") == 1);
	assert(validCategory("meat") == 1);
}

void test_validCategoryNOTOK() {
	assert(validCategory("vegetable") == -1);
	assert(validCategory("diary") == -1);
	assert(validCategory("") == -1);
	
}

void test_validExpirationDateOK() {
	assert(validExpirationDate("12/02/19") == 1);
}

void test_validExpirationDateNOTOK() {
	assert(validExpirationDate("12.02.19") == -1);
}

void test_validProductOK() {
	Product *p = createProduct("peach", "fruit", 4, "12/02/19");
	assert(validProduct(p) == 1);
	destroyProduct(p);
}

void test_validProductNOTOK() {
	Product *p1 = createProduct("peach", "ffruit", 4, "12/02/19");
	assert(validProduct(p1) == -1);
	destroyProduct(p1);
	
	Product *p2 = createProduct("peach", "fruit", 4, "12.02.19");
	assert(validProduct(p2) == -1);
	destroyProduct(p2);

	Product *p3 = createProduct("peach", "ffruit", 4, "12.02.19");
	assert(validProduct(p3) == -1);
	destroyProduct(p3);
}

void test_Validator() {
	test_validCategoryOK();
	test_validCategoryNOTOK();
	test_validExpirationDateOK();
	test_validExpirationDateNOTOK();
	test_validProductOK();
	test_validProductNOTOK();
}


void test_compareNames() {
	Product *p1 = createProduct("blueberry", "fruit", 3, "12/09/19");
	Product *p2 = copyProduct(p1);
	Product *p3 = createProduct("Apple", "fruit", 5, "12/09/19");
	Product *p4 = createProduct("peach", "fruit", 5, "12/09/19");
	assert(compareNames(p1, p2) == 1);
	assert(compareNames(p1, p3) == 1);
	assert(compareNames(p1, p4) == 0);

	destroyProduct(p1);
	destroyProduct(p2);
	destroyProduct(p3);
	destroyProduct(p4);
}

void test_compareQuantity() {
	Product *p1 = createProduct("blueberry", "fruit", 3, "12/09/19");
	Product *p2= createProduct("apricot", "fruit", 3, "12/09/19");
	Product *p3 = createProduct("Apple", "fruit", 6, "12/09/19");
	Product *p4 = createProduct("peach", "fruit", 2, "12/09/19");
	assert(compareQuantity(p1, p2) == 1);
	assert(compareQuantity(p1, p3) == 1);
	assert(compareQuantity(p1, p4) == 0);

	destroyProduct(p1);
	destroyProduct(p2);
	destroyProduct(p3);
	destroyProduct(p4);
}

void test_Product() {
	Product *p;
	p = createProduct("Apple", "fruit", 3, "12/09/2019");
	assert( strcmp(getName(p),"Apple")==0);
	assert(strcmp(getCategory(p), "fruit") == 0);
	assert(strcmp(getExpirationDate(p), "12/09/2019") == 0);
	assert(getQuantity(p) == 3);

	Product *p2 = copyProduct(p);
	
	assert(eq(p, p2) == 1);
	
	Product *p3 = createProduct("grapes", "fruit", 6, "23/09/19");
	assert(eq(p2, p3) == -1);
	
	destroyProduct(p);
	destroyProduct(p2);
	destroyProduct(p3);

	test_compareNames();
	test_compareQuantity();
}

void test_getLength() {
	ProductRepository *repo = createRepository();
	assert(getLength(repo) == 0);

	Product *p = createProduct("Apple", "fruit", 3, "12/09/2019");
	addProduct(p, repo);
	assert(getLength(repo) == 1);

	destroyRepository(repo);
}

void test_findProductOK() {
	ProductRepository *repo = createRepository();
	Product *p = createProduct("Apple", "fruit", 3, "12/09/2019");
	addProduct(p, repo);
	assert(findProduct("Apple", "fruit", repo) == 0);
	
	destroyRepository(repo);
}

void test_findProductNOTOK() {
	ProductRepository *repo = createRepository();
	Product *p = createProduct("Apple", "fruit", 3, "12/09/2019");
	addProduct(p, repo);
	assert(findProduct("peach", "fruit", repo) == -1);

	destroyRepository(repo);
}

void test_getProductOK() {
	ProductRepository *repo = createRepository();
	Product *p = createProduct("Apple", "fruit", 3, "12/09/2019");
	addProduct(p, repo);
	
	Product *p1 = getProductRepo("Apple", "fruit", repo);
	assert(strcmp(getName(p1), "Apple") == 0);
	assert(strcmp(getCategory(p1), "fruit") == 0);
	assert(strcmp(getExpirationDate(p1), "12/09/2019") == 0);
	assert(getQuantity(p1) == 3);

	destroyRepository(repo);
	destroyProduct(p1);
}

void test_getProductNOTOK() {
	ProductRepository *repo = createRepository();
	Product *p = createProduct("Apple", "fruit", 3, "12/09/19");
	addProduct(p, repo);
	
	Product *p1 = getProductRepo("peach", "fruit", repo);
	assert(p1 == NULL);

	destroyRepository(repo);
	destroyProduct(p1);
}

void test_addRepoOK() {
	ProductRepository *repo = createRepository();
	Product *p = createProduct("Apple", "fruit", 3, "12/09/19");

	assert(addProduct(p, repo) == 1);

	destroyRepository(repo);

}

void test_addRepoDuplicate() {
	ProductRepository *repo = createRepository();
	Product *p = createProduct("strawberry", "fruit", 3, "12/09/19");
	addProduct(p, repo);
	Product *p2 = createProduct("strawberry", "fruit", 6, "12/09/19");
	assert(addProduct(p2, repo) == 0);
	assert(getQuantity(p) == 6);

	destroyRepository(repo);
}

void test_addRepoNOTOK() { 
	ProductRepository *repo = createRepository();
	Product *p = createProduct("strawberry", "fruit", 3, "12.09.19");
	
	assert(addProduct(p, repo) == -1);

	destroyRepository(repo);
}

void test_deleteRepoOK() {
	ProductRepository *repo = createRepository();
	Product *p = createProduct("Apple", "fruit", 3, "12/09/19");
	addProduct(p, repo);
	assert(deleteProduct("Apple","fruit", repo) == 1);
		
	destroyRepository(repo);
}

void test_deleteRepoNOTOK() {
	ProductRepository *repo = createRepository();
	Product *p = createProduct("Apple", "fruit", 3, "12/09/19");
	addProduct(p, repo);
	assert(deleteProduct("peach", "fruit", repo) == -1);

	destroyRepository(repo);
}

void test_updateRepoOK() {
	ProductRepository *repo = createRepository();
	Product *p = createProduct("Apple", "fruit", 3, "12/09/19");
	addProduct(p, repo);

	assert(updateProduct("Apple", "fruit", 6, repo) == 1);
	destroyRepository(repo);

}

void test_updateRepoNOTOK() {
	ProductRepository *repo = createRepository();
	Product *p = createProduct("Apple", "fruit", 3, "12/09/19");
	addProduct(p, repo);

	assert(updateProduct("peach", "fruit", 6, repo) == -1);
	destroyRepository(repo);

}

void test_filterBySubstring() {
	ProductRepository* repo = createRepository();
	
	Product *p1=createProduct("apple", "fruit", 3, "12/09/20");
	Product *p2 = createProduct("chocolate", "sweets", 7, "23/10/20");
	Product *p3 = createProduct("milk", "dairy", 2, "17/03/19");
	Product *p4 = createProduct("steak", "meat", 5, "25/04/19");
	Product *p5 = createProduct("cherry yogurt", "dairy", 6, "29/03/19");
	
	addProduct(p1, repo);
	addProduct(p2, repo);
	addProduct(p3, repo);
	addProduct(p4, repo);
	addProduct(p5, repo);
	ProductRepository *repo2 = filterBySubstring("a", repo);
	
	assert(findProduct("apple", "fruit", repo2) == 0);
	assert(findProduct("chocolate", "sweets", repo2) == 1);
	assert(findProduct("milk", "dairy", repo2) == -1);
	assert(findProduct("steak", "meat", repo2) == 2);
	assert(findProduct("cherry yogurt", "dairy", repo2) == -1);
	destroyRepository(repo);
	free(repo2);
}

test_Repository() {
	
	test_getLength();
	test_findProductOK();
	test_findProductNOTOK();
	test_getProductOK();
	test_getProductNOTOK();
	test_addRepoOK();
	test_addRepoDuplicate();
	test_addRepoNOTOK();
	test_deleteRepoOK();
	test_deleteRepoNOTOK();
	test_updateRepoOK();
	test_updateRepoNOTOK(); 
	test_filterBySubstring();
}

void test_addProductControllerOK() {
	ProductRepository *repo = createRepository();
	ProductController *ctrl = createController(repo);
	assert(addProductController("Apple", "fruit", 3, "12/09/19", ctrl) == 1);

	destroyController(ctrl);
}


void test_addProductControllerDUPLICATE() {
	ProductRepository *repo = createRepository();
	ProductController *ctrl = createController(repo);
	
	assert(addProductController("steak", "meat", 3, "12/09/19",ctrl)==1);
	assert(addProductController("steak", "meat", 6, "12/09/19", ctrl) == 0);
	destroyController(ctrl);
}
test_addProductControllerNOTOK() {
	ProductRepository *repo = createRepository();
	ProductController *ctrl = createController(repo);

	assert(addProductController("steak", "meeat", 3, "12/09/19", ctrl) == -1);
	destroyController(ctrl);
}

void test_deleteProductControllerOK() {
	ProductRepository *repo = createRepository();
	ProductController *ctrl = createController(repo);
	

	addProductController("Apple", "fruit", 3, "12/09/19",ctrl);
	assert(deleteProductController("Apple", "fruit", ctrl) == 1);

	destroyController(ctrl);
}

void test_deleteProductControllerNOTOK() {
	ProductRepository *repo = createRepository();
	ProductController *ctrl = createController(repo);

	addProductController("Apple", "fruit", 3, "12/09/19",ctrl);
	assert(deleteProductController("peach", "fruit", ctrl) == -1);

	destroyController(ctrl);
}

void test_updateProductControllerOK() {
	ProductRepository *repo = createRepository();
	ProductController *ctrl = createController(repo);

	addProductController("Apple", "fruit", 3, "12/09/19", ctrl);

	assert(updateProductController("Apple", "fruit", 6, ctrl) == 1);
	destroyController(ctrl);

}

void test_updateProductControllerNOTOK(){
	ProductRepository *repo = createRepository();
	ProductController *ctrl = createController(repo);

	addProductController("Apple", "fruit", 3, "12/09/19", ctrl);

	assert(updateProductController("peach", "fruit", 6, ctrl) == -1);
	destroyController(ctrl);

}

void test_sortDescendingName(){
	ProductRepository* repo = createRepository();
	ProductController *ctrl = createController(repo);
	
	addProductController("apple", "fruit", 3, "12/09/20", ctrl);
	addProductController("chocolate", "sweets", 7, "23/10/20", ctrl);
	addProductController("milk", "dairy", 2, "17/03/19", ctrl);
	addProductController("steak", "meat", 5, "25/04/19", ctrl);
	addProductController("cherry yogurt", "dairy", 6, "29/03/19", ctrl);

	ProductRepository* repo2 = sortDescendingName(ctrl);
	assert(findProduct("apple", "fruit", repo2) == 4);
	assert(findProduct("chocolate", "sweets", repo2) == 2);
	assert(findProduct("milk", "dairy", repo2) == 1);
	assert(findProduct("steak", "meat", repo2) == 0);
	assert(findProduct("cherry yogurt", "dairy", repo2) == 3);
	destroyRepository(repo);
	free(repo2);
}

void test_Controller() {
	test_addProductControllerOK();
	test_addProductControllerDUPLICATE();
	test_addProductControllerNOTOK();
	test_deleteProductControllerOK();
	test_deleteProductControllerNOTOK();
	test_updateProductControllerOK();
	test_updateProductControllerNOTOK();
	test_sortDescendingName();

}

void testAll() {
	test_Validator();
	test_Product();
	test_Repository();
	test_Controller();
}