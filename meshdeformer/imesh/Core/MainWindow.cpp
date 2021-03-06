// MainWindow.cpp --- MainWindow of app and controls the workflow 
// copyright (c) 2010 dreamway
// 
//  This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the Free Software Foundation;
//  Free free to contact dreamway(jingwenlai@163.com)
// 
// website: cg.xplore.cn
// 
// 

// Commentary: 
// Be seen as the Controller of MVC Design Pattern
// 

#include "MainWindow.h"
#include <QToolBar>
#include <QApplication>
#include <QObject>
#include <QPluginLoader>
#include <QPushButton>
#include <QString>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <glog/logging.h>


#include "globals.hpp"
#include "widgets/aboutDialog/AboutDialog.hpp"
#include "widgets/statusBar/StatusBar.h"
#include "widgets/pluginDialog/PluginDialog.h"
#include "widgets/consoleWidgets/ConsoleWidgetManager.h"

#include "BasePlugin/BaseInterface.h"
#include "BasePlugin/LoggingInterface.h"
#include "BasePlugin/StatusBarInterface.h"
#include "BasePlugin/ToolBoxInterface.h"
#include "BasePlugin/MeshCoreInterface.h"
#include "BasePlugin/RenderInterface.h"



void MainWindow::setupMenu()
{
   mainMenuBar                     = new QMenuBar(this);
   fileMenu                        = new QMenu(tr("&File"),mainMenuBar);
   
   openAction                      = new QAction(tr("&Open"),fileMenu);
   connect(openAction,SIGNAL(triggered()),this,SLOT(fileOpen()));
   fileMenu->addAction(openAction);

   actSave                         = new QAction(tr("&Save"),fileMenu);
   connect(actSave,SIGNAL(triggered()),this,SLOT(fileSave()));
   fileMenu->addAction(actSave);

   
   actSaveImage                    = new QAction(tr("&Save Image"),fileMenu);
   actSaveImage->setShortcut(QKeySequence(tr("Ctrl+S")));
   connect(actSaveImage,SIGNAL(triggered()),this,SLOT(fileSaveImage()));
   fileMenu->addAction(actSaveImage);

   fileMenu->addSeparator();

   exitAction                      = new QAction(tr("E&xit"),fileMenu);
   connect(exitAction,SIGNAL(triggered()),this,SLOT(fileExit()));
   fileMenu->addAction(exitAction);
   mainMenuBar->addMenu(fileMenu);

   viewMenu                        = new QMenu(tr("&View"),mainMenuBar);
   actViewLog                      = new QAction(tr("&Log"),viewMenu);
   connect(actViewLog,SIGNAL(triggered()),this,SLOT(viewLog()));
   viewMenu->addAction(actViewLog);
   actViewWireframe                = new QAction(tr("&WireFrame"),viewMenu);
   connect(actViewWireframe,SIGNAL(triggered()),this,SLOT(viewWireFrame()));
   viewMenu->addAction(actViewWireframe);

   actViewSolidFlat                = new QAction(tr("&Solid Flat"),viewMenu);
   connect(actViewSolidFlat,SIGNAL(triggered()),this,SLOT(viewSolidFlat()));
   viewMenu->addAction(actViewSolidFlat);
   
   actViewSolidSmooth              = new QAction(tr("&Solid Smooth"),viewMenu);
   connect(actViewSolidSmooth,SIGNAL(triggered()),this,SLOT(viewSolidSmooth()));
   viewMenu->addAction(actViewSolidSmooth);
   mainMenuBar->addMenu(viewMenu);

   /*
   qglViewerMenu_                  = new QMenu( tr( "Viewer Settings" ), mainMenuBar );
   actQGLViewerSetBackgroundColor_ = new QAction( tr( "Set Background Color" ), qglViewerMenu_ );
   connect( actQGLViewerSetBackgroundColor_, SIGNAL( triggered(  ) ), this, SLOT( slotChangeViewerBackgroundColor(  ) ) );
   qglViewerMenu_->addAction( actQGLViewerSetBackgroundColor_ );

   mainMenuBar->addMenu( qglViewerMenu_ );
   */

   helpMenu                        = new QMenu(tr("&Help"),mainMenuBar);
   aboutAction                     = new QAction(tr("&About"),helpMenu);
   connect(aboutAction,SIGNAL(triggered()),this,SLOT(helpAbout()));
   helpMenu->addAction(aboutAction);
   mainMenuBar->addMenu(helpMenu);

   infoMenu                        = new QMenu(tr("Info"),mainMenuBar);
   actInfoBoundingBox              = new QAction(tr("BoundingBox"),infoMenu);
   connect(actInfoBoundingBox,SIGNAL(triggered()),this,SLOT(infoPrintBoundingBox()));
   infoMenu->addAction(actInfoBoundingBox);
   actInfoShowDebugInfo            = new QAction(tr("Debug Info"),infoMenu);
   connect(actInfoShowDebugInfo,SIGNAL(triggered()),this,SLOT(infoShowDebugInfo()));
   infoMenu->addAction(actInfoShowDebugInfo);

   actInfoToggleRunningMode        = new QAction(tr("ToggleRunningMode"),infoMenu);
   connect(actInfoToggleRunningMode,SIGNAL(triggered()),this,SLOT(infoToggleRunningMode()));
   infoMenu->addAction(actInfoToggleRunningMode);

   actInfoPluginDialog             = new QAction(tr("Plugin Dialog"),infoMenu);
   connect(actInfoPluginDialog,SIGNAL(triggered()),this,SLOT(infoPluginDialog()));
   infoMenu->addAction(actInfoPluginDialog);
				      
   mainMenuBar->addMenu(infoMenu);

   setMenuBar(mainMenuBar);
}

