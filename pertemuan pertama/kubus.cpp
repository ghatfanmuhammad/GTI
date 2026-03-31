#include <gl/glut.h>

void drawCube(float x, float y, float size, float r, float g, float b) {
    glColor3f(r, g, b); 
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); 
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    float s = 0.25f;
    float g = 0.01f;

    // Lapis Bawah (3 Kubus)
    drawCube(-(1.5*s + g), -0.5f, s, 0.0f, 0.5f, 1.0f); 
    drawCube(-(0.5*s), -0.5f, s, 0.0f, 0.5f, 1.0f); 
    drawCube(0.5*s + g, -0.5f, s, 0.0f, 0.5f, 1.0f); 

    // Lapis Tengah (2 Kubus)
    drawCube(-(s + 0.5*g), -0.5f + s + g, s, 0.0f, 0.8f, 0.0f); 
    drawCube(0.5*g, -0.5f + s + g, s, 0.0f, 0.8f, 0.0f); 

    // Lapis Atas (1 Kubus)
    drawCube(-0.5*s, -0.5f + 2*(s + g), s, 1.0f, 0.3f, 0.3f); 

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas no 3 - Piramida Kubus");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
