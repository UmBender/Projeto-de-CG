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
GLfloat look_angle = 0;
GLfloat xvector = 0, yvector = 1.0, zvector = 0;

World world;
Controller controller;
Camera camera;
Seeder seeder;

std::vector<Flower *> flowers;

void Desenha(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glViewport(0, 0, largura, altura);
  world.draw_floor();
  world.draw_sky();

  for (Flower *i : flowers) {
    i->draw_flower();
  }

  glutSwapBuffers();
}

void Inicializa(void) {

  GLfloat luzAmbiente[4] = {0.2, 0.2, 0.2, 1.0}; // {R, G, B, alfa}
  GLfloat luzDifusa[4] = {
      0.5, 0.5, 0.5,
      1.0}; // o 4o componente, alfa, controla a opacidade/transparência da luz
  GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0};
  GLfloat posicaoLuz[4] = {200.0, 200.0, 100.0,
                           1.0}; // aqui o 4o componente indica o tipo de fonte:
                                 // 0 para luz direcional (no infinito) e 1 para
                                 // luz pontual (em x, y, z)
  GLfloat posicaoLuz2[4] = {-200.0, 200.0, 100.0, 1.0};

  // Capacidade de brilho do material
  GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
  GLint especMaterial = 100; // 0 a 128
  //

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glShadeModel(GL_SMOOTH); // modelo de GOURAUD: a cor de cada ponto da
  // primitiva é interpolada a partir dos vértices
  // glShadeModel(GL_FLAT); // a cor de cada primitiva é única em todos os
  // pontos

  // Define a refletância do material
  glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
  // Define a concentração do brilho
  glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
  // Define a emissão de luz pelo objeto
  // glMaterialfv(GL_FRONT, GL_EMISSION, emissao);

  // Ativa o uso da luz ambiente
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

  // Define os parâmetros da luz de número 0
  glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
  glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
  glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

  glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa);
  glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular);
  glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz2);

  // Habilita a definição da cor do material a partir da cor corrente
  glEnable(GL_COLOR_MATERIAL);
  // Habilita o uso de iluminação
  glEnable(GL_LIGHTING);
  // Habilita a luz de número 0
  glEnable(GL_LIGHT0);
  // Habilita o depth-buffering

  glEnable(GL_DEPTH_TEST);                            // ativa o zBuffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // aplica o zBuffer

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
void GerenciaMouse(int button, int state, int x, int y) {
  // if (button == GLUT_LEFT_BUTTON)
  //   if (state == GLUT_DOWN) { // Zoom-in
  //                             // if (angle >= 10) angle -= 5;
  //     ycamera += 10; }
  // if (button == GLUT_RIGHT_BUTTON)
  //   if (state == GLUT_DOWN) { // Zoom-out if (angle <= 130) angle += 5;
  //     ycamera -= 10;
  //   }
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // aplica o zBuffer
  EspecificaParametrosVisualizacao();
  glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y) {
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

void GerenciaTeclado(unsigned char key, int x, int y) {
  switch (key) {
  case ' ':
    flowers.push_back(seeder.generate_flower());
    break;
  }
  EspecificaParametrosVisualizacao();
  glutPostRedisplay();
}

int main(int argc, char **argv) {
  camera = Camera();
  seeder = Seeder(&camera);
  world = World();

  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |
                      GLUT_DEPTH); // GLUT_DOUBLE trabalha com dois buffers: um
                                   // para renderização e outro para exibição

  glutInitWindowPosition(100, 50);
  largura = 1720;
  altura = 980;
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
