///////////////////////////////////////////////////////////////////////////////
// LSystem LSymbolsManager.h
// ========
//	For creating one LSystem structure!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////


#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <GL/freeglut.h>
#include "LTurtle.h"


class LSymbolsManager
{
public:
	LSymbolsManager();
	~LSymbolsManager();
	LNodesContainer getNodeContainer() const{return nodeContainer;}
	list<LSymbols> getFinalList() const {return _finlaListOfLSymbols;}

private:
	list<LSymbols> _finlaListOfLSymbols;
	LNodesContainer nodeContainer;

};

