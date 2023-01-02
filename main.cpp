#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <windows.h>
#include <math.h>

void display();
void reshape(int w,int h);
void keyboard(unsigned char Key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);
void texture();
void timer(int t);

float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0,angle=0.0;
int translateX=0,translateY=0, translateZ=0;

void idleFunc (void)
{
zRotated += 1;
yRotated += 1;
glutPostRedisplay();// redisplay
}

void init(){
    glClearColor(0.0,0.0,0.0,1.0);
}
///////////////////////////////////////////////////////////onmouseclick\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
void OnMouseClick(int button, int state, int x, int y)
{//the object is translated forward when we click left button
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
    if(translateZ<14){

        translateZ++;

      }
  }
  // the object is translated backward when we click right button
  if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
     if(translateZ>-24){

        translateZ--;

      }

  }
}

void keyboard(unsigned char Key, int x, int y){

    switch(Key){  // the object is translated right when we press d
        case 'c' : if(translateX<14){
                     translateX++;
                   }
        break;
                   // the object is translated left when we press a
        case 'h' : if(translateX>-17){
                     translateX--;
                   }
        break;
                  // the object is translated upward when we press w
        case 'r' : if(translateY<13){
                     translateY++;
                   }
        break;
                  // the object is translated downward when we press s
        case 'i' : if(translateY>-10){
                     translateY--;
                   }
        break;
                   // the object is translated forward when we press x
        case 's' :  if(translateZ<12){
                     translateZ++;
                   }
        break;
                // the object is translated backward when we press z
        case 't' : if(translateZ>-24){
                     translateZ--;
                   }
        break;
                 //to enter full screen mode
        case 'm' : glutFullScreen();
        break;
               //when esc is pressed the project is terminated
        case 27 : exit(0);
        break;
    }
}

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200,50);//set the window position with respect to screen size
    glutInitWindowSize(1000,1000);//set window size with respect to screen size
    glutCreateWindow("Merry_Christmas");// change window name
    glutDisplayFunc(display);//call display function which contain all objects
    glutReshapeFunc(reshape);//call reshape function which
    glutKeyboardFunc(keyboard);//call keyboard to move input
    glutMouseFunc(OnMouseClick);//call mouse function to get input from mouse and move object
    glutTimerFunc(0,timer,0);// used form auto animation
    glutIdleFunc (idleFunc);// used for rotation and redisplay
    sndPlaySound("C:\\Users\\B-One\\Desktop\\sara\\12project\\Christmas.wav",SND_ASYNC);//play the music
    init();//set color of back ground
    texture();//set texture and lightning of 3D objects

    glutMainLoop();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//depth is used to create 3D objects
            glLoadIdentity();
 //----------------------------------------------------------snowmanMAN--------------------------------------------
            // head.
            glColor3f(0.7450980392,0.9411764706,0.8901960784);//set color of snowman
            glPushMatrix();//push the coordinates to a matrix to make the object appear
            //set the position of snowman's head and move it using variables translate X,Y,Z
            glTranslatef(1.5+translateX, 1.3+translateY, -15.0+translateZ);
            glutSolidSphere(0.64, 20, 20);//draw sphere
            glPopMatrix();//pops the coordinates to a matrix to make the object appear
           //upper body.
            glColor3f(0.7450980392,0.9411764706,0.8901960784);//set color of snowman
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            //set the position of snowman's upper body and move it using variables translate X,Y,Z
            glTranslatef(1.5+translateX,0.0+translateY,-15.2+translateZ);
            glutSolidSphere(1,20,20);//draw sphere
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear
            //  lower body.
            glColor3f(0.7450980392,0.9411764706,0.8901960784);//set color of snowman
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            //set the position of snowman's lower body and move it using variables translate X,Y,Z
            glTranslatef(1.5+translateX,-1.85+translateY,-15.2+translateZ);
            glutSolidSphere(1.5,20,20);//draw sphere
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear
            //left eye.
            glColor3f (0, 0,0);//set color of snowman's eye
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            //set the position of snowman's left eye and move it using variables translate X,Y,Z
            glTranslatef(1.2+translateX, 1.3+translateY, -14.5+translateZ);
            glutSolidSphere(0.1,20,20);//draw sphere
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear
            // right eye
            glColor3f (0, 0, 0);//set color of snowman's eye
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            //set the position of snowman's right eye and move it using variables translate X,Y,Z
            glTranslatef(1.8+translateX, 1.3+translateY, -14.5+translateZ);
            glutSolidSphere(0.1,20,20);//draw sphere
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear
//------------------------------------------------------TREE----------------------------------------------------------
           // the first lower cone of the tree
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            glTranslatef(-1.0,-1.0,-4.5);//set  position
            glColor3f(0.0, 1.0, 0.0);
            glRotatef(-90.0, 1,0,0);
            glRotatef(zRotated, 0,0,1);
            glScalef(1.0,1.0,1.0);
            glutSolidCone(0.555,0.9,20,20);//draw cone
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

            // the second lower cone of the tree
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            glTranslatef(-1.0,-0.62,-4.5);//set  position
            glColor3f(0.0, 1.0, 0.0);
            glRotatef(-90.0, 1,0,0);
            glRotatef(zRotated, 0,0,1);
            glScalef(1.0,1.0,1.0);
            glutSolidCone(0.45,0.9,20,20);//draw cone
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

            // the third lower cone of the tree
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            glTranslatef(-1.0,-0.25,-4.5);//set  position
            glColor3f(0.0, 1.0, 0.0);
            glRotatef(-90.0, 1,0,0);
            glRotatef(zRotated, 0,0,1);
            glScalef(1.0,1.0,1.0);
            glutSolidCone(0.35,0.9,20,20);//draw cone
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

            // the upper cone of the tree
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            glTranslatef(-1.0,0.1,-4.5);//set  position
            glColor3f(0.0, 1.0, 0.0);
            glRotatef(-90.0, 1,0,0);
            glRotatef(zRotated, 0,0,1);
            glScalef(1.0,1.0,1.0);
            glutSolidCone(0.29,0.7,20,20);//draw cone
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

            //star
            glPushMatrix(); //push the coordinates to a matrix to make the object appear
            glTranslatef(-1.0,0.9,-4.5);//set  position
            glRotatef(zRotated, 0,1,0);//used for rotation
            glColor3f(1.0, 1.0, 0.0);//set color of star
            glScalef(0.2,0.2,0.2);//set its scale
            glutSolidIcosahedron();//draw star on tree
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

            // red present
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            glColor3f(1.0, 0.0, 0.0);//set color of present
            glTranslatef(-0.5,-0.9,-3.5);//set  position
            glRotatef(40, 0,1,0);//used for rotation
            glutSolidCube(0.3);//draw cube
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            glColor3f(0.0, 1.0, 1.0);//set color of present
            glTranslatef(-0.5,-0.9,-3.5);//set  position
            glRotatef(60, 0,1,0);//used for rotation
            glutSolidCube(0.3);//draw cube
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

             // blue present
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            glColor3f(0.0, 0.0, 1.0);//set color of present
            glTranslatef(-1.2,-0.9,-3.5);//set  position
            glRotatef(40, 0,1,0);//used for rotation
            glutSolidCube(0.29);//draw cube
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            glColor3f(0.890196, 0.16862, 1.0);//set color of present
            glTranslatef(-1.2,-0.9,-3.5);//set  position
            glRotatef(60, 0,1,0);//used for rotation
            glutSolidCube(0.29);//draw cube
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

            // middle present
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            glColor3f(0.168627, 1.0, 0.4470588235);//set color of present
            glTranslatef(-0.9,-1.0,-3.4);//set  position
            glRotatef(40, 0,1,0);//used for rotation
            glutSolidCube(0.28);//draw cube
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            glColor3f(1.0, 1.0, 0.0);//set color of present
            glTranslatef(-0.9,-1.0,-3.4);//set  position
            glRotatef(60, 0,1,0);//used for rotation
            glutSolidCube(0.28);//draw cube
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

