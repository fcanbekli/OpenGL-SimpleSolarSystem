# OpenGL-SimpleSolarSystem
![Alt Text](https://media.giphy.com/media/RfASwDX7J9I0wv5sJb/giphy.gif)

Simple toy project for learn basics of OpenGL. Helpful to learn these consepts
* Scaling
* Basic Rotations
* Drawing and OpenGL Skeleton
* GLFW



This method to draw circles. Step represent number of edges drawn circle have. To have perfect circle increased step number
```
void drawCircle(int steps, float red, float green, float blue) { _// Simple Circle Draw Method._

float radius = 1;

const float angle = 3.1415926*2/steps;

float oldX = 0; **float** oldY = 1;

for(**int** i = 0; i <= steps; i++) {

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
```
