#include <iostream>

 // int main(){
 // 	std::cout<< "hello, mingw64, cpp."<<std::endl;
 // 	return 0;
 // }


#if  1
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#define window_width  640
#define window_height 480
// Main loop
void main_loop_function() {
    // Z angle
    static float angle;
    // Clear color (screen)
    // And depth (used internally to block obstructed objects)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Load identity matrix
    glLoadIdentity();
    // Multiply in translation matrix
    glTranslatef(0, 0, -10);
    // Multiply in rotation matrix
    glRotatef(angle, 0, 0, 1);
    // Render colored quad
    glBegin(GL_QUADS);
    glColor3ub(255, 000, 000);
    glVertex2f(-1, 1);
    glColor3ub(000, 255, 000);
    glVertex2f(1, 1);
    glColor3ub(000, 000, 255);
    glVertex2f(1, -1);
    glColor3ub(255, 255, 000);
    glVertex2f(-1, -1);
    glEnd();
    // Swap buffers (color buffers, makes previous render visible)
    glutSwapBuffers();
    // Increase angle to rotate
    angle += 0.25;
}
// Initialze OpenGL perspective matrix
void GL_Setup(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    gluPerspective(45, (float) width / height, .1, 100);
    glMatrixMode(GL_MODELVIEW);
}
// Initialize GLUT and start main loop
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(window_width, window_height);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("GLUT Example!!!");
    glutDisplayFunc(main_loop_function);
    GL_Setup(window_width, window_height);
    glutMainLoop();
}
#endif

#if  0
#include <gl/glut.h>

void Initial(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(50.0f, 100.0f, 150.0f, 50.0f);
	glFlush();
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 120);
	glutCreateWindow("My first OpenGL demo");
	glutDisplayFunc(Display);
	Initial();
	glutMainLoop();

	return 0;
}
#endif
