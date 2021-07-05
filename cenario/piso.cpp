#include "piso.h"

Piso::Piso()
{
    for(int i=0;i<tamanhoTabuleiro;i++){
        for(int j=0;j<tamanhoTabuleiro;j++){
            this->tabuleiro[i][j] = Quadrado(i,j);
            this->tabuleiro[i][j].setCor(255,0,0);
        }
    }
}

void Piso::desenha()
{
    for(int i=0;i<tamanhoTabuleiro;i++){
        for(int j=0;j<tamanhoTabuleiro;j++){
            tabuleiro[i][j].desenha();
        }
    }
//    glColor3f(0,0,1);
//    glBegin(GL_LINES);
//        glVertex3d(tabuleiro[tamanhoTabuleiro-1][tamanhoTabuleiro-1].getCentroX(), 0,tabuleiro[tamanhoTabuleiro-1][tamanhoTabuleiro-1].getCentroZ());
//        glVertex3d(tabuleiro[tamanhoTabuleiro-1][tamanhoTabuleiro-1].getCentroX(), 1,tabuleiro[tamanhoTabuleiro-1][tamanhoTabuleiro-1].getCentroZ());
//    glEnd();
}
