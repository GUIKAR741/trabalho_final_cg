#include "canvas.h"

Canvas::Canvas(QWidget *parent): QOpenGLWidget(parent)
{
    cena = Cena(height(), width());
}

void Canvas::idleGL()
{
    update();
}

void Canvas::initializeGL()
{
    glClearColor(1,1,1,1);
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
//    glEnable(GL_CULL_FACE);
    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_POINT_SMOOTH);
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void Canvas::paintGL()
{
    glViewport(0,0,width(),height());
    cena.desenha();
}
