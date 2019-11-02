#include <GL/gl.h>
#include <windows.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#define RAND_MAX = -1000
#define RAND_MIN = -1000


int px = 0;
int py = 0;
int qx = 0;
int qy = 0;
int rx = 0;
int ry = 0;
int sx = 0;
int sy = 0;

int upx = -500;
int upy = 300;

int downx = 500;
int downy = -300;



int click = 0;

// upx , upy , downx , downy
int lines[100][4];
int i=0,j=0 ;
// i keeps track of current index of array while insertiion
// j keeps track of object when retrieval happens

struct newLine
{

    float x  = 0.0;
    float y =0.0;
} newup , newdown;
//newLine newup, newdown; // points of intersection of points

//LineDimension up, down;
//dimension p,q,r,s;
void resetParameters()
{

    upx = -500;
    downx = 500;
    upy = 300;
    downy = -300;
}


void resetarr()
{
    for(int i = 0 ; i<100; i++)
    {

        lines[i][0] = 0;
        lines[i][1] = 0;
        lines[i][2] = 0;
        lines[i][3] = 0;
    }

}

void setParameters(int k )
{

    upx = lines[k][0];
    upy = lines[k][1];
    downx = lines[k][2];
    downy = lines[k][3];
}

float greater( float p1, float p2 , float p3 ,float p4 )
{
    int i =0 ;
    float fl[4];
   if( p1 > 0 )
   {
       fl[i] = p1;
       i++;

   }
   if(p2> 0)
   {

       fl[i] = p2;
       i++;
   }
   if(p3>0)
   {

       fl[i] = p3;
       i++;
   }
   if(p4>0)
   {

       fl[i] = p4;
       i++;
   }
   return 1.2;

}

bool isGreater(float val)
{

    if(val > 0)
    {

        return true;
    }
}
bool isLesser(float val)
{

    if(val<0)
    {

        return true;
    }
}


float mostMinimum(float arr[])
{

    float minimum = arr[0];

    for(int i = 0 ; i< 4 ; i++)
    {

        if(arr[i] < minimum)
        {

            minimum = arr[i];
        }
    }

    if (minimum < 1)
    {

        return minimum;
    }
    else
    {

        return 1;
    }

}


float mostMaximum(float arr[])
{
    float Maximum = arr[0];

    for(int i = 0 ; i< 4 ; i++)
    {

        if(arr[i] >Maximum)
        {

            Maximum = arr[i];
        }
    }

    if (Maximum >0 )
    {

        return Maximum;
    }
    else
    {

        return 0;
    }
}


