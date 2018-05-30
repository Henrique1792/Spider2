#ifndef SPIDER_H_
#define SPIDER_H_
#include "settings.h"
#include "vector.h"

#define RAD2DEG 180.0f / M_PI
#define DEG2RAD M_PI / 180.0f

//spider defines
#define HEAD_RADIUS 0.25f
#define BODY_RADIUS 0.4f
#define JOINT_SIZE 0.55f
#define FOOT_SIZE 0.75f

#define THETA_JOINT_1 1.50f
#define THETA_JOINT_3 1.75f
#define THETA_JOINT_5 -1.50f
#define THETA_JOINT_7 -1.50f

#define THETA_FOOT_1  1.0f
#define THETA_FOOT_3  3.0f
#define THETA_FOOT_5  -1.5f
#define THETA_FOOT_7  -3.0f

#define LEG_HEIGHT 1.5f

typedef struct spider_t{
    vec3 pos;
    GLfloat direction;

    float spider_J1, spider_F1;
    float spider_J2, spider_F2;
    float spider_J3, spider_F3;
    float spider_J4, spider_F4;
    float spider_J5, spider_F5;
    float spider_J6, spider_F6;
    float spider_J7, spider_F7;
    float spider_J8, spider_F8;
    
}spider_t;

spider_t *spider_create(vec3 *initial, GLfloat direction);
void spider_init(spider_t *spider, vec3 *initial, GLfloat direction);
void spider_destroy(spider_t *spider);
void spider_draw(spider_t *spider);

void spider_move(spider_t* spider, GLfloat x, GLfloat y, GLfloat z);
void spider_direction(spider_t* spider, GLfloat direction);

#endif