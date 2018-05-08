#include "includesVoids.h"
bool SEARCH_TEXT(string searchThrough,char find){
	for(int n=0;n<searchThrough.length();n++){
		if(searchThrough[n]==find){
			return true;
		}
	}
	return false;
}
void SPECIAL_TEXT_INPUT(int key){
	if(WINDOW.currentScreen==1){//left and right: 
		if(WINDOW.buttonCurrentlyClicked>=3&&WINDOW.buttonCurrentlyClicked<=6){
			if(key==GLUT_KEY_LEFT){
				if(TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]>0){
					TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]-=1;
				}
			}
			if(key==GLUT_KEY_RIGHT){
				if(TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]<OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0].length()){
					TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]+=1;
				}
			}
		}
	}
}
void REGULAR_TEXT_INPUT(int key){
	if(	WINDOW.buttonCurrentlyClicked==3&&WINDOW.currentScreen==1||
		WINDOW.buttonCurrentlyClicked==4&&WINDOW.currentScreen==1||
		WINDOW.buttonCurrentlyClicked==5&&WINDOW.currentScreen==1||
		WINDOW.buttonCurrentlyClicked==6&&WINDOW.currentScreen==1){
		if(key==8){//erase: backspace key
			if(TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]>0){
				if(OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0][TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]-1]=='.'){
					TEXTINPUT.decimalUsed[WINDOW.buttonCurrentlyClicked-3]=false;
				}
				if(OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0][TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]-1]=='-'){
					TEXTINPUT.negativeUsed[WINDOW.buttonCurrentlyClicked-3]=false;
				}
				OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0].erase(TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]-1,1);
				BUTTON[1][WINDOW.buttonCurrentlyClicked].text=OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0];//+"";
				TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]-=1;
			}
		}
		else if(key==(int)127){//erase: delete key
			if(TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]<OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0].length()){
				if(OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0][TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]]=='.'){
					TEXTINPUT.decimalUsed[WINDOW.buttonCurrentlyClicked-3]=false;
				}
				if(OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0][TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]]=='-'){
					TEXTINPUT.negativeUsed[WINDOW.buttonCurrentlyClicked-3]=false;
				}
				OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0].erase(TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3],1);
			}
			BUTTON[1][WINDOW.buttonCurrentlyClicked].text=OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0];//+"";
		}
		else if(key>47&&key<58&&TEXTINPUT.negativeUsed[WINDOW.buttonCurrentlyClicked-3]==false||
				key>47&&key<58&&TEXTINPUT.negativeUsed[WINDOW.buttonCurrentlyClicked-3]==true&&TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]!=0||
				key==45&&TEXTINPUT.negativeUsed[WINDOW.buttonCurrentlyClicked-3]==false&&TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]==0||
				key==46&&TEXTINPUT.decimalUsed[WINDOW.buttonCurrentlyClicked-3]==false&&TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]==0&&BUTTON[1][WINDOW.buttonCurrentlyClicked].text[0]!='-'||
				key==46&&TEXTINPUT.decimalUsed[WINDOW.buttonCurrentlyClicked-3]==false&&TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]!=0
			){//-, ., 0-9;
				if(	OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0].length()<5&&
					OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0][0]!='-'&&
					SEARCH_TEXT(OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0],'.')==false||/////
					OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0].length()<6&&
					OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0][0]=='-'&&
					SEARCH_TEXT(OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0],'.')==false||/////
					OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0].length()<6&&
					OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0][0]!='-'&&
					SEARCH_TEXT(OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0],'.')==true||/////
					OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0].length()<7&&
					OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0][0]=='-'&&
					SEARCH_TEXT(OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0],'.')==true||/////
					key==45&&TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]==0&&TEXTINPUT.negativeUsed[WINDOW.buttonCurrentlyClicked-3]==false||/////
					key==46&&TEXTINPUT.decimalUsed[WINDOW.buttonCurrentlyClicked-3]==false
				){
					if(key==45&&TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]==0)TEXTINPUT.negativeUsed[WINDOW.buttonCurrentlyClicked-3]=true;
					if(key==46)TEXTINPUT.decimalUsed[WINDOW.buttonCurrentlyClicked-3]=true;
					string input="\0";input=key;
					OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0].insert(TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3],input);//+=key;
					BUTTON[1][WINDOW.buttonCurrentlyClicked].text=OBJECTS.transformationValuesString[WINDOW.buttonCurrentlyClicked%2][WINDOW.buttonCurrentlyClicked==3||WINDOW.buttonCurrentlyClicked==4?1:0];//+"";
					TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]+=1;
				}
		}
	}
}
