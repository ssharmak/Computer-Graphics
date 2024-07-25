#include<GL/glut.h>
#include<cmath>

float vertices[8][3] = 
{
    {-0.5,-0.5,-0.5},
    {0.5,-0.5,-0.5},
    {0.5,0.5,-0.5},
    {-0.5,0.5,-0.5},
    {-0.5,-0.5,0.5},
    {0.5,-0.5,0.5},
    {0.5,0.5,0.5},
    {-0.5,0.5,0.5}
};

float translation[3] = {0.9f,1.5f,0.0f};
float rotationAngleDegrees = 45.0f;
float rotationAxis[3] = {0.0f,1.0f,0.0f};
float scale[3] = {1.3f,1.0f,1.0f};

void drawCube()
{
    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[3]);

    // Back face 
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[7]);

    // Top face 
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[7]);

    // Bottom face
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[4]);

    // Right face
    glColor3f(0.0f,1.0f,1.0f);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[2]);

    // Left face
    glColor3f(1.0f,0.0f,1.0f);
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[3]);

    glEnd();
}

void applyTransformations()
{
    // Translation
    for (int i = 0 ;i < 9; i++)
    {
        vertices[i][0] += translation[0];
        vertices[i][1] += translation[1];
        vertices[i][2] += translation[2];
    }

    // Rotation
    float angleRadians = rotationAngleDegrees * (M_PI / 180.f);
    float cosAngle = cos(angleRadians);
    float sinAngle = sin(angleRadians);
    for(int i = 0; i < 8; ++i)
    {
        float x = vertices[i][0];
        float y = vertices[i][1];
        float z = vertices[i][2];
        vertices[i][0] = x* (cosAngle + (1 - cosAngle) * rotationAxis[0] * rotationAxis[0]) + 
                         y* ((1-cosAngle) * rotationAxis[0] * rotationAxis[1] - sinAngle * rotationAxis[2]) +
                         z* ((1-cosAngle) * rotationAxis[0] * rotationAxis[2] + sinAngle * rotationAxis[1]);
        vertices[i][1] = x* ((1-cosAngle) * rotationAxis[1] * rotationAxis[0] + sinAngle * rotationAxis[2]) +
                         y* (cosAngle + (1 - cosAngle) * rotationAxis[1] * rotationAxis[1]) +
                         z* ((1-cosAngle) * rotationAxis[1] * rotationAxis[2] - sinAngle * rotationAxis[0]);
        vertices[i][2] = x* ((1-cosAngle) * rotationAxis[2] * rotationAxis[0] - sinAngle * rotationAxis[1]) +
                         y* ((1-cosAngle) * rotationAxis[2] * rotationAxis[1] + sinAngle * rotationAxis[0]) + 
                         z* (cosAngle + (1 - cosAngle) * rotationAxis[2] * rotationAxis[2]);
    }
    //Scaling 
    for(int i = 0; i < 8; ++i)
    {
        vertices[i][0] *= scale[0];
        vertices[i][1] *= scale[1];
        vertices[i][2] *= scale[2];
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
    drawCube();
    applyTransformations();
    drawCube();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,double(width)/double(height),1.0,100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("Basic geometric operations on cube");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0,0.0,0.0,1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

