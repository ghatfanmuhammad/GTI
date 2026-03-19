#include <GL/glut.h>
#include <math.h>
void drawFace() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);

    // 1. ALIS/MATA KIRI
    glBegin(GL_POLYGON);
        glVertex2f(-0.7, 0.65); glVertex2f(-0.5, 0.75); glVertex2f(-0.2, 0.7);
        glVertex2f(-0.1, 0.6);  glVertex2f(-0.2, 0.55); glVertex2f(-0.4, 0.6);
        glVertex2f(-0.6, 0.55);
    glEnd();

    // 2. ALIS/MATA KANAN 
    glBegin(GL_POLYGON);
        glVertex2f(0.1, 0.6);   glVertex2f(0.3, 0.8);   glVertex2f(0.6, 0.85);
        glVertex2f(0.8, 0.75);  glVertex2f(0.5, 0.75);  glVertex2f(0.3, 0.6);
        glVertex2f(0.4, 0.3);   glVertex2f(0.35, 0.25); glVertex2f(0.2, 0.5);
    glEnd();

    // 3. HIDUNG
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.15);  glVertex2f(0.4, 0.1);   glVertex2f(0.45, 0.0);
        glVertex2f(0.3, 0.05);  glVertex2f(0.0, 0.08);
    glEnd();

    // 4. BIBIR ATAS
    glBegin(GL_POLYGON);
        glVertex2f(-0.1, -0.2); glVertex2f(0.2, -0.15); glVertex2f(0.5, -0.25);
        glVertex2f(0.6, -0.35); glVertex2f(0.3, -0.32); glVertex2f(0.0, -0.35);
    glEnd();

    // 5. BIBIR BAWAH
    glBegin(GL_POLYGON);
        glVertex2f(-0.1, -0.45); glVertex2f(0.3, -0.4);  glVertex2f(0.6, -0.5);
        glVertex2f(0.5, -0.6);   glVertex2f(0.2, -0.65); glVertex2f(-0.1, -0.55);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Shadow Face Stencil");
    init();
    glutDisplayFunc(drawFace);
    glutMainLoop();
    return 0;
}
