#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

#define PI 3.1415926535898

// Fungsi untuk membuat lingkaran yang halus dengan banyak titik [cite: 108-115]
void drawCircle(float x, float y, float radius, int segments = 100) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float angle = 2 * PI * i / segments;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // --- STACK 1: LANGIT (FULL BACKGROUND) --- [cite: 12, 70]
    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(0.7f, 0.8f, 1.0f); // Biru Langit Cerah
            glVertex2f(-1.0f, 1.0f);
            glVertex2f(1.0f, 1.0f);
            glColor3f(0.9f, 0.95f, 1.0f); // Gradasi ke arah bawah
            glVertex2f(1.0f, 0.0f);
            glVertex2f(-1.0f, 0.0f);
        glEnd();
    glPopMatrix();

    // --- STACK 2: AWAN --- [cite: 137]
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        // Awan Kiri
        drawCircle(-0.7f, 0.75f, 0.1f); drawCircle(-0.6f, 0.75f, 0.12f); drawCircle(-0.5f, 0.75f, 0.1f);
        // Awan Kanan
        drawCircle(0.5f, 0.85f, 0.08f); drawCircle(0.6f, 0.85f, 0.1f); drawCircle(0.7f, 0.85f, 0.08f);
    glPopMatrix();

    // --- STACK 3: LAUT & TEBING (BACKGROUND TENGAH) --- [cite: 12, 137]
    glPushMatrix();
        // Laut
        glBegin(GL_QUADS);
            glColor3f(0.4f, 0.5f, 0.9f);
            glVertex2f(-1.0f, 0.0f); glVertex2f(1.0f, 0.0f);
            glVertex2f(1.0f, -0.2f); glVertex2f(-1.0f, -0.2f);
        glEnd();
        // Tebing Cokelat
        glColor3f(0.3f, 0.2f, 0.15f);
        glBegin(GL_POLYGON);
            glVertex2f(0.6f, -0.2f); glVertex2f(1.0f, -0.2f);
            glVertex2f(1.0f, 0.1f); glVertex2f(0.8f, 0.05f);
        glEnd();
    glPopMatrix();

    // --- STACK 4: PADANG RUMPUT (GROUND) --- 
    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(0.2f, 0.6f, 0.2f); // Hijau Tua
            glVertex2f(-1.0f, -0.2f); glVertex2f(1.0f, -0.2f);
            glColor3f(0.4f, 0.8f, 0.3f); // Hijau Muda
            glVertex2f(1.0f, -1.0f); glVertex2f(-1.0f, -1.0f);
        glEnd();
    glPopMatrix();

    // --- STACK 5: MOBIL VAN (OBJEK UTAMA) --- [cite: 16, 137, 138]
    glPushMatrix();
        glTranslatef(-0.1f, -0.3f, 0.0f); // Mengatur posisi mobil di tanah
        
        // Badan Bawah Van
        glColor3f(0.0f, 0.6f, 0.9f); // Biru Terang
        glRectf(-0.6f, -0.3f, 0.6f, 0.15f);
        
        // Atap Putih Van
        glColor3f(0.95f, 0.95f, 0.95f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.58f, 0.15f); glVertex2f(0.58f, 0.15f);
            glVertex2f(0.55f, 0.3f); glVertex2f(-0.55f, 0.3f);
        glEnd();

        // Jendela-jendela (Dibuat smooth)
        glColor3f(0.8f, 0.9f, 1.0f);
        glRectf(-0.5f, 0.0f, -0.15f, 0.2f); // Jendela belakang
        glRectf(-0.1f, 0.0f, 0.25f, 0.2f);  // Jendela tengah
        glBegin(GL_POLYGON); // Jendela Depan (Melengkung)
            glVertex2f(0.3f, 0.0f); glVertex2f(0.55f, 0.0f);
            glVertex2f(0.52f, 0.2f); glVertex2f(0.3f, 0.2f);
        glEnd();

        // Roda (Dibuat sangat halus/smooth)
        glColor3f(0.1f, 0.1f, 0.1f);
        drawCircle(-0.35f, -0.3f, 0.14f, 100); // Roda Belakang
        drawCircle(0.35f, -0.3f, 0.14f, 100);  // Roda Depan
        
        // Velg
        glColor3f(0.4f, 0.4f, 0.4f);
        drawCircle(-0.35f, -0.3f, 0.06f, 50);
        drawCircle(0.35f, -0.3f, 0.06f, 50);
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Full Landscape Van 2D - Smooth Version");
    
    glutDisplayFunc(RenderScene);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    glutMainLoop();
    return 0;
}
