//
//  main.cpp
//  GlutTest
//
//  Created by Benjamin Johnson on 13/03/2016.
//  Copyright © 2016 Benjamin Johnson. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>//GLUT Library, will make you life easier
#include <OpenGL/OpenGL.h>//OpenGL Library


void keyboardHandler(unsigned char c, int x, int y) {
    // Escape
    if (c == 27) {
        exit(0);
    }
}

void mouseHandler(int button, int state, int x, int y) {
    if(button == GLUT_RIGHT_BUTTON) {
        exit(0);
    }
}

//Now, lets tell it to display some stuff
void render(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear the buffer
    
    glBegin(GL_TRIANGLES);//Let us begin drawing some points

    //Specify the points
    glColor3f(1, 0, 0);
    glVertex2f(-0.5,-0.5);
    
    glColor3f(0, 1, 0);
    glVertex2f(0.5,-0.5);
    
    glColor3f(0, 0, 1);
    glVertex2f(0.0, 0.5);
    
    glEnd();//Ok we are done specifying points
   
    glutSwapBuffers();
}



int main(int argc, char * argv[]) {
    
    //Init glut passing some args, if you know C++ you should know we are just passing the args straight thru from main
    glutInit(&argc, argv);
    
    //Specify the Display Mode, this one means there is a single buffer and uses RGB to specify colors
    glutInitDisplayMode(GLUT_DEPTH| GLUT_DOUBLE |GLUT_RGB);
    
    //Set the window size
    glutInitWindowSize(640, 480);
    
    //Where do we want to place the window initially?
    glutInitWindowPosition(100,100);
    
    //Name the window and create it
    glutCreateWindow("Simple GLUT Application");
    
    //Set the callback function, will be called as needed
    glutDisplayFunc(render);
    
    // Setup Keyboard Handler
    glutKeyboardFunc(keyboardHandler);
    
    // Setup Mouse Handler
    glutMouseFunc(mouseHandler);
    
    
    //Start the main loop running, nothing after this will execute for all eternity (right now)
    glutMainLoop();

    return 0;
}
