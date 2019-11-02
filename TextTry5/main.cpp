// Fonts.cpp : Defines the entry point for the console application.


#include <math.h>
#include<GL/glut.h>
#include <Windows.h>
void drawBitmapText(char *string,float x,float y)
{
	char *c;
	glRasterPos2f(x, y);

	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
	}

//GLUT_BITMAP_HELVETICA_18
//GLUT_BITMAP_8_BY_13
//GLUT_BITMAP_TIMES_ROMAN_24



}

void drawStrokeText(char*string,int x,int y)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,0);
	  glScalef(0.5f,0.50f,0);

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
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
    float c = ((rand())%7 );
    float c2 = ((rand())%7 );
    float c3 = ((rand())%7 );
    if(c >0.9 && c2>0.85 && c3 > 0.85)
    {

         c = ((rand())%7 );
         c2 = ((rand())%5 );
         c3 = ((rand())%7 );
     }
     c = ((rand())%7 );
     c2 = ((rand())%7 );
     c3 = ((rand())%7 );
	glColor3f(c,c2,c3);
	Sleep(1000);
	float x = rand()%500;
	float y = rand()%500;
	drawBitmapText("Abhinav Singh Rana",x,y);

     x = rand()%300;
	 y = rand()%300;
	 drawBitmapText(" Roll Number : R110217005",x,y);
	glutSwapBuffers();
}


int main(int argc, char* argv[])
{
		// initialize glut
        glutInit(&argc, argv);

        // specify the display mode to be RGB and single buffering
        // we use single buffering since this will be non animated
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

        // define the size
        glutInitWindowSize(500,500);

        // the position where the window will appear
        glutInitWindowPosition(00,00);
        glutCreateWindow("Text Using Glut");

        glutDisplayFunc(render);

        glutIdleFunc(render);
        glutReshapeFunc(reshape);

        // enter the main loop
        glutMainLoop();
	return 0;
}
