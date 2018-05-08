#include "includesVoids.h"
void INIT(){
	BUTTONS_INIT();
		
	if(INIT_==true){
		//clear: 
		TEXTINPUT.ss.str("\0");TEXTINPUT.ss.clear();
		
		WINDOW_INIT();//window: winW, winH, aspect and fullscreen are dynamic.
		TEXT_INIT();//TEXTINPUT:  
		
		//objects,window zoom, etc: 
		OBJECTS.type=-1;
		OBJECTS.typeOutPut="\0";
		OBJECTS.transformationValuesString[0][0]="1";
		OBJECTS.transformationValuesString[0][1]="0";
		OBJECTS.transformationValuesString[1][0]="0";
		OBJECTS.transformationValuesString[1][1]="1";
		OBJECTS.transformationValues[0][0]=0;
		OBJECTS.transformationValues[0][1]=0;
		OBJECTS.transformationValues[1][0]=0;
		OBJECTS.transformationValues[1][1]=0;
		//
		OBJECTS.nSidedValueString="5";
		OBJECTS.nSidedValue=5;
			OBJECTS.nSIDED.size=0;
		OBJECTS.nSIDED.xPoints.resize(OBJECTS.nSIDED.size+1);
			OBJECTS.nSIDED.xPoints.clear();
		OBJECTS.nSIDED.yPoints.resize(OBJECTS.nSIDED.size+1);
			OBJECTS.nSIDED.yPoints.clear();
			OBJECTS.nSIDED.xPointsOld.resize(OBJECTS.nSIDED.size+1);
				OBJECTS.nSIDED.xPointsOld.clear();
			OBJECTS.nSIDED.yPointsOld.resize(OBJECTS.nSIDED.size+1);
				OBJECTS.nSIDED.yPointsOld.clear();
			//set values: 
			for(int n=0;n<OBJECTS.nSIDED.size;n++){
				OBJECTS.nSIDED.xPoints[n]=(cos(n*2*3.14/OBJECTS.nSIDED.size)*1);
				OBJECTS.nSIDED.yPoints[n]=(sin(n*2*3.14/OBJECTS.nSIDED.size)*1);
			}
		//
		for(int n=0;n<360;n++){
			OBJECTS.tempTransformationValuesX[n]=0;
			OBJECTS.tempTransformationValuesY[n]=0;
		}
		OBJECTS.pointLookingAt=0;
		//triangles:
		OBJECTS.TRIANGLES.xPoints[0]=-1;OBJECTS.TRIANGLES.yPoints[0]=0;
		OBJECTS.TRIANGLES.xPoints[1]=1;OBJECTS.TRIANGLES.yPoints[1]=0;
		OBJECTS.TRIANGLES.xPoints[2]=0;OBJECTS.TRIANGLES.yPoints[2]=1;
		OBJECTS.TRIANGLES.size=3;
		for(int n=0;n<3;n++){
			OBJECTS.TRIANGLES.xPointsOld[n]=OBJECTS.TRIANGLES.xPoints[n];
			OBJECTS.TRIANGLES.yPointsOld[n]=OBJECTS.TRIANGLES.yPoints[n];
		}
		//Quadrilateral: 
		OBJECTS.SQUARES.xPoints[0]=1;OBJECTS.SQUARES.yPoints[0]=1;
		OBJECTS.SQUARES.xPoints[1]=1;OBJECTS.SQUARES.yPoints[1]=-1;
		OBJECTS.SQUARES.xPoints[2]=-1;OBJECTS.SQUARES.yPoints[2]=-1;
		OBJECTS.SQUARES.xPoints[3]=-1;OBJECTS.SQUARES.yPoints[3]=1;
		OBJECTS.SQUARES.size=4;
		for(int n=0;n<4;n++){
			OBJECTS.SQUARES.xPointsOld[n]=OBJECTS.SQUARES.xPoints[n];
			OBJECTS.SQUARES.yPointsOld[n]=OBJECTS.SQUARES.yPoints[n];
		}
		//ellipse: 
		OBJECTS.CIRCLES.xPoints[0]=1;
		OBJECTS.CIRCLES.yPoints[0]=1;
		OBJECTS.CIRCLES.xPointsOld[0]=OBJECTS.CIRCLES.xPoints[0];
		OBJECTS.CIRCLES.yPointsOld[0]=OBJECTS.CIRCLES.yPoints[0];
		OBJECTS.CIRCLES.size=1;
		//
		WINDOW.zoom=-25;
		//
		drewOriginal=false;
		drewnSided=false;
		
		LISTS();//lists:
		
		INIT_=false;//set init_ to false: 
	}
}/*END INIT*/
