#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Header.h"
GLuint VBO; // инициализируем указатель на хранение буфера вершин 

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0); // параметры вершины 
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // массив будет хранить буфер вершин 
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // данные внутри буфера 

    glDrawArrays(GL_POINTS, 0, 1); // функция отрисовки 

    glDisableVertexAttribArray(0); // отключение атрибута вершины 

    glutSwapBuffers();
}


static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer()
{
    Vector3f Vertices[1];
    Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f); // создаем массив и задаем XYZ пон нулям и точка будет в центре экрана 
    
 	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // приготовка к отрисовке, здесь особа не важна 
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); // принимает нахвание цели
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA); // создание окна 
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 02");

    InitializeGlutCallbacks();

    
    GLenum res = glewInit(); //инициализируем GLEW и проверяем на ошибки.
    if (res != GLEW_OK) {
      fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
      return 1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    CreateVertexBuffer();

    glutMainLoop();

    return 0;
}
