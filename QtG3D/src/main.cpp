#include <iostream>

#include <QApplication>
#include "GLWidget.h"

#include <G3D/G3DAll.h>
#include <GLG3D/GLG3D.h>


G3D_START_AT_MAIN();

void drawCube() {
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

void drawFrame(int w, int h, int frameNum) {
	// Set up the camera
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0f, (GLfloat)w/(GLfloat)h, 0.1f, 100.0f);

	glClearColor(0.0f, 0.2f, 0.4f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_LIGHTING);

	float angle = frameNum * 2;

	// Move the cube in camera space
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);

	// Rotate the cube around the Y axis
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glRotatef(angle, 1.0f, 1.0f, 1.0f);

	drawCube();
}

/*
int main(int argc, char** argv) {
	const int WIDTH = 640, HEIGHT = 480;
	RenderDevice* rd = new RenderDevice();
	OSWindow::Settings settings;
	settings.width  = WIDTH;
	settings.height = HEIGHT;
	rd->init(settings);

	for (int i = 0; i < 100; ++i) {
		drawFrame(WIDTH, HEIGHT, i);

		// Render at 30 fps
		System::sleep(1.0/30.0);

		// See also RenderDevice::beginFrame, RenderDevice::endFrame
		rd->swapBuffers();
	}

	rd->cleanup();
	delete rd;

	return 0;
}
*/

int main(int argc,char ** argv)
{
  QApplication app(argc,argv);

  OSWindow::Settings settings;
  const int WIDTH = 640,HEIGHT = 480;
  settings.width = WIDTH;
  settings.height = HEIGHT;
  settings.resizable = true;
  
  QGWindow* window = QGWindow::create(settings);

  G3D::RenderDevice * rd = window->renderDevice();
  std::cout<<"renderdevice is "<<rd<<std::endl;
 
  for (int i = 0; i < 100; ++i) {
	  drawFrame(WIDTH, HEIGHT, i);

	  // Render at 30 fps
	  System::sleep(1.0/30.0);

	  // See also RenderDevice::beginFrame, RenderDevice::endFrame
	  rd->swapBuffers();
  }
  
  return app.exec();
}