void MainWindow::setupToolBar()
{
  QToolBar * toolbar = new QToolBar(this);
  toolbar->addAction(openAction);
  toolbar->addAction(aboutAction);
  addToolBar(toolbar);
}

void MainWindow::setupToolBox(  ) {
  toolbox_ = new QToolBox(  );
}

void MainWindow::setupMainLayout(  ) {
  mainLayout_ = new QHBoxLayout(  );
  mainLayout_->addWidget( mainViewer_ );
  mainLayout_->addWidget( toolbox_ );
}
    

void MainWindow::setupConsoleWidget()
{
	consoleWidgetManager = new ConsoleWidgetManager(this);
	consoleWidgetManager->setAllowedAreas(Qt::BottomDockWidgetArea);
	addDockWidget(Qt::BottomDockWidgetArea,consoleWidgetManager);
	consoleWidgetManager->setVisible(false);
}

void MainWindow::fileSave()
{
  consoleWidgetManager->logMessage(QString(tr("Save mesh. TODO ")));
}

void MainWindow::fileOpen()
{
	QString filename = QFileDialog::getOpenFileName(this,
		QString(tr("Open File")),
		QString(tr(".")),
		QString(tr("Mesh files(*.off *.obj *.ply *)"))
		);
	mainViewer_->reloadMesh(filename);

  emit updatePluginMesh( mainViewer_->mesh(  ) );
}

void MainWindow::fileSaveImage()
{
	QString filename = QFileDialog::getSaveFileName(this,
		QString(QObject::tr("Save File")),
		QString(QObject::tr("../result.png")),
		QString(QObject::tr("Images (*.png)"))
		);
	mainViewer_->saveImage(filename);
}

void MainWindow::fileExit()
{
  qApp->exit();
}

void MainWindow::helpAbout()
{
  AboutDialog* aboutDialog = new AboutDialog(this);
  aboutDialog->exec();
}

void MainWindow::viewLog()
{
	if(consoleWidgetManager->isVisible()){
		consoleWidgetManager->setVisible(false);
	}
	else{
		consoleWidgetManager->setVisible(true);
	}
}

void MainWindow::viewWireFrame()
{
	if(mainViewer_)
	  {
	    mainViewer_->setPolygonMode(PM_WIREFRAME);
	  }
}

void MainWindow::viewSolidFlat()
{
	if(mainViewer_)
		mainViewer_->setPolygonMode(PM_SOLID_FLAT);
}

void MainWindow::viewSolidSmooth()
{
  if(mainViewer_)
    mainViewer_->setPolygonMode(PM_SOLID_SMOOTH);
}


void MainWindow::infoPrintBoundingBox()
{
	if(mainViewer_){
	  //		mainViewer_->getModel()->printBoundingBox();
	}

}

void MainWindow::infoShowDebugInfo()
{
  if(mainViewer_){
    mainViewer_->printDebugInfo();
  }
}

void MainWindow::infoToggleRunningMode()
{
  RUNNING_AT_TEST_MODE = !RUNNING_AT_TEST_MODE; 
}


void MainWindow::slotLog(const QString& message)
{
  consoleWidgetManager->logMessage(message);
}


void MainWindow::setupStatusBar( )
{
  statusBar_ = new StatusBar( this );
  setStatusBar( statusBar_ );  
}


//StatusBar slot messages
void MainWindow::slotUpdateStatusBarMessage( const QString& message ) {
  statusBar_->showMessage( message);  
}

