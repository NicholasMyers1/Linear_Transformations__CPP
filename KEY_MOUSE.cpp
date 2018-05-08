#include "includesVoids.h"
void mousemoveunpressed(int x, int y){
	for(int n=0;n<numberButtonsDraw[WINDOW.currentScreen];n++){//button collision: 
		if(	x>(BUTTON[WINDOW.currentScreen][n].x)&&
			x<(BUTTON[WINDOW.currentScreen][n].x)+(BUTTON[WINDOW.currentScreen][n].width*WINDOW.aspect)&&
			y>(BUTTON[WINDOW.currentScreen][n].y)&&
			y<(BUTTON[WINDOW.currentScreen][n].y)+(BUTTON[WINDOW.currentScreen][n].height*WINDOW.aspect)
		){
			WINDOW.buttonCurrentlySelected=n;
			BUTTONS_NO_CLICK(WINDOW.buttonCurrentlySelected);
			if(WINDOW.currentScreen==2){
				if(n==2||n==4)BUTTON_LOGIC(WINDOW.buttonCurrentlySelected);
			}
			break;
		}
		else if(n==numberButtonsDraw[WINDOW.currentScreen]-1)WINDOW.buttonCurrentlySelected=-1;
	}
}//end void;
void mousemotion(int x, int y){
	for(int n=0;n<numberButtonsDraw[WINDOW.currentScreen];n++){//button collision: 
		if(	x>(BUTTON[WINDOW.currentScreen][n].x)&&
			x<(BUTTON[WINDOW.currentScreen][n].x)+(BUTTON[WINDOW.currentScreen][n].width*WINDOW.aspect)&&
			y>(BUTTON[WINDOW.currentScreen][n].y)&&
			y<(BUTTON[WINDOW.currentScreen][n].y)+(BUTTON[WINDOW.currentScreen][n].height*WINDOW.aspect)
		){
			WINDOW.buttonCurrentlySelected=n;
			BUTTONS_NO_CLICK(WINDOW.buttonCurrentlySelected);
			if(WINDOW.currentScreen==2){
				if(n==2||n==4)BUTTON_LOGIC(WINDOW.buttonCurrentlySelected);
			}
			break;
		}
		else if(n==numberButtonsDraw[WINDOW.currentScreen]-1)WINDOW.buttonCurrentlySelected=-1;
	}
}
void mouseclick(int button, int state, int x, int y){
	if(state==GLUT_DOWN){//to know where the player clicked;
		WINDOW.clicked[0]=x;
		WINDOW.clicked[1]=y;
	}
	if(state==GLUT_UP){//MOUSE RELEASE FROM BUTTON AND READ IF IT IS WITHIN THE RANGE OF A BUTTON: 
		WINDOW.released[0]=x;
		WINDOW.released[1]=y;
		if(WINDOW.clicked[0]==WINDOW.released[0]&&WINDOW.clicked[1]==WINDOW.released[1]){
			for(int n=0;n<numberButtonsDraw[WINDOW.currentScreen];n++){//button collision: 
				if(	x>(BUTTON[WINDOW.currentScreen][n].x)&&
					x<(BUTTON[WINDOW.currentScreen][n].x)+(BUTTON[WINDOW.currentScreen][n].width*WINDOW.aspect)&&
					y>(BUTTON[WINDOW.currentScreen][n].y)&&
					y<(BUTTON[WINDOW.currentScreen][n].y)+(BUTTON[WINDOW.currentScreen][n].height*WINDOW.aspect)&&
					WINDOW.buttonCurrentlySelected==n//button is being hovered over; meaning allowed;
				){
					WINDOW.buttonCurrentlyClicked=n;
					BUTTONS_NO_CLICK(WINDOW.buttonCurrentlySelected);
					BUTTON_LOGIC(WINDOW.buttonCurrentlySelected);
					if(WINDOW.currentScreen==1&&n>2&&n<7)WINDOW.typing=true;
					break;
				}
				else if(n==numberButtonsDraw[WINDOW.currentScreen]-1){
					WINDOW.buttonCurrentlyClicked=-1;
					WINDOW.typing=false;
				}
			}
		}
	}
}//end void;
void keyUnpressedSpecial(int key, int x, int y){
}
void keyPressedSpecial(int key, int x, int y){
	SPECIAL_TEXT_INPUT(key);//enter text: 
}//end void;
void keyUnpressed(unsigned char key, int x, int y){
	if(key=='f'&&WINDOW.typing==false)WINDOW.fullScreen=bool((1+(bool)WINDOW.fullScreen)%2);
}//end void;
void keyPressed(unsigned char key, int x, int y){//glutKeyboardFunc(keyPressed);
	REGULAR_TEXT_INPUT(key);//enter text: 
}//end void;
