#include "tests.h"
#include "UI.h"

int main() {
	Test::testAll();
	
	Repository repo1 =Repository();
	Repository repo2 = Repository();
	DateAndTime d = DateAndTime();
	Controller ctrl = Controller(repo1,repo2);	
	

	ctrl.addEventAdmin("Alternosfera concert", "National tour", "www", 23, 2,7,0,0);
	ctrl.addEventAdmin("Art gallery", "Works of art students", "www", 3, 15, 6, 0, 0);
	ctrl.addEventAdmin("Irish pub opening", "There will be free beer!", "www", 40, 7, 7, 0, 0);
	ctrl.addEventAdmin("Jazz in the park", "Good music, good vibes", "www", 100, 28, 8, 0, 0);
	ctrl.addEventAdmin("Free Java Script course", "Limites places, complete online formular", "www", 16, 14, 5, 0, 0);
	UI ui = UI(ctrl);
	ui.run(); 

}