float calculateT1(float p1, float p2 , float p3 ,float p4 , float q1, float q2 , float q3 , float q4)
{
    bool arr[4];
    int i = 0; // To Keep Track of boolean index

    // isGreater function will return if the value of P1 is greater than or less than 0 if it is less than 0 then it we mark it true for futher processing
    if(!isGreater(p1))
    {
        arr[i] = true;
        i++;
    }
    else{
        arr[i] = false;
        i++;
    }

    if(!isGreater(p2))
    {

        arr[i] = true;
        i++;
    }
    else
    {

        arr[i] = false;
        i++;
    }

    if( !isGreater(p3))
    {

        arr[i] = true;
        i++;
    }
    else{
        arr[i] = false;
        i++;
    }
    if(!isGreater(p4))
    {

        arr[i] = true;
        i++;
    }
    else{
        arr[i] = false;
        i++;
    }

    // Now I Know which one is Greater than one and which one is not
    float allP[] = {p1, p2, p3,p4};
    float allQ[] = {q1, q2, q3, q4};

    float smallerP[4];
    float smallerQ[4];

    for(int j = 0 ; j<4; j++)
    {

        if(arr[j])
        {
            smallerP[j] = allP[j];
            smallerQ[j]= allQ[j];
        }
        else
        {

            smallerP[j] = -9999;
            smallerQ[j] = 1;
        }

    }
    for(int j = 0 ; j<4 ; j++)
    {

      printf(" smaller p = %f \n", smallerP[j]);
    }
    float dividearr[4]; // In this array division of Pi by Qi is stored
    for(int j = 0 ; j<4 ; j++)
    {

        dividearr[j] = (smallerQ[j]/smallerP[j]);
    }
      for(int j = 0 ; j<4 ; j++)
    {

      printf(" smaller d = %f \n", dividearr[j]);
    }
    //now I have all the divided elements stored in dividearr
    // now I will define another function to return me minimum

    float T1 = mostMaximum(dividearr);
    return T1;


}
float calculateT2(float p1, float p2 , float p3 ,float p4 , float q1, float q2 , float q3 , float q4)
{
    bool arr[4];
    int i = 0; // To Keep Track of boolean index
    if(!isLesser(p1))
    {

        arr[i] = true;
        i++;
    }
    else{
        arr[i] = false;
        i++;
    }

    if(!isLesser(p2))
    {

        arr[i] = true;
        i++;
    }
    else
    {

        arr[i] = false;
        i++;
    }

    if( !isLesser(p3))
    {

        arr[i] = true;
        i++;
    }
    else{
        arr[i] = false;
        i++;
    }
    if(!isLesser(p4))
    {

        arr[i] = true;
        i++;
    }
    else{
        arr[i] = false;
        i++;
    }

    // Now I Know which one is Greater than one and which one is not
    float allP[] = {p1, p2, p3,p4};
    float allQ[] = {q1, q2, q3, q4};

    float GreaterP[4];
    float GreaterQ[4];

    for(int j = 0 ; j<4; j++)
    {

        if(arr[j])
        {
            GreaterP[j] = allP[j];
            GreaterQ[j]= allQ[j];
        }
        else
        {

            GreaterP[j] = 1;
            GreaterQ[j] = 9999;
        }

    }
    float dividearr[4]; // In this array division of Pi by Qi is stored

     for(int j = 0 ; j<4 ; j++)
    {

      printf(" greater p = %f   greater q = %f\n", GreaterP[j] , GreaterQ[j]);
    }

    for(int j = 0 ; j<4 ; j++)
    {

        dividearr[j] = (GreaterQ[j]/GreaterP[j]);
    }


    for(int j = 0 ; j<4 ; j++)
    {

      printf(" T2 - dividearr  %f\n", dividearr[j]);
    }

    //now I have all the divided elements stored in dividearr
    // now I will define another function to return me minimum

    float T2 = mostMinimum(dividearr);
    return T2;

}


                //Liang Barsky
void LianBarsky()
{
    // windows minimum coordinate = s
    // windows maximum coordinate = q
    // here x1 ,y1 for line = up
    // x2 ,y2 for line = down


    int dx = downx - upx;
    int dy = downy - upy;



    int xmax = qx;
    int xmin = px;
    int ymax = qy;
    int ymin = ry;
    printf(" Minimum y %d",  ymin);
    printf(" Minimum x %d",  xmin);
    float p1 = -1* dx;
    float p2 = dx;
    float p3 = -1* dy;
    float p4 = dy;
    float q1 = upx - xmin;
    float q2 = xmax - upx;
    float q3 = upy - ymin;
    float q4 = ymax - upy;
    printf("value of dx = %d , dy = %d", dx, dy);
    printf("\nP1 %f \n", p1);
    printf("P2 %f \n", p2);
    printf("P3 %f \n", p3);
    printf("P4 %f \n", p4);
    printf("q1 %f \n", q1);
    printf("q2 %f \n", q2);
    printf("q3 %f \n", q3);
    printf("q4 %f \n", q4);


    float T1 = calculateT1(p1, p2,p3, p4 , q1, q2, q3, q4);
    float T2 = calculateT2(p1, p2,p3, p4 , q1, q2, q3, q4);
    printf(" T1 %f  and T2 %f .\n" , T1 , T2);

    int x1 = upx+ T1*dx;
    int y1 = upy + T1*dy;

    int x2 = upx +T2*dx;
    int y2 = upy + T2*dy;
    if(T1<T2)
    {
        //srand(time(0));
        glColor3d(1,1,1);
        glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glEnd();
        glFlush();
    }

    printf("x1= %d  , y1 = %d \n", x1, y1);
    printf("x2 = %d , y2 = %d \n" , x2, y2);


}


