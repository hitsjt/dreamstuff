// ToolboxInterface.h --- Just testing for dynamically adding Toolbox
// copyright (c) 2010 dreamway
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the Free Software Foundation;
//  Free free to contact dreamway(jingwenlai@163.com)
// 
// website: cg.xplore.cn
// 
// 

// Commentary: 
// 
//
#ifndef _TOOLBOXINTERFACE_H_
#define _TOOLBOXINTERFACE_H_

#include <QtPlugin>

/**
   \brief just a testing interface
*/
class ToolBoxInterface {
 public:  
  virtual ~ToolBoxInterface() {
  }
 signals:
  virtual void addToolBox( QString , QWidget*  ) = 0;
};

Q_DECLARE_INTERFACE( ToolBoxInterface, "ToolBoxInterface/0.1" )

#endif /* _TOOLBOXINTERFACE_H_ */
//  
// 
// ToolboxInterface.h ends here
