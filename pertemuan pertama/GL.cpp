#include <gl/glut.h>

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. GL_LINE_STRIP 
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f); 
        glVertex2f(-0.9f, 0.8f);
        glVertex2f(-0.7f, 0.9f);
        glVertex2f(-0.5f, 0.8f);
    glEnd();

    // 2. GL_LINE_LOOP 
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(-0.3f, 0.8f);
        glVertex2f(-0.1f, 0.9f);
        glVertex2f(0.1f, 0.8f);
        glVertex2f(-0.1f, 0.7f);
    glEnd();
    // 3. GL_TRIANGLE_STRIP 
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f); 
        glVertex2f(0.4f, 0.8f);
        glVertex2f(0.5f, 0.9f);
        glVertex2f(0.6f, 0.8f);
        glVertex2f(0.7f, 0.9f);
    glEnd();
    // 4. GL_TRIANGLE_FAN 
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex2f(-0.7f, 0.3f); 
        glVertex2f(-0.8f, 0.5f);
        glVertex2f(-0.6f, 0.5f);
        glVertex2f(-0.5f, 0.4f);
    glEnd();
    // 5. GL_QUADS 
    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 1.0f); 
        glVertex2f(-0.1f, 0.3f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(0.2f, 0.5f);
        glVertex2f(-0.1f, 0.5f);
    glEnd();
    // 6. GL_QUAD_STRIP
    glBegin(GL_QUAD_STRIP);
        glColor3f(1.0f, 0.5f, 0.0f); // Oranye
        glVertex2f(0.5f, 0.3f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.7f, 0.3f);
        glVertex2f(0.7f, 0.5f);
        glVertex2f(0.9f, 0.3f);
        glVertex2f(0.9f, 0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas Primitif OpenGL - No 1");
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
//opan