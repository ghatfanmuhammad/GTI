#include <gl/glut.h>

void Segitiga(void) 
{
    // Membersihkan buffer warna agar layar bersih sebelum digambar
    glClear(GL_COLOR_BUFFER_BIT); 

    // Transformasi: Translasi (geser) lalu Rotasi (putar)
    glTranslatef(0.25, -0.25, 0); 
    glRotated(60.0, 0.0, 0.0, 1.0); 

    // Mulai menggambar objek primitif segitiga
    glBegin(GL_TRIANGLES); 
        glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.05, -0.05, 0.00); 
        glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.15, -0.05, 0.00); 
        glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(-0.05, 0.05, 0.00); 
    glEnd(); 

    // Memastikan perintah segera dieksekusi ke layar
    glFlush(); 
}

int main(int argc, char* argv[]) 
{
    glutInit(&argc, argv); 
    glutInitWindowSize(640, 480); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
    glutCreateWindow("Rotasi Segitiga"); 
    
    glutDisplayFunc(Segitiga); 
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Latar belakang biru
    
    glutMainLoop(); 
    return 0; 
}
