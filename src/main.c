#include "../include/settings.h"
#include "../include/display.h"

int width=800, height=600;

void init(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition((SCREEN_SIZEX)/2, (SCREEN_SIZEY)/2);
	glutInitWindowSize(width, height);
	glutCreateWindow("Spider - 3D");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


}



int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	init();

		glutDisplayFunc(display);
		glutReshapeFunc(reshape);

	glutMainLoop();
}