//-------------------------------------------------SKY--------------------------------------------
           //moon
            glPushMatrix();//push the coordinates to a matrix to make the object appear
            glColor3f(1,1,1);//set color moon
            glTranslated(-1.8,2,-4.5);//set  position
            glRotatef(60.0, 0,0,1);//used for rotation
            glRotatef(zRotated, 0,1,0);//used for rotation
            glutSolidSphere(0.3,20,30);//draw sphere
            glPopMatrix();//pops the coordinates to a matrix to make the object appear

            //star 1
            glPushMatrix();//push the coordinates to a matrix to make the object appear
            glColor3f(1.0,1.0,1.0);//set color of star
            glTranslated(5.0,6.0,-10.0);//set  position
            glScalef(0.2,0.2,0.2);//set its scale
            glutSolidTetrahedron();//draw star
            glPopMatrix();//pops the coordinates to a matrix to make the object appear

            // star 2
            glPushMatrix();//push the coordinates to a matrix to make the object appear
            glColor3f(1.0,1.0,1.0);//set color of star
            glTranslated(3.0,6,-10.0);//set  position
            glScalef(0.2,0.2,0.2);//set its scale
            glutSolidTetrahedron();//draw star
            glPopMatrix();//pops the coordinates to a matrix to make the object appear

            // star 3
            glPushMatrix();//push the coordinates to a matrix to make the object appear
            glColor3f(1.0,1.0,1.0);//set color of star
            glTranslated(-6.0,3,-10.0);//set  position
            glScalef(0.2,0.2,0.2);//set its scale
            glutSolidTetrahedron();//draw star
            glPopMatrix();//pops the coordinates to a matrix to make the object appear

            // star 4
            glPushMatrix();//push the coordinates to a matrix to make the object appear
            glColor3f(1.0,1.0,1.0);//set color of star
            glTranslated(-3.0,5,-10.0);//set  position
            glScalef(0.2,0.2,0.2);//set its scale
            glutSolidTetrahedron();//draw star
            glPopMatrix();//pops the coordinates to a matrix to make the object appear

            // star 5
            glPushMatrix();//push the coordinates to a matrix to make the object appear
            glColor3f(1.0,1.0,1.0);//set color of star
            glTranslated(1.0,3,-10.0);//set  position
            glScalef(0.2,0.2,0.2);//set its scale
            glutSolidTetrahedron();//draw star
            glPopMatrix();//pops the coordinates to a matrix to make the object appear

            // star 6
            glPushMatrix();//push the coordinates to a matrix to make the object appear
            glColor3f(1.0,1.0,1.0);//set color of star
            glTranslated(-6,7,-10.0);//set  position
            glScalef(0.2,0.2,0.2);//set its scale
            glutSolidTetrahedron();//draw star
            glPopMatrix();//pops the coordinates to a matrix to make the object appear

            // star 7
            glPushMatrix();//push the coordinates to a matrix to make the object appear
            glColor3f(1.0,1.0,1.0);//set color of star
            glTranslated(8,5,-10.0);//set  position
            glScalef(0.2,0.2,0.2);//set its scale
            glutSolidTetrahedron();//draw star
            glPopMatrix();//pops the coordinates to a matrix to make the object appear

            // star 8
            glPushMatrix();//push the coordinates to a matrix to make the object appear
            glColor3f(1.0,1.0,1.0);//set color of star
            glTranslated(5,7,-10.0);//set  position
            glScalef(0.2,0.2,0.2);//set its scale
            glutSolidTetrahedron();//draw star
            glPopMatrix();//pops the coordinates to a matrix to make the object appear

            // star 9
            glPushMatrix();//push the coordinates to a matrix to make the object appear
            glColor3f(1.0,1.0,1.0);//set color of star
            glTranslated(-10,5,-10.0);//set  position
            glScalef(0.2,0.2,0.2);//set its scale
            glutSolidTetrahedron();//draw star
            glPopMatrix();//pops the coordinates to a matrix to make the object appear


