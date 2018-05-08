#ifndef INCLUDESVOIDS_H
#define INCLUDESVOIDS_H
		#include <future>
		#include <math.h>
		#include <ctime>
		#ifdef WIN32
			#define WIN32_LEAN_AND_MEAN
				#define _WIN32_WINNT 0x501
			#include <windows.h>
		#endif
			#include <winsock2.h>
			#include <ws2tcpip.h>
			#include <future>
			#include <math.h>
		#include <iostream>
		#include <stdlib.h>
		#include <stdio.h>
		#include <stdarg.h>
		#include <cstring>
		#include <fstream>
	#define GLEW_STATIC
		#include <GL/glew.h>
		#include <gl\gl.h>
		#include <gl\glext.h>
		#include <gl\glaux.h>
		#include <gl\glu.h>
		#include <GL\glut.h>
		#include <assert.h>
		#include <sstream>
		#include <iomanip>
		#include <ctime>
		#include <cstring>
		#include <cmath>
		#include <limits.h>
		#include <random>
		#include <fstream>
		#include <time.h>
		#include <string.h>
		#include <string>
		#include <cstdlib>
		#include <cstdio>
		#include <gl\glfw.h>
		#include <vector>
		#include <conio.h>
		#include <new>
			#include <pthread.h>
	using namespace std;
/*
-lWs2_32
-lMswsock
-lAdvApi32
//
-lglew32s
-lglut32
-lglu32
-lwinmm
-lgdi32
-lmingw32
-lopengl32
-pthread
*/
/*
	ADD:
	*ADD TRANSLATE LEFT RIGHT UP DOWN BUTTONS;
	*ADD A RESET BUTTON FOR: LEFT RIGHT UP DOWN;
	*FIX FLOATING POINT ERRORS;
	*
*/
	//VOIDS: 
		void INIT();
			void BUTTONS_INIT();
			void WINDOW_INIT();
			void TEXT_INIT();
			void LISTS();
				void CALCULATE();
		int main(int argc,char **argv);
			void mousemoveunpressed(int x, int y);
			void mousemotion(int x, int y);
			void mouseclick(int button,int state,int x,int y);
			void BUTTON_LOGIC(int buttonNumber);
				void BUTTONS_NO_CLICK(int buttonNumber);
			void keyPressedSpecial(int key,int x,int y);
				void SPECIAL_TEXT_INPUT(int key);
				void REGULAR_TEXT_INPUT(int key);
				bool SEARCH_TEXT(string searchThrough,char find);
			void keyUnpressedSpecial(int key, int x, int y);
			void keyPressed(unsigned char key,int x,int y);
			void keyUnpressed(unsigned char key, int x, int y);
		void reshape(int w,int h);
		void display();
			void DRAW2D();
				void DRAW_BOARD();
			void DRAW3D();
				void DRAW_BUTTONS();
					void UPDATE_BUTTON_TEXT();
					void DRAW_BUTTON_TEXT(int n);
			//void drawText();
	//LISTS: 
		extern GLuint board[10];//Quadrilateral, triangle, ellipse, n-sided; 			1-10;
		extern GLuint boardOriginals[10];//Quadrilateral, triangle, ellipse, n-sided;	11-20;
			extern bool drewOriginal,drewnSided;
	//STRUCTURES:
		//buttons; 
		struct _BUTTONS{
			double x,y;
			double width,height;
			string text;
		};extern _BUTTONS BUTTON[3][20];//[SERVERCONNECT.playerStatus][buttonCurrentlyClicked];
			extern int numberButtonsDraw[3];//[WINDOW.currentScreen]max number of buttons to draw for this screen;
//
		struct _OBJECTS{
			int pointLookingAt;
			int type;
			string typeOutPut;
			string transformationValuesString[2][2];//string to display values entered by the user;
			double transformationValues[2][2];//string values are converted to this double value;
			double tempTransformationValuesX[360];//these are the temp x values held;
			double tempTransformationValuesY[360];//these are the temp y values held;
			//[360]
			//
			string nSidedValueString;
			int nSidedValue;
			struct _TRIANGLES{
				int size;
				double xPoints[3];
				double yPoints[3];
				double xPointsOld[3];
				double yPointsOld[3];	
			};_TRIANGLES TRIANGLES;
			struct _SQUARES{
				int size;
				double xPoints[4];
				double yPoints[4];
				double xPointsOld[4];
				double yPointsOld[4];	
			};_SQUARES SQUARES;
			struct _CIRCLES{
				int size;
				double xPoints[1];
				double yPoints[1];
				double xPointsOld[1];
				double yPointsOld[1];
			};_CIRCLES CIRCLES;
			struct _nSIDED{
				int size;
				vector<double> xPoints;
				vector<double> yPoints;	
				vector<double> xPointsOld;
				vector<double> yPointsOld;
			};_nSIDED nSIDED;
		};extern _OBJECTS OBJECTS;
//
		struct _WINDOW{
			bool keysCurrentlyPressedSpecial[128];
			double winW,winH;//dynamic; not initialized in init;
			double aspect;//dynamic;not valued in init;
			bool fullScreen;//starts as false; not implemented yet;
			int zoom;
			unsigned int clicked[2],released[2];//x and y press and release;
			unsigned int currentScreen;
			unsigned int buttonCurrentlyClicked;//which button is currently clicked on the current screen?
			unsigned int buttonCurrentlySelected;
			bool typing;
			_WINDOW(){
				fullScreen=true;
			}
		};extern _WINDOW WINDOW;
//
		struct _TEXT_INPUT{
			stringstream ss; 
				//TEXTINPUT.ss<<number;		string=TEXTINPUT.ss.str();
				//TEXTINPUT.ss.str("\0");	TEXTINPUT.ss.clear();
			int pointerPosition[4];
			string pointer;
			bool pointerBlinkAlphaOn;
			int pointerBlinkingRate;
			DWORD blinkertimer;
			bool negativeUsed[4],decimalUsed[4];
		};extern _TEXT_INPUT TEXTINPUT;
//
	//GLOBALS: 
		extern bool INIT_;
#endif
