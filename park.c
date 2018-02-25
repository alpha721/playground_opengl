#include<GL/gl.h>
#include<GL/glut.h>
double eyeX=2,eyeY=3,eyeZ=3;

void myKeyBoard(unsigned char key,int x,int y) //key board functions
{
    switch(key)
    {
         case 'x':
         case'X': eyeX=3;eyeY=3;eyeZ=0;    //press x/X to view model in xy plane
         break;
         case 'y':
         case'Y':eyeX=0;eyeY=3;eyeZ=3;    //press y/Y to view model in YZ plane
         break;
         case 'd':
         case 'D':eyeX=2;eyeY=3,eyeZ=3;break;   //press d/D to get default view.
    }
    glutPostRedisplay();
}

void displayWire(void)
{
    glMatrixMode(GL_PROJECTION);  //projection mode
    glLoadIdentity();  //load identity matrix
    glOrtho(-2.0*64/48.0,2.0*64/48.0,-2,2,0.1,100); //set the scene
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ,0,0,0,0,1,0); //defines how to look at the model

    glClear(GL_COLOR_BUFFER_BIT); //clear color buffers
    glScaled(0.5,0.5,0.5); // scale the entire model to 0.5 of its original size.

    glPushMatrix(); // push current transformation matrix on to the stack
    glScaled(1.5,1,1.5); //scaling grass carpet and ground at a time.
    glPushMatrix();
    glColor3d(0.87,0.721,0.5289);  //set color to sand brown
    glScaled(5,0.5,6.5); //scale the cube to make it like a ground
    glutSolidCube(1); //solid cube
    glPopMatrix();   //pop the previous matrix from stack.

    glPushMatrix(); //Draws green carpet on the brown sand cube
    glColor3d(0,1,0); //set color to green
    glScaled(5,0,6.5);  // y component is zero so that cube looks like plane
    glutSolidCube(1); // cube of side 1
    glPopMatrix(); //makes current matrix as the matrix that is popped
    glPopMatrix(); // end of changes to ground and grass carpet.

    /*<<<Tree right>>*/
  glPushMatrix(); //push current matrix onto stack
  glTranslated(-1,0,-4.5); //translate initally to -1,0,-4.5
  GLUquadricObj *qob=gluNewQuadric(); //create a quadric object which is initially parallel to y axis
  glRotated(-90,1,0,0); // rotates cylinder to 90 degrees about x axis.
  glPushMatrix(); //cylinder drawing begins
  glColor3f(0.9,0.5,0.3);  //put the color of cylinder to sand brown
  gluCylinder(qob,0.2,0.09,1,8,8);  // creates trunk like cylinder
  glPopMatrix();  // end of cylinder drawing
  glPushMatrix(); //tree top drawing begins
  glColor3d(0,0.5,0); //set color of tree top to dark green
  glTranslated(0,0,0.5); //lift it to certain height so that it sits on trunk top.
  glutSolidCone(0.3,1.5,10,10); //draw cone
  glPopMatrix(); //end of tree top drawing
  glPushMatrix(); //draw tree neighbours
  for(int i=0;i<4;i++)
  { glTranslated(1,0,0);  //each time translate along x by 1 unit.
    glColor3f(0.9,0.5,0.3);  //set color of trunk
  gluCylinder(qob,0.2,0.09,1,8,8); //draw trunk
  } //after drawing you hit the end of green carpet
  glPushMatrix();  //trees at the entrance are drawn by rotating those trees that cross green zone
  glRotated(-180,1,0,0);
  glRotated(90,0,0,1);
  glRotated(180,1,0,0); //rotates trunk
  for(int i=0;i<5;i++)
  {
   glTranslated(1,0,0);
   glColor3f(0.9,0.5,0.3);
  gluCylinder(qob,0.2,0.09,1,8,8);
  }
  glPopMatrix();//end of drawing entrance trees' trunk
  glPopMatrix();//end of drawing trunks
  glPushMatrix(); //draw tree tops
  for(int i=0;i<4;i++)
  {
    glTranslated(1,0,0); //move along x direction each time by 1 unit
    glPushMatrix();
  glColor3d(0,0.5,0);
  glTranslated(0,0,0.5);//lift the tree top
  glutSolidCone(0.3,1.5,10,10); //draw tree top
  glPopMatrix();
  }
  glPushMatrix(); //draw tree tops for trees at entrance
  glRotated(-180,1,0,0);
  glRotated(90,0,0,1);
  glRotated(180,1,0,0);
  for(int i=0;i<5;i++)
  {
    glTranslated(1,0,0);
    glPushMatrix();
  glColor3d(0,0.5,0);
  glTranslated(0,0,0.5);
  glutSolidCone(0.3,1.5,10,10); //tree top as cone
  glPopMatrix();
  }
  GLUquadricObj *entr=gluNewQuadric();
  glTranslated(0,5,2);
  glColor3d(0,0,1);
  //glRotated(90,1,0,0);
  gluCylinder(entr,0.09,0.09,2,8,8);
  glPopMatrix();
  glPopMatrix();//gets the matrix that was present when only one tree was drawn
  glPushMatrix();//draw trees
  for(int i=0;i<2;i++)
  { glTranslated(-1,0,0);
   glColor3f(0.9,0.5,0.3);
  gluCylinder(qob,0.2,0.09,1,8,8); //draws tree trunk
  }
    glPushMatrix();//draws all the trees behind .
  glRotated(-180,1,0,0);
  glRotated(90,0,0,1);
  glRotated(180,1,0,0);
  for(int i=0;i<6;i++) //draws trunk first
  {
   glTranslated(1.5,0,0);
   glColor3f(0.9,0.5,0.3);
  gluCylinder(qob,0.2,0.09,1,8,8);
  }
  glPopMatrix();

  glPopMatrix();
  glPushMatrix();
  for(int i=0;i<2;i++)
  {
    glTranslated(-1,0,0);
    glPushMatrix();
  glColor3d(0,0.5,0);
  glTranslated(0,0,0.5);
  glutSolidCone(0.3,1.5,10,10); //tree tops for rightmost trees in the model
  glPopMatrix();
  }
  glPushMatrix();
  glRotated(-180,1,0,0);
  glRotated(90,0,0,1);
  glRotated(180,1,0,0);
  for(int i=0;i<6;i++)
  {
    glTranslated(1.5,0,0);
    glPushMatrix();
  glColor3d(0,0.5,0);
  glTranslated(0,0,1.5);
  glutSolidSphere(0.5,8,10); //put sphere as tree top for trees at the back.
  //glutSolidTorus(0.2,0.1,10,20);
  glPopMatrix();
  }
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();

   /*<<<Tree left>>*/
  glPushMatrix(); //draws set of trees to the left of the scene
  glTranslated(-1,0,4.55);
  GLUquadricObj *qo=gluNewQuadric();
  glRotated(-90,1,0,0); //make the trunk upright
  glPushMatrix();
  glColor3f(0.9,0.5,0.3); //set the color
  gluCylinder(qo,0.2,0.09,1,8,8);//draw trunk
  glPopMatrix();
  glPushMatrix();
  glColor3d(0,0.5,0);
  glTranslated(0,0,0.5);
  glutSolidCone(0.3,1.5,10,10); //draw top of tree
  glPopMatrix();
  glPushMatrix();
  for(int i=0;i<4;i++)//w.r.t given position take 1 unit translation and draw trees towards entrance
  { glTranslated(1,0,0);
   glColor3f(0.9,0.5,0.3);
  gluCylinder(qo,0.2,0.09,1,8,8);
  }
  glPopMatrix();
  glPushMatrix();
  for(int i=0;i<4;i++)
  {
    glTranslated(1,0,0);
    glPushMatrix();
  glColor3d(0,0.5,0);
  glTranslated(0,0,0.5);
  glutSolidCone(0.3,1.5,10,10); //draw their tops
  glPopMatrix();
  }
  glPopMatrix();
  glPushMatrix();
  for(int i=0;i<2;i++) //extend the trees to back edge
  { glTranslated(-1,0,0);
   glColor3f(0.9,0.5,0.3);
  gluCylinder(qo,0.2,0.09,1,8,8);
  }
  glPopMatrix();
  glPushMatrix();
  for(int i=0;i<2;i++)
  {
    glTranslated(-1,0,0);
    glPushMatrix();
  glColor3d(0,0.5,0);
  glTranslated(0,0,0.5);
  glutSolidCone(0.3,1.5,10,10);
  glPopMatrix();
  }
  glPopMatrix();
  glPopMatrix();//end of tree drawing


 /*<<<<<<<<<<<SWing Construction>>>>>>>>>>>>*/
    glPushMatrix();
    glTranslated(0.5,0,-2.5);//translate entire string at a time.
    glPushMatrix();
    glTranslated(-2,0,0);
    glPushMatrix();
    glColor3d(0,0,0.9);
    GLUquadricObj *cylin1=gluNewQuadric(); //draw supporting stand1
    glTranslated(0.4,2.5,2.25);
    glRotated(90,1,0,0);
    gluCylinder(cylin1,0.05,0.05,2,8,8);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0,0,0.9);
    GLUquadricObj *cylin2=gluNewQuadric(); //draw supporting stand2
    glTranslated(0.4,2.5,1.05);
    glRotated(90,1,0,0);
    gluCylinder(cylin1,0.05,0.05,2,8,8);
    glPopMatrix();

    glPushMatrix(); //draws swing seat
    glColor3d(1,0,0);
    glTranslated(0.4,1,1.625);
    glScaled(0.2,0.1,0.5);//scale it to look flat.
    glutSolidCube(1);//solid cube of size1
    glPopMatrix();

    glPushMatrix();//swing body
    glColor3d(0.549,0.305,.3843);
    glLineWidth(2);
    glBegin(GL_LINES); //ropes suspending from top and attached to seat
    glVertex3d(0.4,2.5,2);
    glVertex3d(0.4,1,2);
    glVertex3d(0.4,1,2);
    glVertex3d(0.4,1,1.85);
    glEnd();
    glBegin(GL_LINES);  //ropes suspending from top and attached to seat
    glVertex3d(0.4,2.5,1.25);
    glVertex3d(0.4,1,1.25);
    glVertex3d(0.4,1,1.25);
    glVertex3d(0.4,1,1.4);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3d(0.9,.3,0.257);
    glBegin(GL_POLYGON); //swing top
    glVertex3d(0,2.5,2.5);
    glVertex3d(1,2.5,2.5);
    glVertex3d(1,2.5,1);
    glVertex3d(0,2.5,1);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();//end of swing drawing

    /*<<<<Climber construction>>>>*/
    glPushMatrix();
    glTranslated(-3.0,0,-1.0);
    glColor3d(0,0,0.9);
    GLUquadricObj *cylin3=gluNewQuadric();//supporting stand1
    glTranslated(6,5,4.5);
    glRotated(90,1,0,0);
    gluCylinder(cylin3,0.05,0.05,2,8,8);
    glTranslated(0.5,0,0);
    gluCylinder(cylin3,0.05,0.05,2,8,8); //construct another stand2
    glPushMatrix();
    glRotated(90,1,0,0);
    gluCylinder(cylin3,0.05,0.05,2,8,8); //horizontal bar1
    glTranslated(-0.5,0,0);
    gluCylinder(cylin3,0.05,0.05,2,8,8); //horizontal bar2
    glPopMatrix();
    glTranslated(0,-2,0);
    gluCylinder(cylin3,0.05,0.05,2,8,8);//construct stand3
    glTranslated(-0.5,0,0);
    gluCylinder(cylin3,0.05,0.05,2,8,8);//construct stand4
    glColor3d(1,0,0);
    GLUquadricObj *cylin4 =gluNewQuadric();
    glRotated(90,0,1,0);
    gluCylinder(cylin4,0.05,0.05,0.5,8,8);
    glPushMatrix();//draw small cylinders to climb
    for(int i=0;i<3;i++)
    {
      glTranslated(-0.5,0,0);
      gluCylinder(cylin4,0.05,0.05,0.5,8,8);
    }
    glPopMatrix();
    for(int i=0;i<4;i++) //draws small cylinders across horizontal bars
    { glTranslated(0,0.53,0);
      gluCylinder(cylin4,0.05,0.05,0.5,8,8);
    }
    for(int i=0;i<3;i++)//draws cylinder on other two stands
    {
      glTranslated(-0.5,0,0);
      gluCylinder(cylin4,0.05,0.05,0.5,8,8);
    }
    glPopMatrix();

 /*<<<<<Slide>>>>>>*/
  glPushMatrix();
   glTranslated(0.5,0,-1.5);
  glPushMatrix();
  glTranslated(0,5,5);
  GLUquadricObj *cylin5 =gluNewQuadric(); //supporting rod1
  glRotated(90,1,0,0);
  gluCylinder(cylin5,0.05,0.05,2,8,8);
  glPopMatrix();
  glPushMatrix();
  glTranslated(0,5,5.75);
  glRotated(90,1,0,0);
  gluCylinder(cylin5,0.05,0.05,2,8,8);//rod2
  glPopMatrix();
  glPushMatrix();
  glTranslated(0,5,5);
  glPushMatrix();
  glColor3d(0.9,0.5,0.3); //horizontal cylinders
  gluCylinder(cylin5,0.05,0.05,0.75,8,8);
  glColor3d(0,0,0);
  glPushMatrix();//cylinders to climb up
   for(int i=0;i<3;i++)
   {
     glTranslated(0,-0.5,0);
     gluCylinder(cylin5,0.05,0.05,0.75,8,8);
   }
   glPopMatrix();//cylinders horizontal
  for(int i=0;i<5;i++)
  {
   glTranslated(0.15,0,0);
   glColor3d(0.9,0.5,0.3);
   gluCylinder(cylin5,0.05,0.05,0.75,8,8);
  }
  glPushMatrix();
  glRotated(90,0,0,1);
  glRotated(-140,0,0,1);
  for(int i=0;i<17;i++) //cylinders along the slide
  {
   glTranslated(0.12,0,0);
   glColor3d(0.9,0.5,0.3);
   gluCylinder(cylin5,0.05,0.05,0.75,8,8);
  }
  glPopMatrix();
  glPopMatrix();
  glColor3d(0,0,0);
  glPushMatrix();
  glRotated(90,0,1,0);
  gluCylinder(cylin5,0.05,0.05,0.8,8,8); //slide sides
  glPopMatrix();
  glTranslated(0,0,0.75);
  glRotated(90,0,1,0);
  gluCylinder(cylin5,0.05,0.05,0.8,8,8); //slide side
  glPopMatrix();
  double j=0;
  for(int i =0;i<2;i++)
  { glPushMatrix();
    glColor3d(0,0,0.9);
    glTranslated(0.8,5,5+j);
    glRotated(90,0,1,0);
    glRotated(50,1,0,0);
    gluCylinder(cylin5,0.07,0.07,2,8,8);
    glPopMatrix();
    j+=0.75;
  }
  glPopMatrix();
  glPopMatrix();

  glFlush();

}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("wireframes");
    glutDisplayFunc(displayWire);
    glutKeyboardFunc(myKeyBoard);
    glClearColor(1,1,1,1);
    glViewport(0,0,640,480);
    glutMainLoop();
}
