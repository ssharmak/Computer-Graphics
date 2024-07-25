#include<GL/glut.h>

float object_size=0.2f;
float object_x=0.0f;
float object_y=0.0f;
float velocity_x=0.005f;
float velocity_y=0.005f;

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(object_x-object_size,object_y-object_size);
    glVertex2f(object_x+object_size,object_y-object_size);
    glVertex2f(object_x+object_size,object_y+object_size);
    glVertex2f(object_x-object_size,object_y+object_size);
    glEnd();
    glFlush();
}

void update(int value)
{
    object_x+=velocity_x;
    object_y+=velocity_y;
    if(object_x+object_size>=1.0f||object_x-object_size<=-1.0f)
    {
        velocity_x*=-1;
    }

    if(object_y+object_size>=1.0f||object_y-object_size<=-1.0f)
    {
        velocity_y*=-1;
    }
    glutPostRedisplay();
    glutTimerFunc(30,update,0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Animation Effects");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0,update,0);
    glutMainLoop();
    return 0;
}