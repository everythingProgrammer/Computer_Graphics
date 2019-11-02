#include <gl/glut.h>
#include <math.h>
#include <cstdlib>
#include <iostream>
#define RAND_MAX = 9
using namespace std;
static int r =50;
static float cx = 0;
static float cy = 0;


void draw_dda()
{
    if(r <= 10)
    {

        r = 50;
    }
    for(; r >=10 ; )
	{
	    glBegin(GL_POLYGON);
	    float c = ((rand()+ rand())%7 );
        float c2 = ((rand() * rand())%7 );
        float c3 = ((rand() + rand()* rand())%7 );
        if(c >0.9 && c2>0.85 && c3 > 0.85)
        {

            c = ((rand())%7 );
            c2 = ((rand())%5 );
            c3 = ((rand())%7 );
        }
        glColor4f(c,c2,c3 , 1.0);
        float theta = 0.0;
        for(int i =0 ; i<360 ; i++)
        {

            theta = i*3.14/180;
            glVertex2f(r*cos(theta)+cx  , r*sin(theta)+ cy);
        }
        r=r-10;

     glEnd();
       break;
	}

	glFlush();
}

void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		cx = x ;
		cy = 480-y;
		glClear(GL_COLOR_BUFFER_BIT);


	}

}

void myKeyboardFunc(unsigned char key , int x, int y)
{
    if(key == ' ')
    {
        draw_dda();

    }

}



void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void display(void) {}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Mouse Func");
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	glutKeyboardFunc(myKeyboardFunc);
	init();
	glutMainLoop();

	return 0;
}
