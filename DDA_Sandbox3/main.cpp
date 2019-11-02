
// This is completely working code of DDA Algorithm
// Hurray .


#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

#define ROUND(a) ((int)(a+0.5))


int trclick = 0 ; // to make sure right click happens only once .
int tlclick = 0 ; // To make sure that click happens only once  .


void init()
{
        gluOrtho2D(-500,500,-300,300);

}
struct Coord {
	int x;
	int y;
};

Coord c1, c2;
// c1 stores coordinates of start point .
// c2 contains coordinates of end point .




void BitmapText(char* string, float xc, float yc)
{
char c;
int i = 0;
glRasterPos2f(xc, yc);

for (i = 0; string[i] != '\0'; i++)
{
c = string[i];
glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
}
}


void BitmapCordinates(int x , int y, float xc, float yc)
{
int i = 0;
glRasterPos2f(xc, yc);

char array[1000];
sprintf( array, "x = %d , y = %d", x ,y);
for (i = 0; array[i] != '\0'; i++)
{
    char c = array[i];

    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);

}

}


void LineDDA()
{

    int  dx = c2.x-c1.x;
    int dy = c2.y - c1.y;
    int steps ;
    int k ;
    float xIncrement , yIncrement , x = c1.x , y = c1.y;
    if(abs(dx)> abs(dy))
    {

        steps = abs(dx);
    }
    else
        steps = abs(dy);
    xIncrement = dx/(float)steps;
    yIncrement = dy/ (float)steps;
    glBegin(GL_POINTS);
    glColor3f(1, 1, 0);
    glVertex2f(ROUND(x), ROUND(y));
    glEnd();

    glBegin(GL_POINTS);
    for(k =0 ; k< steps ; k++)
    {


        x+= xIncrement;
        y+= yIncrement;
        glVertex2f(ROUND(x), ROUND(y));


    }
    glEnd();
    glFlush();

}

void myMouseFunc(int button, int state, int x, int y)
{

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && trclick == 0)
    {

        trclick = 1;
		int a  = x ;
		int b = 300-y;
		c1.x = x-500;
		c1.y = 300-y;
		//c1.x = x;
		//c1.y = 480-y;
		//click = 1;
		//glColor3f(1, 0, 1);
		char msg[] = "Start Coordinates " ;
		BitmapText(msg, 200, -200);
		BitmapCordinates(c1.x,b , 200, -215);
		glFlush();


	}
	else if( trclick == 1 &&  button != GLUT_LEFT_BUTTON && tlclick == 0)
    {
        tlclick = 1;

        c2.x = x-500;
        c2.y = 300-y;
        char msg[] = "End Coordinates ";
        BitmapText(msg , 200, -230);
        BitmapCordinates(c2.x , c2.y , 200 ,-245);
        float m = (float)(c2.y-c1.y)/(float)(c2.x -c1.x);

        char Slope[1000];
        sprintf( Slope, "Slope of Line = %f",m);
        BitmapText(Slope , 200,255);


        glFlush();
        LineDDA();
    }

}






void display()
{




	glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1,1,1);
    //glBegin(GL_LINES);
    //    glVertex2d(-500,0);
    //    glVertex2d(500,0);
    //    glVertex2d(0,-300);
   //     glVertex2d(0,300);
    //glEnd();
    glColor3f(1, 0, 0);
    char name[] = "Abhinav Singh Rana";
    char sap[] = "500060202";
    BitmapText(name, 200, -280);
    BitmapText(sap, 200, -290);
    glutSwapBuffers();
    glFlush();

}


int main(int argc,char** argv)
{
	int mode = GLUT_RGB|GLUT_SINGLE;
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(mode);
	glutInitWindowSize(1000,600);
	glutCreateWindow("DDA");
    //glutMouseFunc(OnMouseClick);
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);

    glutMainLoop();
    return 0;
}





