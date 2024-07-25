#include <GL/glut.h> 
#include <cmath> 
float squareX = 0.0f;
float squareY = 0.0f;
float squareSize = 0.2f;
float rotationAngleDegrees = 45.0f;
float rotationAngleRadians = rotationAngleDegrees * (M_PI / 180.0f);

void drawSquare(float x, float y, float size) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();
} 

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    drawSquare(squareX, squareY, squareSize);

    glColor3f(0.0f, 1.0f, 0.0f);
    drawSquare(squareX + 0.5f, squareY, squareSize);

    glColor3f(0.0f, 0.0f, 1.0f);
    drawSquare(squareX, squareY + 0.5f, squareSize * 2);

    float cosAngle = cos(rotationAngleRadians);
    float sinAngle = sin(rotationAngleRadians);

    float centerX = squareX + squareSize / 2.0f;
    float centerY = squareY + squareSize / 2.0f;

    float vertices[8] = {
        squareX, squareY,
        squareX + squareSize, squareY,
        squareX + squareSize, squareY + squareSize,
        squareX, squareY + squareSize
    };

    for (int i = 0; i < 8; i += 2) {
        float x = vertices[i] - centerX;
        float y = vertices[i + 1] - centerY;
        vertices[i] = x * cosAngle - y * sinAngle + centerX;
        vertices[i + 1] = x * sinAngle + y * cosAngle + centerY;
    }

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    for (int i = 0; i < 8; i += 2) {
        glVertex2f(vertices[i] + 0.5f, vertices[i + 1] + 0.4f);
    }
    glEnd();
    glutSwapBuffers();
}

void reshapeWindow(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Basic Geometric Operations");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshapeWindow);
    glutMainLoop();
    return 0;
}
