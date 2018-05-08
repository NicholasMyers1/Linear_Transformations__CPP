#include "includesVoids.h"
//GLOBALS: 
	bool INIT_=true;//this is the only variable to initialize in the VARIABLES.cpp file and the lists below...
	//LISTS: 
		GLuint board[10];
		GLuint boardOriginals[10];
			bool drewOriginal,drewnSided;
	//STRUCTS: 
		_BUTTONS BUTTON[3][20];
			int numberButtonsDraw[3];
		_OBJECTS OBJECTS;
		_WINDOW WINDOW;
		_TEXT_INPUT TEXTINPUT;
