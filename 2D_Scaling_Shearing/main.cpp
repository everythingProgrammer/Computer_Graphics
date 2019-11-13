#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Line{
	int x1;
	int y1;
	int x2;
	int y2;
}L1[100];

int i = 0; // int i is used to keep track of how many total objects are there on screen.
int j = 0;// int j is used to keep track of which object is under transformation currently.

int rclick = 0 ;
int lclick = 0;

void init()
{

        gluOrtho2D(0,1000,0,600);
        glClear(GL_COLOR_BUFFER_BIT);
}



void BitmapText(char* string, float xc, float yc)
{
char c;
int k = 0;
glRasterPos2f(xc, yc);

for (k = 0; string[k] != '\0'; k++)
    {
        c = string[k];
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
    }
}


void BitmapCordinates(int x , float xc, float yc)
{
int k = 0;
glRasterPos2f(xc, yc);

char array[1000];
sprintf( array, "%d", x );
for (i = 0; array[k] != '\0'; k++)
{
    char c = array[k];

    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
}

}



void shearing()
{
    int  a = 4, b = 0 ;

    // a will be applied for x shearing
    // y will be applied for y shearing
    j = 0;
    glutPostRedisplay();
    while(j<i)
    {

        int line_Matrix1[] = {L1[j].x1, L1[j].y1 , 1};
        int line_Matrix2[] = {L1[j].x2, L1[j].y2 , 1};

        int transformationMatrix[][3] = {{0, 1, 0},
                                         { 1, 0, 0},
                                         { 0, 0, 1} }; // Fill in the reflection Matrix

        // perform operations accordingly
        //int t1x = L1[j].x1;
        //int t2 = L1[j].y2;
        int t1x = L1[j].x1;
        int t1y = L1[j].y1;
        int t2x = L1[j].x2;
        int t2y = L1[j].y2;



        cout<< "a = "<<a<<endl;
        cout<< "t1y = "<< t1y<<endl;
        cout<< " a* t1y = "<<a*t1y<<endl;


        L1[j].x1 = L1[j].x1 + (a*t1y);
        L1[j].y1 = L1[j].y1+ (b*t1x);
        cout<<"L1[j].x1 = "<< L1[j].x1<<endl;
        cout<<"L1[j].y1 = "<< L1[j].y1<<endl;


        L1[j].x2 = L1[j].x2 + (a* t2y);
        L1[j].y2 = L1[j].y2+ (b*t2x);

        cout<<"L1[j].x2 = "<< L1[j].x2<<endl;
        cout<<"L1[j].y2 = "<< L1[j].y2<<endl;

        // draw the line
        glColor3d(1,1,0);
        glBegin(GL_LINES);
        glVertex2d(L1[j].x1,L1[j].y1);
        glVertex2d(L1[j].x2, L1[j].y2);
        glEnd();
        glFlush();
        j++;

    }

}


void scaling()
{
    int  a = 2, b = 2 ;

    // a will be applied for x shearing
    // y will be applied for y shearing
    j = 0;
    glutPostRedisplay();
    while(j<i)
    {

        int line_Matrix1[] = {L1[j].x1, L1[j].y1 , 1};
        int line_Matrix2[] = {L1[j].x2, L1[j].y2 , 1};

        int transformationMatrix[][3] = {{a,0, 0},
                                         {0,b, 0},
                                         {0,0, 1} }; // Fill in the reflection Matrix

        // perform operations accordingly
        //int t1x = L1[j].x1;
        //int t2 = L1[j].y2;
        int t1x = L1[j].x1;
        int t1y = L1[j].y1;
        int t2x = L1[j].x2;
        int t2y = L1[j].y2;



        cout<< "a = "<<a<<endl;
        cout<< "t1y = "<< t1y<<endl;
        cout<< " a* t1y = "<<a*t1y<<endl;


        L1[j].x1 = L1[j].x1 + (a*L1[j].x1);
        L1[j].y1 = L1[j].y1+  (b*L1[j].y1);
        cout<<"L1[j].x1 = "<< L1[j].x1<<endl;
        cout<<"L1[j].y1 = "<< L1[j].y1<<endl;


        L1[j].x2 = L1[j].x2 + (a*L1[j].x2 );
        L1[j].y2 = L1[j].y2+  (b*L1[j].y2);

        cout<<"L1[j].x2 = "<< L1[j].x2<<endl;
        cout<<"L1[j].y2 = "<< L1[j].y2<<endl;

        // draw the line
        glColor3d(1,1,0);
        glBegin(GL_LINES);
        glVertex2d(L1[j].x1,L1[j].y1);
        glVertex2d(L1[j].x2, L1[j].y2);
        glEnd();
        glFlush();
        j++;

    }

}








void drawLine()
{
    glColor3d(1,1,0);
    glBegin(GL_LINES);
    glVertex2d(L1[i-1].x1, L1[i-1].y1);
    glVertex2d(L1[i-1].x2, L1[i-1].y2);
    glEnd();
    glFlush();
    cout<< "L1.x1  " <<L1[i-1].x1<< " L1.y1 "<< L1[i-1].y1<<endl;
    cout<< "L1.x2  " <<L1[i-1].x2<< " L1.y2 "<< L1[i-1].y2<<endl;
    //glutPostRedisplay();
}

void display()
{

    glColor3f(1,1,0);
    glBegin(GL_LINES);
    glVertex2d(-500,0);
    glVertex2d(500, 0);
    glVertex2d(0,300);
    glVertex2d(0,-300);
    glEnd();
    glFlush();

   /* glColor3d(1,1,1);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(0,50);
    glVertex2d(0,50);
    glVertex2d(50,50);
    glVertex2d(50,50);
    glVertex2d(50,0);
    glEnd();
    glFlush();*/

    glColor3f(1, 0, 0);

    char name[] = "Abhinav Singh Rana";
    char sap[] = "500060202";
    BitmapText(name, -500, -280);
    BitmapText(sap, -500, -290);




    //glutSwapBuffers();
    glFlush();

}

void myMouseFunc(int button, int state, int x, int y)
{

        //cout<<"x , y-600 " << x <<" " << 600-y<<endl;
        if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && rclick == 0 && lclick == 0 )
        {

            L1[i].x1 = x;
            L1[i].y1 = 600-y;
            rclick = 1;

        }
        else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && lclick == 0 && rclick ==1)
        {
            L1[i].x2 =x;
            L1[i].y2 =600-y;
            lclick = 1;
        }
        if(rclick == 1 && lclick == 1)
        {
            rclick = 0 ;
            lclick = 0 ;

            //BitmapCordinates(i, 0+(10*i),0);
            i++;
            drawLine();
        }
}



void myKeyboardFunc(unsigned char key , int x, int y)
{
    if(key =='h')
    {
         glClear(GL_COLOR_BUFFER_BIT);
         glFlush();
         shearing();
    }

    else if(key == 'c')
    {
        glClear(GL_COLOR_BUFFER_BIT);
         glFlush();
         scaling();

    }
}

int main(int argc,char** argv)
{

	int mode = GLUT_RGB|GLUT_SINGLE;
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(mode);
	glutInitWindowSize(1000,600);
	glutCreateWindow("2D Reflections");
    init();
    glutDisplayFunc(display);

    glutKeyboardFunc(myKeyboardFunc);
    glutMouseFunc(myMouseFunc);
	glutMainLoop();
	return 0;
}
