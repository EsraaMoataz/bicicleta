// Assignment_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h> //Needed for "exit" function

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;


//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
	int x, int y) {    //The current mouse coordinates
	switch (key) {
	case 27: //Escape key
		exit(0); //Exit the program
	}
}

//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective


//Called when the window is resized
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}
float x = 0.0;
float flag = 0.0;
float angle = 0.0;
//float turn = 0.0;
float s = 0.0;
//float z = 0.0;
//float flag2 = 0.0;
//float turn_angle = 90.0;

void DrawEllipse(float c1,float c2)
{
	glColor3f(1.0, 1.0, 1.0);
	float a, b, c ;
	int t;
	glBegin(GL_POLYGON);
	for (t = 0; t <= 360; t += 1)
	{
		a = c1 * sin(t);
		b = c2 * cos(t);
		c = 0;
		glVertex3f(a, b, c);
	}
	glEnd();
}
//Draws the 3D scene
void drawScene() {
	//Clear information from last draw
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	glPushMatrix();
	glTranslatef(-40.0, -35.0, -100.0);
	glScalef(s, s, 1.0);
	glBegin(GL_POLYGON);  //ball circle

	const float DEG2RAD7 = 3.14159 / 180;


	for (int i = 0; i < 360; i++)
	{

		float degInRad7 = i * DEG2RAD7;
		glVertex2f(cos(degInRad7) * 5, sin(degInRad7) * 5);
	}

	glEnd();
	glPopMatrix();
	
	glTranslatef(35.0, -35.0, -100.0);
	glTranslatef(x, 0.0,0.0);
	glColor3f(1.0f, 1.0f, 1.0f);  //white
	//glRotatef(turn_angle, 0.0, turn, 0.0);
	//glTranslatef(0.0, 0.0, z);
	//glScalef(s, s, 1.0);
	
	
	glPushMatrix();
	glRotatef(angle, 0.0, 0.0, 1.0);  //steel bar right wheel
	glBegin(GL_LINES);
	 
	glVertex3f(-5.0f, 0.0f, 0.0f);
	glVertex3f(5.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 5.0f, 0.0f);
	glVertex3f(0.0f, -5.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0); //steel bar left wheel
	glTranslatef(20.0, 0.0, 0.0);
	
	glBegin(GL_LINES);
	glVertex3f(-25.0f, 0.0f, 0.0f);
	glVertex3f(-15.0f, 0.0f, 0.0f);
	glVertex3f(-20.0f, 5.0f, 0.0f);
	glVertex3f(-20.0f, -5.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(-6.0, -1.0, 0.0);
	glBegin(GL_LINES);

	glVertex3f(-6.0f, -1.0f, 0.0f);
	glVertex3f(-20.0f, -1.0f, 0.0f);
	glVertex3f(-20.0f, 1.0f, 0.0f);
	glVertex3f(-17.0f, 9.0f, 0.0f);
	glVertex3f(-10.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 8.0f, 0.0f);
	glVertex3f(0.0f, 5.0f, 0.0f);
	glVertex3f(0.0f, 10.0f, 0.0f);
	glVertex3f(0.0f, 9.0f, 0.0f);
	glVertex3f(-17.0f, 9.0f, 0.0f);
	glVertex3f(-12.0f,0.2f, 0.0f);
	glVertex3f(-20.0f, 15.0f, 0.0f);

	glVertex3f(-15.0f, 14.0f, 0.0f);
	glVertex3f(-19.0f, 12.0f, 0.0f);
	glVertex3f(-17.0f, 19.0f, 0.0f);
	glVertex3f(-21.0f, 18.0f, 0.0f);
	glVertex3f(-19.0f, 12.0f, 0.0f);
	glVertex3f(-21.0f, 18.0f, 0.0f);

	glVertex3f(-8.0f, 0.5f, 0.0f);//البدال 
	glVertex3f(-6.0f, 0.5f, 0.0f);
	glVertex3f(-6.0f, 0.5f, 0.0f);
	glVertex3f(-7.0f, -2.5f, 0.0f);
	glVertex3f(-7.0f, -2.5f, 0.0f);
	glVertex3f(-9.0f, -2.5f, 0.0f);
	glVertex3f(-9.0f, -2.5f, 0.0f);
	glVertex3f(-8.0f, 0.5f, 0.0f);




	glEnd();
	glPopMatrix();
	glBegin(GL_TRIANGLES);
	glVertex3f(3.0f, 13.0f, 0.0f);
	glVertex3f(-4.0f, 10.0f, 0.0f);
	glVertex3f(0.0f, 10.0f, 0.0f);

	glEnd();



	glBegin(GL_POINTS);  // right circle
	
	const float DEG2RAD1 = 3.14159 / 180;

	
	for (int i = 0; i < 360; i++)
	{

		float degInRad1 = i * DEG2RAD1;
		glVertex2f(cos(degInRad1) * 5, sin(degInRad1) * 5);
	}

	glEnd();

	glPushMatrix();
	glTranslatef(-20.0, 0.0, 0.0);
	glBegin(GL_POINTS);  //left circle

	const float DEG2RAD2 = 3.14159 / 180;


	for (int i = 0; i < 360; i++)
	{

		float degInRad2 = i * DEG2RAD2;
		glVertex2f(cos(degInRad2) * 5, sin(degInRad2) * 5);
	}

	glEnd();
	
	glPopMatrix();

	glBegin(GL_POINTS);  // inner1 circle

	const float DEG2RAD6 = 3.14159 / 180;


	for (int i = 0; i < 360; i++)
	{

		float degInRad6 = i * DEG2RAD6;
		glVertex2f(cos(degInRad6) * 1, sin(degInRad6) * 1);
	}

	glEnd();

	glPushMatrix();
	glTranslatef(-20.0, 0.0, 0.0);
	glBegin(GL_POINTS);  // inner2 circle

	const float DEG2RAD3 = 3.14159 / 180;


	for (int i = 0; i < 360; i++)
	{

		float degInRad3 = i * DEG2RAD3;
		glVertex2f(cos(degInRad3) * 1, sin(degInRad3) * 1);
	}

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-10.0, -1.0, 0.0);
	glBegin(GL_POINTS);  // middle circle

	const float DEG2RAD4 = 3.14159 / 180;


	for (int i = 0; i < 360; i++)
	{

		float degInRad4 = i * DEG2RAD4;
		glVertex2f(cos(degInRad4) * 2, sin(degInRad4) * 2);
	}

	glEnd();
	glPopMatrix();

	


	glPushMatrix();  //head circle
	glTranslatef(0.0, 37.0, 0.0);
	glBegin(GL_POLYGON);  

	const float DEG2RAD5 = 3.14159 / 180;


	for (int i = 0; i < 360; i++)
	{

		float degInRad5 = i * DEG2RAD5;
		glVertex2f(cos(degInRad5) * 5, sin(degInRad5) * 5);
	}

	glEnd();
	glPopMatrix();

	
	glPushMatrix();   //body ellipse
	glTranslatef(0.0, 23.0, 0.0);
    DrawEllipse(5,10);
	glPopMatrix();

	glPushMatrix();  //thigh ellipse
	glTranslatef(-5.0, 14.0, 0.0);
	DrawEllipse(8, 3);
	glPopMatrix();

	glPushMatrix();  //left leg  ellipse
	glTranslatef(-10., 7.5, 0.0);
	glRotatef(110, 0.0, 0.0, 1.0);
	DrawEllipse(7, 2);
	glPopMatrix();

	glPushMatrix();  //right leg  ellipse
	glTranslatef(-10., 7.5, 0.0);
	glRotatef(-110, 0.0, 0.0, 1.0);
	DrawEllipse(7, 2);
	glPopMatrix();

	glPushMatrix();  //left arm  ellipse
	glTranslatef(-8.0, 21.0, 0.0);
	glRotatef(42, 0.0, 0.0, 1.0);
	DrawEllipse(12, 2);
	glPopMatrix();

	glPushMatrix();  //right arm  ellipse
	glTranslatef(-8.0, 25.0, 0.0);
	glRotatef(35, 0.0, 0.0, 1.0);
	DrawEllipse(10, 2);
	glPopMatrix();

	if (flag == 0.0)
		if (x >= -50.0f) {
			x -= 0.01f;
			s += 0.0002;
		}

		
		else
			flag = 1.0;
	if (flag == 1.0) {
		x = 0.0f;
		s = 0.0;
	     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		flag = 0.0;
	}
	angle += 0.1f;

	/*if (flag2 == 0.0)
		if (x <= -50.0f) {
			turn_angle = 90.0;
			turn = 1.0;

			if (s > 0.0) {
				s -= 0.1;
				z -= 0.1;
			}
			else {
				  flag = 1.0;
				  flag2 = 1.0;
				  
			    }
		}
		
			
	if (flag2 == 1.0) {
		turn = 0.0;
		turn_angle = -90.0;
		s = 1.0;
		z = 0.0;
		flag2 = 0.0;
	}*/
	
	glutPostRedisplay();              //Tell GLUT that the display has changed
	glutTimerFunc(25, 0, 0);          //Tell GLUT to call update again in 25 milliseconds
	glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv)
{ //Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400); //Set the window size

	//Create the window
	glutCreateWindow(" bicicleta- videotutorialsrock.com");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
