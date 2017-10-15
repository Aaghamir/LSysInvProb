///////////////////////////////////////////////////////////////////////////////
// LSystem LTutle.h
// ========
//	Turtle interpretation of LSymbols objects!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////

#pragma once


#include "LSysParam.h"
#include "LNodesContainer.h"
#include <math.h>

class LTurtle
{
public:
	LTurtle(list <LSymbols>& _finalSymbolList, LNodesContainer& nodesContain);
	~LTurtle();
	list <LSymbols> getSymbols2Turtle() const;
	void move();
	void rotatePositive();
	void rotateNegative();
	void execute(LNodesContainer& nodesContain);
	void rotate2zPositive();
	void rotate2zNegative();
	void printlist( list<LSymbols>& finalListOfSymbols );


private:
	list <LSymbols> listOfSymbols;
	GLfloat distance;
	GLdouble phiAngle;
	GLdouble thetaAngle;

	LNode node1;
	vector <LNode> stackNodes;

	GLdouble round(GLdouble n, double d);
};

