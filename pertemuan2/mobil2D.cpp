#include <GL/glut.h>
#include <math.h>
#include <string.h>

// ================= TEXT =================
void tulisTeks(float x, float y, const char* teks) {
    glRasterPos2f(x, y);
    for (int i = 0; i < strlen(teks); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, teks[i]);
    }
}

// ================= LINGKARAN =================
void lingkaran(float x, float y, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float sudut = 2 * 3.1416 * i / 100;
        glVertex2f(x + r * cos(sudut), y + r * sin(sudut));
    }
    glEnd();
}

// ================= POHON =================
void pohon() {
    // Batang
    glColor3f(0.4, 0.2, 0.1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.015, -0.1);
        glVertex2f(0.015, -0.1);
        glVertex2f(0.015, 0.25);
        glVertex2f(-0.015, 0.25);
    glEnd();

    // Daun
    glColor3f(0.0, 0.6, 0.0);
    lingkaran(0, 0.35, 0.1);
    lingkaran(-0.06, 0.28, 0.08);
    lingkaran(0.06, 0.28, 0.08);
}

// ================= GEDUNG DETAIL =================
void gedung(float x, float r, float g, float b, const char* label) {
    glPushMatrix();
    glTranslatef(x, 0, 0);

    // Body
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(-0.3, -0.3);
        glVertex2f(0.3, -0.3);
        glVertex2f(0.3, 0.6);
        glVertex2f(-0.3, 0.6);
    glEnd();

    // Atap
    glColor3f(r - 0.1, g - 0.1, b - 0.1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.3, 0.6);
        glVertex2f(0.3, 0.6);
        glVertex2f(0.3, 0.7);
        glVertex2f(-0.3, 0.7);
    glEnd();

    // Pintu
    glColor3f(0.3, 0.2, 0.1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.05, -0.3);
        glVertex2f(0.05, -0.3);
        glVertex2f(0.05, -0.1);
        glVertex2f(-0.05, -0.1);
    glEnd();

    // Jendela
    glColor3f(0.9, 0.9, 1);
    for (float y = -0.1; y < 0.5; y += 0.15) {
        for (float x = -0.22; x < 0.22; x += 0.1) {
            glBegin(GL_POLYGON);
                glVertex2f(x, y);
                glVertex2f(x + 0.06, y);
                glVertex2f(x + 0.06, y + 0.08);
                glVertex2f(x, y + 0.08);
            glEnd();
        }
    }

    glColor3f(1,1,1);
    tulisTeks(-0.25, 0.62, label);

    glPopMatrix();
}

// ================= AWAN =================
void awan() {
    glColor3f(1,1,1);
    lingkaran(-0.06, 0, 0.08);
    lingkaran(0.06, 0, 0.08);
    lingkaran(0, 0.05, 0.08);
}

// ================= LAMPU =================
void lampu() {
    // Tiang
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
        glVertex2f(-0.01, -0.3);
        glVertex2f(0.01, -0.3);
        glVertex2f(0.01, 0.3);
        glVertex2f(-0.01, 0.3);
    glEnd();

    // Lampu
    glColor3f(1, 1, 0.6);
    lingkaran(0, 0.35, 0.04);
}

// ================= TRUCK =================
void truck() {
    glPushMatrix();

    // Bak belakang
    glColor3f(0.85, 0.4, 0.1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.35, 0.05);
        glVertex2f(0.05, 0.05);
        glVertex2f(0.05, 0.28);
        glVertex2f(-0.35, 0.28);
    glEnd();

    // Garis detail bak
    glColor3f(0.6, 0.3, 0.1);
    for(float y = 0.08; y < 0.25; y += 0.05){
        glBegin(GL_LINES);
            glVertex2f(-0.35, y);
            glVertex2f(0.05, y);
        glEnd();
    }

    // Kepala truck (lebih miring)
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
        glVertex2f(0.05, 0.05);
        glVertex2f(0.22, 0.05);
        glVertex2f(0.2, 0.25);
        glVertex2f(0.05, 0.25);
    glEnd();

    // Kaca
    glColor3f(0.7, 0.9, 1);
    glBegin(GL_POLYGON);
        glVertex2f(0.08, 0.12);
        glVertex2f(0.18, 0.12);
        glVertex2f(0.17, 0.22);
        glVertex2f(0.08, 0.22);
    glEnd();

    // Lampu depan
    glColor3f(1, 1, 0.6);
    lingkaran(0.22, 0.08, 0.015);

    // Roda
    glColor3f(0, 0, 0);
    lingkaran(-0.2, 0, 0.06);
    lingkaran(0.1, 0, 0.06);

    // Velg
    glColor3f(0.7, 0.7, 0.7);
    lingkaran(-0.2, 0, 0.025);
    lingkaran(0.1, 0, 0.025);

    glPopMatrix();
}

