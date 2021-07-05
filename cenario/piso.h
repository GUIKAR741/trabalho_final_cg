#ifndef PISO_H
#define PISO_H

#include <GL/gl.h>
#include <QDebug>
#include "objetos/quadrado.h"

#define tamanhoTabuleiro 8

class Piso
{
public:
    Piso();
    void desenha();
private:
    Quadrado tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];
};

#endif // PISO_H
