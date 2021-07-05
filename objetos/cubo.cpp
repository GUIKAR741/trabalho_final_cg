#include "cubo.h"

Cubo::Cubo()
{
    setLado(1);
    computarFaces();
}

float Cubo::getLado()
{
    return lado;
}

Cubo* Cubo::setLado(float lado)
{
    this->lado = lado;
    computarVertices();
    return this;
}

Cubo* Cubo::setPos(float posX, float posZ)
{
    this->posX = posX;
    this->posZ = posZ;
    return this;
}

void Cubo::desenha()
{
    glPushMatrix();
    glm::vec3 posicao = glm::vec3(posX, lado/4, posZ);
    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, posicao);
    glMultMatrixf(glm::value_ptr(modelMatrix));
    cube();
    borda();
    glPopMatrix();
}

Cubo* Cubo::cube()
{
    glBegin(GL_QUADS);
        for(int i=0;i<6;i++){
            glColor3f(corFace[i].redF(), corFace[i].greenF(), corFace[i].blueF());
            for(int j=0;j<4;j++){
               glVertex3fv(glm::value_ptr(vertices[faces[i][j]]));
            }
        }
    glEnd();
    return this;
}

Cubo *Cubo::borda()
{
    glColor3f(0,0,0);
    glLineWidth(2);
    for(int j=0;j<6;j++){
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<4;i++){
           glVertex3fv(glm::value_ptr(vertices[faces[j][i]]));
        }
        glEnd();
    }
    glLineWidth(1);
    return this;
}


Cubo* Cubo::computarFaces()
{
    setFace(0,3,0,1,2); corFace[0].setRgb(255,0,0);
    setFace(1,7,4,0,3); corFace[1].setRgb(255,127,0);
    setFace(2,4,5,6,7); corFace[2].setRgb(191,255,0);
    setFace(3,5,1,2,6); corFace[3].setRgb(0,255,0);
    setFace(4,2,3,7,6); corFace[4].setRgb(0,255,255);
    setFace(5,4,5,1,0); corFace[5].setRgb(0,0,255);
    return this;
}

Cubo* Cubo::setFace(int face, int v1, int v2, int v3, int v4)
{
    faces[face][0] = v1;
    faces[face][1] = v2;
    faces[face][2] = v3;
    faces[face][3] = v4;
    return this;
}

Cubo* Cubo::computarVertices()
{
    vertices[0] = glm::vec3(-lado/2, -lado/4, -lado/2);
    vertices[1] = glm::vec3( lado/2, -lado/4, -lado/2);
    vertices[2] = glm::vec3( lado/2,  lado/4, -lado/2);
    vertices[3] = glm::vec3(-lado/2,  lado/4, -lado/2);
    vertices[4] = glm::vec3(-lado/2, -lado/4,  lado/2);
    vertices[5] = glm::vec3( lado/2, -lado/4,  lado/2);
    vertices[6] = glm::vec3( lado/2,  lado/4,  lado/2);
    vertices[7] = glm::vec3(-lado/2,  lado/4,  lado/2);
    return this;
}