//---------------------------------------------------HOUSE--------------------------------------------------------
    glTranslatef(4.0,-0.2,-6.5);//set  position of the house
            glBegin(GL_QUADS); //draw 3D quads
            //front  face
            glColor3f(1.0,0.0,0.0);//set color red
            //set its coordinates
            glVertex3f(-1.3,1.3,1.3);
            glVertex3f(-1.3,-1.3,1.3);
            glVertex3f(1.3,-1.3,1.3);
            glVertex3f(1.3,1.3,1.3);

            //back face
            glColor3f(1.0,0.0,0.0);//set color red
            //set its coordinates
            glVertex3f(1.3,1.3,-1.3);
            glVertex3f(1.3,-1.3,-1.3);
            glVertex3f(-1.3,-1.3,-1.3);
            glVertex3f(-1.3,1.3,-1.3);

            //right face coordinates
            glColor3f(0.6705882353,0.01176470588,0.01176470588);//set color maroon
            //set its coordinates
            glVertex3f(1.3,1.3,1.3);
            glVertex3f(1.3,-1.3,1.3);
            glVertex3f(1.3,-1.3,-1.3);
            glVertex3f(1.3,1.3,-1.3);

            //left face coordinates
            glColor3f(0.6705882353,0.01176470588,0.01176470588);//set color maroon
            //set its coordinates
            glVertex3f(-1.3,1.3,-1.3);
            glVertex3f(-1.3,-1.3,-1.3);
            glVertex3f(-1.3,-1.3,1.3);
            glVertex3f(-1.3,1.3,1.3);

            //upper face
            glColor3f(0.98823529,0.19607843,0.19607843);//set color light red
            //set its coordinates
            glVertex3f(-1.3,1.3,-1.3);
            glVertex3f(-1.3,1.3,1.3);
            glVertex3f(1.3,1.3,1.3);
            glVertex3f(1.3,1.3,-1.3);

            //bottom face
            glColor3f(0.98823529,0.19607843,0.19607843);//set color light red
            //set its coordinates
            glVertex3f(-1.3,-1.3,-1.3);
            glVertex3f(1.3,-1.3,-1.3);
            glVertex3f(1.3,-1.3,1.3);
            glVertex3f(-1.3,-1.3,1.3);

            glEnd();// end of cube "house" drawn manually

