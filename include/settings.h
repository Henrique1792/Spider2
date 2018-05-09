
#ifndef SETTINGS_H_
#define SETTINGS_H_

//includes 
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

//defines
#define SCREEN_SIZEX glutGet(GLUT_WINDOW_WIDTH)
#define SCREEN_SIZEY glutGet(GLUT_WINDOW_HEIGHT)
#define VIEWPORT_X 800
#define VIEWPORT_Y 600

#define ORTHO_X 300
#define ORTHO_Y 300
#define ORTHO_NEAR -1
#define ORTHO_FAR 1


#define CENTER_X ORTHO_X/2
#define CENTER_Y ORTHO_Y/2

#endif