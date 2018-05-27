#include "../include/spider.h"
#include "../include/forms.h"

static bool gDrawOrigin = false;

spider_t *spider_create(vec3 *initial, GLfloat rotation, GLfloat scale){
	spider_t *rt=(spider_t *)malloc(sizeof(spider_t));
	if(rt!=NULL)
		spider_init(rt, initial, rotation, scale);
	return rt;
}

void spider_init(spider_t *spider, vec3 *initial, GLfloat rotation, GLfloat scale){
	for(int i=0; i<3; i++){
		spider->target.cd[i]=0;
		spider->pos.cd[i]=initial->cd[i];
	}

	spider->hasTarget=false;
	spider->rotate=rotation;
	spider->scale=scale;
	//set leg values

	spider->spider_J1 = THETA_JOINT_1; spider->spider_F1 = THETA_FOOT_1;
	spider->spider_J2 = THETA_JOINT_1; spider->spider_F2 = THETA_FOOT_1;
	spider->spider_J3 = THETA_JOINT_3; spider->spider_F3 = THETA_FOOT_3;
	spider->spider_J4 = THETA_JOINT_3; spider->spider_F4 = THETA_FOOT_3;
	spider->spider_J5 = THETA_JOINT_5; spider->spider_F5 = THETA_FOOT_5;
	spider->spider_J6 = THETA_JOINT_5; spider->spider_F6 = THETA_FOOT_5;
	spider->spider_J7 = THETA_JOINT_7; spider->spider_F7 = THETA_FOOT_7;
	spider->spider_J8 = THETA_JOINT_7; spider->spider_F8 = THETA_FOOT_7;

}

void spider_destroy(spider_t *spider){
	free(spider);
}
void spider_draw(spider_t *spider){
	//draw Head
	glPushMatrix();
		glTranslatef(BODY_RADIUS, HEAD_RADIUS, BODY_RADIUS);
		glutSolidSphere(HEAD_RADIUS, 50, 50);
		//DrawLegs
			glColor3f(1.0f, 0.0f, 1.0f);
		//1
			drawLine(HEAD_RADIUS, 0.0, 0.0, 
					spider->spider_J1, LEG_HEIGHT, 0.0);
			drawLine(spider->spider_J1, LEG_HEIGHT, 0.0,
					spider->spider_F1, 0.0, 0.0);
		//2
			drawLine(0.0, 0.0, HEAD_RADIUS, 
					 0.0, LEG_HEIGHT,spider->spider_J2);
			drawLine(0.0, LEG_HEIGHT,spider->spider_J2, 
					0.0, 0.0, spider->spider_F2);

		//3
			drawLine(HEAD_RADIUS*cos(30*DEG2RAD), 0.0, 0.0, 
					spider->spider_J3, LEG_HEIGHT*cos(30*DEG2RAD), 0.0);
			drawLine(spider->spider_J3, LEG_HEIGHT*cos(30*DEG2RAD), 0.0,
					spider->spider_F3, 0.0, 0.0);
		//4
			drawLine(0.0, 0.0, HEAD_RADIUS*cos(30*DEG2RAD), 
					 0.0, LEG_HEIGHT*cos(30*DEG2RAD),spider->spider_J4);
			drawLine(0.0, LEG_HEIGHT*cos(30*DEG2RAD),spider->spider_J4, 
					0.0, 0.0, spider->spider_F4);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0, HEAD_RADIUS, 0.0);
		glColor3f(0.0f, 0.0f, 0.0f);
		glutSolidSphere(BODY_RADIUS, 50, 50);
	glPopMatrix();

	//draw Legs
	
	//2
	glPushMatrix();
	glPopMatrix();

	//3
	glPushMatrix();
	glPopMatrix();

	//4
	glPushMatrix();
	glPopMatrix();
	//5
	glPushMatrix();
	glPopMatrix();
	//6
	glPushMatrix();
	glPopMatrix();
	//7
	glPushMatrix();
	glPopMatrix();
	//8
	glPushMatrix();
	glPopMatrix();
}
void spider_setX(spider_t* spider, GLfloat x){
	spider->pos.cd[0]=x;
}
void spider_setY(spider_t* spider, GLfloat y){
	spider->pos.cd[1]=y;
}
void spider_setZ(spider_t* spider, GLfloat z){
	spider->pos.cd[2]=z;
}
void spider_setPosition(spider_t* spider, GLfloat x, GLfloat y, GLfloat z){
	spider->pos.cd[0]=x;
	spider->pos.cd[1]=y;
	spider->pos.cd[2]=z;
}
void spider_setRotation(spider_t* spider, GLfloat rotation){
	if (rotation > 360.0f)
		rotation = 0.0f;
	else if (rotation < 0.0f)
		rotation = 360.0f;

	spider->rotate = rotation;
}
void spider_setScale(spider_t* spider, GLfloat scale){
	if (scale > 0.2f && scale < 5.0f)
		spider->scale = scale;
}

void spider_drawOrigin(bool draw){
	gDrawOrigin=draw;
}
bool spider_getDrawOrigin(void);

void spider_rotate(spider_t* spider, GLfloat delta);
void spider_scale(spider_t* spider, GLfloat delta);

void spider_setTarget(spider_t* spider, float x, GLfloat y, GLfloat z){
	spider->target.cd[0]=x;
	spider->target.cd[1]=y;
	spider->target.cd[2]=z;
	spider->hasTarget=true;
}