#include "piramide.h"

Piramide::Piramide(){
    setLado(1);
    corFace[0].setRgb(255,0,0);
    corFace[1].setRgb(255,127,0);
    corFace[2].setRgb(191,255,0);
    corFace[3].setRgb(0,255,0);
    corFace[4].setRgb(0,255,255);
}

void Piramide::desenha()
{
    glPushMatrix();
    glm::vec3 posicao = glm::vec3(posX, 0, posZ);
    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, posicao);
    glMultMatrixf(glm::value_ptr(modelMatrix));
    pyramid()->borda();
    glPopMatrix();
}

Piramide* Piramide::setPos(float posX, float posZ)
{
    this->posX = posX;
    this->posZ = posZ;
    return this;
}

Piramide* Piramide::setLado(float lado)
{
    this->lado = lado;
    computarVertice();
    return this;
}

float Piramide::getLado()
{
    return lado;
}

void Piramide::computarVertice()
{
    base[0] = glm::vec3(-lado/2, 0     , -lado/2);
    base[1] = glm::vec3(-lado/2, 0     ,  lado/2);
    base[2] = glm::vec3( lado/2, 0     ,  lado/2);
    base[3] = glm::vec3( lado/2, 0     , -lado/2);
    topo    = glm::vec3( 0     , lado/2,  0);
}

Piramide *Piramide::pyramid()
{
    glColor3f(corFace[0].redF(), corFace[0].greenF(), corFace[0].blueF());
    glBegin(GL_QUADS);
        for(int i=0;i<4;i++){
            glVertex3fv(glm::value_ptr(base[i]));
        }
    glEnd();
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLES);
        glColor3f(corFace[1].redF(), corFace[1].greenF(), corFace[1].blueF());
        glVertex3fv(glm::value_ptr(topo));
        glVertex3fv(glm::value_ptr(base[1]));
        glVertex3fv(glm::value_ptr(base[0]));

        glColor3f(corFace[2].redF(), corFace[2].greenF(), corFace[2].blueF());
        glVertex3fv(glm::value_ptr(base[3]));
        glVertex3fv(glm::value_ptr(topo));
        glVertex3fv(glm::value_ptr(base[0]));

        glColor3f(corFace[3].redF(), corFace[3].greenF(), corFace[3].blueF());
        glVertex3fv(glm::value_ptr(topo));
        glVertex3fv(glm::value_ptr(base[1]));
        glVertex3fv(glm::value_ptr(base[2]));

        glColor3f(corFace[4].redF(), corFace[4].greenF(), corFace[4].blueF());
        glVertex3fv(glm::value_ptr(topo));
        glVertex3fv(glm::value_ptr(base[2]));
        glVertex3fv(glm::value_ptr(base[3]));
    glEnd();
    return this;
}

Piramide *Piramide::borda()
{
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<4;i++){
            glVertex3fv(glm::value_ptr(base[i]));
        }

        glVertex3fv(glm::value_ptr(topo));
        glVertex3fv(glm::value_ptr(base[1]));
        glVertex3fv(glm::value_ptr(base[0]));

        glVertex3fv(glm::value_ptr(base[3]));
        glVertex3fv(glm::value_ptr(topo));
        glVertex3fv(glm::value_ptr(base[0]));

        glVertex3fv(glm::value_ptr(topo));
        glVertex3fv(glm::value_ptr(base[1]));
        glVertex3fv(glm::value_ptr(base[2]));

        glVertex3fv(glm::value_ptr(topo));
        glVertex3fv(glm::value_ptr(base[2]));
        glVertex3fv(glm::value_ptr(base[3]));
    glEnd();
    glLineWidth(1);
    return this;
}
