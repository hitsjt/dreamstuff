// MainWidget.cpp --- 
// copyright (c) 2010 dreamway
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the Free Software Foundation;
//  Feel free to contact dreamway(jingwenlai@163.com)
// 
// website: cg.xplore.cn
// 
// 

// Commentary: 
// 
//
#include "MainWidget.hh"

void MainWidget::draw(  ) {
  testDrawCube(  );
}

void MainWidget::testDrawCube(  ) {
  	glTranslatef(0.0f,0.0f,0.0f);
		// Code from http://www.morrowland.com/apron/tutorials/gl/gl_rotating_cube.php
		glBegin(GL_QUADS);
		glColor3f(0.0f,1.0f,0.0f);// Color Blue
		glVertex3f( 1.0f, 1.0f,-1.0f);// Top Right Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f,-1.0f);// Top Left Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f, 1.0f);// Bottom Left Of The Quad (Top)
		glVertex3f( 1.0f, 1.0f, 1.0f);// Bottom Right Of The Quad (Top)

		glColor3f(1.0f,0.5f,0.0f);// Color Orange
		glVertex3f( 1.0f,-1.0f, 1.0f);// Top Right Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f, 1.0f);// Top Left Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f,-1.0f);// Bottom Left Of The Quad (Bottom)
		glVertex3f( 1.0f,-1.0f,-1.0f);// Bottom Right Of The Quad (Bottom)

		glColor3f(1.0f,0.0f,0.0f);// Color Red
		glVertex3f( 1.0f, 1.0f, 1.0f);// Top Right Of The Quad (Front)
		glVertex3f(-1.0f, 1.0f, 1.0f);// Top Left Of The Quad (Front)
		glVertex3f(-1.0f,-1.0f, 1.0f);// Bottom Left Of The Quad (Front)
		glVertex3f( 1.0f,-1.0f, 1.0f);// Bottom Right Of The Quad (Front)

		glColor3f(1.0f,1.0f,0.0f);// Color Yellow
		glVertex3f( 1.0f,-1.0f,-1.0f);// Top Right Of The Quad (Back)
		glVertex3f(-1.0f,-1.0f,-1.0f);// Top Left Of The Quad (Back)
		glVertex3f(-1.0f, 1.0f,-1.0f);// Bottom Left Of The Quad (Back)
		glVertex3f( 1.0f, 1.0f,-1.0f);// Bottom Right Of The Quad (Back)

		glColor3f(0.0f,0.0f,1.0f);// Color Blue
		glVertex3f(-1.0f, 1.0f, 1.0f);// Top Right Of The Quad (Left)
		glVertex3f(-1.0f, 1.0f,-1.0f);// Top Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f,-1.0f);// Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f, 1.0f);// Bottom Right Of The Quad (Left)

		glColor3f(1.0f,0.0f,1.0f);// Color Violet
		glVertex3f( 1.0f, 1.0f,-1.0f);// Top Right Of The Quad (Right)
		glVertex3f( 1.0f, 1.0f, 1.0f);// Top Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f, 1.0f);// Bottom Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f,-1.0f);// Bottom Right Of The Quad (Right)
		glEnd();
}

//  
// 
// MainWidget.cpp ends here
