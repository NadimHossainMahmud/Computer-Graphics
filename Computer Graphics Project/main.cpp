#include <windows.h>
#include <GL/glut.h>
#include <math.h>
# define PI 3.14159265358979323846



float sr=133;///sky Color
float sg=204;
float sb=250;
float mr=255;///moon and sun
float mg=255;
float mb=0;
float br= 130;
float bg= 150;
float bb= 137;

GLfloat positionRL = 0.0f;
GLfloat speedRL = 0.05f;
GLfloat m = 0.0f;


void updateRL(int value) {

    if(positionRL <-2.0)
        positionRL = 1.0f;

    positionRL -= speedRL;

	glutPostRedisplay();


	glutTimerFunc(100, updateRL, 0);
}

GLfloat positionLR = 0.0f;
GLfloat speedLR = 0.05f;
void updateLR(int value) {

    if(positionLR >4.0)
        positionLR = -1.0f;

    positionLR += speedLR;
	glutPostRedisplay();


	glutTimerFunc(100, updateLR, 0);
}


GLfloat ship_position = 0.0f;
GLfloat ship_speed = 0.1f;
void ship_update(int value) {

    if(ship_position <-3.0)
        ship_position = 2.0f;

    ship_position -= ship_speed;

	glutPostRedisplay();


	glutTimerFunc(100, ship_update, 0);
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void bench()
{
    	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3f(0.6f, 0.0f, 0.0f);
	glVertex2f(-0.2f, 0.1f);
	glVertex2f(-0.1f, 0.0f);
	glVertex2f(0.4f, 0.0f);
	glVertex2f(0.3f, 0.1f);
	glEnd();

	glLineWidth(6.0);

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.6f, 0.0f, 0.0f);
	glVertex2f(-0.19f, 0.1f);
	glVertex2f(-0.19f, -0.1f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.6f, 0.0f, 0.0f);
	glVertex2f(-0.09f, 0.0f);
	glVertex2f(-0.09f, -0.2f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.6f, 0.0f, 0.0f);
	glVertex2f(0.29f, 0.1f);
	glVertex2f(0.29f, -0.1f);

	glEnd();
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.6f, 0.0f, 0.0f);
	glVertex2f(0.39f, 0.0f);
	glVertex2f(0.39f, -0.2f);
	glEnd();

}
void tree()
{

    glPushMatrix();
    glTranslatef(-0.2,0,0);
    glPushMatrix();
    glScalef(0.4,0.4,0);
	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3f(0.6f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.4f);
	glVertex2f(0.0f, -0.5f);
	glVertex2f(0.08f, -0.5f);
	glVertex2f(0.08f, 0.4f);
	glEnd();

    glBegin(GL_TRIANGLES);//
    glColor3ub(0, 179,44);//rgb color picker

    glVertex2f(-.2f, -0.01f);
	glVertex2f(+0.28f, -0.01f);
	glVertex2f(+.04f, 0.6f);
	glEnd();

	glBegin(GL_TRIANGLES);//
    glColor3ub(13,239, 66);//rgb color picker

    glVertex2f(-.15f, .25f);    // x, y
	glVertex2f(+0.22f,.25f);
	glVertex2f(+.04f, 0.8f);
	glEnd();
	glPopMatrix();
	glPopMatrix();
}
void forest()
{
    tree();
	glPushMatrix();
	glScalef(0.5f,0.5f,0);
	glTranslatef(-0.6f,0.0f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.8f,0.6f,0);
	glTranslatef(-0.2f,-0.1f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.8f,0.8f,0);
	glTranslatef(-0.4f,0.0f,0);
	tree();
	glPopMatrix();
}
void railline()
{
    glPushMatrix();
    glTranslatef(0,-0.4,0);
    glPushMatrix();
    for(float i=-1;i<1;i+=0.06){
        glColor3ub(120,54,5);
        glBegin(GL_POLYGON);
        glVertex2f(0.02+i,-0.33f);
        glVertex2f(0.02+i,-0.31f);
        glVertex2f(0.06f+i,-0.31f);
        glVertex2f(0.06f+i,-0.33f);
        glEnd();

        glColor3ub(153,153,153);
        glBegin(GL_POLYGON);
        glVertex2f(0.029f+i,-0.33f);
        glVertex2f(0.051f+i,-0.33f);
        glVertex2f(0.051f+i,-0.42f);
        glVertex2f(0.029f+i,-0.42f);
        glEnd();


        glColor3ub(120,54,5);
        glBegin(GL_POLYGON);
        glVertex2f(0.02f+i,-0.44f);
        glVertex2f(0.02f+i,-0.42f);
        glVertex2f(0.06f+i,-0.42f);
        glVertex2f(0.06f+i,-0.44f);
        glEnd();

    }


glPopMatrix();
glPopMatrix();

}

