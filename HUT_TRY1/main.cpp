#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>




void drawBitmapText(char *string,float x,float y)
{
	char *c;
	glRasterPos2f(x, y);

	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
	}
}

void drawStrokeText(char*string,int x,int y)
{

	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+1.8,0);
	  glScalef(0.19f,-0.18f,0);

	  for (c=string; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
}


void reshape(int w,int h)
{

    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,w,h,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}


void render(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(0,0,0);
	drawStrokeText("Abhinav Singh Rana",0.0,0.0);

	glutSwapBuffers();
}




void display()
{

    gluOrtho2D(5.0,5.0,5.0,5.0);


	glClear(GL_COLOR_BUFFER_BIT);




	glColor4f(0.40,0.40,1,1);
	glBegin(GL_POLYGON);
        glVertex2f(-5.0,0.0);
        glVertex2f(5.0,0.0);
        glVertex2f(5.0,5.0);
        glVertex2f(-5.0,5.0);
glEnd();
glColor4f(0.0,1,0.0,1);

glBegin(GL_POLYGON);
    glVertex2f(-5.0,0.0);
    glVertex2f(5.0,0.0);
    glVertex2f(5.0,-5.0);
    glVertex2f(-5.0,-5.0);
glEnd();


	glColor4f(1,1,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(-0.00,-0.35);
		glVertex2f(-0.00,0.2);
		//****glVertex2f(0.5,0.5);
		glVertex2f(0.4,0.1);
		glVertex2f(0.4,-0.15);
        // Max Height of Side wall = 0.2
        // Depth of Side wall = -0.5
        // Sides of SideWall = -0.2 and 0.7
        glEnd();

// RoofLine

//Depth = 0.1  ||0.2-0.1
//Length = 0.6 ||0.0 -0.6
glColor4f(0.7,0.2,0.8,1);
glBegin(GL_POLYGON);
    glVertex2f(-0.12,0.55); //* front height of roof
    glVertex2f(0.35,0.22);
    glVertex2f(0.45,0.00);
    glVertex2f(0.03,0.12); //*

glEnd();

// Front Door

glColor4f(0.6,0.3,0.4,1);
glBegin(GL_POLYGON);
    //Door lower edge
    glVertex2f(0.0,-0.35); // Door Lower Edge right
    glVertex2f(-0.23, -0.32); // Door Lower Edge right
    // Door left edge
    glVertex2f(-0.23,-0.32);
    glVertex2f(-0.23,0.17);

    // Door upper edge
    glVertex2f(-0.23,0.17);
    glVertex2f(0.0,0.2);

    // Door right edge

    glVertex2f(0.0,0.2);
    glVertex2f(0.0,-0.35);

glEnd();


// actual DOOR



// left side of roof
glColor4f(0.7,0.2,0.8,1);
glBegin(GL_LINES);
    glVertex2f(-0.12,0.55);
    glVertex2f(-0.25,0.12);
glEnd();


glColor4f(0.2,0.7,0.4,1);
glBegin(GL_POLYGON);
    glVertex2f(-0.235,0.17);
    glVertex2f(0.0,0.2);
    glVertex2f(-0.12,0.55);
glEnd();


// Creating Sun
glColor4f(0.7,1,0.0,1);
glBegin(GL_POLYGON);
    float theta = 0.0;
    int Q = 0;
    for(int i =0 ; i<360 ; i++)
    {

        theta = i*3.14/180;
        glVertex2f(0.08*cos(theta)-0.5  , 0.125*sin(theta)+0.65);

    }
glEnd();



//POND
glColor4f(0.0,0,1.0,1);
glBegin(GL_POLYGON);
     theta = 0.0;
     Q = 0;
    for(int i =0 ; i<360 ; i++)
    {

        theta = i*3.14/180;
        glVertex2f(0.90*cos(theta)-0.9  , 0.90*sin(theta)-1.35);

    }
glEnd();



glFlush();
}





void display2()
{

    gluOrtho2D(5.0,5.0,5.0,5.0);


	glClear(GL_COLOR_BUFFER_BIT);




	glColor4f(0.0,0.0,0.6,1);
	glBegin(GL_POLYGON);
        glVertex2f(-5.0,0.0);
        glVertex2f(5.0,0.0);
        glVertex2f(5.0,5.0);
        glVertex2f(-5.0,5.0);
glEnd();
glColor4f(0.33,0.41,0.0,1);

glBegin(GL_POLYGON);
    glVertex2f(-5.0,0.0);
    glVertex2f(5.0,0.0);
    glVertex2f(5.0,-5.0);
    glVertex2f(-5.0,-5.0);
glEnd();


	glColor4f(0.5,1,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(-0.00,-0.35);
		glVertex2f(-0.00,0.2);
		//****glVertex2f(0.5,0.5);
		glVertex2f(0.4,0.1);
		glVertex2f(0.4,-0.15);
        // Max Height of Side wall = 0.2
        // Depth of Side wall = -0.5
        // Sides of SideWall = -0.2 and 0.7
        glEnd();

// RoofLine

//Depth = 0.1  ||0.2-0.1
//Length = 0.6 ||0.0 -0.6
glColor4f(0.7,0.2,0.8,1);
glBegin(GL_POLYGON);
    glVertex2f(-0.12,0.55); //* front height of roof
    glVertex2f(0.35,0.22);
    glVertex2f(0.45,0.00);
    glVertex2f(0.03,0.12); //*

glEnd();

// Front Door

glColor4f(0.6,0.3,0.4,1);
glBegin(GL_POLYGON);
    //Door lower edge
    glVertex2f(0.0,-0.35); // Door Lower Edge right
    glVertex2f(-0.23, -0.32); // Door Lower Edge right
    // Door left edge
    glVertex2f(-0.23,-0.32);
    glVertex2f(-0.23,0.17);

    // Door upper edge
    glVertex2f(-0.23,0.17);
    glVertex2f(0.0,0.2);

    // Door right edge

    glVertex2f(0.0,0.2);
    glVertex2f(0.0,-0.35);

glEnd();


// actual DOOR



// left side of roof
glColor4f(0.7,0.2,0.8,1);
glBegin(GL_LINES);
    glVertex2f(-0.12,0.55);
    glVertex2f(-0.25,0.12);
glEnd();


glColor4f(0.2,0.7,0.4,1);
glBegin(GL_POLYGON);
    glVertex2f(-0.235,0.17);
    glVertex2f(0.0,0.2);
    glVertex2f(-0.12,0.55);
glEnd();

glColor4f(1.0,1,1.0,1);
glBegin(GL_POLYGON);
    float theta = 0.0;
    int Q = 0;
    for(int i =0 ; i<360 ; i++)
    {

        theta = i*3.14/180;
        glVertex2f(0.08*cos(theta)-0.5  , 0.125*sin(theta)+0.65);

    }
glEnd();



//POND
glColor4f(0.0,0,1.0,1);
glBegin(GL_POLYGON);
     theta = 0.0;
     Q = 0;
    for(int i =0 ; i<360 ; i++)
    {

        theta = i*3.14/180;
        glVertex2f(0.90*cos(theta)-0.9  , 0.90*sin(theta)-1.35);

    }
glEnd();



glFlush();
}




void OnMouseClick(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        display2();
    }
    else if(button ==GLUT_LEFT_BUTTON && state == GLUT_UP)
    {

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
	glutCreateWindow("Simple");
    glutMouseFunc(OnMouseClick);
    glutDisplayFunc(display);

	//glutKeyboardFunc(key);
    glutMainLoop();
}
