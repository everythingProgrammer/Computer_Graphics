#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int xwmax , xwmin, ywmax, ywmin ;
int yvmax , yvmin, xvmax, xvmin ;

int xw = 0 , yw = 0 ;
int xv = 0 , yv = 0 ;


double Sx , Sy ;
double Tx , Ty ;


void display();


int click = 1; // To keep track weather we are entering the point co-ordinates or windows co-ordinates.

void spawnScreen(int , int );
void calculateSx();
void calculateSy();
void calculateTx();
void calculateTy();
void calculatePoint();


void display2()
{

    glColor3d(255,255,255);
	glBegin(GL_LINES);
	glVertex2d(-500,0);
	glVertex2d(500 , 0);
	glVertex2d(0,300);
	glVertex2d(0 , -300);
	glEnd();
	glFlush();
	glutPostRedisplay();
}


init()
{

    gluOrtho2D(-500,500,-300,300);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();

    display2();
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
    for (int i = 0; array[k] != '\0'; k++)
    {
        char c = array[k];

        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
    }

}


void myKeyboardFunc(unsigned char key , int x, int y)
{
    if(key =='r')
    {
              glClear(GL_COLOR_BUFFER_BIT);
              glFlush();
              display();
              display2();
              xwmax = 0;
              xwmin= 0;
              ywmax= 0;
             ywmin= 0;
             yvmax= 0;
             yvmin= 0;
             xvmax= 0;
             xvmin= 0;

             xw = 0;
             yw = 0 ;
             xv = 0;
             yv = 0 ;


            Sx= 0.0;
            Sy= 0.0 ;
            Tx = 0.0 ;
            Ty = 0.0;
            click = 1;


    }

}



void spawnScreen(int x , int y )
{
    cout<<"Recieved x, y = "<<x<<" "<<y <<endl;

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2d(x-50 , 50+y);
    glVertex2d(50+x , 50+y);
    glVertex2d(50+x , y-50);
    glVertex2d(x-50 , y-50);

    glEnd();
    glFlush();

    xvmax = 50+x;
    xvmin = x-50;
    yvmax = 50+y;
    yvmin = y-50;
}


void calculateSx()
{
    cout<<"upper -"<< xvmax - xvmin <<endl;
    cout<<"lower -"<< xwmax - xwmin <<endl;
    Sx = ((float)(xvmax - xvmin)/(float)(xwmax - xwmin ));
    cout<<"Sx "<<Sx<<endl;
}

void calculateSy()
{
     Sy = ((float)(yvmax - yvmin)/(float)(ywmax - ywmin ));
     cout<<"Sy "<<Sy<<endl;
}


void calculateTx()
{
    Tx = (float)((float)((xwmax * xvmin ) - (xvmax * xwmin ))/ (float)(xwmax - xvmin ));
    cout<<"Tx "<<Tx<<endl;
}


void calculateTy()
{
    Ty = ((float)((ywmax * yvmin ) -  (yvmax * ywmin))/(float)(ywmax - yvmin));
    cout<<"Ty "<<Ty<<endl;
}


void calculatePoint()
{
    xv = Sx* xw + Tx;
    yv = Sy* yw + Ty;

    if((xv >= xvmin && xv <=xvmax) && (yv>= yvmin && yv <=yvmax))
    {
        char msg[] = "Point Inside the Clipped Window";
        BitmapText(msg, -50, 210);
        glColor3d(255,255,255);
        glBegin(GL_POINTS);
        glVertex2d(xv, yv);
        glEnd();
        glFlush();

        cout<<"xv = "<<xv<<"  yv = "<<yv<<endl;
        cout<<"xvmin = "<<xvmin <<" xvmax = "<<xvmax<<endl;
        cout<<"yvmin = "<<yvmin <<" yvmax = "<<yvmax<<endl;
        cout<<"xwmin = "<<xwmin <<"xwmax = "<<xwmax <<endl;
        cout<<"ywmin = "<<ywmin <<"ywmax = "<<ywmax <<endl;



       /* glBegin(GL_LINES);
        glVertex2d();
        glVertex2d();
        glVertex2d();
        glVertex2d();
        glVertex2d();
        glVertex2d();
        glVertex2d();
        glVertex2d();*/

    }

}

void onMouseClick(int button, int state, int x, int y)
{
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN  )
        {
            if(click == 1)
            {
                xw = x - 500;
                yw = 300 - y ;
                click++;
                //init();
                cout<<"xw  = " <<xw<< " yw "<< yw<<endl;
            }
            else if(click == 2)
            {

                spawnScreen((x-500) , (300 - y));
                calculateSx();
                calculateSy();
                calculateTx();
                calculateTy();
                calculatePoint();
            }

        }
}




void display(void) {


	glColor3f(1, 1, 0);
	glBegin(GL_LINES);
	glVertex2d(-200,200);
	glVertex2d(200,200);
	glVertex2d(200,200);
	glVertex2d(200,-200);
	glVertex2d(200,-200);
	glVertex2d(-200,-200);
	glVertex2d(-200,-200);
	glVertex2d(-200,200);
	glEnd();
	glFlush();
	xwmax = 200;
	ywmax = 200;
	xwmin = -200;
	ywmin = -200;




}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Point Clipping");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
	glutKeyboardFunc(myKeyboardFunc);
	glutMainLoop();
	return 0 ;
}

