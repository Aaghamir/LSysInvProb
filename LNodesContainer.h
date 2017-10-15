///////////////////////////////////////////////////////////////////////////////
// LSystem LNodeContainer.h
// ========
//	For creating start nodes and end nodes vectors!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////


#pragma once

#include "LNode.h"
#include <vector>
using std::vector;

class LNodesContainer
{
public:
	LNodesContainer();
	~LNodesContainer();
	
	inline void addStartNode(LNode _sNode)
	{
		startNodes.push_back(_sNode);
	}
	inline void removeStartNode()
	{
		startNodes.pop_back();
	}
	inline void addEndNode(LNode _eNode)
	{
		endNodes.push_back(_eNode);
	}
	inline vector <LNode> getStartNodes() const
	{
		return startNodes;
	}
	inline vector <LNode> getEndNodes() const
	{
		return endNodes;
	}

private:
	vector <LNode> startNodes;
	vector <LNode> endNodes;

};
