#include "../include/display.h"

int extern width, height;
spider_t extern *spider;
void cleanScreen(){
	glClear(GL_COLOR_BUFFER_BIT); 
	glPointSize(10);
}

int isLeftKeyPressed = 0;
int isRightKeyPressed = 0;
int isUpKeyPressed = 0;
int isDownKeyPressed = 0;

void arrowKeypressed(int key, int x, int y){
	
	switch (key) {
 		case GLUT_KEY_LEFT:
			isLeftKeyPressed = 1;
			if (isLeftKeyPressed == 1) {
				printf("LEFT: %d", key);
			}
			break;
		case GLUT_KEY_RIGHT:
			isRightKeyPressed = 1;
			if (isRightKeyPressed == 1) {
				printf("RIGHT: %d", key);
			}
			break;
		case GLUT_KEY_UP:
			isUpKeyPressed = 1;
			if (isUpKeyPressed == 1) {
				printf("UP: %d", key);
			}
			break;
		case GLUT_KEY_DOWN:
			isDownKeyPressed = 1;
			if (isDownKeyPressed == 1) {
				printf("DOWN: %d", key);
			}
			break;
 	}
}

void arrowKeyReleased(int key, int x, int y){
	
	switch (key) {
 		case GLUT_KEY_LEFT:
  			isLeftKeyPressed = 0;
  			break;
 		case GLUT_KEY_RIGHT:
  			isRightKeyPressed = 0;
  			break;
		case GLUT_KEY_UP:
  			isUpKeyPressed = 0;
  			break;
		case GLUT_KEY_DOWN:
  			isDownKeyPressed = 0;
  			break;
	}
}

void display(){
	cleanScreen();
	glRotatef(90.0, 1.0, 0.0, 0.0);

	glColor3f(1.0f, 0.0f, 0.0f);
/*Desenha a janela no canto superior esquerdo
 *câmera em perspectiva*/
	// Diminuir o 1-H
	glViewport(0, height/2 - 20, width/2, height/2);
	glLoadIdentity();
	gluLookAt(2.5, 2.5, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	drawWAxes();
	glColor3f(0.0f, 0.0f, 0.0f);
	spider_draw(spider);
/*Desenha a janela no canto inferior esquerdo
 *câmera em y*/
	glViewport(0, 20, width/2, height/2);
	glLoadIdentity();
	gluLookAt(0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	drawWAxes();
	glColor3f(0.0, 0.0, 0.0);
	spider_draw(spider);

/** Desenha a janela no canto inferior direito
 *câmera em x*/
	glViewport(width/2, 20, width/2, height/2);
	glLoadIdentity();
	gluLookAt(5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	drawWAxes();
	glColor3f(0.0, 0.0, 0.0);
	spider_draw(spider);

/*Desenha janela no canto inferior direito
 *câmera em z*/
	glViewport(width/2, height/2 - 20, width/2, height/2);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	drawWAxes();
	glColor3f(0.0, 0.0, 0.0);
	spider_draw(spider);
	
	glutSwapBuffers();
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
