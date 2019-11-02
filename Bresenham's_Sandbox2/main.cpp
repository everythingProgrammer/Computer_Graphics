// This works for slope   0<m<1

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
        glClear(GL_COLOR_BUFFER_BIT);

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


void Bresenhams()
{
    glColor3d(1,1,0);
    glBegin(GL_POINTS);
    for(int x = 200 ; x <= 400 ; x++)
    {

        glVertex2d(x,250);
    }
    glEnd();
    glFlush();

    glColor3d(1, 0, 1);

    int dx = abs(c2.x - c1.x);
    int dy = abs(c2.y - c1.y);
    int p = 2*dy - dx;
    int tDy = 2*dy;
    int tDyDx = 2*(dy-dx);
    int x, y, xEnd;
    int yinc = 1;
    if(c1.x > c2.x)
    {
        x = c2.x;
        y = c2.y;
        xEnd = c1.x;
    }
    else
    {

        x = c1.x;
        y = c1.y;
        xEnd = c2.x;

    }


    float m = (float)(c2.y - c1.y )/ (float)(c2.x -c1.x );
    if( m> 0 && m<= 1)
    {
            glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();
        while(x<xEnd)
        {

            x++;
            if(p<0)
                p+=tDy;
            else
            {

                y=y+yinc;
                p+=tDyDx;
            }
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
        }
        glFlush();
    }
    glutPostRedisplay();
}



void myMouseFunc(int button, int state, int x, int y)
{

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && trclick == 0)
    {
        tlclick = 0;
        trclick = 1;
		int a  = x ;
		int b = 300-y;
		c1.x = x-500;
		c1.y = 300-y;

		char msg[] = "Start Coordinates " ;
		BitmapText(msg,c1.x, c1.y);
		BitmapCordinates(c1.x,b ,c1.x +15, c1.y - 15);
		glFlush();


	}
	else if( trclick == 1 &&  button != GLUT_LEFT_BUTTON && tlclick == 0)
    {
        tlclick = 1;
        trclick = 0;
        c2.x = x-500;
        c2.y = 300-y;
        char msg[] = "End Coordinates ";
        BitmapText(msg , c2.x, c2.y);
        BitmapCordinates(c2.x , c2.y , c2.x +25 ,c2.y -10);
        float m = (float)(c2.y-c1.y)/(float)(c2.x -c1.x);

        char Slope[1000];
        sprintf( Slope, "Slope of Line = %f",m);

        BitmapText(Slope , (int)((c1.x+c2.x)/2),(int)((c1.y + c2.y)/2));


        glFlush();
        Bresenhams();
    }

}






void display()
{


    glColor3f(1, 0, 0);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex2d(-500,0);
        glVertex2d(500,0);
       glVertex2d(0,-300);
        glVertex2d(0,300);
    glEnd();
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
	glutCreateWindow("Bresenham's Algorithm ");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);

    //glutIdleFunc(display);
    glutMainLoop();
    return 0;
}