//---------------------------------------------ROOF---------------------------------------------
     glTranslatef(4.0,1,-3.3);
           glBegin(GL_QUADS);
           //front  face
           glColor3f(0.9299117647,0.6705882353,0.2784313725);//set color beij
           //set its coordinates
           glVertex3f(-3.7,1.3,1.3);
           glVertex3f(-3.7,1,1.3);
           glVertex3f(1,1,1.3);
           glVertex3f(1,1.3,1.3);

            //back face
           glColor3f(1.0,0.0,0.0);//set color red
           //set its coordinates
           glVertex3f(1,1.3,-3.5);
           glVertex3f(1,1,-3.5);
           glVertex3f(-3.7,1,-3.5);
           glVertex3f(-3.7,1.3,-3.5);

            //right face
            glColor3f(1,1,1);//set color white
            //set its coordinates
            glVertex3f(1,1.3,1.3);
            glVertex3f(1,1,1.3);
            glVertex3f(1,1,-1.3);
            glVertex3f(1,1.3,-1.3);

            //left face
            glColor3f(0.83137254,0.54117647,0.10980239216);//set color beij
            //set its coordinates
            glVertex3f(-3.7,1.3,-3.5);
            glVertex3f(-3.7,1,-3.5);
            glVertex3f(-3.7,1,1.3);
            glVertex3f(-3.7,1.3,1.3);

            //upper face
            glColor3f(1,1,1);//set color white
            //set its coordinates
            glVertex3f(-3.7,1.3,-1.3);
            glVertex3f(-3.7,2,1.3);
            glVertex3f(1,2,1.3);
            glVertex3f(1,1.3,-1.3);

            //bottom face
            glColor3f(1,1,1);//set color white
            //set its coordinates
            glVertex3f(-3.7,-1.3,-1.3);
            glVertex3f(1,1,-1.3);
            glVertex3f(1,1,1.3);
            glVertex3f(-3.7,-1.3,1.3);

            glEnd();//end of cuboid "roof" drawn manually


            glColor3f(0.0, 1.0, 0.0);//set color green "Christmas decor"
            glPushMatrix ();//push the coordinates to a matrix to make the object appear
            glTranslatef(-4,-1,4.5);//set position
            glutSolidTorus(0.3f, 1.00f, 10, 10);//draw torus shape
            glPopMatrix ();//pops the coordinates to a matrix to make the object appear

    glutSwapBuffers();// because we are using double display mode

}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);//set the view port width and height
    glMatrixMode(GL_PROJECTION);//set matrix mode to projection
    glLoadIdentity();
    gluPerspective(80.0,(GLdouble)w/(GLdouble)h,0.5,40.0);//set the 3D overview "fovy vision", aspect ration and depth of z-axis
    glMatrixMode(GL_MODELVIEW);//set matrix mode to model view
}

void timer(int)
{
  glutPostRedisplay();//used to redisplay for animation
  glutTimerFunc(2500/60,timer,0);//set the rate/time of redisplaying

}

void texture(){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };//set light ambient
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };// set  diffusion
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };//set light color
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.2f };//set light position

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };// set ambient
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };// set diffusion
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };//set color
const GLfloat high_shininess[] = { 100.0f };//shininess of light
//enable cull face and set it to back
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
//enable depth and set it to less
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
//set the light
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//set the material
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

