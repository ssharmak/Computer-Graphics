#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

GLint xone, yone, xtwo, ytwo;

void resize(int, int);
void setPixel(GLint, GLint);
void lineBres_L1(GLint, GLint, GLint, GLint, GLfloat);
void lineBres_GE1(GLint, GLint, GLint, GLint, GLfloat);
void display();

int main(int argc, char **argv)
{
    printf("******Bresenham's Line Drawing Algorithm******");
    printf("\nEnter starting vertex (x1, y1): ");
    scanf("%d%d", &xone, &yone);
    printf("\nEnter ending vertex (x2, y2): ");
    scanf("%d%d", &xtwo, &ytwo);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(800, 50);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}

void resize(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, w, 0.0, h, -1.0, 1.0);
    glViewport(0, 0, w, h);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat m = (float)(ytwo - yone) / (xtwo - xone);
    if (fabs(m) >= 1)
        lineBres_GE1(xone, yone, xtwo, ytwo, m);
    else
        lineBres_L1(xone, yone, xtwo, ytwo, m);
    glFlush();
}

void lineBres_L1(GLint x0, GLint y0, GLint xEnd, GLint yEnd, GLfloat m)
{
    GLint dx = abs(xEnd - x0);
    GLint dy = abs(yEnd - y0);
    GLint p = 2 * dy - dx;
    GLint twoDy = 2 * dy;
    GLint twoDyMinusDx = 2 * (dy - dx);
    GLint x = x0, y = y0; 
    if (x0 > xEnd)
    {
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    }
    setPixel(x, y);
    while (x < xEnd)
    {
        x++;
        if (p < 0)
        {
            p += twoDy;
        }
        else
        {
            y += (m < 0) ? -1 : 1;
            p += twoDyMinusDx;
        }
        setPixel(x, y);
    }
}

void lineBres_GE1(GLint x0, GLint y0, GLint xEnd, GLint yEnd, GLfloat m)
{
    GLint dx = abs(xEnd - x0);
    GLint dy = abs(yEnd - y0);
    GLint p = 2 * dx - dy;
    GLint twoDx = 2 * dx;
    GLint twoDxMinusDy = 2 * (dx - dy);
    GLint x = x0, y = y0;
    if (y0 > yEnd)
    {
        x = xEnd;
        y = yEnd;
        yEnd = y0;
    }
    setPixel(x, y);
    while (y < yEnd)
    {
        y++;
        if (p < 0)
        {
            p += twoDx;
        }
        else
        {
            x += (m < 0) ? -1 : 1;
            p += twoDxMinusDy;
        }
        setPixel(x, y);
    }
}

void setPixel(GLint xcor, GLint ycor)
{
    glBegin(GL_POINTS);
    glVertex2i(xcor, ycor);
    glEnd();
}