void init()
{

        gluOrtho2D(-500,500,-300,300);
        glClear(GL_COLOR_BUFFER_BIT);
}

void ssss()
{
    for(int k = 0 ; k < j ; k++)
    {
        setParameters(k);
        LianBarsky();
    }
    resetParameters();
    LianBarsky();
}



void spawnScreen(int a , int b)
{


    printf("\nwhile initializing values  down x %d  \n",downx );
    printf("while initializing values of down %d \n",downy );
    printf("while initializing values of upx %d \n",upx );
    printf("while initializing values of upy %d \n",upy );
    glBegin(GL_LINES);
    px = a-50;
    py = b+50;
    qx = a+50;
    qy = b+50;
    glVertex2d(a-50,b+50);
    glVertex2d(a+50,b+50);

    rx = a+50;
    ry = b-50;
    glVertex2d(a+50,b+50);
    glVertex2d(a+50,b-50);

    sx = a-50;
    sy = b-50;
    glVertex2d(a+50,b-50);
    glVertex2d(a-50,b-50);

    glVertex2d(a+50,b-50);
    glVertex2d(a-50,b-50);

    glVertex2d(a-50 ,b-50);
    glVertex2d(a-50 , b+50);
    glEnd();

    /*printf("px %d ", px);
    printf("py %d \n", py);
    printf("qx %d ", qx);
    printf("qy %d \n", qy);
    printf("sx %d ", sx);
    printf("sy %d \n", sy);
    printf("rx %d ", rx);
    printf("ry %d ", ry);*/
    glFlush();
    LianBarsky();
    ssss(); // will paint intersection of other lines
}



void display()
{
    resetarr();
    glColor3d(0,255,0);
    glBegin(GL_LINES);
    glVertex2d(-500,300);
    glVertex2d(500,-300);
    glEnd();
    glFlush();


}

void myKeyboardFunc(unsigned char key , int x, int y)
{
    if(key =='r')
    {
         glClear(GL_COLOR_BUFFER_BIT);
         display();
        //glutPostRedisplay();

    }

}
void createLine()
{

    lines[i][0] = upx;
    lines[i][1] = upy;
    lines[i][2] = downx;
    lines[i][3] = downy;
    i++;
    j = i;

    glColor3d(1,0,1);
    glBegin(GL_LINES);
    glVertex2d(upx,upy);
    glVertex2d(downx, downy);
    glEnd();
    glFlush();
}

void myMouseFunc(int button, int state, int x, int y)
{
        if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && click <2)
        {
                if (click == 0)
            {
                    upx = x-500;
                    upy = 300-y;

            }
                if(click == 1 )
                {

                    downx = x-500;
                    downy = 300-y;
                     createLine();
                }
            click++;
                if(click == 2)
                {

                 resetParameters();
                 click =0;
                }
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            glColor3d(1,1,1);
            spawnScreen(x-500 , 300-y );
            if(click == 2)
            {

                click = 0;
                resetParameters();
            }

        }
}

int main(int argc,char** argv)
{
    newLine newup, newdown; // points of intersection of points

	int mode = GLUT_RGB|GLUT_SINGLE;
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(mode);
	glutInitWindowSize(1000,600);
	glutCreateWindow("Liang Barsky");
    init();
    glutDisplayFunc(display);

    glutKeyboardFunc(myKeyboardFunc);
    glutMouseFunc(myMouseFunc);
    glutMainLoop();
    return 0;
}