void MainWindow::slotAddToolBox( QString title , QWidget* widget) {
  printf( "MainWindow::slotAddToolBox...\n" );
  
  //widget->setParent(toolbox_);
  toolbox_->addItem( widget, title );
}

void MainWindow::infoPluginDialog(  ) {
  PluginDialog plugin_dialog;
  plugin_dialog.setPluginsInfo( plugins_info_ );
  plugin_dialog.exec(  );
}
    
//Plugin Management
void MainWindow::loadPlugins(  ) {  
  //load the dynamic plugins
  QDir pluginsDir( qApp->applicationDirPath(  ) );
  pluginsDir.cd( "plugins" );

  foreach( QString fileName, pluginsDir.entryList( QDir::Files ) ) {
    QPluginLoader pluginLoader( pluginsDir.absoluteFilePath( fileName ) );

    PluginInfo plugin_info;
    //load the plugin
    QObject* plugin = pluginLoader.instance(  );
    if( plugin ) {
      //Plugin's baseInterface
      BaseInterface* baseInterface = qobject_cast<BaseInterface*>( plugin );
      if( baseInterface ) {
        //BaseInterface connection for pluginsInitialized
        connect( this, SIGNAL( pluginsInitialized(  ) ),plugin, SLOT( pluginInitialized(  ) ) );
        plugin_info.name = baseInterface->name(  );
        plugin_info.description = baseInterface->description(  );
        plugin_info.interfaces_name.append( QString( "BaseInterface" ) );
      }
      
      //Plugin's LoggingInterface
      LoggingInterface* loggingInterface = qobject_cast<LoggingInterface*>( plugin );
      if( loggingInterface ) {
        connect( plugin, SIGNAL( log( const QString& ) ), this, SLOT( slotLog( const QString& ) ) );
        plugin_info.interfaces_name.append( QString( "LoggingInterface" ) );
      }

      //Plugin's StatusbarInterface
      StatusBarInterface* statusBarInterface = qobject_cast<StatusBarInterface*>( plugin );
      if( statusBarInterface ) {
        connect( plugin, SIGNAL( updateStatusBarMessage( const QString& ) ), this, SLOT( slotUpdateStatusBarMessage( const QString& ) ) );

        plugin_info.interfaces_name.append( QString( "StatusBarInterface" ) );
      }

      //Plugins's ToolBoxInterface
      ToolBoxInterface* toolBoxInterface = qobject_cast<ToolBoxInterface*>( plugin );
      if( toolBoxInterface ) {
        connect( plugin, SIGNAL( addToolBox( QString, QWidget* ) ), this, SLOT( slotAddToolBox( QString, QWidget* ) ) );
        plugin_info.interfaces_name.append( QString( "ToolBoxInterface" ) );
      }

      MeshCoreInterface* meshCoreInterface = qobject_cast<MeshCoreInterface*>( plugin );
      if( meshCoreInterface ) {
        connect( this, SIGNAL( updatePluginMesh( MeshCore* ) ), plugin, SLOT( setMesh( MeshCore* ) ) );
        plugin_info.interfaces_name.append( QString( "MeshCoreInterface" ) );
      }
      //RenderInterface
      RenderInterface* renderInterface = qobject_cast<RenderInterface*>( plugin );
      if( renderInterface ) {
        //TODO: howto use the RenderInterface? [ confused ]
        RendererInfo renderer_info;
        //        renderer_info.name = plugin->metaObject(  ).className(  );
        renderer_info.name = plugin->objectName(  );
        renderer_info.plugin = plugin;
        renderers_info_.push_back( renderer_info );
        plugin_info.interfaces_name.append( QString( "RenderIntrface" ) );
      }


      //InitializePlugin
      if( baseInterface ) {
        //Invoke Plugin initialize method
        QMetaObject::invokeMethod( plugin,"initializePlugin",Qt::DirectConnection );
      }
    } else {
      qDebug(  )<<"could not instance this plugin: "<<fileName;
    }

    plugins_info_.append( plugin_info );
  }

  LOG( WARNING )<<"Renderers_Info size is: "<<renderers_info_.size(  );
  for (QVector<RendererInfo>::iterator renderer = renderers_info_.begin(  );
       renderer  != renderers_info_.end(  ); ++renderer) {
    qDebug(  )<<"renderer_name: "<<renderer->name;
  }
  
  //Emit a signal to setup all plugins
  emit pluginsInitialized(  );
}


void MainWindow::setViewerRendererInterfaces( Viewer* _viewer,QVector<RendererInfo>& renderer_interfaces ) {
  _viewer->setRendererInterface( renderer_interfaces );
}


