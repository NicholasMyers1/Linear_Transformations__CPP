#include "includesVoids.h"
void CALCULATE(){
	//convert the strings to double values;
	OBJECTS.transformationValues[1][1]=atof(OBJECTS.transformationValuesString[0][0].c_str());//br
	OBJECTS.transformationValues[0][1]=atof(OBJECTS.transformationValuesString[0][1].c_str());//bl
	OBJECTS.transformationValues[1][0]=atof(OBJECTS.transformationValuesString[1][0].c_str());//tr
	OBJECTS.transformationValues[0][0]=atof(OBJECTS.transformationValuesString[1][1].c_str());//tl

cout<<OBJECTS.transformationValues[0][0]<<":00tl\n";
cout<<OBJECTS.transformationValues[0][1]<<":01tr\n";
cout<<OBJECTS.transformationValues[1][0]<<":10bl\n";
cout<<OBJECTS.transformationValues[1][1]<<":11br\n";
	//set the temp values for the new points;
	for(int n=0;n<360;n++){
		if(OBJECTS.type==0&&n<4){//quadrilaterals;
			OBJECTS.tempTransformationValuesX[n]=(OBJECTS.transformationValues[0][0]*OBJECTS.SQUARES.xPoints[n])+(OBJECTS.transformationValues[0][1]*OBJECTS.SQUARES.yPoints[n]);//0;
			OBJECTS.tempTransformationValuesY[n]=(OBJECTS.transformationValues[1][0]*OBJECTS.SQUARES.xPoints[n])+(OBJECTS.transformationValues[1][1]*OBJECTS.SQUARES.yPoints[n]);//0;
		}
		else if(OBJECTS.type==1&&n<3){//triangles;
			OBJECTS.tempTransformationValuesX[n]=(OBJECTS.transformationValues[0][0]*OBJECTS.TRIANGLES.xPoints[n])+(OBJECTS.transformationValues[0][1]*OBJECTS.TRIANGLES.yPoints[n]);//0;
			OBJECTS.tempTransformationValuesY[n]=(OBJECTS.transformationValues[1][0]*OBJECTS.TRIANGLES.xPoints[n])+(OBJECTS.transformationValues[1][1]*OBJECTS.TRIANGLES.yPoints[n]);//0;
		}
		else if(OBJECTS.type==2&&n<1){//ellipses;
			OBJECTS.tempTransformationValuesX[n]=(OBJECTS.transformationValues[0][0]*OBJECTS.CIRCLES.xPoints[n])+(OBJECTS.transformationValues[0][1]*OBJECTS.CIRCLES.yPoints[n]);//0;
			OBJECTS.tempTransformationValuesY[n]=(OBJECTS.transformationValues[1][0]*OBJECTS.CIRCLES.xPoints[n])+(OBJECTS.transformationValues[1][1]*OBJECTS.CIRCLES.yPoints[n]);//0;
		}
		else if(OBJECTS.type==3&&n<OBJECTS.nSIDED.size){//n-sided;
			OBJECTS.tempTransformationValuesX[n]=(OBJECTS.transformationValues[0][0]*OBJECTS.nSIDED.xPoints[n])+(OBJECTS.transformationValues[0][1]*OBJECTS.nSIDED.yPoints[n]);//0;
			OBJECTS.tempTransformationValuesY[n]=(OBJECTS.transformationValues[1][0]*OBJECTS.nSIDED.xPoints[n])+(OBJECTS.transformationValues[1][1]*OBJECTS.nSIDED.yPoints[n]);//0;
		}
/*
		if(OBJECTS.type==0&&n<4){//quadrilaterals;
			OBJECTS.tempTransformationValuesX[n]=(OBJECTS.transformationValues[0][0]*OBJECTS.SQUARES.xPoints[n])+(OBJECTS.transformationValues[0][1]*OBJECTS.SQUARES.yPoints[n]);//0;
			OBJECTS.tempTransformationValuesY[n]=(OBJECTS.transformationValues[1][0]*OBJECTS.SQUARES.xPoints[n])+(OBJECTS.transformationValues[1][1]*OBJECTS.SQUARES.yPoints[n]);//0;
		}
		else if(OBJECTS.type==1&&n<3){//triangles;
			OBJECTS.tempTransformationValuesX[n]=(OBJECTS.transformationValues[0][0]*OBJECTS.TRIANGLES.xPoints[n])+(OBJECTS.transformationValues[0][1]*OBJECTS.TRIANGLES.yPoints[n]);//0;
			OBJECTS.tempTransformationValuesY[n]=(OBJECTS.transformationValues[1][0]*OBJECTS.TRIANGLES.xPoints[n])+(OBJECTS.transformationValues[1][1]*OBJECTS.TRIANGLES.yPoints[n]);//0;
		}
		else if(OBJECTS.type==2&&n<1){//ellipses;
			OBJECTS.tempTransformationValuesX[n]=(OBJECTS.transformationValues[0][0]*OBJECTS.CIRCLES.xPoints[n])+(OBJECTS.transformationValues[0][1]*OBJECTS.CIRCLES.yPoints[n]);//0;
			OBJECTS.tempTransformationValuesY[n]=(OBJECTS.transformationValues[1][0]*OBJECTS.CIRCLES.xPoints[n])+(OBJECTS.transformationValues[1][1]*OBJECTS.CIRCLES.yPoints[n]);//0;
		}
		else if(OBJECTS.type==3&&n<OBJECTS.nSIDED.size){//n-sided;
			OBJECTS.tempTransformationValuesX[n]=(OBJECTS.transformationValues[0][0]*OBJECTS.nSIDED.xPoints[n])+(OBJECTS.transformationValues[0][1]*OBJECTS.nSIDED.yPoints[n]);//0;
			OBJECTS.tempTransformationValuesY[n]=(OBJECTS.transformationValues[1][0]*OBJECTS.nSIDED.xPoints[n])+(OBJECTS.transformationValues[1][1]*OBJECTS.nSIDED.yPoints[n]);//0;
		}
*/
		else break;
	}
	//once finished: move temp to perm values: 
	for(int n=0;n<360;n++){//set the permanent point values
		if(OBJECTS.type==0&&n<4){							OBJECTS.SQUARES.xPoints[n]=OBJECTS.tempTransformationValuesX[n];	OBJECTS.SQUARES.yPoints[n]=OBJECTS.tempTransformationValuesY[n];}
		else if(OBJECTS.type==1&&n<3){						OBJECTS.TRIANGLES.xPoints[n]=OBJECTS.tempTransformationValuesX[n];	OBJECTS.TRIANGLES.yPoints[n]=OBJECTS.tempTransformationValuesY[n];}
		else if(OBJECTS.type==2&&n<1){						OBJECTS.CIRCLES.xPoints[n]=OBJECTS.tempTransformationValuesX[n];	OBJECTS.CIRCLES.yPoints[n]=OBJECTS.tempTransformationValuesY[n];}
		else if(OBJECTS.type==3&&n<OBJECTS.nSIDED.size){	OBJECTS.nSIDED.xPoints[n]=OBJECTS.tempTransformationValuesX[n];		OBJECTS.nSIDED.yPoints[n]=OBJECTS.tempTransformationValuesY[n];}
		else break;
	}
	//update lists:
	LISTS();
}
void LISTS(){
	//new: 
	if(drewOriginal==true){
		for(int n=0;n<4;n++){
			board[n]=n+3+1;//set the list number;
			//generate the list;
			glGenLists(board[n]);
			glNewList(board[n],GL_COMPILE);
			if(n==0){//quadrilateral;
				glBegin(GL_POLYGON);
					glVertex2f(OBJECTS.SQUARES.xPoints[0],OBJECTS.SQUARES.yPoints[0]);
			    	glVertex2f(OBJECTS.SQUARES.xPoints[1],OBJECTS.SQUARES.yPoints[1]);
			    	glVertex2f(OBJECTS.SQUARES.xPoints[2],OBJECTS.SQUARES.yPoints[2]);
			    	glVertex2f(OBJECTS.SQUARES.xPoints[3],OBJECTS.SQUARES.yPoints[3]);
				glEnd();
			}
			if(n==1){//triangle;
				glBegin(GL_POLYGON);
			    	glVertex2f(OBJECTS.TRIANGLES.xPoints[0], OBJECTS.TRIANGLES.yPoints[0]);
			    	glVertex2f(OBJECTS.TRIANGLES.xPoints[1], OBJECTS.TRIANGLES.yPoints[1]);
			    	glVertex2f(OBJECTS.TRIANGLES.xPoints[2], OBJECTS.TRIANGLES.yPoints[2]);
				glEnd();
			}
			if(n==2){//ellipse;
				glBegin(GL_POLYGON);
					for(int m=0;m<360;m++){
						glVertex2f((cos(m*2*3.14/360)*OBJECTS.CIRCLES.xPoints[0])+0,(sin(m*2*3.14/360)*OBJECTS.CIRCLES.yPoints[0])+0);//the 0's are the x and y coordinates translated from the origin. 
					}
				glEnd();
			}
			if(n==3){//n-sided;
				glBegin(GL_POLYGON);
					for(int m=0;m<OBJECTS.nSIDED.size;m++){
						glVertex2f(OBJECTS.nSIDED.xPoints[m],OBJECTS.nSIDED.yPoints[m]);
					}
				glEnd();
			}
			glEndList();
		}
	}
	//originals: 
	if(drewOriginal==false){
		for(int n=0;n<3;n++){
			boardOriginals[n]=n+10+1;//set the list number;
			//generate the list;
			glGenLists(boardOriginals[n]);
			glNewList(boardOriginals[n],GL_COMPILE);
			if(n==0){//quadrilateral;
				glBegin(GL_POLYGON);
					glVertex2f(OBJECTS.SQUARES.xPoints[0],OBJECTS.SQUARES.yPoints[0]);
			    	glVertex2f(OBJECTS.SQUARES.xPoints[1],OBJECTS.SQUARES.yPoints[1]);
			    	glVertex2f(OBJECTS.SQUARES.xPoints[2],OBJECTS.SQUARES.yPoints[2]);
			    	glVertex2f(OBJECTS.SQUARES.xPoints[3],OBJECTS.SQUARES.yPoints[3]);
				glEnd();
			}
			if(n==1){//triangle;
				glBegin(GL_POLYGON);
			    	glVertex2f(OBJECTS.TRIANGLES.xPoints[0], OBJECTS.TRIANGLES.yPoints[0]);
			    	glVertex2f(OBJECTS.TRIANGLES.xPoints[1], OBJECTS.TRIANGLES.yPoints[1]);
			    	glVertex2f(OBJECTS.TRIANGLES.xPoints[2], OBJECTS.TRIANGLES.yPoints[2]);
				glEnd();
			}
			if(n==2){//ellipse;
				glBegin(GL_POLYGON);
					for(int m=0;m<360;m++){
						glVertex2f((cos(m*2*3.14/360)*OBJECTS.CIRCLES.xPoints[0])+0,(sin(m*2*3.14/360)*OBJECTS.CIRCLES.yPoints[0])+0);//the 0's are the x and y coordinates translated from the origin. 
					}
				glEnd();
			}//3 is special;
			glEndList();
		}
		drewOriginal=true;
	}
	if(drewnSided==false){
		OBJECTS.nSIDED.size=OBJECTS.nSidedValue;
		OBJECTS.nSIDED.xPoints.resize(OBJECTS.nSIDED.size+1);
		OBJECTS.nSIDED.yPoints.resize(OBJECTS.nSIDED.size+1);
			OBJECTS.nSIDED.xPointsOld.resize(OBJECTS.nSIDED.size+1);
			OBJECTS.nSIDED.yPointsOld.resize(OBJECTS.nSIDED.size+1);
		//set values: 
		for(int n=0;n<OBJECTS.nSIDED.size;n++){
			OBJECTS.nSIDED.xPoints[n]=(cos(n*2*3.14/OBJECTS.nSIDED.size)*1);
			OBJECTS.nSIDED.yPoints[n]=(sin(n*2*3.14/OBJECTS.nSIDED.size)*1);
				OBJECTS.nSIDED.xPointsOld[n]=OBJECTS.nSIDED.xPoints[n];
				OBJECTS.nSIDED.yPointsOld[n]=OBJECTS.nSIDED.yPoints[n];
		}
		int n=3;
		boardOriginals[n]=n+10+1;//set the list number;
		//generate the list;
		glGenLists(boardOriginals[n]);
		glNewList(boardOriginals[n],GL_COMPILE);
		glBegin(GL_POLYGON);
			for(int m=0;m<OBJECTS.nSIDED.size;m++){
				glVertex2f((cos(m*2*3.14/OBJECTS.nSIDED.size)*1)+0,(sin(m*2*3.14/OBJECTS.nSIDED.size)*1)+0);//the 0's are the x and y coordinates translated from the origin. 
			}
		glEnd();
		glEndList();
	}
}