// ================= MOBIL =================
void mobil(float r, float g, float b) {
    glPushMatrix();

    // Body bawah
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(-0.18, 0);
        glVertex2f(0.18, 0);
        glVertex2f(0.2, 0.08);
        glVertex2f(-0.2, 0.08);
    glEnd();

    // Body atas (lebih landai)
    glBegin(GL_POLYGON);
        glVertex2f(-0.12, 0.08);
        glVertex2f(0.12, 0.08);
        glVertex2f(0.08, 0.18);
        glVertex2f(-0.08, 0.18);
    glEnd();

    // Kaca depan & belakang
    glColor3f(0.7, 0.9, 1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.1, 0.09);
        glVertex2f(0.1, 0.09);
        glVertex2f(0.07, 0.16);
        glVertex2f(-0.07, 0.16);
    glEnd();

    // Lampu depan
    glColor3f(1, 1, 0.6);
    lingkaran(0.19, 0.04, 0.015);

    // Lampu belakang
    glColor3f(1, 0, 0);
    lingkaran(-0.19, 0.04, 0.015);

    // Roda luar
    glColor3f(0, 0, 0);
    lingkaran(-0.1, -0.02, 0.045);
    lingkaran(0.1, -0.02, 0.045);

    // Velg (dalam roda)
    glColor3f(0.7, 0.7, 0.7);
    lingkaran(-0.1, -0.02, 0.02);
    lingkaran(0.1, -0.02, 0.02);

    glPopMatrix();
}
// ================= DISPLAY =================
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Langit
    glBegin(GL_POLYGON);
        glColor3f(0.2, 0.6, 1.0); glVertex2f(-1, 1);
        glColor3f(0.5, 0.8, 1.0); glVertex2f(1, -0.3);
        glVertex2f(1, 1);
        glVertex2f(-1, -0.3);
    glEnd();

    // Matahari
    glColor3f(1, 0.9, 0);
    lingkaran(0.75, 0.75, 0.2);

    // Awan
    glPushMatrix(); glTranslatef(-0.6, 0.8, 0); awan(); glPopMatrix();
    glPushMatrix(); glTranslatef(0.1, 0.85, 0); awan(); glPopMatrix();
    glPushMatrix(); glTranslatef(0.5, 0.75, 0); awan(); glPopMatrix();

    // Gedung
    gedung(-0.5, 0.5, 0.5, 0.5, "Badan Gizi Nasional");
    gedung(0.4, 0.4, 0.5, 0.4, "DPR RI");

    // Pohon
    for(float x=-0.9; x<=0.9; x+=0.3){
        glPushMatrix();
        glTranslatef(x, -0.3, 0);
        pohon();
        glPopMatrix();
    }

    // Lampu
    for(float x=-0.8; x<=0.8; x+=0.5){
        glPushMatrix();
        glTranslatef(x, 0, 0);
        lampu();
        glPopMatrix();
    }

    // Jalan
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1,-0.3);
        glVertex2f(-1,-0.3);
    glEnd();

    // Garis jalan
    glColor3f(1,1,1);
    for(float x=-0.9; x<1; x+=0.4){
        glBegin(GL_POLYGON);
            glVertex2f(x,-0.62);
            glVertex2f(x+0.15,-0.62);
            glVertex2f(x+0.15,-0.58);
            glVertex2f(x,-0.58);
        glEnd();
    }

    // Kendaraan
    glPushMatrix(); glTranslatef(-0.4, -0.7, 0); truck(); glPopMatrix();
    glPushMatrix(); glTranslatef(0.3, -0.85, 0); mobil(1,0,0); glPopMatrix();
    glPushMatrix(); glTranslatef(0.7, -0.75, 0); mobil(0,0.1,0.8); glPopMatrix();

    glFlush();
}

// ================= INIT =================
void init() {
    glClearColor(0.2, 0.6, 1, 1);
    gluOrtho2D(-1,1,-1,1);
}

// ================= MAIN =================
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,700);
    glutCreateWindow("Lanskap Kota Final");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
