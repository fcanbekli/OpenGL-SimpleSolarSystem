//
//  main.cpp
//  OpenGLProject1
//
//  Created by Fatih Canbekli on 12.05.2019.
//  Copyright © 2019 Fatih Canbekli. All rights reserved.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>

void drawCircle(int steps, float red, float green, float blue) { // Simple Circle Draw Method.
    float radius = 1;
    const float angle = 3.1415926*2/steps;
    float oldX = 0; float oldY = 1;
    for(int i = 0; i <= steps; i++) {
        float newX = radius * sin(angle*i);
        float newY = -radius * cos(angle*i);
        
        glColor3f(red, green, blue);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, 0.f, 0.f);
        glVertex3f(oldX, oldY, 0.f);
        glVertex3f(newX, newY, 0.f);
        glEnd();
        
        oldX = newX;
        oldY = newY;
    }
}

int main(int argc, const char * argv[]) {
    
    GLFWwindow * window;
    if(!glfwInit()){
        std::cout << "Init Error!\n";
        return -1;
    }
    // MARK: - Create New Window with 800 600 Size
    window = glfwCreateWindow(800, 600, "Hello World", 0, 0);
    if(!window){
        std::cout<< "Window Creation Error";
        glfwTerminate(); // Close Window and Shutdown Application
        return -1;
    }
    glfwMakeContextCurrent(window); // OpenGL is a state machine. An OpenGL context holds that state.

    glMatrixMode(GL_MODELVIEW); // glMatrixMode and glLoadIdentitiy means all future updates will effect our model
    glLoadIdentity();
    
    glScalef(0.1, 0.1, 1);
    
    float angleEarth = 0;
    float angleMoon = 0;
    // Rendering Loop, every OpenGL program has event loop.
    while(!glfwWindowShouldClose(window)){
        
        glClearColor(0.0, 0.0, 0.0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // The Sun
        drawCircle(100, 1, 1, 0);
        {
            // The Earth
            glPushMatrix();
            glRotatef(angleEarth, 0, 0, 1); // First rotate then translate!
            glTranslatef(0, 5, 0);
            glScalef(0.6, 0.6, 1);
            drawCircle(100, 0, 0.3, 1);
            angleEarth += 0.1; // Earth Rotation Speed factor
            {
                // The Moon
                glPushMatrix();
                glRotatef(angleMoon, 0, 0, 1);
                glTranslatef(0, 3, 0);
                glScalef(0.5, 0.5, 0.5);
                drawCircle(100, 0.5, 0.5, 0.5);
                glPopMatrix();
                angleMoon +=0.2; // Moon Rotation Speed factor
            }
            glPopMatrix();
        }
        glfwSwapBuffers(window); // Refreshing Screen with teardown (1/60 refresh rate for smooth)
        glfwPollEvents(); // This function processes only those events that are already in the event queue and then returns immediately.
        
    }
    glfwTerminate();
}
