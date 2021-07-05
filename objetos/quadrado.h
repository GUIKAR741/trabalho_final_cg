#ifndef QUADRADO_H
#define QUADRADO_H

#include <QColor>
#include <QDebug>
#include <GL/gl.h>
#include <glm/gtc/type_ptr.hpp>


class Quadrado
{
public:
    Quadrado();
    Quadrado(int linha, int coluna);
    void desenha();
    Quadrado *quad();
    Quadrado* borda();
    Quadrado* setCor(int r, int g, int b);
    Quadrado* setLado(float lado);
    Quadrado* setCentro(float posX, float posZ);
    float getCentroX();
    float getCentroZ();
private:
    Quadrado* computarVertice();
    QColor cor;
    glm::vec3 vertices[4];
    float lado, centroX = 0, centroZ = 0;
    int linha, coluna;
};

#endif // QUADRADO_H
