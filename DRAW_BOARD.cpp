#include "includesVoids.h"
void DRAW_BOARD(){
	//draw the axis x,y: 
	glLoadIdentity();
	glColor4f(.5,.5,0,.75);
	glTranslatef(0,0,-5);
	glBegin(GL_LINES);
		glVertex2f(-100,0);
		glVertex2f(100,0);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0,-100);
		glVertex2f(0,100);
	glEnd();

	//draw original: 
	glLoadIdentity();
	glColor4f(.7,0,.3,1);
	glTranslatef(0,0,WINDOW.zoom);
	glCallList(boardOriginals[OBJECTS.type]);

	//draw new: 
	glLoadIdentity();
	glColor4f(0,1,0,.5);
	glTranslatef(0,0,WINDOW.zoom);
	glCallList(board[OBJECTS.type]);
	
	//draw points old:
	glPointSize(5);
	double pointsOld[2]={0,0};
	if(OBJECTS.type==0){		pointsOld[0]=OBJECTS.SQUARES.xPointsOld[OBJECTS.pointLookingAt];	pointsOld[1]=OBJECTS.SQUARES.yPointsOld[OBJECTS.pointLookingAt];}
	else if(OBJECTS.type==1){	pointsOld[0]=OBJECTS.TRIANGLES.xPointsOld[OBJECTS.pointLookingAt];	pointsOld[1]=OBJECTS.TRIANGLES.yPointsOld[OBJECTS.pointLookingAt];}
	else if(OBJECTS.type==2){	pointsOld[0]=OBJECTS.CIRCLES.xPointsOld[OBJECTS.pointLookingAt];	pointsOld[1]=OBJECTS.CIRCLES.yPointsOld[OBJECTS.pointLookingAt];}
	else if(OBJECTS.type==3){	pointsOld[0]=OBJECTS.nSIDED.xPointsOld[OBJECTS.pointLookingAt];		pointsOld[1]=OBJECTS.nSIDED.yPointsOld[OBJECTS.pointLookingAt];}
	glLoadIdentity();
	glColor4f(.7,.5,.7,1);
	glTranslatef(0,0,WINDOW.zoom);
	glBegin(GL_POINTS);
		glVertex2f(pointsOld[0],pointsOld[1]);
	glEnd();
	
	//draw points new:
	double points[2]={0,0};
	if(OBJECTS.type==0){		points[0]=OBJECTS.SQUARES.xPoints[OBJECTS.pointLookingAt];	points[1]=OBJECTS.SQUARES.yPoints[OBJECTS.pointLookingAt];}
	else if(OBJECTS.type==1){	points[0]=OBJECTS.TRIANGLES.xPoints[OBJECTS.pointLookingAt];points[1]=OBJECTS.TRIANGLES.yPoints[OBJECTS.pointLookingAt];}
	else if(OBJECTS.type==2){	points[0]=OBJECTS.CIRCLES.xPoints[OBJECTS.pointLookingAt];	points[1]=OBJECTS.CIRCLES.yPoints[OBJECTS.pointLookingAt];}
	else if(OBJECTS.type==3){	points[0]=OBJECTS.nSIDED.xPoints[OBJECTS.pointLookingAt];	points[1]=OBJECTS.nSIDED.yPoints[OBJECTS.pointLookingAt];}
	glLoadIdentity();
	glColor4f(.3,1,.3,1);
	glTranslatef(0,0,WINDOW.zoom);
	glBegin(GL_POINTS);
		glVertex2f(points[0],points[1]);
	glEnd();
}
