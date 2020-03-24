#include "Event.h"

class Validator {
public:
	/*Check if the input data is right
	-makes sure date is in the right format and it's not past the curent date
	IN: a date
	OUT: true if it is valid, false otherwise.*/
	bool static validateDateAndTime(DateAndTime d);
	/*Checks if the input data is right
	-makes sure there are no empty fields*
	IN: an event
	OUT: true of it is valid, false otherwise.*/
	bool static validateEvent(Event e);

	bool static validateMonth(int month);
};