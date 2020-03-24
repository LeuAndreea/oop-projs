#include <stdio.h>
#include <crtdbg.h>
#include "tests.h"
#include "ui.h"

void populateController(ProductController* ctrl) {
	addProductController("apple", "fruit", 3, "14/04/20", ctrl);
	addProductController("chocolate", "sweets", 7, "23/10/20", ctrl);
	addProductController("milk", "dairy", 2, "17/03/19", ctrl);
	addProductController("steak", "meat", 5, "25/04/19", ctrl);
	addProductController("cherry yogurt", "dairy", 6, "29/03/19", ctrl);
	addProductController("peach", "fruit", 3, "13/04/20", ctrl);
}


int main() {
	testAll();
	
	ProductRepository* repo = createRepository();
	ProductController* ctrl = createController(repo);
	UI* ui = createUI(ctrl);
	
	populateController(ui->ctrl);
	

	startUI(ui);
	destroyUI(ui);
	
	_CrtDumpMemoryLeaks();
	
	system("pause");
}
