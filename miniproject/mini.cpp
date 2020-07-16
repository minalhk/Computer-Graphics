#include<stdlib.h> 
#include<GL/glut.h> 
#include<fstream>
#include<iostream>
#include<math.h> 
using namespace std;
void display();
void reshape(int,int);
void timer(int);
int main(int argc,char** argv){

glutInit(&argc,argv);

glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);		//sets color mode
glutInitWindowPosition(200,200);	//position
glutInitWindowSize(400,400);		//size of window
glutCreateWindow("demo");		//creation

//glClearColor(1.0,1.0,0.0,1.0);        function to set bg colorr   

glutDisplayFunc(display);	//to redraw window
glutReshapeFunc(reshape);
glutTimerFunc(0,timer,0);
glutMainLoop();			//to keep prog running infinitely

}


float y=-10;


void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(4.0);
glColor3f(1.0,1.0,0.0);
glBegin(GL_LINES);

glVertex2f(0,-10);
glVertex2f(0,10);
glEnd();

glColor3f(0.0,255.0,0);
glBegin(GL_QUADS);
glVertex2f(0,y);
glVertex2f(4,y);
glVertex2f(4,y+1);
glVertex2f(0,y+1);
glEnd();
glColor3f(255.0,255.0,255.0);
glBegin(GL_QUADS);
glVertex2f(0,y+1);
glVertex2f(4,y+1);
glVertex2f(4,y+2);
glVertex2f(0,y+2);
glEnd();
glColor3f(255.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(0,y+2);
glVertex2f(4,y+2);
glVertex2f(4,y+3);
glVertex2f(0,y+3);
glEnd();
 glBegin(GL_LINE_LOOP);
glColor3f(0,0,255);

    for(int ii = 0; ii < 24; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(24);//get the current angle

        float x1 = 0.5 * cosf(theta);//calculate the x component
        float y1 = 0.5* sinf(theta);//calculate the y component
        
        glVertex2f(x1 + 2, y1 + y+1.5);//output vertex


    }
    glEnd();
  for(int ii = 0; ii < 24; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(24);//get the current angle

        float x1 = 0.5 * cosf(theta);//calculate the x component
        float y1 = 0.5* sinf(theta);//calculate the y component
        
        
        if(ii%3==0)
{        
glBegin(GL_LINES);

glVertex2f(2,y+1.5);
glVertex2f(x1 + 2, y1 + y+1.5);
glEnd();
}
        

    }


//glFlush();			//draw on screen
glutSwapBuffers();







}


void reshape(int w,int h)
{

glViewport(0,0,(GLsizei)w,(GLsizei)h);	//provide coordinate for viewport

//projection
glMatrixMode(GL_PROJECTION);
glLoadIdentity();		//reset any prev matrix tranformation
gluOrtho2D(-10,10,-10,10);
glMatrixMode(GL_MODELVIEW);




}


void timer(int a)
{
glutPostRedisplay();
glutTimerFunc(1000/60,timer,0);

if(y<=7)
y=y+0.15;
else
y=y;





















}
