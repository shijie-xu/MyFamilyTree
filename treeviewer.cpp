#include "treeviewer.h"
#include <QDebug>

TreeViewer::TreeViewer(QWidget *parent)
{

}

void TreeViewer::initializeGL()
{
    initializeOpenGLFunctions();

    QOpenGLShader *vshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    const char *vsrc={
        "void main(){\n"
        "gl_Position=vec4(0.0,0.0,0.0,1.0);\n"
        "}"
    };
    vshader->compileSourceCode(vsrc);

    QOpenGLShader *fshader = new QOpenGLShader(QOpenGLShader::Fragment, this);

    const char *fsrc =
            "void main() {                              \n"
            "   gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
            "}                                          \n";
    fshader->compileSourceCode(fsrc);

    program = new QOpenGLShaderProgram;
    program->addShader(vshader);
    program->addShader(fshader);
    program->link();
    program->bind();
}

void TreeViewer::paintGL()
{
    glDrawArrays(GL_POINTS, 0,1);
}

void TreeViewer::resizeGL(int w, int h)
{

}

void TreeViewer::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Space){
        qDebug() << "You pressed space";
    }
}

void TreeViewer::mousePressEvent(QMouseEvent *ev)
{
    qDebug() << "You clicked";
    this->setFocus();
}

void TreeViewer::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug() << ev->pos().x() << ev->pos().y();
}
