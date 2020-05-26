#ifndef TREEVIEWER_H
#define TREEVIEWER_H

#include <QObject>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

#include <QKeyEvent>
#include <QMouseEvent>

class TreeViewer:
        public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit TreeViewer(QWidget *parent= nullptr);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    void keyPressEvent(QKeyEvent *e) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
private:
    QOpenGLShaderProgram *program;
};

#endif // TREEVIEWER_H
