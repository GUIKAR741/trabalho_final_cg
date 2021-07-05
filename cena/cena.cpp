#include "cena.h"

Cena::Cena(float h, float w)
{
    this->h = h;
    this->w = w;
}

Cena::Cena()
{

}

void Cena::desenha()
{
    glClear(GL_COLOR_BUFFER_BIT);

    projecao();
    visualizacao();

    glBegin(GL_LINES);
        glColor3f(0,1,0);
        glVertex3d(0,0,0);
        glVertex3d(100,0,0);
        glColor3f(1,0,0);
        glVertex3d(0,0,0);
        glVertex3d(0,100,0);
        glColor3f(0,0,1);
        glVertex3d(0,0,0);
        glVertex3d(0,0,100);
    glEnd();

    piso.desenha();

}

void Cena::projecao()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float largura = 2, altura = largura*h / w;
    glFrustum(-largura/2,largura/2,-altura/2,altura/2,1,100000);
}

void Cena::visualizacao()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(50,10,50,
              0,0,0,
              0,1,0);
}
