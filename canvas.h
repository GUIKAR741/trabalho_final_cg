#ifndef CANVAS_H
#define CANVAS_H

#include <QOpenGLWidget>
#include "cena/cena.h"


class Canvas : public QOpenGLWidget
{
    Q_OBJECT
    public:
        Canvas(QWidget *parent);
    public slots:
        void idleGL();
    protected:
        virtual void initializeGL();
        virtual void paintGL();
    private:
        Cena cena;

};

#endif // CANVAS_H
