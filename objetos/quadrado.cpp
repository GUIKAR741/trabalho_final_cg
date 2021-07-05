#include "quadrado.h"

Quadrado::Quadrado(){

}

Quadrado::Quadrado(int linha, int coluna)
{
    this->linha = linha;
    this->coluna = coluna;
    centroX = lado * linha + lado/2;
    centroZ = lado * coluna + lado/2;
}

Quadrado* Quadrado::desenha()
{
    glPushMatrix();
    glm::vec3 posicao = glm::vec3(centroX, 0, centroZ);
    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, posicao);
    glMultMatrixf(glm::value_ptr(modelMatrix));
    quad()->borda();
    glPopMatrix();
    return this;
}

Quadrado *Quadrado::quad()
{
    glColor3f(cor.redF(), cor.greenF(), cor.blueF());
    glBegin(GL_QUADS);
//        glVertex3f(lado*linha,0,lado*coluna);
//        glVertex3f(lado*(linha+1),0,lado*coluna);
//        glVertex3f(lado*(linha+1),0,lado*(coluna+1));
//        glVertex3f(lado*linha,0,lado*(coluna+1));
        glVertex3f(lado/2,0,lado/2);
        glVertex3f(lado/2,0,-lado/2);
        glVertex3f(-lado/2,0,-lado/2);
        glVertex3f(-lado/2,0,lado/2);
    glEnd();
    return this;
}

Quadrado* Quadrado::borda()
{
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
//        glVertex3f(lado*linha,0,lado*coluna);
//        glVertex3f(lado*(linha+1),0,lado*coluna);
//        glVertex3f(lado*(linha+1),0,lado*(coluna+1));
//        glVertex3f(lado*linha,0,lado*(coluna+1));
        glVertex3f(lado/2,0,lado/2);
        glVertex3f(lado/2,0,-lado/2);
        glVertex3f(-lado/2,0,-lado/2);
        glVertex3f(-lado/2,0,lado/2);
    glEnd();
    glLineWidth(1);
    return this;
}


Quadrado* Quadrado::setCor(int r, int g, int b)
{
    cor.setRgb(r,g,b);
    return this;
}

int Quadrado::getCentroX()
{
    return centroX;
}

int Quadrado::getCentroZ()
{
    return centroZ;
}
