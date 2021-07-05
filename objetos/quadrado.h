#ifndef QUADRADO_H
#define QUADRADO_H

#include <QColor>
#include <QDebug>
#include <GL/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Quadrado
{
public:
    Quadrado();
    Quadrado(int linha, int coluna);
    Quadrado* desenha();
    Quadrado *quad();
    Quadrado* borda();
    Quadrado* setCor(int r, int g, int b);
    int getCentroX();
    int getCentroZ();
private:
    QColor cor;
    int centroX, centroZ;
    int lado = 4, linha, coluna;
};

#endif // QUADRADO_H
