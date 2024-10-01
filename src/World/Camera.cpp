#include "Camera.hpp"
Camera::Camera()
    : xcamera(0.0f), ycamera(50.0f), zcamera(300.0f), xtarget(0.0f),
      ytarget(0.0f), ztarget(0.0f), xvector(0.0f), yvector(1.0f),
      zvector(0.0f) {}
Camera::Camera(GLfloat xcamera, GLfloat ycamera, GLfloat zcamera,
               GLfloat xtarget, GLfloat ytarget, GLfloat ztarget,
               GLfloat xvector, GLfloat yvector, GLfloat zvector)
    : xcamera(xcamera), ycamera(ycamera), zcamera(zcamera), xtarget(xtarget),
      ytarget(ytarget), ztarget(ztarget), xvector(xvector), yvector(yvector),
      zvector(zvector) {}

GLfloat Camera::get_xcamera() { return xcamera; }
GLfloat Camera::get_ycamera() { return ycamera; }
GLfloat Camera::get_zcamera() { return zcamera; }

GLfloat Camera::get_xtarget() {
  return xcamera + 300.0f * sin(angle / 360.0f * (M_PI * 2.0f));
}
GLfloat Camera::get_ytarget() { return ytarget; }
GLfloat Camera::get_ztarget() {
  return zcamera + 300.0f * cos(angle / 360.0f * (M_PI * 2.0f));
}

GLfloat Camera::get_xvector() { return xvector; }
GLfloat Camera::get_yvector() { return yvector; }
GLfloat Camera::get_zvector() { return zvector; }

void Camera::move_front() {
  zcamera += 10 * cos(angle / 360.0f * (M_PI * 2.0f));
  xcamera += 10 * sin(angle / 360.0f * (M_PI * 2.0f));
}
void Camera::move_back() {
  zcamera -= 10 * cos(angle / 360.0f * (M_PI * 2.0f));
  xcamera -= 10 * sin(angle / 360.0f * (M_PI * 2.0f));
}
void Camera::rotate_rigth() { angle -= 5; }
void Camera::rotate_left() { angle += 5; }
