#include "includesVoids.h"
void BUTTONS_NO_CLICK(int buttonNumber){
	if(WINDOW.currentScreen==0){
		if(WINDOW.buttonCurrentlySelected==6){
			if(OBJECTS.nSidedValue<=5){
				WINDOW.buttonCurrentlyClicked=-1;
				WINDOW.buttonCurrentlySelected=-1;
			}
		}
		if(WINDOW.buttonCurrentlySelected==7){
			if(OBJECTS.nSidedValue>=360){
				WINDOW.buttonCurrentlyClicked=-1;
				WINDOW.buttonCurrentlySelected=-1;
			}
		}
	}
	if(WINDOW.currentScreen==1){
		if(WINDOW.buttonCurrentlySelected==7){
			if(	OBJECTS.transformationValuesString[0][0].length()==0||OBJECTS.transformationValuesString[0][1].length()==0||
				OBJECTS.transformationValuesString[1][0].length()==0||OBJECTS.transformationValuesString[1][1].length()==0||
				OBJECTS.transformationValuesString[0][0]=="-"||OBJECTS.transformationValuesString[0][0]=="."||OBJECTS.transformationValuesString[0][0]=="-."||
				OBJECTS.transformationValuesString[0][1]=="-"||OBJECTS.transformationValuesString[0][1]=="."||OBJECTS.transformationValuesString[0][1]=="-."||
				OBJECTS.transformationValuesString[1][0]=="-"||OBJECTS.transformationValuesString[1][0]=="."||OBJECTS.transformationValuesString[1][0]=="-."||
				OBJECTS.transformationValuesString[1][1]=="-"||OBJECTS.transformationValuesString[1][1]=="."||OBJECTS.transformationValuesString[1][1]=="-."
			){
				WINDOW.buttonCurrentlyClicked=-1;
				WINDOW.buttonCurrentlySelected=-1;
			}
		}
	}
	if(WINDOW.currentScreen==2){
		if(WINDOW.buttonCurrentlySelected==7){
			if(OBJECTS.pointLookingAt<=0){
				WINDOW.buttonCurrentlyClicked=-1;
				WINDOW.buttonCurrentlySelected=-1;
			}
		}
		if(WINDOW.buttonCurrentlySelected==8){
			if(	OBJECTS.pointLookingAt>=OBJECTS.SQUARES.size-1&&OBJECTS.type==0||
				OBJECTS.pointLookingAt>=OBJECTS.TRIANGLES.size-1&&OBJECTS.type==1||
				OBJECTS.pointLookingAt>=OBJECTS.CIRCLES.size-1&&OBJECTS.type==2||
				OBJECTS.pointLookingAt>=OBJECTS.nSIDED.size-1&&OBJECTS.type==3
			){
				WINDOW.buttonCurrentlyClicked=-1;
				WINDOW.buttonCurrentlySelected=-1;
			}
		}
		if(WINDOW.buttonCurrentlySelected==4){
			if(WINDOW.zoom>=-1){
				WINDOW.buttonCurrentlyClicked=-1;
				WINDOW.buttonCurrentlySelected=-1;
			}
		}
	}
}
void BUTTON_LOGIC(int buttonNum){
	switch(WINDOW.currentScreen){
		case 0://welcome screen: 
			switch(buttonNum){
				case 2:		OBJECTS.type=0/*"Quadrilateral"*/;	OBJECTS.typeOutPut="Quadrilateral";								WINDOW.currentScreen=1;	WINDOW.buttonCurrentlyClicked=-1;break;//quadrilaterals:
				case 3:		OBJECTS.type=1/*"Triangle"*/;		OBJECTS.typeOutPut="Triangle";									WINDOW.currentScreen=1;	WINDOW.buttonCurrentlyClicked=-1;break;//triangle:
				case 4:		OBJECTS.type=2/*"Ellipse"*/;		OBJECTS.typeOutPut="Ellipse";									WINDOW.currentScreen=1;	WINDOW.buttonCurrentlyClicked=-1;break;//ellipse: 
				case 5:		OBJECTS.type=3/*"n-sided"*/;		OBJECTS.typeOutPut=OBJECTS.nSidedValueString+"-sided figure";	WINDOW.currentScreen=1;	WINDOW.buttonCurrentlyClicked=-1;break;//n-sided: 
				case 6:		OBJECTS.nSidedValue-=1;				TEXTINPUT.ss<<OBJECTS.nSidedValue;		OBJECTS.nSidedValueString=TEXTINPUT.ss.str();TEXTINPUT.ss.str("\0");TEXTINPUT.ss.clear();break;
				case 7:		OBJECTS.nSidedValue+=1;				TEXTINPUT.ss<<OBJECTS.nSidedValue;		OBJECTS.nSidedValueString=TEXTINPUT.ss.str();TEXTINPUT.ss.str("\0");TEXTINPUT.ss.clear();break;
				case 8: 	exit(0);break;//exit;
			}break;
		case 1://rules screen: 
			switch(buttonNum){
				case 7: 	WINDOW.currentScreen=2;			LISTS();		drewnSided=true;		CALCULATE();		WINDOW.buttonCurrentlyClicked=-1;break;//start game:  
				case 8: 	INIT_=true;						INIT();break;//reset:
				case 9: 	exit(0);break;//exit:
			}break;
		case 2://controls screen: 
			switch(buttonNum){
				case 2: 	WINDOW.zoom-=1;break;//-zoom:
				case 4: 	WINDOW.zoom+=1;break;//+zoom:
				case 5: 	INIT_=true;						INIT();break;//reset:
				case 7: 	OBJECTS.pointLookingAt-=1;break;//prev point:
				case 8: 	OBJECTS.pointLookingAt+=1;break;//next point:
				case 9: 	exit(0);break;//exit:
				case 10:	WINDOW.zoom=-25;break;
			}break;
	}
}