void train()
{
     //train start
    glPushMatrix();

    glTranslatef(positionLR,0.0f, 0.0f);
    glPushMatrix();
    glScalef(0.6,0.6,0);
    glTranslatef(-0.6,-0.4f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0,0.5f,0.3f);
    glVertex2f(-0.1,-0.5);
    glVertex2f(-0.1,-0.7);
    glVertex2f(0.1,-0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0.5f,0.3f);
    glVertex2f(-0.9,-0.5);
    glVertex2f(-0.1,-0.5);
    glVertex2f(-0.1,-0.7);
    glVertex2f(-0.9,-0.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f,0,0);
    glVertex2f(-0.5,-0.3);
    glVertex2f(-0.1,-0.3);
    glVertex2f(-0.1,-0.5);
    glVertex2f(-0.5,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f,0,0);
    glVertex2f(-0.9,-0.1);
    glVertex2f(-0.5,-0.1);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.9,-0.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(-0.8,-0.2);
    glVertex2f(-0.6,-0.2);
    glVertex2f(-0.6,-0.4);
    glVertex2f(-0.8,-0.4);
    glEnd();

    //train end
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-1.0,0.0);
    glVertex2f(-0.4,0.0);
    glVertex2f(-0.4,-0.1);
    glVertex2f(-1.0,-0.1);
    glEnd();

    //wheel
   glPushMatrix();

    glColor3ub(0,0,0);
    glTranslatef(-0.2f,-0.7f, 0.0f);
    glutSolidSphere(0.06, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(-0.7f,-0.7f, 0.0f);
    glutSolidSphere(0.06, 50, 50);
    glPopMatrix();
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.97,0.0,0);
	glPushMatrix();
	glScalef(1.6,1.6,0);
    glPushMatrix();
        glBegin(GL_POLYGON);
     glColor3ub(0,43,85);
                glVertex2f(-0.2f,-0.38f);
                glVertex2f(-0.57f,-0.38f);
                glVertex2f(-0.6f,-0.41f);
                glVertex2f(-0.2f,-0.41f);
        glEnd();
       glBegin(GL_POLYGON);
     glColor3ub(0,43,85);
                glVertex2f(-0.2f,-0.38f);
                glVertex2f(-0.57f,-0.38f);
                glVertex2f(-0.57f,-0.32f);
                glVertex2f(-0.2f,-0.32f);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3ub(255,255,255);
                glVertex2f(-0.2f,-0.32f);
                glVertex2f(-0.57f,-0.32f);
                glVertex2f(-0.56f,-0.30f);
                glVertex2f(-0.2f,-0.30f);
        glEnd();
    glPopMatrix();
