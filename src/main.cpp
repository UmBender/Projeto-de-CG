#include "Flowers/Flower.hpp"
#include "Flowers/Seeder.hpp"
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <vector>

GLfloat angle, fAspect, largura, altura;
GLfloat xcamera = 0, ycamera = 0, zcamera = 300;
GLfloat xtarget = 0, ytarget = 0, ztarget = 0;
GLfloat look_angle = 0;
GLfloat xvector = 0, yvector = 1.0, zvector = 0;
std::vector<Flower *> flowers;

void Desenha(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  // Especifica a viewport
  glViewport(0, 0, largura, altura);

  // Desenha objetos 3D (wire-frame)
  // glutSolidTeapot(20.0f);
  // glutWireCube(50.0);
  // glutWireSphere(50, 20, 20);

  // glColor3f(1.0f, 0.2f, 0.2f);
  // glPushMatrix();
  // glTranslated(0, 0, 0);
  // glutWireTeapot(25.0f);
  // // glColor3f(0.0f, 0.2f, 0.2f); glutWireSphere(50, 20, 20); glColor3f(1.0f,
  // // 0.2f, 0.0f); glutWireCube(50.0);
  // glPopMatrix();
  for (Flower *i : flowers) {
    i->draw_flower();
  }
  /*
          // Desenha um cubo utilizando primitivas
          glColor3f(0.7f, 0.4f, 1.0f);
          glBegin(GL_QUADS);			// Face frontal
                  glNormal3f(0.0, 0.0, 1.0); 	// Normal da face
                  glVertex3f(40.0, 40.0, 80.0);
                  glVertex3f(-40.0, 40.0, 80.0);
                  glVertex3f(-40.0, -40.0, 80.0);
                  glVertex3f(40.0, -40.0, 80.0);
          glEnd();
                  glColor3f(0.0f, 0.0f, 1.0f);
          glBegin(GL_QUADS);			// Face posterior
                  glNormal3f(0.0, 0.0, -1.0);	// Normal da face
  glVertex3f(40.0, 40.0, 0.0); glVertex3f(40.0, -40.0, 0.0); glVertex3f(-40.0,
  -40.0, 0.0); glVertex3f(-40.0, 40.0, 0.0); glEnd(); glColor3f(1.0f, 1.0f,
  0.0f); glBegin(GL_QUADS);			// Face inferior glNormal3f(0.0,
  -1.0, 0.0); 	// Normal da face glVertex3f(-40.0, -40.0, 0.0);
                  glVertex3f(40.0, -40.0, 0.0);
                  glVertex3f(40.0, -40.0, 80.0);
                  glVertex3f(-40.0, -40.0, 80.0);
          glEnd();
  glColor3f(0.0f, 1.0f, 0.0f);
          glBegin(GL_QUADS);			// Face lateral esquerda
                  glNormal3f(-1.0, 0.0, 0.0); 	// Normal da face
                  glVertex3f(-40.0, 40.0, 80.0);
                  glVertex3f(-40.0, 40.0, 0.0);
                  glVertex3f(-40.0, -40.0, 0.0);
                  glVertex3f(-40.0, -40.0, 80.0);
          glEnd();

          glColor3f(0.0f, 1.0f, 0.0f);
          glBegin(GL_QUADS);			// Face lateral direita
                  glNormal3f(1.0, 0.0, 0.0);	// Normal da face
                  glVertex3f(40.0, 40.0, 80.0);
                  glVertex3f(40.0, -40.0, 80.0);
                  glVertex3f(40.0, -40.0, 0.0);
                  glVertex3f(40.0, 40.0, 0.0);
          glEnd();
          glColor3f(0.0f, 1.0f, 1.0f);
          glBegin(GL_QUADS);			// Face superior
                  glNormal3f(0.0, 1.0, 0.0);  	// Normal da face
                  glVertex3f(-40.0, 40.0, 0.0);
                  glVertex3f(-40.0, 40.0, 80.0);
                  glVertex3f(40.0, 40.0, 80.0);
                  glVertex3f(40.0, 40.0, 0.0);
          glEnd();
  */
  glutSwapBuffers();
}

