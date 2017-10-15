///////////////////////////////////////////////////////////////////////////////
// LSystem LNodeContainer.cpp
// ========
//	For creating start nodes and end nodes vectors!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////


#include "LNodesContainer.h"

LNodesContainer::LNodesContainer()
{
	LNode zero;
	addStartNode(zero);
}
LNodesContainer::~LNodesContainer()
{
	startNodes.clear();
	endNodes.clear();
}