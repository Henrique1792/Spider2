#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "settings.h"

void display();
void reshape(int w, int h);


void drawWAxes();
void drawAxes(float *basePoint, float *i, float *j, float *k);
#endif
