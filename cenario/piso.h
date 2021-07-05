#ifndef PISO_H
#define PISO_H

#include <GL/gl.h>
#include <QDebug>
#include "objetos/quadrado.h"
#include "objetos/cubo.h"
#include "objetos/piramide.h"
#include <glm/vec3.hpp>
#include <glm/gtc/type_ptr.hpp>

#define tamanhoTabuleiro 8

class Piso
{
public:
    Piso();
    void desenha();
private:
    Quadrado tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];
    Cubo cubo;
    Piramide piramide1, piramide2;
};

#endif // PISO_H
