#include "../include/spider.h"
#include "../include/forms.h"

static bool gDrawOrigin = false;

spider_t *spider_create(vec3 *initial, GLfloat direction){
	spider_t *rt=(spider_t *)malloc(sizeof(spider_t));
	if(rt!=NULL)
		spider_init(rt, initial, direction);
	return rt;
}

void spider_init(spider_t *spider, vec3 *initial, GLfloat direction){
	for(int i=0; i<3; i++){
		spider->pos.cd[i]=initial->cd[i];
	}

	spider->direction = direction;
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
	
	// Draw Head
	glPushMatrix();
		glTranslatef(BODY_RADIUS, HEAD_RADIUS, BODY_RADIUS);
		glutSolidSphere(HEAD_RADIUS, 50, 50);
		glRotatef(spider->direction, 0.0f, 1.0f, 0.0f);
	glPopMatrix();
	
	// // Draw Body
	glPushMatrix();
		glTranslatef(0.0, HEAD_RADIUS, 0.0);
		glColor3f(0.0f, 0.0f, 0.0f);
		glutSolidSphere(BODY_RADIUS, 50, 50);
	glPopMatrix();


		// //DrawLegs
		// 	glColor3f(1.0f, 0.0f, 1.0f);
		// //1
		// 	drawLine(HEAD_RADIUS, 0.0, 0.0, 
		// 			spider->spider_J1, LEG_HEIGHT, 0.0);
		// 	drawLine(spider->spider_J1, LEG_HEIGHT, 0.0,
		// 			spider->spider_F1, 0.0, 0.0);
		// //2
		// 	drawLine(0.0, 0.0, HEAD_RADIUS, 
		// 			 0.0, LEG_HEIGHT,spider->spider_J2);
		// 	drawLine(0.0, LEG_HEIGHT,spider->spider_J2, 
		// 			0.0, 0.0, spider->spider_F2);

		// //3
		// 	drawLine(HEAD_RADIUS*cos(30*DEG2RAD), 0.0, 0.0, 
		// 			spider->spider_J3, LEG_HEIGHT*cos(30*DEG2RAD), 0.0);
		// 	drawLine(spider->spider_J3, LEG_HEIGHT*cos(30*DEG2RAD), 0.0,
		// 			spider->spider_F3, 0.0, 0.0);
		// //4
		// 	drawLine(0.0, 0.0, HEAD_RADIUS*cos(30*DEG2RAD), 
		// 			 0.0, LEG_HEIGHT*cos(30*DEG2RAD),spider->spider_J4);
		// 	drawLine(0.0, LEG_HEIGHT*cos(30*DEG2RAD),spider->spider_J4, 
		// 			0.0, 0.0, spider->spider_F4);
		
		// //5
		// 	drawLine(HEAD_RADIUS*cos(30*DEG2RAD), 0.0, 0.0, 
		// 			spider->spider_J5, LEG_HEIGHT*cos(30*DEG2RAD), 0.0);
		// 	drawLine(spider->spider_J5, LEG_HEIGHT*cos(30*DEG2RAD), 0.0,
		// 			spider->spider_F5, 0.0, 0.0);
		// //6
		// 	drawLine(0.0, 0.0, HEAD_RADIUS*cos(30*DEG2RAD), 
		// 			 0.0, LEG_HEIGHT*cos(30*DEG2RAD),spider->spider_J6);
		// 	drawLine(0.0, LEG_HEIGHT*cos(30*DEG2RAD),spider->spider_J6, 
		// 			0.0, 0.0, spider->spider_F6);

		// //7
		// 	drawLine(HEAD_RADIUS*cos(60*DEG2RAD), 0.0, 0.0, 
		// 			spider->spider_J7, LEG_HEIGHT*cos(60*DEG2RAD), 0.0);
		// 	drawLine(spider->spider_J7, LEG_HEIGHT*cos(60*DEG2RAD), 0.0,
		// 			spider->spider_F7, 0.0, 0.0);
		// //8
		// 	drawLine(0.0, 0.0, HEAD_RADIUS*cos(60*DEG2RAD), 
		// 			 0.0, LEG_HEIGHT*cos(60*DEG2RAD),spider->spider_J8);
		// 	drawLine(0.0, LEG_HEIGHT*cos(60*DEG2RAD),spider->spider_J8, 
		// 			0.0, 0.0, spider->spider_F8);

	//draw Legs
}

void spider_move(spider_t* spider, GLfloat x, GLfloat y, GLfloat z){
	spider->pos.cd[0]+=x;
	spider->pos.cd[1]+=y;
	spider->pos.cd[2]+=z;
}

void spider_direction(spider_t* spider, GLfloat direction){
	spider->direction += direction;
	// if (spider->direction > 360.0f)
	// 	spider->direction = 0.0f;
	// else if (spider->direction <= 0.0f)
	// 	spider->direction = 360.0f;
}