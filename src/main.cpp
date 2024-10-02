#include "Bird.hpp"
#include "Flowers/Flower.hpp"
#include "Flowers/Seeder.hpp"
#include "World/Camera.hpp"
#include "World/Controller.hpp"
#include "World/World.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <vector>

GLfloat angle, fAspect, largura, altura;
GLfloat look_angle = 90;

World world;
Controller controller;
Camera camera;
Seeder seeder;
std::vector<Flower *> flowers;
Bird bird;

void Desenha(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glViewport(0, 0, largura, altura);
  world.draw_floor();
  world.draw_sky();
  world.draw_sun();
  bird.draw_bird();

  for (Flower *i : flowers) {
    i->draw_flower();
  }

  glutSwapBuffers();
}

void Inicializa(void) {

  GLfloat luzAmbiente[4] = {0.5, 0.5, 0.5, 1.0};
  GLfloat luzDifusa[4] = {0.9, 0.9, 0.9, 1.0};
  GLfloat luzEspecular[4] = {0.9, 0.9, 0.9, 1.0};
  GLfloat posicaoLuz[4] = {0.0, 4000.0, 0.0, 0.0};

  glShadeModel(GL_SMOOTH);
  glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
  glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
  glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_COLOR_MATERIAL_FACE);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  angle = 90;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void) {
  // Especifica sistema de coordenadas de projeção
  glMatrixMode(GL_PROJECTION);
  // Inicializa sistema de coordenadas de projeção
  glLoadIdentity();
  // Especifica a projeção perspectiva
  gluPerspective(angle, fAspect, 0.1, sqrt(2.5) * 8000);

  // Especifica sistema de coordenadas do modelo
  glMatrixMode(GL_MODELVIEW);
  // Inicializa sistema de coordenadas do modelo
  glLoadIdentity();

  // Especifica posição do observador e do alvo
  gluLookAt(camera.get_xcamera(), camera.get_ycamera(), camera.get_zcamera(),
            camera.get_xtarget(), camera.get_ytarget(), camera.get_ztarget(),
            camera.get_xvector(), camera.get_yvector(), camera.get_zvector());
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
void GerenciaMouse(int button, int state, int, int) {
  if (button == GLUT_LEFT_BUTTON)
    if (state == GLUT_DOWN) {
      camera.look_up();
    }
  if (button == GLUT_RIGHT_BUTTON)
    if (state == GLUT_DOWN) {
      camera.look_down();
    }
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // aplica o zBuffer
  EspecificaParametrosVisualizacao();
  glutPostRedisplay();
}

void TeclasEspeciais(int key, int, int) {
  if (key == GLUT_KEY_UP) {

    camera.move_front();
  }
  if (key == GLUT_KEY_DOWN) {
    camera.move_back();
  }
  if (key == GLUT_KEY_RIGHT) {
    camera.rotate_rigth();
  }
  if (key == GLUT_KEY_LEFT) {
    camera.rotate_left();
  }
  EspecificaParametrosVisualizacao();
  glutPostRedisplay();
}

void GerenciaTeclado(unsigned char key, int, int) {
  switch (key) {
  case ' ':
    flowers.push_back(seeder.generate_flower());
    break;
  case 'w':
    camera.move_up();
    break;
  case 's':
    camera.move_down();
    break;
  }

  EspecificaParametrosVisualizacao();
  glutPostRedisplay();
}

void ControleTempo(int value) {

  // Redesenha a cena e executa o timer novamente para ter uma animacao continua
  bird.flap();
  glutPostRedisplay();
  glutTimerFunc(100, ControleTempo, 1);
}

int main(int argc, char **argv) {
  camera = Camera();
  seeder = Seeder(&camera);
  world = World();
  bird = Bird(&camera);

  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |
                      GLUT_DEPTH); // GLUT_DOUBLE trabalha com dois buffers: um
                                   // para renderização e outro para exibição

  glutInitWindowPosition(100, 50);
  largura = 1720;
  altura = 980;
  glutInitWindowSize(largura, altura);
  fAspect = (GLfloat)largura / (GLfloat)altura;
  glutCreateWindow("Projeto Jardim");

  glutTimerFunc(100, ControleTempo,
                1); // registra a função callback para temporizador

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
