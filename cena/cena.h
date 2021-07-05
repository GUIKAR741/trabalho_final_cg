#ifndef CENA_H
#define CENA_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "cenario/piso.h"

class Cena
{
public:
    Cena(float h, float w);
    Cena();
    void desenha();
private:
    float h,w;
    void projecao();
    void visualizacao();
    Piso piso;

};

#endif // CENA_H
