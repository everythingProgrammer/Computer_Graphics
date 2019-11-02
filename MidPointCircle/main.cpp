
//                          Main Working Midpoint Circle , Ellipse combination program


#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROUND(a) ((int)(a+0.5))

int trclick = 0 ; // to make sure right click happens only once .
int tlclick = 0 ; // To make sure that click happens only once  .
int counter = 0;
int counter2 = 0;
int arr[200];
int arr2[200];


struct Colour {
	int a;
	int b;
	int c;
};

Colour color;


int colorCounter = 0;

void colorChange()
{
    if(colorCounter==0 || colorCounter>= 25)
    {
        srand(time(0));
        colorCounter = colorCounter%25;
        int k= (int)(rand()*rand()% 7);
        int l = (int)(rand()*rand()% 7);
        int m =  (int)(rand()*rand())% 7;


        color.a = k;
        color.b = l;
        color.c = m;
    }
    colorCounter++;
}
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

void printPixel(int x,int y)
{
    glBegin(GL_POINTS);
       // glColor3f(1, 1, 0);
        glVertex2f(ROUND(x),ROUND(y));
    glEnd();
    glFlush();
}

void ellipsePoints(int xC,int yC,int x,int y)
{
    printPixel(xC + x,yC + y);
    printPixel(xC - x,yC + y);
    printPixel(xC + x,yC - y);
    printPixel(xC - x,yC - y);
}
void ellipse()
{
    int xC = c2.x;
    int yC = c2.y;
    int a = 72;
    int b = 36;
    int a2 = a*a;
    int b2 = b*b;
    int twoa2 = 2 * a2;
    int twob2 = 2 * b2;

    int p0;
    int x = 0;
    int y = b;
    int dx = 0;
    int dy = twoa2 * y;
    glColor3d(215,115,170);
    ellipsePoints(xC,yC,x,y);

    //For Region-1
    p0 = ROUND(b2 - (a2 * b) + 0.25 * a2);
    while(dx < dy)
    {
        if(p0 <0)
        {
            x = x + 1;
            dx = dx + twob2;
            p0 = p0 + b2 + dx;
        }
        else
        {
            x = x + 1;
            dx = dx + twob2;
            y = y - 1;
            dy = dy - twoa2;
            p0 = p0 + b2 + dx - dy;
        }
        ellipsePoints(xC,yC,x,y);
    }

    //For Region-2
    p0 = ROUND(b2*(x+0.5)*(x+0.5) + a2*(y-1)*(y-1) - a2*b2);
    while(y>0)
    {
        if(p0>0)
        {
            y = y - 1;
            dy = dy - twoa2;
            p0 = p0 + a2 - dy;
        }
        else
        {
            y = y - 1;
            dy = dy - twoa2;
            x = x + 1;
            dx = dx + twob2;
            p0 = p0 + a2 - dy + dx;
        }
        ellipsePoints(xC,yC,x,y);
    }
}

void ellipse2(int c )
{
    int xC = c1.x;
    int yC = c1.y;
    int a = 86;
    int b = 42;
    int a2 = a*a;
    int b2 = b*b;
    int twoa2 = 2 * a2;
    int twob2 = 2 * b2;

    int p0;
    int x = 0;
    int y = b;
    int dx = 0;
    int dy = twoa2 * y;
     glColor3d(110,215,70);
    ellipsePoints(xC,yC,x,y);

    //For Region-1
    p0 = ROUND(b2 - (a2 * b) + 0.25 * a2);
    while(dx < dy)
    {
        if(p0 <0)
        {
            x = x + 1;
            dx = dx + twob2;
            p0 = p0 + b2 + dx;
        }
        else
        {
            x = x + 1;
            dx = dx + twob2;
            y = y - 1;
            dy = dy - twoa2;
            p0 = p0 + b2 + dx - dy;
        }
        ellipsePoints(xC,yC,x,y);
    }

    //For Region-2
    p0 = ROUND(b2*(x+0.5)*(x+0.5) + a2*(y-1)*(y-1) - a2*b2);
    while(y>0)
    {
        if(p0>0)
        {
            y = y - 1;
            dy = dy - twoa2;
            p0 = p0 + a2 - dy;
        }
        else
        {
            y = y - 1;
            dy = dy - twoa2;
            x = x + 1;
            dx = dx + twob2;
            p0 = p0 + a2 - dy + dx;
        }
        ellipsePoints(xC,yC,x,y);
    }
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
sprintf( array, "x= %d,y= %d", x ,y);
for (i = 0; array[i] != '\0'; i++)
{
    char c = array[i];

    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
    }

}


void drawCircle()
{
    if(counter<100)
    {

        arr[counter] = c1.x;
        counter++;
        arr[counter] = c1.y;
        counter++;
    }
    int xCentre = c1.x;
    int yCentre = c1.y;
    int radius = 65; // this is radius .
    int x = 0 ;
    int y = radius;
    int p = 1- radius;
    void circlePlotPoints(int ,int ,int ,int);
    circlePlotPoints(xCentre , yCentre , x , y );
    if(counter < 100)
    {
        arr[counter] = x ;
        counter++;
        arr[counter] = y;
        counter++;
    }

    while(x< y)
    {

        x++;
        if(p<0 )
        {

            p += 2*x+1;
        }
        else{
            y--;
            p+= 2*(x-y)+1;
        }
        if(counter < 100)
        {
            arr[counter] = x ;
            counter++;
            arr[counter] = y;
            counter++;
        }
        circlePlotPoints(xCentre , yCentre , x, y);
    }
    glutPostRedisplay();
}
void drawCircle(int a)
{
    if(counter2<100)
    {

        arr2[counter2] = c2.x;
        counter2++;
        arr2[counter2] = c2.y;
        counter2++;
    }
    int xCentre = c2.x;
    int yCentre = c2.y;
    int radius = 65; // this is radius .
    int x = 0 ;
    int y = radius;
    int p = 1- radius;
    void circlePlotPoints(int ,int ,int ,int);

    circlePlotPoints(xCentre , yCentre , x , y );

    while(x< y)
    {
        if(counter2<100)
        {

            arr2[counter2] = x;
            counter2++;
            arr2[counter2] = y;
            counter2++;
        }
        x++;
        if(p<0 )
        {

            p += 2*x+1;
        }
        else{
            y--;
            p+= 2*(x-y)+1;
        }
        circlePlotPoints(xCentre , yCentre , x, y);
    }
    glutPostRedisplay();
}




