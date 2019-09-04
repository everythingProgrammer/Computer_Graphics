// Works perfectly



#include <gl/glut.h>
#include <math.h>
#include <cstdlib>
#include <iostream>
#define RAND_MAX = 9
using namespace std;

struct Point {
	GLint x;
	GLint y;
};

Point p1, p2;

void draw_dda(Point p1) {
	GLfloat x1 = p1.x;
	GLfloat y1 = p2.y;

	glClear(GL_COLOR_BUFFER_BIT);

    for(int rdx = 30 ; rdx >=10 ; rdx=rdx -10)
	{
	    glBegin(GL_POLYGON);
	    float c = ((rand())%7 );
        float c2 = ((rand())%7 );
        float c3 = ((rand())%7 );
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
            glVertex2f(rdx*cos(theta)+x1  , rdx*sin(theta)+ p1.y);
        }
     glEnd();
	}

	glFlush();
}

void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		p1.x = x;
		p1.y = 480-y;
		draw_dda(p1);
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
	init();
	glutMainLoop();

	return 0;
}
