#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

struct Line{
	int x1;
	int y1;
	int x2;
	int y2;
}L1[100];

int i = 0; // int i is used to keep track of how many total objects are there on screen.
int j = 0;// int j is used to keep track of which object is under transformation currently.

void display();


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







void rotateCounterClockwise90()
{
    double theta = 90;

    // a will be applied for x shearing
    // y will be applied for y shearing
    j = 0;
    glutPostRedisplay();
    while(j<i)
    {

        int line_Matrix1[] = {L1[j].x1, L1[j].y1 , 1};
        int line_Matrix2[] = {L1[j].x2, L1[j].y2 , 1};

        /*int transformationMatrix[][3] = {{0, 1, 0},
                                         { 1, 0, 0},
                                         { 0, 0, 1} };*/             // Fill in the reflection Matrix

        // perform operations accordingly
        //int t1x = L1[j].x1;
        //int t2 = L1[j].y2;


        int t1x = L1[j].x1;
        int t1y = L1[j].y1;
        int t2x = L1[j].x2;
        int t2y = L1[j].y2;




        //cout<< "t1y = "<< t1y<<endl;


        /*L1[j].x1 = (t1x* cos(theta)) - (t1y * sin(theta))  ;
        L1[j].y1 = (t1x* sin(theta)) + (t1y*cos(theta)) ;
        cout<<"L1[j].x1 = "<< L1[j].x1<<endl;
        cout<<"L1[j].y1 = "<< L1[j].y1<<endl;
        cout<<"sin theta = "<< sin(90)<<endl;

        L1[j].x2 = (t2x* cos(theta)) - (t2y * sin(theta)) ;
        L1[j].y2 = (t2x* sin(theta)) + (t2y * cos(theta)) ;

        cout<<"L1[j].x2 = "<< L1[j].x2<<endl;
        cout<<"L1[j].y2 = "<< L1[j].y2<<endl;*/


        L1[j].x1 = -t1y;
        L1[j].y1 = t1x;
        L1[j].x2 = -t2y;
        L1[j].y2 = t2x;




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


void rotateCounterClockwiseTheta()
{
    double theta = 90;

    // a will be applied for x shearing
    // y will be applied for y shearing
    j = 0;
    glutPostRedisplay();
    while(j<i)
    {

        int line_Matrix1[] = {L1[j].x1, L1[j].y1 , 1};
        int line_Matrix2[] = {L1[j].x2, L1[j].y2 , 1};

        /*int transformationMatrix[][3] = {{0, 1, 0},
                                         { 1, 0, 0},
                                         { 0, 0, 1} };*/             // Fill in the reflection Matrix

        // perform operations accordingly
        //int t1x = L1[j].x1;
        //int t2 = L1[j].y2;


        int t1x = L1[j].x1;
        int t1y = L1[j].y1;
        int t2x = L1[j].x2;
        int t2y = L1[j].y2;




        //cout<< "t1y = "<< t1y<<endl;

        float cos_val = cos(theta) * 57.29;
        float sin_val = sin(theta) * 57.29;


        L1[j].x1 = (t1x* cos_val) - (t1y * sin_val)  ;
        L1[j].y1 = (t1x* sin_val) + (t1y*cos_val) ;
        cout<<"L1[j].x1 = "<< L1[j].x1<<endl;
        cout<<"L1[j].y1 = "<< L1[j].y1<<endl;
        cout<<"sin theta = "<< sin_val<<endl;

        L1[j].x2 = (t2x* cos_val) - (t2y * sin_val) ;
        L1[j].y2 = (t2x* sin_val) + (t2y * cos_val) ;

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



void rotateCounterClockwise30()
{
    double theta = 30;

    // a will be applied for x shearing
    // y will be applied for y shearing
    j = 0;
    glutPostRedisplay();
    while(j<i)
    {

        int line_Matrix1[] = {L1[j].x1, L1[j].y1 , 1};
        int line_Matrix2[] = {L1[j].x2, L1[j].y2 , 1};

        /*int transformationMatrix[][3] = {{0, 1, 0},
                                         { 1, 0, 0},
                                         { 0, 0, 1} };*/             // Fill in the reflection Matrix

        // perform operations accordingly
        //int t1x = L1[j].x1;
        //int t2 = L1[j].y2;


        int t1x = L1[j].x1;
        int t1y = L1[j].y1;
        int t2x = L1[j].x2;
        int t2y = L1[j].y2;




        //cout<< "t1y = "<< t1y<<endl;


        L1[j].x1 = t1x*0.866  -  t1y*0.5;
        L1[j].y1 = t1x*0.5    +  t1y*0.866;
        L1[j].x2 = t2x*0.866  -  t2y*0.5;
        L1[j].y2 = t2x*0.5    +  t2y*0.866;




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

void rotateCounterClockwise45()
{
    double theta = 45;

    // a will be applied for x shearing
    // y will be applied for y shearing
    j = 0;
    glutPostRedisplay();
    while(j<i)
    {

        int line_Matrix1[] = {L1[j].x1, L1[j].y1 , 1};
        int line_Matrix2[] = {L1[j].x2, L1[j].y2 , 1};

        /*int transformationMatrix[][3] = {{0, 1, 0},
                                         { 1, 0, 0},
                                         { 0, 0, 1} };*/             // Fill in the reflection Matrix

        // perform operations accordingly
        //int t1x = L1[j].x1;
        //int t2 = L1[j].y2;


        int t1x = L1[j].x1;
        int t1y = L1[j].y1;
        int t2x = L1[j].x2;
        int t2y = L1[j].y2;




        //cout<< "t1y = "<< t1y<<endl;


        L1[j].x1 = t1x*0.7070    -  t1y*0.7070;
        L1[j].y1 = t1x*0.7070    +  t1y*0.7070;
        L1[j].x2 = t2x*0.7070    -  t2y*0.7070;
        L1[j].y2 = t2x*0.7070    +  t2y*0.7070;




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

void rotateClockwise30()
{
    double theta = 45;

    // a will be applied for x shearing
    // y will be applied for y shearing
    j = 0;
    glutPostRedisplay();
    while(j<i)
    {

        int line_Matrix1[] = {L1[j].x1, L1[j].y1 , 1};
        int line_Matrix2[] = {L1[j].x2, L1[j].y2 , 1};


        int t1x = L1[j].x1;
        int t1y = L1[j].y1;
        int t2x = L1[j].x2;
        int t2y = L1[j].y2;




        //cout<< "t1y = "<< t1y<<endl;


        L1[j].x1 =  t1x*0.866    +  t1y*0.5;
        L1[j].y1 = t1x*-0.50    +  t1y*0.866;
        L1[j].x2 =  t2x*0.866    +  t2y*0.5;
        L1[j].y2 = t2x*-0.50    +  t2y*0.866;




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

void rotateClockwise45()
{
    double theta = 45;

    // a will be applied for x shearing
    // y will be applied for y shearing
    j = 0;
    glutPostRedisplay();
    while(j<i)
    {

        int line_Matrix1[] = {L1[j].x1, L1[j].y1 , 1};
        int line_Matrix2[] = {L1[j].x2, L1[j].y2 , 1};


        int t1x = L1[j].x1;
        int t1y = L1[j].y1;
        int t2x = L1[j].x2;
        int t2y = L1[j].y2;




        //cout<< "t1y = "<< t1y<<endl;


        L1[j].x1 = t1x*0.7070    +  t1y*0.7070;
        L1[j].y1 = t1x*0.7070    +  t1y*0.7070;
        L1[j].x2 = t2x*0.7070    +  t2y*0.7070;
        L1[j].y2 = t2x*0.7070    +  t2y*0.7070;




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

void rotateClockwise90()
{
    double theta = 90;

    // a will be applied for x shearing
    // y will be applied for y shearing
    j = 0;
    glutPostRedisplay();
    while(j<i)
    {

        int line_Matrix1[] = {L1[j].x1, L1[j].y1 , 1};
        int line_Matrix2[] = {L1[j].x2, L1[j].y2 , 1};


        int t1x = L1[j].x1;
        int t1y = L1[j].y1;
        int t2x = L1[j].x2;
        int t2y = L1[j].y2;

        //cout<< "t1y = "<< t1y<<endl;
        cout<< t1x<<" -"<<t1y<<endl;
        cout<< t2x<<" -"<<t2y<<endl;

        L1[j].x1 = t1y;
        L1[j].y1 = -t1x;
        L1[j].x2 = t2y;;
        L1[j].y2 = -t2x;


        cout<<"x1 y1 = "<<L1[j].x1<<" "<<L1[j].y1<<endl;
        cout<<"x2 y2 = "<<L1[j].x2<<" "<<L1[j].y2<<endl;
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




void init()
{

        gluOrtho2D(-500,500,-300,300);
        glClear(GL_COLOR_BUFFER_BIT);
        display();
}


int rclick = 0;
int lclick = 0;


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
    float slope = ((float)(L1[i-1].y2 - L1[i-1].y1))/((float)(L1[i-1].x2 - L1[i-1].x1));
    cout<< "Slope = " <<slope;
    cout<<endl<<"angle = "<<tan(slope)<<endl;


    //glutPostRedisplay();
}


void myMouseFunc(int button, int state, int x, int y)
{
        if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && rclick == 0 && lclick == 0 )
        {

            L1[i].x1 = x-500;
            L1[i].y1 = 300-y;
            rclick = 1;

        }
        else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && lclick == 0 && rclick ==1)
        {
            L1[i].x2 =x-500;
            L1[i].y2 =300-y;
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



    glColor3f(1, 0, 0);

    char name[] = "Abhinav Singh Rana";
    char sap[] = "500060202";
    BitmapText(name, -500, -280);
    BitmapText(sap, -500, -290);

    char key_binding1[] = "l -counter clockwise 90";
    char key_binding2[] = "k - counter clockwise 45";
    char key_binding3[] = "a - clockwise 90";
    char key_binding4[] = "s - clockwise 45";
    char key_binding5[] = "t - translate ";
    BitmapText(key_binding1, 150, -230);
    BitmapText(key_binding2, 150, -250);
    BitmapText(key_binding3, 150, -265);
    BitmapText(key_binding4, 150, -285);
    //BitmapText(key_binding5, 150, -295);


    //glutSwapBuffers();
    glFlush();

}

void myKeyboardFunc(unsigned char key , int x, int y)
{
    if(key =='l')
    {
         glClear(GL_COLOR_BUFFER_BIT);
         glFlush();
         rotateCounterClockwise90();
    }
    else if(key =='k')
    {
         glClear(GL_COLOR_BUFFER_BIT);
         glFlush();
         rotateCounterClockwise45();
    }
    else if(key =='j')
    {
         glClear(GL_COLOR_BUFFER_BIT);
         glFlush();
         rotateCounterClockwise30();
    }
    else if(key =='d')
    {
         glClear(GL_COLOR_BUFFER_BIT);
         glFlush();
         rotateClockwise30();
    }
    else if(key == 's')
    {
         glClear(GL_COLOR_BUFFER_BIT);
         glFlush();
         rotateClockwise45();
    }
    else if(key == 'a')
    {
         glClear(GL_COLOR_BUFFER_BIT);
         glFlush();
         rotateClockwise90();
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
