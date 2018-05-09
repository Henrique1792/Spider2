#include "../include/display.h"

int extern width, height;

void cleanScreen(){
	glClear(GL_COLOR_BUFFER_BIT); 
	glPointSize(10);
}

void display(){
	cleanScreen();

	glColor3f(1.0f, 0.0f, 0.0f);
	/** Desenha a janela mais a direita */

	glViewport(width/2, 0, width/2, height);
	glLoadIdentity();
	gluLookAt(3.0, 2.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	drawWAxes();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCone(1.0, 2.0, 4, 4);


/*Desenha a primeira janela mais a esquerda
 *câmera em z*/
	glViewport(0, 2*height/3, width/2, height/3);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	drawWAxes();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCone(1.0, 2.0, 4, 4);


/*Desenha a janela do meio
 *câmera em x*/

	glViewport(0, height/3, width/2, height/3);
	glLoadIdentity();
	gluLookAt(10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	drawWAxes();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCone(1.0, 2.0, 4, 4);
	
/*Desenah a última janela
 *câmera em y*/
	glViewport(0, 0, width/2, height/3);
	glLoadIdentity();
	gluLookAt(0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	drawWAxes();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glutWireCone(1.0, 2.0, 4, 4);
	
	/** Dispara os comandos APENAS uma vez */
	glFlush();

}


void reshape(int w, int h){
	width=w, height=h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}


void drawAxes(float *basePoint, float *i, float *j, float *k){
	float currentColor[4];
	/** Armazena cor atual */
	glGetFloatv(GL_CURRENT_COLOR, currentColor);
	/** Desenha versores */
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex3f(basePoint[0], basePoint[1], basePoint[2]);
		glVertex3f(i[0], i[1], i[2]);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	
	glBegin(GL_LINES);
		glVertex3f(basePoint[0], basePoint[1], basePoint[2]);
		glVertex3f(j[0], j[1], j[2]);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(basePoint[0], basePoint[1], basePoint[2]);
		glVertex3f(k[0], k[1], k[2]);
	glEnd();
	/** Retorna para cor anterior */
	glColor3f(currentColor[0], currentColor[1], currentColor[2]);
}

void drawWAxes(){
	float *basePoint, *i, *j, *k;

	basePoint = (float *)malloc(3*sizeof(float));
	basePoint[0] = basePoint[1] = basePoint[2] = 0.0;
	i = (float *)malloc(3*sizeof(float));
	i[0] = 5.0;
	i[1] = i[2] = 0.0;
	j = (float *)malloc(3*sizeof(float));
	j[0] = j[2] = 0.0;
	j[1] = 5.0;
	k = (float *)malloc(3*sizeof(float));
	k[0] = k[1] = 0.0;
	k[2] = 5.0;
	drawAxes(basePoint, i, j, k);
}