void Inicializa(void) {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

  glEnable(GL_DEPTH_TEST);                            // ativa o zBuffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // aplica o zBuffer

  angle = 45;
}

void set_look_angle() {
  xvector = std::sin(look_angle);
  yvector = std::cos(look_angle);
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void) {
  Seeder *sed = Seeder::GetInstance();
  // Especifica sistema de coordenadas de projeção
  glMatrixMode(GL_PROJECTION);
  // Inicializa sistema de coordenadas de projeção
  glLoadIdentity();
  // Especifica a projeção perspectiva
  gluPerspective(angle, fAspect, 0.1, 1000);

  // Especifica sistema de coordenadas do modelo
  glMatrixMode(GL_MODELVIEW);
  // Inicializa sistema de coordenadas do modelo
  glLoadIdentity();

  set_look_angle();

  // Especifica posição do observador e do alvo
  gluLookAt(sed->get_x(), sed->get_y(), sed->get_z(), // posição da câmera
            xtarget, ytarget, ztarget,                // posição do alvo
            xvector, yvector, zvector);               // vetor UP da câmera
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLint largura, GLint altura) {
  // Para previnir uma divisão por zero
  if (altura == 0)
    altura = 1;

  // Especifica o tamanho da viewport
  glViewport(0, 0, largura, altura);

  // Calcula a correção de aspecto
  fAspect = (GLfloat)largura / (GLfloat)altura;

  EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON)
    if (state == GLUT_DOWN) { // Zoom-in
                              // if (angle >= 10) angle -= 5;
      ycamera += 10;
    }
  if (button == GLUT_RIGHT_BUTTON)
    if (state == GLUT_DOWN) { // Zoom-out
                              // if (angle <= 130) angle += 5;
      ycamera -= 10;
    }
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // aplica o zBuffer
  EspecificaParametrosVisualizacao();
  glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y) {
  Seeder *sed = Seeder::GetInstance();
  if (key == GLUT_KEY_UP) {
    sed->move_z(-10);
    ztarget -= 10;
  }
  if (key == GLUT_KEY_DOWN) {
    sed->move_z(10);
    ztarget += 10;
  }
  if (key == GLUT_KEY_RIGHT) {
    sed->move_x(10);
    xtarget += 10;
  }
  if (key == GLUT_KEY_LEFT) {
    sed->move_x(-10);
    xtarget -= 10;
  }
  EspecificaParametrosVisualizacao();
  glutPostRedisplay();
}

void GerenciaTeclado(unsigned char key, int x, int y) {
  Seeder *sed = Seeder::GetInstance();
  switch (key) {
  case ' ': // restaura posição inicial da camera
    // xcamera = 0, ycamera = 0, zcamera = 300;
    // xtarget = 0, ytarget = 0, ztarget = 0;
    // look_angle = 0;
    // xvector = 0, yvector = 1.0, zvector = 0;
    flowers.push_back(sed->generate_flower());
    break;
  // movimentacao do observador
  case 'd':
    break;
  case 'a':
    break;
  case 'q':
    look_angle += 0.3;
    break;
  case 'e':
    look_angle -= 0.3;
    break;
  }
  EspecificaParametrosVisualizacao();
  glutPostRedisplay();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE |
                      GLUT_RGB); // GLUT_DOUBLE trabalha com dois buffers: um
                                 // para renderização e outro para exibição

  glutInitWindowPosition(300, 50);
  largura = 1200;
  altura = 600;
  glutInitWindowSize(largura, altura);
  fAspect = (GLfloat)largura / (GLfloat)altura;
  glutCreateWindow("Aula Pratica 4");

  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela); // Função para ajustar o tamanho da tela
  glutMouseFunc(GerenciaMouse);
  glutKeyboardFunc(GerenciaTeclado); // Define qual funcao gerencia o
  // comportamento do teclado
  glutSpecialFunc(TeclasEspeciais); // Define qual
  // funcao gerencia as teclas especiais
  Inicializa();
  glutMainLoop();
}