glPushMatrix();
    glBegin(GL_POLYGON);
        glColor3ub(153,0,79);
        glVertex2f(-0.2f,-0.40f);
        glVertex2f(-0.2f,-0.385f);
        glVertex2f(-0.18f,-0.385f);
        glVertex2f(-0.18f,-0.40f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(153,0,79);
        glVertex2f(0.22f,-0.40f);
        glVertex2f(0.22f,-0.385f);
        glVertex2f(0.24f,-0.385f);
        glVertex2f(0.24f,-0.40f);
    glEnd();
    glPushMatrix();
    glTranslatef(0.42f,0,0);
 glBegin(GL_POLYGON);
        glColor3ub(153,0,79);
        glVertex2f(0.21f,-0.40f);
        glVertex2f(0.21f,-0.385f);
        glVertex2f(0.249f,-0.385f);
        glVertex2f(0.249f,-0.40f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glBegin(GL_POLYGON);
     glColor3ub(0,97,0);
                    glVertex2f(0.22f,-0.41f);
                    glVertex2f(-0.18f,-0.41f);
                    glVertex2f(-0.18f,-0.30f);
                    glVertex2f(0.22f,-0.30f);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glBegin(GL_POLYGON);
     glColor3ub(237,237,237);
                    glVertex2f(0.24f,-0.41f);
                    glVertex2f(0.64f,-0.41f);
                    glVertex2f(0.64f,-0.30f);
                    glVertex2f(0.24f,-0.30f);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        for(float i=0.15;i<0.5;i+=0.05){
            glBegin(GL_POLYGON);
            glColor3ub(0,0,0);
                glVertex2f(-0.702+i,-0.373);
                glVertex2f(-0.678+i,-0.373);
                glVertex2f(-0.678+i,-0.327);
                glVertex2f(-0.702+i,-0.327);
            glEnd();
        }
        for(float i=0.15;i<0.5;i+=0.05){
            glBegin(GL_POLYGON);
     glColor3ub(br,bg,bb);
                glVertex2f(-0.7f+i,-0.37);
                glVertex2f(-0.68f+i,-0.37f);
                glVertex2f(-0.68f+i,-0.33f);
                glVertex2f(-0.7f+i,-0.33f);
            glEnd();
        }
    glPopMatrix();
    glPushMatrix();
        for(float i=0.54;i<0.92;i+=0.05){
            glBegin(GL_POLYGON);
            glColor3ub(0,0,0);
                glVertex2f(-0.702f+i,-0.373f);
                glVertex2f(-0.68f+i,-0.373f);
                glVertex2f(-0.68f+i,-0.327f);
                glVertex2f(-0.702f+i,-0.327f);
            glEnd();
        }
        for(float i=0.54;i<0.92;i+=0.05){
            glBegin(GL_POLYGON);
     glColor3ub(br,bg,bb);
                glVertex2f(-0.7+i,-0.37f);
                glVertex2f(-0.68+i,-0.37f);
                glVertex2f(-0.68+i,-0.33f);
                glVertex2f(-0.7+i,-0.33f);
            glEnd();
        }
    glPopMatrix();
    glPushMatrix();
        for(float i=0.96;i<1.34;i+=0.05){
            glBegin(GL_POLYGON);
                glColor3ub(0,0,0);
                glVertex2f(-0.702+i,-0.373);
                glVertex2f(-0.68+i,-0.373f);
                glVertex2f(-0.68+i,-0.327f);
                glVertex2f(-0.702+i,-0.327f);
            glEnd();
        }
        for(float i=0.96;i<1.34;i+=0.05){
            glBegin(GL_POLYGON);
     glColor3ub(br,bg,bb);
                glVertex2f(-0.7+i,-0.37);
                glVertex2f(-0.68+i,-0.37f);
                glVertex2f(-0.68+i,-0.33f);
                glVertex2f(-0.7+i,-0.33f);
            glEnd();
        }
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(-0.53,-0.41, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(-0.27,-0.41, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(-0.11,-0.41, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(0.15,-0.41, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(0.31f,-0.41f, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
    glPushMatrix();
           glColor3ub(0,0,0);
           glTranslatef(0.57f,-0.41f, 0.0f);
           glutSolidSphere(0.02, 50, 50);
    glPopMatrix();
glPopMatrix();
glPopMatrix();
	glPopMatrix();
}
void sky()
{
      glBegin(GL_QUADS);
	glColor3ub(sr, sg, sb);

	glVertex2f(-0.999f, 1.0f);
	glVertex2f(-0.999f, 0.2f);
	glVertex2f(0.999f, 0.2f);
	glVertex2f(0.999f, 1.0f);

	glEnd();
}
void lake()
{
      glBegin(GL_QUADS);
	glColor3ub(sr, sg, sb);

	glVertex2f(-0.999f, 1.0f);
	glVertex2f(-0.999f, 0.2f);
	glVertex2f(0.999f, 0.2f);
	glVertex2f(0.999f, 1.0f);

	glEnd();
}

void ship()
{
    glPushMatrix();
    glTranslatef(ship_position,0.0f, 0.0f);
    glBegin(GL_QUADS);             // ship
    glColor3ub(78,78,76);
    glVertex2f(0.8f, 0.65f);
    glVertex2f(0.5f, 0.8f);
    glVertex2f(2.2f, 0.8f);
    glVertex2f(2.2f, 0.65f);
    glEnd();



    glBegin(GL_QUADS);             // ship 1st deck
    glColor3ub(146,134,134);
    glVertex2f(0.8f, 0.95f);
    glVertex2f(0.8f, 0.8f);
    glVertex2f(2.0f, 0.8f);
    glVertex2f(2.0f, 0.95f);
    glEnd();



    glBegin(GL_QUADS);             // ship 2nd deck
    glColor3ub(137,124,111);
    glVertex2f(1.1f, 1.1f);
    glVertex2f(1.0f, 0.95f);
    glVertex2f(2.0f, 0.95f);
    glVertex2f(2.0f, 1.1f);
    glEnd();



    glBegin(GL_QUADS);             // 1st chim
    glColor3ub(0,65,80);
    glVertex2f(1.2f, 1.3f);
    glVertex2f(1.2f, 1.1f);
    glVertex2f(1.3f, 1.1f);
    glVertex2f(1.3f, 1.3f);
    glEnd();



    glBegin(GL_QUADS);             // 2nd chim
    glColor3ub(0,65,80);
    glVertex2f(1.5f, 1.3f);
    glVertex2f(1.5f, 1.1f);
    glVertex2f(1.6f, 1.1f);
    glVertex2f(1.6f, 1.3f);
    glEnd();



    glBegin(GL_QUADS);             // 3rd chim
    glColor3ub(0,65,80);
    glVertex2f(1.8f, 1.3f);
    glVertex2f(1.8f, 1.1f);
    glVertex2f(1.9f, 1.1f);
    glVertex2f(1.9f, 1.3f);
    glEnd();




    glBegin(GL_QUADS);             // window1
    glColor3ub(255,255,0);
    glVertex2f(1.2f, 1.06f);
    glVertex2f(1.2f, 0.98f);
    glVertex2f(1.3f, 0.98f);
    glVertex2f(1.3f, 1.06f);
    glEnd();



    glBegin(GL_QUADS);             // window2
    glColor3ub(255,255,0);
    glVertex2f(1.5f, 1.06f);
    glVertex2f(1.5f, 0.98f);
    glVertex2f(1.6f, 0.98f);
    glVertex2f(1.6f, 1.06f);
    glEnd();



    glBegin(GL_QUADS);             // window1
    glColor3ub(255,255,0);
    glVertex2f(1.8f, 1.06f);
    glVertex2f(1.8f, 0.98f);
    glVertex2f(1.9f, 0.98f);
    glVertex2f(1.9f, 1.06f);
    glEnd();
    glPopMatrix();
}

void ground()
{
      glBegin(GL_QUADS);
	glColor3f(0.0f,0.4f, 0.0f);

	glVertex2f(-0.999f, 0.2f);
	glVertex2f(-0.999f, -0.3f);
	glVertex2f(0.999f, -0.3f);
	glVertex2f(0.999f, 0.2f);

	glEnd();
}
void footpath()
{
      glBegin(GL_QUADS);
	glColor3f(0.8f, 0.4f, 0.0f);

	glVertex2f(-0.999f, -0.3f);
	glVertex2f(-0.999f, -0.4f);
	glVertex2f(0.999f, -0.4f);
	glVertex2f(0.999f, -0.3f);

	glEnd();
}

void road()
{
      glBegin(GL_QUADS);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(-0.999f, -0.4f);
	glVertex2f(-0.999f, -1.0f);
	glVertex2f(0.999f, -1.0f);
	glVertex2f(0.999f, -0.4f);

	glEnd();


}
void pole()
{
    glPushMatrix();
    glTranslatef(-0.74, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(0.01f, 0.2f);
	glVertex2f(0.01f, -0.2f);
	glVertex2f(0.03f, -0.2f);
	glVertex2f(0.03f, 0.2f);
	glEnd();
	glPopMatrix();

}
void lightbox()
{
 glPushMatrix();
    glTranslatef(-0.79, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.09f, 0.05f);
	glVertex2f(0.09f, -0.1f);
	glVertex2f(0.05f, -0.1f);
	glVertex2f(0.05f, 0.05f);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.72, 0.02f, 0.0f);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.0,1.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.016;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.72, -0.02f, 0.0f);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,0.4,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.016;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.72, -0.06f, 0.0f);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.016;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();


}
void sunmoon()
{
    glPushMatrix();
	glTranslatef(-0.72, 0.8f, 0.0f);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(mr,mg,mb);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.1;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	glPopMatrix();
}

void car()
{
    glPushMatrix();
	glTranslatef(positionRL, 0.2f, 0.0f);
    glPushMatrix();
	glTranslatef(-0.3, -0.6f, 0.0f);
    glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.0f, 0.0f);

	glVertex2f(0.05f, 0.2f);
	glVertex2f(0.05f, 0.12f);
	glVertex2f(0.6f, 0.12f);
	glVertex2f(0.6f, 0.25f);
	glVertex2f(0.18f, 0.25f);

	glEnd();

	glLineWidth(9.0);

	glBegin(GL_LINES);
	glColor3f(0.8f, 0.0f, 0.1f);
	glVertex2f(0.18f, 0.24f);
	glVertex2f(0.25f, 0.32f);

	glEnd();

    glLineWidth(9.0);

	glBegin(GL_LINES);
	glColor3f(0.8f, 0.0f, 0.1f);
	glVertex2f(0.25f, 0.32f);
	glVertex2f(0.5f, 0.32f);
	glEnd();

	glLineWidth(9.0);

	glBegin(GL_LINES);
	glColor3f(0.8f, 0.0f, 0.1f);
	glVertex2f(0.5f, 0.32f);
	glVertex2f(0.53f, 0.24f);
	glEnd();

	glLineWidth(9.0);

	glBegin(GL_LINES);
	glColor3f(0.8f, 0.0f, 0.1f);
	glVertex2f(0.35f, 0.32f);
	glVertex2f(0.37f, 0.24f);
	glEnd();

	glPopMatrix();


//tire
glLineWidth(7.5);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3ub(0, 0, 0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.07;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(-0.1+x,-0.5+y);
}
glEnd();

                         //tire
glLineWidth(7.5);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3ub(0, 0, 0);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.07;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(0.2+x,-0.5+y);
}
glEnd();

    glPopMatrix();

}
void building()
{
    glTranslatef(0.4, -0.2f, 0.0f);
     glBegin(GL_QUADS);
	glColor3f(1.0f, 0.8f, 0.0f);

	glVertex2f(-0.3f, 1.0f);
	glVertex2f(-0.3f, -0.1f);
	glVertex2f(0.3f, -0.1f);
	glVertex2f(0.3f, 1.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.3f, 0.0f);

	glVertex2f(-0.1f, 1.0f);
	glVertex2f(-0.1f, -0.1f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, 1.0f);

	glEnd();


	glLineWidth(1.0);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.1f);
	glVertex2f(-0.3f, 0.20f);
	glVertex2f(0.3f, 0.20f);

	glEnd();

	glLineWidth(1.0);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.1f);
	glVertex2f(-0.3f, 0.4f);
	glVertex2f(0.3f, 0.4f);

	glEnd();

	glLineWidth(1.0);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.1f);
	glVertex2f(-0.3f, 0.6f);
	glVertex2f(0.3f, 0.6f);
	glEnd();


	glLineWidth(1.0);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.1f);
	glVertex2f(-0.3f, 0.8f);
	glVertex2f(0.3f, 0.8f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.2f, 0.0f, 0.0f);

	glVertex2f(-0.1f, 0.1f);
	glVertex2f(-0.1f, -0.1f);
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.1f, 0.1f);

	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-0.09f, 0.09f);
	glVertex2f(-0.09f, -0.1f);
	glVertex2f(0.09f, -0.1f);
	glVertex2f(0.09f, 0.09f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(-0.23f, 0.27f);
	glVertex2f(-0.23f, 0.34f);
	glVertex2f(-0.17f, 0.34f);
	glVertex2f(-0.17f, 0.27f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(-0.23f, 0.47f);
	glVertex2f(-0.23f, 0.54f);
	glVertex2f(-0.17f, 0.54f);
	glVertex2f(-0.17f, 0.47f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(-0.23f, 0.67f);
	glVertex2f(-0.23f, 0.74f);
	glVertex2f(-0.17f, 0.74f);
	glVertex2f(-0.17f, 0.67f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(-0.23f, 0.87f);
	glVertex2f(-0.23f, 0.94f);
	glVertex2f(-0.17f, 0.94f);
	glVertex2f(-0.17f, 0.87f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(0.23f, 0.27f);
	glVertex2f(0.23f, 0.34f);
	glVertex2f(0.17f, 0.34f);
	glVertex2f(0.17f, 0.27f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(0.23f, 0.47f);
	glVertex2f(0.23f, 0.54f);
	glVertex2f(0.17f, 0.54f);
	glVertex2f(0.17f, 0.47f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(0.23f, 0.67f);
	glVertex2f(0.23f, 0.74f);
	glVertex2f(0.17f, 0.74f);
	glVertex2f(0.17f, 0.67f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);

	glVertex2f(0.23f, 0.87f);
	glVertex2f(0.23f, 0.94f);
	glVertex2f(0.17f, 0.94f);
	glVertex2f(0.17f, 0.87f);

	glEnd();

}

void scene3()
{

     glClearColor(0.0f, 0.6f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glLoadIdentity();
	glLineWidth(4.5);

	glPushMatrix();
	glTranslatef(-0.05f,0.44,0);
	glScalef(0.5f,0.5f,0);
	// Station Right
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(128, 128, 0); // Red
	glVertex2f(0.8f, -0.3f);    // x, y
	glVertex2f(0.8f, -1.2f);    // x, y
    glVertex2f(1.9f, -1.2f);    // x, y
    glVertex2f(1.9f, -0.3f);    // x, y

	glEnd();

    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(1.9f, -0.5f);

	glEnd();

    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(1.3f, -0.5f);
	glVertex2f(1.3f, -1.2f);

	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0, 0, 255);
	glVertex2f(1.45f, -0.7f);    // x, y
	glVertex2f(1.45f, -1.2f);    // x, y
    glVertex2f(1.75f, -1.2f);    // x, y
    glVertex2f(1.75f, -0.7f);    // x, y

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.3f, -1.05f);
	glVertex2f(1.45f, -1.05f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.75f, -1.05f);
	glVertex2f(1.9f, -1.05f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.3f, -1.0f);
	glVertex2f(1.45f, -1.0f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.75f, -1.0f);
	glVertex2f(1.9f, -1.0f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.3f, -0.95f);
	glVertex2f(1.45f, -0.95f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.75f, -0.95f);
	glVertex2f(1.9f, -0.95f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.3f, -0.90f);
	glVertex2f(1.45f, -0.90f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.75f, -0.90f);
	glVertex2f(1.9f, -0.90f);

	glEnd();

    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.3f, -0.90f);
	glVertex2f(1.3f, -1.05f);

	glEnd();

     glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.9f, -0.90f);
	glVertex2f(1.9f, -1.05f);

	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0, 0, 255);
	glVertex2f(0.8f, -1.1f);    // x, y
	glVertex2f(1.3f, -1.1f);    // x, y
    glVertex2f(1.3f, -1.0f);    // x, y
    glVertex2f(0.8f, -1.0f);    // x, y

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.85f, -1.1f);    // x, y
	glVertex2f(0.85f, -1.2f);    // x, y
    glVertex2f(0.9f, -1.2f);    // x, y
    glVertex2f(0.9f, -1.1f);    // x, y

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.2f, -1.1f);    // x, y
	glVertex2f(1.2f, -1.2f);    // x, y
    glVertex2f(1.25f, -1.2f);    // x, y
    glVertex2f(1.25f, -1.1f);    // x, y

	glEnd();

    glBegin(GL_QUADS);
	glColor3f(128,0,0);
	glVertex2f(0.81f, -1.2f);    // x, y
	glVertex2f(0.81f, -1.3f);    // x, y
    glVertex2f(1.89f, -1.3f);    // x, y
    glVertex2f(1.89f, -1.2f);    // x, y

	glEnd();

    //Rail Station Left

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(128, 128, 0);
	glVertex2f(-0.8f, -0.3f);    // x, y
	glVertex2f(-0.8f, -1.2f);    // x, y
    glVertex2f(-1.9f, -1.2f);    // x, y
    glVertex2f(-1.9f, -0.3f);    // x, y

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-1.9f, -0.5f);
    glEnd();

    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-1.3f, -0.5f);
	glVertex2f(-1.3f, -1.2f);

	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0, 0, 255);
	glVertex2f(-1.45f, -0.7f);    // x, y
	glVertex2f(-1.45f, -1.2f);    // x, y
    glVertex2f(-1.75f, -1.2f);    // x, y
    glVertex2f(-1.75f, -0.7f);    // x, y

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.3f, -1.05f);
	glVertex2f(-1.45f, -1.05f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.75f, -1.05f);
	glVertex2f(-1.9f, -1.05f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.3f, -1.0f);
	glVertex2f(-1.45f, -1.0f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.75f, -1.0f);
	glVertex2f(-1.9f, -1.0f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.3f, -0.95f);
	glVertex2f(-1.45f, -0.95f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.75f, -0.95f);
	glVertex2f(-1.9f, -0.95f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.3f, -0.90f);
	glVertex2f(-1.45f, -0.90f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.75f, -0.90f);
	glVertex2f(-1.9f, -0.90f);

	glEnd();

    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.3f, -0.90f);
	glVertex2f(-1.3f, -1.05f);

	glEnd();

     glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.9f, -0.90f);
	glVertex2f(-1.9f, -1.05f);

	glEnd();

    glBegin(GL_QUADS);
	glColor3f(0, 0, 255);
	glVertex2f(-0.8f, -1.1f);    // x, y
	glVertex2f(-1.3f, -1.1f);    // x, y
    glVertex2f(-1.3f, -1.0f);    // x, y
    glVertex2f(-0.8f, -1.0f);    // x, y

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.85f, -1.1f);    // x, y
	glVertex2f(-0.85f, -1.2f);    // x, y
    glVertex2f(-0.9f, -1.2f);    // x, y
    glVertex2f(-0.9f, -1.1f);    // x, y

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.2f, -1.1f);    // x, y
	glVertex2f(-1.2f, -1.2f);    // x, y
    glVertex2f(-1.25f, -1.2f);    // x, y
    glVertex2f(-1.25f, -1.1f);    // x, y

	glEnd();

    glBegin(GL_QUADS);
	glColor3f(128,0,0);
	glVertex2f(-0.81f, -1.2f);    // x, y
	glVertex2f(-0.81f, -1.3f);    // x, y
    glVertex2f(-1.89f, -1.3f);    // x, y
    glVertex2f(-1.89f, -1.2f);    // x, y

	glEnd();



    //Road.........

    glBegin(GL_QUADS);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex2f(-1.9f, 0.0f);    // x, y
	glVertex2f(1.9f, 0.0f);    // x, y
    glVertex2f(1.9f, 0.7f);    // x, y
    glVertex2f(-1.9f, 0.7f);    // x, y

	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(-1.8f, 0.3f);    // x, y
	glVertex2f(-1.3f, 0.3f);    // x, y
    glVertex2f(-1.3f, 0.4f);    // x, y
    glVertex2f(-1.8f, 0.4f);    // x, y

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(-1.0f, 0.3f);    // x, y
	glVertex2f(-.5f, 0.3f);    // x, y
    glVertex2f(-.5f, 0.4f);    // x, y
    glVertex2f(-1.0f, 0.4f);    // x, y

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(-0.1f, 0.3f);    // x, y
	glVertex2f(.4f, 0.3f);    // x, y
    glVertex2f(.4f, 0.4f);    // x, y
    glVertex2f(-0.1f, 0.4f);    // x, y

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(0.8f, 0.3f);    // x, y
	glVertex2f(1.3f, 0.3f);    // x, y
    glVertex2f(1.3f, 0.4f);    // x, y
    glVertex2f(0.8f, 0.4f);    // x, y

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex2f(1.3f, -0.3f);    // x, y
	glVertex2f(1.9f, -0.3f);    // x, y
    glVertex2f(1.9f, -0.0f);    // x, y
    glVertex2f(1.3f, -0.0f);    // x, y

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(1.5f, -0.1f);    // x, y
	glVertex2f(1.5f, -0.3f);    // x, y
    glVertex2f(1.6f, -0.3f);    // x, y
    glVertex2f(1.6f, -0.1f);    // x, y

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex2f(-1.3f, -0.3f);    // x, y
	glVertex2f(-1.9f, -0.3f);    // x, y
    glVertex2f(-1.9f, -0.0f);    // x, y
    glVertex2f(-1.3f, -0.0f);    // x, y

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(-1.5f, -0.1f);    // x, y
	glVertex2f(-1.5f, -0.3f);    // x, y
    glVertex2f(-1.6f, -0.3f);    // x, y
    glVertex2f(-1.6f, -0.1f);    // x, y

	glEnd();


	//Tree.......

	glBegin(GL_QUADS);
	glColor3f(128, 0, 0);
	glVertex2f(1.05f, -0.2f);    // x, y
	glVertex2f(1.05f, -0.3f);    // x, y
    glVertex2f(1.15f, -0.3f);    // x, y
    glVertex2f(1.15f, -0.2f);    // x, y

	glEnd();


    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.0f);

    glVertex2f(1.1f, -0.05f);
    glVertex2f(0.95f, -0.2f);    // x, y
	glVertex2f(1.25f, -0.2f);    // x, y

	glEnd();
	glPopMatrix();
	glPushMatrix();
	glScalef(1.9,0.38f,0);
	glTranslatef(0.0f,2.0f,0);
	sky();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f,0.4,0);
	railline();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f,0.3,0);
	train();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f,-1.6f,0);
	lake();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.7f,0.8f,0);
	glTranslatef(0.0f,-1.8f,0);
	ship();
	glPopMatrix();


	glFlush();
}

