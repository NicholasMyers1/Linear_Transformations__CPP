#include "includesVoids.h"
void DRAW_BUTTONS(){
	for(int n=0;n<numberButtonsDraw[WINDOW.currentScreen];n++){
		glLoadIdentity();//load the identity: 
			glTranslatef(BUTTON[WINDOW.currentScreen][n].x,BUTTON[WINDOW.currentScreen][n].y,0);//translate: 
			glScalef(WINDOW.aspect,WINDOW.aspect,1.0f);//scale: 
			glColor3f(1,0,1);//color: 
			if(n==WINDOW.buttonCurrentlySelected)glColor3f(.2,.5,.2);//WHICH BUTTON IS BEING HOVERED OVER;
			if(n==WINDOW.buttonCurrentlyClicked)glColor3f(0,1,0);//button currently selected;
		//draw buttons: //dynamic buttons, so lengths and widths change when the window resizes: 
			glBegin(GL_LINE_LOOP);//regular button: 
				glVertex2f(BUTTON[WINDOW.currentScreen][n].width,0);
				glVertex2f(BUTTON[WINDOW.currentScreen][n].width,BUTTON[WINDOW.currentScreen][n].height);
				glVertex2f(0,BUTTON[WINDOW.currentScreen][n].height);
				glVertex2f(0,0);
			glEnd(); 
		DRAW_BUTTON_TEXT(n);//draw the button text: 
	}
	UPDATE_BUTTON_TEXT();
}
void UPDATE_BUTTON_TEXT(){
	//set the text for the game screen for every iteration: 
	stringstream convNumToStr;convNumToStr.str("\0");//num to string: 
	BUTTON[0][5].text="n-sided figure: "+OBJECTS.nSidedValueString+" sides";
	BUTTON[1][1].text="You chose: "+OBJECTS.typeOutPut;				/*convNumToStr<<BOARD.gameScore;BUTTON[4][2].text+=convNumToStr.str();*/convNumToStr.str("\0");
	BUTTON[2][1].text="Object: "+OBJECTS.typeOutPut;
	
	string break_="|";
	string space_=" ";
	string dot_="*";
	string equal_="=";
	//[()()] * [()] = [()]
	//[()()] * [()] = [()]
	string lookAt;
	TEXTINPUT.ss<<OBJECTS.pointLookingAt+1;	lookAt=TEXTINPUT.ss.str();
	BUTTON[2][6].text="Matrix for point: "+lookAt+"\n\n";
	TEXTINPUT.ss.str("\0");		TEXTINPUT.ss.clear();
	//
	
	string xNew,yNew,xOld,yOld;
	if(OBJECTS.type==0){TEXTINPUT.ss<<OBJECTS.SQUARES.xPoints[OBJECTS.pointLookingAt];			xNew=TEXTINPUT.ss.str();}
	if(OBJECTS.type==1){TEXTINPUT.ss<<OBJECTS.TRIANGLES.xPoints[OBJECTS.pointLookingAt];		xNew=TEXTINPUT.ss.str();}
	if(OBJECTS.type==2){TEXTINPUT.ss<<OBJECTS.CIRCLES.xPoints[OBJECTS.pointLookingAt];			xNew=TEXTINPUT.ss.str();}
	if(OBJECTS.type==3){TEXTINPUT.ss<<OBJECTS.nSIDED.xPoints[OBJECTS.pointLookingAt];			xNew=TEXTINPUT.ss.str();}
	TEXTINPUT.ss.str("\0");		TEXTINPUT.ss.clear();
	if(OBJECTS.type==0){TEXTINPUT.ss<<OBJECTS.SQUARES.xPointsOld[OBJECTS.pointLookingAt];		xOld=TEXTINPUT.ss.str();}
	if(OBJECTS.type==1){TEXTINPUT.ss<<OBJECTS.TRIANGLES.xPointsOld[OBJECTS.pointLookingAt];		xOld=TEXTINPUT.ss.str();}
	if(OBJECTS.type==2){TEXTINPUT.ss<<OBJECTS.CIRCLES.xPointsOld[OBJECTS.pointLookingAt];		xOld=TEXTINPUT.ss.str();}
	if(OBJECTS.type==3){TEXTINPUT.ss<<OBJECTS.nSIDED.xPointsOld[OBJECTS.pointLookingAt];		xOld=TEXTINPUT.ss.str();}
	TEXTINPUT.ss.str("\0");		TEXTINPUT.ss.clear();
	BUTTON[2][6].text+=break_+OBJECTS.transformationValuesString[1][1]+"\t"+OBJECTS.transformationValuesString[0][1]+break_+"\t"+dot_+"\t"+break_+xOld+break_+"\t"+equal_+"\t"+break_+xNew+break_+"\n";
	
	if(OBJECTS.type==0){TEXTINPUT.ss<<OBJECTS.SQUARES.yPoints[OBJECTS.pointLookingAt];			yNew=TEXTINPUT.ss.str();}
	if(OBJECTS.type==1){TEXTINPUT.ss<<OBJECTS.TRIANGLES.yPoints[OBJECTS.pointLookingAt];		yNew=TEXTINPUT.ss.str();}
	if(OBJECTS.type==2){TEXTINPUT.ss<<OBJECTS.CIRCLES.yPoints[OBJECTS.pointLookingAt];			yNew=TEXTINPUT.ss.str();}
	if(OBJECTS.type==3){TEXTINPUT.ss<<OBJECTS.nSIDED.yPoints[OBJECTS.pointLookingAt];			yNew=TEXTINPUT.ss.str();}
	TEXTINPUT.ss.str("\0");		TEXTINPUT.ss.clear();
	if(OBJECTS.type==0){TEXTINPUT.ss<<OBJECTS.SQUARES.yPointsOld[OBJECTS.pointLookingAt];		yOld=TEXTINPUT.ss.str();}
	if(OBJECTS.type==1){TEXTINPUT.ss<<OBJECTS.TRIANGLES.yPointsOld[OBJECTS.pointLookingAt];		yOld=TEXTINPUT.ss.str();}
	if(OBJECTS.type==2){TEXTINPUT.ss<<OBJECTS.CIRCLES.yPointsOld[OBJECTS.pointLookingAt];		yOld=TEXTINPUT.ss.str();}
	if(OBJECTS.type==3){TEXTINPUT.ss<<OBJECTS.nSIDED.yPointsOld[OBJECTS.pointLookingAt];		yOld=TEXTINPUT.ss.str();}
	TEXTINPUT.ss.str("\0");		TEXTINPUT.ss.clear();
	BUTTON[2][6].text+=break_+OBJECTS.transformationValuesString[1][0]+"\t"+OBJECTS.transformationValuesString[0][0]+break_+"\t"+dot_+"\t"+break_+yOld+break_+"\t"+equal_+"\t"+break_+yNew+break_+"\n";
	
}
void DRAW_BUTTON_TEXT(int n){
	//set values for text: x,y are location of text: tx and ty are the increments of the text so it does not show in one spot.
	for(int m=0;m<BUTTON[WINDOW.currentScreen][n].text.length();m++){
		if(BUTTON[WINDOW.currentScreen][n].text[0]==' '&&m==0||BUTTON[WINDOW.currentScreen][n].text[0]==' '&&m==0)BUTTON[WINDOW.currentScreen][n].text.erase(m,1);
		if(	BUTTON[WINDOW.currentScreen][n].text[m]==' '&&BUTTON[WINDOW.currentScreen][n].text[m+1]==' '||
			BUTTON[WINDOW.currentScreen][n].text[m]==' '&&BUTTON[WINDOW.currentScreen][n].text[m+1]==' '
		){
			while(BUTTON[WINDOW.currentScreen][n].text[m]==' '||BUTTON[WINDOW.currentScreen][n].text[m]==' ')BUTTON[WINDOW.currentScreen][n].text.erase(m,1);
		}
	}
	int endLineCount[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//40 \n's allowed per button?;
	int tabCount=0;
	int countEndLine=0;//determine if the number of lines of text based on \n is odd or even. split text to half a line if odd.
	//THIS IF STATEMENT AND ITS CONTENTS IS A FIX FOR THE POINTER NOT SHOWING UP ON A BLANK TEXT INPUT, AND POINTER NOT SHOWING UP IF IN 0 POSITION OF TEXT: 
	if(	BUTTON[WINDOW.currentScreen][n].text.length()==0&&WINDOW.buttonCurrentlyClicked==n||
		TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3]==0&&WINDOW.buttonCurrentlyClicked==n
	){
		if((GetTickCount()-TEXTINPUT.blinkertimer)>TEXTINPUT.pointerBlinkingRate){//color alpha: 
			if(TEXTINPUT.pointerBlinkAlphaOn==false)	TEXTINPUT.pointerBlinkAlphaOn=true;
			else if(TEXTINPUT.pointerBlinkAlphaOn==true)TEXTINPUT.pointerBlinkAlphaOn=false;
			TEXTINPUT.blinkertimer=GetTickCount();
		}
		glLoadIdentity();
		glColor4f(1,1,1,(int)TEXTINPUT.pointerBlinkAlphaOn);
		glTranslatef(BUTTON[WINDOW.currentScreen][n].x,BUTTON[WINDOW.currentScreen][n].y,0);
		glRotatef(180,1,0,0);
		glTranslatef(((BUTTON[WINDOW.currentScreen][n].width*.5)-(((endLineCount[0]+tabCount)*.5)*15)*WINDOW.aspect)-(7.5*WINDOW.aspect)-((BUTTON[WINDOW.currentScreen][n].text.length()*.5*15)*WINDOW.aspect),-(BUTTON[WINDOW.currentScreen][n].height*.5)+(((countEndLine-1)*.5)*(18))*WINDOW.aspect,0);
		glScalef(0.15*WINDOW.aspect,0.15*WINDOW.aspect,1);
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,TEXTINPUT.pointer[0]);
	}
	for(int m=0;m<BUTTON[WINDOW.currentScreen][n].text.length();m++){
		if(BUTTON[WINDOW.currentScreen][n].text[m]!='\n')endLineCount[countEndLine]+=1;
		else if(BUTTON[WINDOW.currentScreen][n].text[m]=='\n')countEndLine+=1;
		if(BUTTON[WINDOW.currentScreen][n].text[m]=='\t')tabCount+=1;
	}
	double tempX=BUTTON[WINDOW.currentScreen][n].x;
	double tempY=BUTTON[WINDOW.currentScreen][n].y;
	double tempTX=(BUTTON[WINDOW.currentScreen][n].width*.5)-(((endLineCount[0]+tabCount)*.5)*15);
	double tempTY=-(BUTTON[WINDOW.currentScreen][n].height*.5)+(((countEndLine-1)*.5)*(18));
	countEndLine=0;
	//special conditions for the text on specific buttons on specific screens: 
	/*if(WINDOW.currentScreen==1||WINDOW.currentScreen==6){	if(n==1)tempTX=0;}*/
	int colorTextSpecificLineInButton=0;
	bool hadColonYet=false;
	int lineLength=0;
	for(int m=0;m<BUTTON[WINDOW.currentScreen][n].text.length();m++){
		if(m>0&&BUTTON[WINDOW.currentScreen][n].text[m-1]==':')hadColonYet=true;
		//load the identity: 
		glLoadIdentity();
		//special conditions: 
		lineLength+=1;
		if(BUTTON[WINDOW.currentScreen][n].text[m]=='\n'){
			lineLength=0;
			hadColonYet=false;
			countEndLine+=1;
			tempTY-=18;
			tempTX=(BUTTON[WINDOW.currentScreen][n].width*.5)-(((endLineCount[0]+tabCount)*.5)*15);
			colorTextSpecificLineInButton+=1;
		}
		if(BUTTON[WINDOW.currentScreen][n].text[m]=='\t')tempTX+=15;
		glTranslatef(tempX,tempY,0);//initial translation: 
		glRotatef(180,1,0,0);//rotate for the text: 
		glTranslatef(tempTX*WINDOW.aspect,tempTY*WINDOW.aspect,0);//translate each text character: 
		glScalef(0.15*WINDOW.aspect,0.15*WINDOW.aspect,1);//scale for the text: 
		tempTX+=15;//increment value: 
		//color: 
		if(WINDOW.currentScreen==0||WINDOW.currentScreen==1||WINDOW.currentScreen==2){	glColor3f(.7,.9,.7);}//main screen;
		if(n==0){																		glColor4f(1,0.06274509803*m,0,1);}
		//draw text: 
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,BUTTON[WINDOW.currentScreen][n].text[m]);
		//draw pointer:
		if(WINDOW.currentScreen==1){//draw the pointer: 
		//FIX WHY TEXT POINTER DOESN'T SHOW AT THE 0 SPOT;
			if(n>2&&n<7&&WINDOW.buttonCurrentlyClicked==n&&m==TEXTINPUT.pointerPosition[WINDOW.buttonCurrentlyClicked-3/*0*/]-1){
				if((GetTickCount()-TEXTINPUT.blinkertimer)>TEXTINPUT.pointerBlinkingRate){//color alpha: 
					if(TEXTINPUT.pointerBlinkAlphaOn==false)	TEXTINPUT.pointerBlinkAlphaOn=true;
					else if(TEXTINPUT.pointerBlinkAlphaOn==true)TEXTINPUT.pointerBlinkAlphaOn=false;
					TEXTINPUT.blinkertimer=GetTickCount();
				}
				glLoadIdentity();
				glColor4f(1,1,1,(int)TEXTINPUT.pointerBlinkAlphaOn);
				glTranslatef(tempX,tempY,0);
				glRotatef(180,1,0,0);
				glTranslatef((tempTX*WINDOW.aspect)-(7.5*WINDOW.aspect),tempTY*WINDOW.aspect,0);
				glScalef(0.15*WINDOW.aspect,0.15*WINDOW.aspect,1);
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,TEXTINPUT.pointer[0]);
			}
		}
	}
}
