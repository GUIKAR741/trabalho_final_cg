#include "piso.h"

Piso::Piso()
{
    for(int i=0;i<tamanhoTabuleiro;i++){
        for(int j=0;j<tamanhoTabuleiro;j++){
            this->tabuleiro[i][j] = Quadrado(i,j);
            this->tabuleiro[i][j].setCor(255,0,0)->setLado(4);
        }
    }
    cubo.setLado(3);
    piramide1.setLado(3);
    piramide2.setLado(3);
}

void Piso::desenha()
{
    for(int i=0;i<tamanhoTabuleiro;i++){
        for(int j=0;j<tamanhoTabuleiro;j++){
            tabuleiro[i][j].desenha();
        }
    }
    cubo.setPos(tabuleiro[7][7].getCentroX(), tabuleiro[7][7].getCentroZ())->desenha();
    piramide1.setPos(tabuleiro[0][0].getCentroX(), tabuleiro[0][0].getCentroZ())->desenha();
    piramide2.setPos(tabuleiro[7][3].getCentroX(), tabuleiro[7][3].getCentroZ())->desenha();
}