void scene2()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    //sky
    glBegin(GL_QUADS);
    glColor3ub(sr,sg,sb);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,0.0);
    glVertex2f(-1.0,0.0);
    glEnd();

    //grass
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex2f(-1.0,-0.5);
    glVertex2f(1.0,-0.5);
    glVertex2f(1.0,-1.0);
    glVertex2f(-1.0,-1.0);
    glEnd();

    //field
    glBegin(GL_QUADS);
    glColor3ub(205,105,0);
    glVertex2f(-1.0,0.1);
    glVertex2f(1.0,0.1);
    glVertex2f(1,.0-0.5);
    glVertex2f(-1.0,-0.5);
    glEnd();


    //station start
    glBegin(GL_QUADS);
    glColor3ub(90,60,0);
    glVertex2f(-0.2,0.4);
    glVertex2f(0.8,0.4);
    glVertex2f(0.8,-0.1);
    glVertex2f(-0.2,-0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0.2,0.1);
    glVertex2f(0.4,0.1);
    glVertex2f(0.4,-0.1);
    glVertex2f(0.2,-0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-0.1,0.3);
    glVertex2f(0.1,0.3);
    glVertex2f(0.1,0.1);
    glVertex2f(-0.1,0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(0.5,0.3);
    glVertex2f(0.7,0.3);
    glVertex2f(0.7,0.1);
    glVertex2f(0.5,0.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.3);

    glVertex2f(-0.1,0.2);
    glVertex2f(0.1,0.2);

    glVertex2f(0.6,0.1);
    glVertex2f(0.6,0.3);

    glVertex2f(0.5,0.2);
    glVertex2f(0.7,0.2);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,100,153);
    glVertex2f(-0.2,0.5);
    glVertex2f(0.8,0.5);
    glVertex2f(0.8,0.4);
    glVertex2f(-0.2,0.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,153);
    glVertex2f(-0.2,0.5);
    glVertex2f(-0.3,0.4);
    glVertex2f(-0.2,0.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,153);
    glVertex2f(0.8,0.5);
    glVertex2f(0.8,0.4);
    glVertex2f(0.9,0.4);
    glEnd();



	//birds
    glPushMatrix();
    glTranslatef(positionRL,0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0,0,0);

    glVertex2f(0.7,0.7);
    glVertex2f(0.8,0.8);

    glVertex2f(0.7,0.7);
    glVertex2f(0.6,0.8);

    glVertex2f(0.4,0.8);
    glVertex2f(0.5,0.9);

    glVertex2f(0.4,0.8);
    glVertex2f(0.3,0.9);

    glEnd();
    glPopMatrix();

   //windmill
	glBegin(GL_QUADS);
    glColor3ub(96,96,96);
    glVertex2f(-0.75,0.5);
    glVertex2f(-0.65,0.5);
    glVertex2f(-0.65,0.1);
    glVertex2f(-0.75,0.1);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.7,0.5,0.0);
    glScalef(0.5,0.5,0.5);
    glRotatef(m,0.0,0.0,0.1);

    glBegin(GL_QUAD_STRIP);
    glColor3ub(192,192,192);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.1,0.2);
    glVertex2f(0.1,0.2);
    glVertex2f(0.0,0.5);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(192,192,192);
    glVertex2f(0.0,0.0);
    glVertex2f(0.2,0.1);
    glVertex2f(0.2,-0.1);
    glVertex2f(0.5,0.0);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(192,192,192);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,-0.2);
    glVertex2f(-0.1,-0.2);
    glVertex2f(0.0,-0.5);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(192,192,192);
    glVertex2f(0.0,0.0);
    glVertex2f(-0.2,0.1);
    glVertex2f(-0.2,-0.1);
    glVertex2f(-0.5,0.0);
    glEnd();

    glPopMatrix();//glPopMatrix pops the top matrix off the stack
    m-=0.01f;//i=i+.1=.2


    tree();
    glPushMatrix();
	glScalef(0.5f,0.5f,0);
	glTranslatef(-0.6f,0.0f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.8f,0.6f,0);
	glTranslatef(-0.2f,-0.1f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.45,0,0);
	forest();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.1,0,0);
	forest();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.45,-0.2,0);
	forest();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.8f,0.8f,0);
	glTranslatef(-0.4f,0.0f,0);
	tree();
	glPopMatrix();
    sunmoon();
    railline();
    glPushMatrix();
    glTranslatef(0,-0.1,0);
    train();
    glPopMatrix();
	glFlush();
}

