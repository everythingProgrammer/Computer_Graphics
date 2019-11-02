
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>


struct Line{
	int x1;
	int y1;
	int x2;
	int y2;
}L1;

void init()
{

        gluOrtho2D(-500,500,-300,300);
        glClear(GL_COLOR_BUFFER_BIT);
}


int rclick = 0;
int lclick = 0;


void drawLine()
{
	

}


void myMouseFunc(int button, int state, int x, int y)
{
        if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && rclick == 0 )
        {
		L1.x1 = x;
		L1.y1 = 300-y1;
		               
        }
        else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && lclick == 0)
        {
		L1.x2 =x;
		L1.y2 =300-y;
            
        }
	if(rclick == 1 && lclick == 1)
	{
		drawLine();
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

    	//glutKeyboardFunc(myKeyboardFunc);
    	//glutMouseFunc(myMouseFunc);
	glutMainLoop();
	return 0;
}

