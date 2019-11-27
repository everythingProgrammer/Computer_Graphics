#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int gx[4] = {225-228,85-228,390-228,225-228};
int gy[4] = {-120+120,206+120,206+120,-120+120};
int ax[4] = {-443,-404,-328,-285};
int ay[4] = {-117,8,-190,-87};
int ax2[4] = {-443,-404,-328,-285};
int ay2[4] = {-117+40,48,-170+20,-67+20};
int ax3[4] = {-443,-404,-328,-285};
int ay3[4] = {-117+80,88,-150+60,-47+60};

float curvex[1500]; // All the x points of plotted Biezer Curve are stored .
float curvey[1500]; // All the y points of plotted Biezer Curve are stored .
int curvep = 0;  // Number of Points

void bezierCurve1();
void rotateClockwise30();
void rotateCounterClockwise180();
void plotPoints(float x, float y);

void bezierAir()
{
    double point_x,point_y,t;
    glColor3d(1,1,1);
        glBegin(GL_POINTS);
        curvep = 0;
        for(t=0.0;t<=1.0;t=t+0.001)
        {
            point_x = pow(1-t,3)*ax[0] + 3*t*pow(1-t,2)*ax[1] + 3*t*t*(1-t)*ax[2] + pow(t,3)*ax[3];
            point_y = pow(1-t,3)*ay[0] + 3*t*pow(1-t,2)*ay[1] + 3*t*t*(1-t)*ay[2] + pow(t,3)*ay[3];
            plotPoints(point_x,point_y);
            curvex[curvep] = point_x;
            curvey[curvep] = point_y;
            curvep++;
        }
        glEnd();
        glFlush();
}
void bezierAir2()
{
    double point_x,point_y,t;
    glColor3d(1,1,1);
        glBegin(GL_POINTS);
        curvep = 0;
        for(t=0.0;t<=1.0;t=t+0.001)
        {
            point_x = pow(1-t,3)*ax2[0] + 3*t*pow(1-t,2)*ax2[1] + 3*t*t*(1-t)*ax2[2] + pow(t,3)*ax2[3];
            point_y = pow(1-t,3)*ay2[0] + 3*t*pow(1-t,2)*ay2[1] + 3*t*t*(1-t)*ay2[2] + pow(t,3)*ay2[3];
            plotPoints(point_x,point_y);
            curvex[curvep] = point_x;
            curvey[curvep] = point_y;
            curvep++;
        }
        glEnd();
        glFlush();
}
void bezierAir3()
{
    double point_x,point_y,t;
    glColor3d(1,1,1);
        glBegin(GL_POINTS);
        curvep = 0;
        for(t=0.0;t<=1.0;t=t+0.001)
        {
            point_x = pow(1-t,3)*ax3[0] + 3*t*pow(1-t,2)*ax3[1] + 3*t*t*(1-t)*ax3[2] + pow(t,3)*ax3[3];
            point_y = pow(1-t,3)*ay3[0] + 3*t*pow(1-t,2)*ay3[1] + 3*t*t*(1-t)*ay3[2] + pow(t,3)*ay3[3];
            plotPoints(point_x,point_y);
            curvex[curvep] = point_x;
            curvey[curvep] = point_y;
            curvep++;
        }
        glEnd();
        glFlush();
}
void rotateClockwise30()
{
        int t0x =gx[0];
        int t1x =gx[1];
        int t2x =gx[2];
        int t3x =gx[3];

        int t0y =gy[0];
        int t1y =gy[1];
        int t2y =gy[2];
        int t3y =gy[3];

        gx[0] =  t0x*0.866    +  t0y*0.5;
        gx[1] =  t1x*0.866    +  t1y*0.5;
        gx[2] =  t2x*0.866    +  t2y*0.5;
        gx[3] =  t3x*0.866    +  t3y*0.5;

        gy[1] = t1x*-0.50    +  t1y*0.866;
        gy[0] = t0x*-0.50    +  t0y*0.866;
        gy[2]= t2x*-0.50    +  t2y*0.866;
        gy[3]= t3x*-0.50    +  t3y*0.866;

        // Now Print rotated points.
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        bezierCurve1();
}
void rotateClockwise90()
{
        int curvex90[1500];
        int curvey90[1500];
        for(int i = 0 ; i<curvep ; i++)
        {
            int t1x = curvex[i];
            int t1y = curvey[i];

            curvex90[i] = t1y;
            curvey90[i] = -t1x;
        }
        glColor3d(1,1,1);
        glBegin(GL_POLYGON);
        for(int i = 0 ; i< curvep ; i++)
        {
            glVertex2f(curvex90[i], curvey90[i]);
        }
        glEnd();
        glFlush();
        glutPostRedisplay();
}
void rotateCounterClockwise90()
{
        int curvex90[1500];
        int curvey90[1500];
        for(int i = 0 ; i<curvep ; i++)
        {

            int t1x = curvex[i];
            int t1y = curvey[i];

            curvex90[i] = -t1y;
            curvey90[i] =  t1x;
        }
        glBegin(GL_POLYGON);
        for(int i = 0 ; i< curvep ; i++)
        {
            glVertex2f(curvex90[i], curvey90[i]);
        }
        glEnd();
        glFlush();
        rotateClockwise90();
        //glutPostRedisplay();
}
void init()
{
        glClearColor(0,0.0,3.9,1);
        glFlush();
        gluOrtho2D(-500,500,-300,300);
}
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
void plotPoints(float point_x,float point_y)
{

	glVertex2f(point_x,point_y);
}
void display_set()
{
    glClearColor(0,0.3,0.7,1);
    glFlush();
}
void bezierCurve1()
{
    float point_x,point_y,t;
    glColor3d(1,1,1);
        glBegin(GL_POLYGON);
        curvep = 0;
        for(t=0.0;t<=1.0;t=t+0.001)
        {
            point_x = pow(1-t,3)*gx[0] + 3*t*pow(1-t,2)*gx[1] + 3*t*t*(1-t)*gx[2] + pow(t,3)*gx[3];
            point_y = pow(1-t,3)*gy[0] + 3*t*pow(1-t,2)*gy[1] + 3*t*t*(1-t)*gy[2] + pow(t,3)*gy[3];
            plotPoints(point_x,point_y);
            curvex[curvep] = point_x;
            curvey[curvep] = point_y;
            curvep++;
        }
        glEnd();
        glFlush();
        //glutPostRedisplay();
        //rotateClockwise90();
        rotateCounterClockwise90();
}
void manipulation()
{
    glutPostRedisplay();
    Sleep(450);
    rotateClockwise30();
}
void point(int x , int y)
{
    glBegin(GL_POLYGON);
    glVertex2d(x-5, y+5);
    glVertex2d(x+5, y+5);
    glVertex2d(x+5, y-5);
    glVertex2d(x-5, y-5);
    glEnd();
    glFlush();
}
void myMouseFunc(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        point(x-500,300-y);
        cout<<"x = "<<x <<"y = "<<y<<endl;
        bezierCurve1();
    }
    else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        rotateClockwise30();
    }
}
void display()
{

    glColor3f(0.3,0.7,0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-500,-250);
    glVertex2d(500,-250);
    glVertex2d(500,-300);
    glVertex2d(-500,-300);
    glEnd();
    glFlush();
    glColor3d(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(-3-75+100,0);
    glVertex2d(162-75-100,0);
    glVertex2d(162-75-100,-280);
    glVertex2d(-3-75+100,-280);
    glEnd();
    glFlush();
    bezierAir();
    bezierAir2();
    bezierAir3();
    char air[] = "A I R";
    char name[] = "Abhinav Singh Rana";
    char sap[] = "500060202";
    char place[] = "The Promised NeverLand";
    BitmapText(name, 310, 280);
    BitmapText(sap, 330, 260);
    BitmapText(place , 310, 240);
    BitmapText(air , -380, 48);
    glFlush();
}
int main(int argc,char** argv)
{
    int mode = GLUT_RGB|GLUT_SINGLE;
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(mode);
    glutInitWindowSize(1000,600);
    glutCreateWindow("The Promised NeverLand");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);
    glutIdleFunc(manipulation);
    glutMainLoop();
    return 0;
}
