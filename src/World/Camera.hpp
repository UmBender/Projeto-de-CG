#pragma once
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

class Camera {
private:
  GLfloat xcamera, ycamera, zcamera;
  GLfloat xtarget, ytarget, ztarget;
  GLfloat xvector, yvector, zvector;
  int angle;

protected:
public:
  Camera();
  Camera(GLfloat xcamera, GLfloat ycamera, GLfloat zcamera, GLfloat xtarget,
         GLfloat ytarget, GLfloat ztarget, GLfloat xvector, GLfloat yvector,
         GLfloat zvector);

  GLfloat get_xcamera();
  GLfloat get_ycamera();
  GLfloat get_zcamera();

  GLfloat get_xtarget();
  GLfloat get_ytarget();
  GLfloat get_ztarget();

  GLfloat get_xvector();
  GLfloat get_yvector();
  GLfloat get_zvector();

  void move_front();
  void move_back();
  void rotate_rigth();
  void rotate_left();
};
