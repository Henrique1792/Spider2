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
#define THETA_JOINT_5 8.5f
#define THETA_JOINT_7 12.0f

#define THETA_FOOT_1  1.0f
#define THETA_FOOT_3  3.0f
#define THETA_FOOT_5  8.0f
#define THETA_FOOT_7  13.0f

#define LEG_HEIGHT 1.5f

typedef struct spider_t{
    vec3 pos, target;
    GLfloat rotate, scale;
    bool hasTarget;

    float spider_J1, spider_F1;
    float spider_J2, spider_F2;
    float spider_J3, spider_F3;
    float spider_J4, spider_F4;
    float spider_J5, spider_F5;
    float spider_J6, spider_F6;
    float spider_J7, spider_F7;
    float spider_J8, spider_F8;
}spider_t;

void spider_init(spider_t *spider, vec3 *initial, GLfloat rotation, GLfloat scale);
spider_t *spider_create(vec3 *initial, GLfloat rotation, GLfloat scale);
void spider_destroy(spider_t *spider);
void spider_draw(spider_t *spider);
void spider_setX(spider_t* spider, GLfloat x);
void spider_setY(spider_t* spider, GLfloat y);
void spider_setZ(spider_t* spider, GLfloat z);
void spider_setPosition(spider_t* spider, GLfloat x, GLfloat y, GLfloat z);
void spider_setRotation(spider_t* spider, GLfloat rotation);
void spider_setScale(spider_t* spider, GLfloat scale);

void spider_drawOrigin(bool draw);
bool spider_getDrawOrigin(void);

void spider_rotate(spider_t* spider, GLfloat delta);
void spider_scale(spider_t* spider, GLfloat delta);

void spider_setTarget(spider_t* spider, float x, GLfloat y, GLfloat z);
void spider_update(spider_t* spider, float deltaTime);


#endif