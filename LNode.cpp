///////////////////////////////////////////////////////////////////////////////
// LSystem LNode.cpp
// ========
//	For creating nodes with 3D coordinates! + space angles!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////

#define _USE_MATH_DEFINES
#include <cmath>

#include "LNode.h"

LNode::LNode()
{
	//x=100;
	//x = 700;
	x=100;
	//y=500;
	y = 320;
	z = 0;
	//theta = -M_PI/12;
	//theta = -M_PI/4;
	//theta = -M_PI*2/3-M_PI/50;
	//theta = -M_PI/4+0.5*M_PI/180;
	theta = -M_PI/12;
	phi = M_PI/2;
}
LNode::~LNode()
{

}