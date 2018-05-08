#include "includesVoids.h"
//include some subvoids;
void BUTTONS_INIT(){//BUTTONS
		numberButtonsDraw[0]=9;		numberButtonsDraw[1]=10;		numberButtonsDraw[2]=11;
		int B,sub;//current button number to initialize;subButton; 0 is center point. ++ is bottom left. opposites. 
		B=0;sub=0;//main screen: 
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(0*WINDOW.aspect);				BUTTON[B][sub].width=0;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(300*WINDOW.aspect);	BUTTON[B][sub].height=0;
				BUTTON[B][sub].text="LINEAR TRANSFORMATIONS";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(0*WINDOW.aspect);				BUTTON[B][sub].width=0;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(125*WINDOW.aspect);	BUTTON[B][sub].height=0;
				BUTTON[B][sub].text="Choose Object Type:";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(300*WINDOW.aspect);			BUTTON[B][sub].width=200;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(100*WINDOW.aspect);	BUTTON[B][sub].height=75;
				BUTTON[B][sub].text="Quadrilateral";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(100*WINDOW.aspect);			BUTTON[B][sub].width=200;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(100*WINDOW.aspect);	BUTTON[B][sub].height=75;
				BUTTON[B][sub].text="Triangle";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(-100*WINDOW.aspect);			BUTTON[B][sub].width=200;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(100*WINDOW.aspect);	BUTTON[B][sub].height=75;
				BUTTON[B][sub].text="Ellipse";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(300*WINDOW.aspect);			BUTTON[B][sub].width=500;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(25*WINDOW.aspect);		BUTTON[B][sub].height=75;
				BUTTON[B][sub].text="n-sided figure: 5 sides";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(-200*WINDOW.aspect);			BUTTON[B][sub].width=50;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(25*WINDOW.aspect);		BUTTON[B][sub].height=75;
				BUTTON[B][sub].text="-";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(-250*WINDOW.aspect);			BUTTON[B][sub].width=50;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(25*WINDOW.aspect);		BUTTON[B][sub].height=75;
				BUTTON[B][sub].text="+";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(300*WINDOW.aspect);			BUTTON[B][sub].width=600;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(-50*WINDOW.aspect);	BUTTON[B][sub].height=33;
				BUTTON[B][sub].text="Exit";sub+=1;
		B=1;sub=0;//edit transformation values: 
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(0*WINDOW.aspect);				BUTTON[B][sub].width=0;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(300*WINDOW.aspect);	BUTTON[B][sub].height=0;
				BUTTON[B][sub].text="LINEAR TRANSFORMATIONS";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(0*WINDOW.aspect);				BUTTON[B][sub].width=0;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(275*WINDOW.aspect);	BUTTON[B][sub].height=0;
				BUTTON[B][sub].text="You chose: ";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(0*WINDOW.aspect);				BUTTON[B][sub].width=0;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(125*WINDOW.aspect);	BUTTON[B][sub].height=0;
				BUTTON[B][sub].text="Enter the vectors to transform by: ";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(275*WINDOW.aspect);			BUTTON[B][sub].width=200;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(100*WINDOW.aspect);	BUTTON[B][sub].height=50;
				BUTTON[B][sub].text="1";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(-75*WINDOW.aspect);			BUTTON[B][sub].width=200;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(100*WINDOW.aspect);	BUTTON[B][sub].height=50;
				BUTTON[B][sub].text="0";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(275*WINDOW.aspect);			BUTTON[B][sub].width=200;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(50*WINDOW.aspect);		BUTTON[B][sub].height=50;
				BUTTON[B][sub].text="0";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(-75*WINDOW.aspect);			BUTTON[B][sub].width=200;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(50*WINDOW.aspect);		BUTTON[B][sub].height=50;
				BUTTON[B][sub].text="1";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(300*WINDOW.aspect);			BUTTON[B][sub].width=600;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(0*WINDOW.aspect);		BUTTON[B][sub].height=75;
				BUTTON[B][sub].text="Calculate values and output";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(300*WINDOW.aspect);			BUTTON[B][sub].width=600;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(-75*WINDOW.aspect);	BUTTON[B][sub].height=33;
				BUTTON[B][sub].text="Return to main screen";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(300*WINDOW.aspect);			BUTTON[B][sub].width=600;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(-108*WINDOW.aspect);	BUTTON[B][sub].height=33;
				BUTTON[B][sub].text="Exit";sub+=1;
		B=2;sub=0;//display output: 
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(0*WINDOW.aspect);				BUTTON[B][sub].width=0;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(300*WINDOW.aspect);	BUTTON[B][sub].height=0;
				BUTTON[B][sub].text="LINEAR TRANSFORMATIONS";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(0*WINDOW.aspect);				BUTTON[B][sub].width=0;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(275*WINDOW.aspect);	BUTTON[B][sub].height=0;
				BUTTON[B][sub].text="Object: ";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(600*WINDOW.aspect);			BUTTON[B][sub].width=50;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(407.5*WINDOW.aspect);	BUTTON[B][sub].height=20;
				BUTTON[B][sub].text="-";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(500*WINDOW.aspect);			BUTTON[B][sub].width=0;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(400*WINDOW.aspect);	BUTTON[B][sub].height=0;
				BUTTON[B][sub].text="Zoom";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(450*WINDOW.aspect);			BUTTON[B][sub].width=50;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(407.5*WINDOW.aspect);	BUTTON[B][sub].height=20;
				BUTTON[B][sub].text="+";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(800*WINDOW.aspect);			BUTTON[B][sub].width=600;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(-400*WINDOW.aspect);	BUTTON[B][sub].height=75;
				BUTTON[B][sub].text="Return to main screen";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(-407.5*WINDOW.aspect);		BUTTON[B][sub].width=0;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(-400*WINDOW.aspect);	BUTTON[B][sub].height=0;
				BUTTON[B][sub].text="Matrix for point: \n\n";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(-192*WINDOW.aspect);			BUTTON[B][sub].width=215;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(-442.5*WINDOW.aspect);	BUTTON[B][sub].height=25;
				BUTTON[B][sub].text="Previous point";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(-192*WINDOW.aspect);			BUTTON[B][sub].width=215;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(-467.5*WINDOW.aspect);	BUTTON[B][sub].height=25;
				BUTTON[B][sub].text="Next point";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(800*WINDOW.aspect);			BUTTON[B][sub].width=600;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(-475*WINDOW.aspect);	BUTTON[B][sub].height=33;
				BUTTON[B][sub].text="Exit";sub+=1;
			BUTTON[B][sub].x=WINDOW.winW-(WINDOW.winW/2)-(800*WINDOW.aspect);			BUTTON[B][sub].width=165;
			BUTTON[B][sub].y=(WINDOW.winH/2)-(50*WINDOW.aspect)-(410*WINDOW.aspect);	BUTTON[B][sub].height=25;
				BUTTON[B][sub].text="Reset Zoom";sub+=1;

}
void WINDOW_INIT(){
	for(int n=0;n<2;n++){
		WINDOW.clicked[n]=-1;
		WINDOW.released[n]=-1;
	}
	WINDOW.typing=false;
	WINDOW.currentScreen=0;
	WINDOW.buttonCurrentlyClicked=-1;
	WINDOW.buttonCurrentlySelected=-1;
	for(int n=0;n<128;n++){
		WINDOW.keysCurrentlyPressedSpecial[n]=false;
	}
}
VOID TEXT_INIT(){
	for(int n=0;n<4;n++){
		TEXTINPUT.pointerPosition[n]=1;
		TEXTINPUT.negativeUsed[n]=false;
		TEXTINPUT.decimalUsed[n]=false;
	}
	TEXTINPUT.pointer="|";
	TEXTINPUT.pointerBlinkAlphaOn=true;
	TEXTINPUT.pointerBlinkingRate=500;//every (n)ms, the color of alpha changes from 1 to 0 and 0 to 1;
	TEXTINPUT.blinkertimer=GetTickCount();
	TEXTINPUT.ss.clear();;
}
