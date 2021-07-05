#include "quadrado.h"

Quadrado::Quadrado(){

}

Quadrado::Quadrado(int linha, int coluna)
{
    this->linha = linha;
    this->coluna = coluna;
    setLado(1);
}

void Quadrado::desenha()
{
    glPushMatrix();
    glm::vec3 posicao = glm::vec3(centroX, 0, centroZ);
    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, posicao);
    glMultMatrixf(glm::value_ptr(modelMatrix));
    quad()->borda();
    glPopMatrix();
}

Quadrado *Quadrado::quad()
{
    glColor3f(cor.redF(), cor.greenF(), cor.blueF());
    glBegin(GL_QUADS);
        for (int i=0;i<4;i++){
            glVertex3fv(glm::value_ptr(vertices[i]));
        }
    glEnd();
    return this;
}

Quadrado* Quadrado::borda()
{
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        for (int i=0;i<4;i++){
            glVertex3fv(glm::value_ptr(vertices[i]));
        }
    glEnd();
    glLineWidth(1);
    return this;
}


Quadrado* Quadrado::setCor(int r, int g, int b)
{
    cor.setRgb(r,g,b);
    return this;
}

Quadrado *Quadrado::setLado(float lado)
{
    this->lado = lado;
    setCentro(lado * linha + lado/2, lado * coluna + lado/2)->computarVertice();
    return this;
}

Quadrado* Quadrado::setCentro(float centroX, float centroZ)
{
    this->centroX = centroX;
    this->centroZ = centroZ;
    return this;
}

float Quadrado::getCentroX()
{
    return centroX;
}

float Quadrado::getCentroZ()
{
    return centroZ;
}

Quadrado* Quadrado::computarVertice()
{
    vertices[0] = glm::vec3(-lado/2, 0     , -lado/2);
    vertices[1] = glm::vec3(-lado/2, 0     ,  lado/2);
    vertices[2] = glm::vec3( lado/2, 0     ,  lado/2);
    vertices[3] = glm::vec3( lado/2, 0     , -lado/2);
    return this;
}
