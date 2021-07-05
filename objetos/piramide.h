#ifndef PIRAMIDE_H
#define PIRAMIDE_H

#include <QColor>
#include <QDebug>
#include <GL/gl.h>
#include <glm/gtc/type_ptr.hpp>

class Piramide
{
public:
    Piramide();
    Piramide(float posX, float posZ);
    void desenha();
    Piramide* setLado(float lado);
    Piramide* setPos(float posX, float posZ);
    float getLado();
private:
    void computarVertice();
    Piramide* pyramid();
    Piramide* borda();
    QColor corFace[5];
    glm::vec3 base[4];
    glm::vec3 topo;
    float lado, posX = 0, posZ = 0;
};

#endif // PIRAMIDE_H
