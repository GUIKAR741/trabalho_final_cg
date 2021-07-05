#ifndef CUBO_H
#define CUBO_H

#include <QColor>
#include <QDebug>
#include <GL/gl.h>
#include <glm/gtc/type_ptr.hpp>

class Cubo
{
public:
    Cubo();
    float getLado();
    Cubo* setLado(float lado);
    Cubo* setPos(float posX, float posZ);
    void desenha();
private:
    float lado, posX = 0, posZ = 0;
    glm::vec3 vertices[8];
    int faces[6][4];
    QColor corFace[6];
    Cubo* cube();
    Cubo* borda();
    Cubo* computarFaces();
    Cubo* setFace(int face, int v1, int v2, int v3, int v4);
    Cubo* computarVertices();
};

#endif // CUBO_H
