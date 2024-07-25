#include <GL/glut.h>

float angle = 0.0f;
float scale = 1.0f;
float x_transition = 0.0f;
float y_transition = 0.0f;

void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(x_transition,y_transition,1.0f);
    glRotatef(angle,0.0f,0.0f,1.0f);
    glScalef(scale, scale, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(-0.1f, -0.1f);
    glEnd();
    glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'r': angle += 5.0f;
                    break;
        case 'R': angle -= 5.0f;
                    break;
        case 's': scale += 0.1f;
                    break;
        case 'S': scale -= 0.1f;
                    break;
        case 'x': x_transition += 0.1f;
                    break;
        case 'X': x_transition -= 0.1f;
                    break;
        case 'y': y_transition += 0.1f;
                    break;
        case 'Y': y_transition -= 0.1f;
                    break;
        case 27 : exit(0);
                    break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow(" 2d Geometrics");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}
