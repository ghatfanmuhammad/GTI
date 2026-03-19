#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated; // [cite: 93]

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // [cite: 94]
    glLoadIdentity(); // [cite: 96]
    
    glTranslatef(0.0, 0.0, -4.0); // [cite: 97]
    glRotatef(xRotated, 1.0, 0.0, 0.0); // [cite: 98]
    glRotatef(yRotated, 0.0, 1.0, 0.0); // [cite: 99]
    glRotatef(zRotated, 0.0, 0.0, 1.0); // [cite: 100]
    
    glScalef(2.0, 1.0, 1.0); // [cite: 101]
    glutWireCube(1.0); // [cite: 102]
    
    glutSwapBuffers(); // [cite: 103]
    glFlush(); // [cite: 104]
}

void Reshape(int x, int y) {
    if (y == 0 || x == 0) return; // [cite: 106]
    
    glMatrixMode(GL_PROJECTION); // [cite: 108]
    glLoadIdentity(); // [cite: 109]
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0); // [cite: 110]
    glMatrixMode(GL_MODELVIEW); // [cite: 111]
    glViewport(0, 0, x, y); // [cite: 113]
}

void Idle(void) {
    xRotated += 0.3; // [cite: 115]
    yRotated += 0.1; // [cite: 116]
    zRotated += -0.4; // [cite: 118]
    Display(); // [cite: 119]
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); // [cite: 121]
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // [cite: 122]
    glutInitWindowSize(300, 300); // [cite: 123]
    glutCreateWindow("Cube example"); // [cite: 124]
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // [cite: 125]
    xRotated = yRotated = zRotated = 0.0; // [cite: 126]
    glClearColor(0.0, 0.0, 0.0, 0.0); // [cite: 127]
    
    glutDisplayFunc(Display); // [cite: 128]
    glutReshapeFunc(Reshape); // [cite: 129]
    glutIdleFunc(Idle); // [cite: 131]
    
    glutMainLoop(); // [cite: 130]
    return 0;
}
