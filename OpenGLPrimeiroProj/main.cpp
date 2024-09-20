#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>

void cubo() {
    glBegin(GL_LINE_LOOP);
        glColor3f(1, 0, 0);
        glVertex3f(-25, -25, -25);    
        glVertex3f(-25, 25, -25);     
        glVertex3f(25, 25, -25);      
        glVertex3f(25, -25, -25);     
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0, 1, 0);
        glVertex3f(-25, -25, -75);    
        glVertex3f(-25, 25, -75);     
        glVertex3f(25, 25, -75);      
        glVertex3f(25, -25, -75);     
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glVertex3f(-25, -25, -25);    
        glVertex3f(-25, -25, -75);
        glVertex3f(-25, 25, -25);     
        glVertex3f(-25, 25, -75);
        glVertex3f(25, 25, -25);      
        glVertex3f(25, 25, -75);
        glVertex3f(25, -25, -25);     
        glVertex3f(25, -25, -75);   
    glEnd();
    
    glFlush();
}

static void teclado(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Explorando glFrustum", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetWindowPos(window, 50, 100);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        // testes de modificacao nos parametros glFrustum (rodando um por vez tirando as //)
         glFrustum(-90, 90, -40, 40, 25, 125); // Aumentar campo horizontal (params 1 e 2)
        // glFrustum(-40, 40, -25, 25, 25, 125); // Diminuir campo vertical (params 3 e 4)
        // glFrustum(-40, 40, -40, 40, 25, 180); // Aumentar far (ultimo parametro)
        // glFrustum(-40, 40, -40, 40, 15, 125); // Aproximar o near (penultimo param)

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(100.0, 100.0, 200.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        cubo();
        glfwSwapBuffers(window);
        glfwPollEvents();
        glfwSetKeyCallback(window, teclado);
    }

    glfwTerminate();
    return 0;
}