void scene1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	sky();
	ground();
	glPushMatrix();
	glScalef(0.7f,0.7f,0);
	glTranslatef(-0.9f,0.1f,0);
	building();
	glPopMatrix();
	tree();
	glPushMatrix();
	glScalef(0.5f,0.5f,0);
	glTranslatef(-0.6f,0.0f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.8f,0.6f,0);
	glTranslatef(-0.2f,-0.1f,0);
	tree();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.8f,0.8f,0);
	glTranslatef(-0.4f,0.0f,0);
	tree();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.1,0,0);
	forest();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.2,0,0);
	forest();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.7f,0.7f,0);
	glTranslatef(-1.6f,0.0f,0);
	building();
	glPopMatrix();
	road();
	footpath();
	pole();
	lightbox();
	glPushMatrix();
	glScalef(0.3f,0.3f,0);
	glTranslatef(-1.4f,-0.8f,0);
	bench();
	glPopMatrix();
	sunmoon();
	building();
	car();
	glPushMatrix();
	glTranslatef(-0.4,0.1,0);
	railline();
	glPopMatrix();
	train();
	glFlush();

}



void keyboard(unsigned char key, int x, int y) {

    switch(key){

      case 'n':///

                {
                sr=0;///sky night
                sg=0;
                sb=100;
                mr=255;///moon
                mg=255;
                mb=255;
                }
                break;

        case 'd':
                {

                 sr=133;///sky day
                 sg=204;
                 sb=250;
                 mr=255;///sun
                 mg=255;
                 mb=0;
               }
            break;
        case 'p':
                 speedLR = 0.0f;
                 break;
        case 'r':
                 speedLR = 0.1f;
                 break;

        case 'l':
			speedLR += 0.1f;
			break;
        case 'j':
			if (speedLR>=0.1)
	           speedLR -= 0.1f;
	           else speedLR == 0.1;
	           break;
        case 'z':
			   glutDisplayFunc(scene3);
			   glutPostRedisplay();
	           break;
        case 'x':
			   glutDisplayFunc(scene1);
			   glutPostRedisplay();
	           break;
         case 'c':
			   glutDisplayFunc(scene2);
			   glutPostRedisplay();
	           break;
            }

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("Railway System");
	glutInitWindowSize(320, 320);// Set the window's initial width & height
	glutKeyboardFunc(keyboard);
    glutDisplayFunc(scene3);
    glutIdleFunc(Idle);
	glutTimerFunc(100, updateRL, 0);
	glutTimerFunc(100, updateLR, 0);
	glutTimerFunc(100, ship_update, 0);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