void circlePlotPoints(int xCentre , int yCentre , int x , int y)
{
     int a , b , c ;

    //srand(time(0));
    colorChange();
    a = color.a;
    b= color.b;
    c = color.c;
    //a = (int)(rand()*rand()+(x*time(0)) )% 7;
    //b = (int)(rand()*rand()+(y*time(0)) )% 7;
    //c =  (int)(rand()*rand()+(x+y))% 7;
    glColor3d(a,b,c);
    glBegin(GL_POINTS);
    glVertex2d(xCentre+ x, yCentre +y);
    glVertex2d(xCentre- x, yCentre +y);
    glVertex2d(xCentre+ x, yCentre -y);
    glVertex2d(xCentre- x, yCentre -y);
    glEnd();
    glFlush();
    //a = (int)(rand()*rand())% 7;
    //b = (int)(rand()*rand())% 7;
   // c =  (int)(rand()*rand())% 7;
   // glColor3d(a,b,c);
   // glBegin(GL_POINTS);
     //glEnd();
    //glFlush();
    colorChange();
    a = color.a;
    b= color.b;
    c = color.c;
    glColor3d(c,b,a);
    glBegin(GL_POINTS);
    glVertex2d(xCentre+ y, yCentre +x);
    glVertex2d(xCentre+ y, yCentre -x);

    //a = (int)(rand()*rand())% 7;
    //b = (int)(rand()*rand())% 7;
    //c =  (int)(rand()*rand())% 7;

    glVertex2d(xCentre- y, yCentre +x);
    glVertex2d(xCentre- y, yCentre -x);
    glEnd();
    glFlush();

}

void repaint()
{

    for(int i = 2; i<80; i+=2)
    {

        circlePlotPoints(arr[0], arr[1], arr[i], arr[i+1]);
        circlePlotPoints(arr2[0], arr2[1], arr2[i], arr2[i+1]);
    }
}




void myMouseFunc(int button, int state, int x, int y)
{

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
		int a  = x ;
		int b = 300-y;
		c1.x = x-500;
		c1.y = 300-y;
        int x , y , z ;
        x = (int)(rand()*rand())% 7;
        y = (int)(rand()*rand())% 7;
        z =  (int)(rand()*rand())% 7;
        glColor3d(x,z,y);

		glFlush();
		if( (c1.x >=0 && c1.y >=0) || (c1.x <0 && c1.y<0) )
        {
            char msg[] = "Spawning Circle " ;
            BitmapText(msg, a-560, b);
            BitmapCordinates(c1.x,b ,a-560, b-10);
            drawCircle();
        }
        else if( (c1.x <0 && y>=0)||(c1.x>-0 && c1.y<0) )
        {
            char msg[] = "Ellipse " ;
            BitmapText(msg, a-540, b);
            BitmapCordinates(c1.x,b ,a-540, b-10);
            int c  = 1 ;

            //ellipseMidpoint2(c,d);
            ellipse2(c);
        }

	}
    else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
		int a  = x ;
		int b = 300-y;
		c2.x = x-500;
		c2.y = 300-y;
        int x , y , z ;
        x = (int)(rand()*rand())% 7;
        y = (int)(rand()*rand())% 7;
        z =  (int)(rand()*rand())% 7;
        glColor3d(x,z,y);

        if((c2.x >= 0 && c2.y>=0) || (c2.x <0 && c2.y<0))
        {
            //ellipseMidpoint(a,b);
            char msg[] = "Ellipse " ;
            BitmapText(msg, a-540, b);
            BitmapCordinates(c2.x,c2.y ,a-540, b-10);
            int c  = 1 ;
            ellipse();
        }
        else if((c2.x < 0 && c2.y >0) || (c2.x>0 && c2.y <0))
        {

            drawCircle(2);
            glColor3d(x,z,y);
            char msg[] = "Spawning Circle " ;
            BitmapText(msg, a-560, b);
            BitmapCordinates(c1.x,b ,a-560, b-10);
            glFlush();
        }
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




    char one[] = "Left Click - Circle Right Click - Ellipse";
    char two[] = "Left Click - Ellipse Right Click - Circle";

            BitmapText(one, 120,250);
            BitmapText(one, -400,-250);
            BitmapText(two, -400,250);
            BitmapText(two, 120,-250);



    char name[] = "Abhinav Singh Rana";
    char sap[] = "500060202";
    BitmapText(name, -500, -280);
    BitmapText(sap, -500, -290);
    glutSwapBuffers();
    glFlush();

}

void myKeyboardFunc(unsigned char key , int x, int y)
{
    if(key == ' ')
    {
        glClear(GL_COLOR_BUFFER_BIT);
        display();

    }

}
int main(int argc,char** argv)
{
	int mode = GLUT_RGB|GLUT_SINGLE;
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(mode);
	glutInitWindowSize(1000,600);
	glutCreateWindow("Mid Point Circle and Mid Ellipse   ");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);
    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(repaint);
    glutMainLoop();
    return 0;
}
