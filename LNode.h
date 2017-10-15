///////////////////////////////////////////////////////////////////////////////
// LSystem LNode.h
// ========
//	For creating nodes with 3D coordinates! + space angles!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <GL/glut.h>
#include <utility>

class LNode
{
public:
	LNode();
	/*
	LNode(LNode& Ln)
	{
		x=Ln.x;
		y=Ln.y;
		z=Ln.z;
		theta=Ln.theta;
		phi=Ln.phi;
	}
	LNode(LNode&& Ln)
	{
		x=std::move(Ln.x);
		y=std::move(Ln.y);
		z=std::move(Ln.z);
		theta=std::move(Ln.theta);
		phi=std::move(Ln.phi);
	}
	LNode& operator=(LNode& Ln)
	{
		if(&Ln!=this)
		{
			x=Ln.x;
			y=Ln.y;
			z=Ln.z;
			theta=Ln.theta;
			phi=Ln.phi;
		}
		return *this;
	}
	LNode& operator=(LNode&& Ln)
	{
		if(&Ln!=this)
		{
			x=std::move(Ln.x);
			y=std::move(Ln.y);
			z=std::move(Ln.z);
			theta=std::move(Ln.theta);
			phi=std::move(Ln.phi);
		}
		return *this;
	}
	*/
	~LNode();

	inline GLfloat getxPosition() { return x; }
	inline GLfloat getyPosition() { return y; }
	inline GLfloat getzPosition() { return z; }
	inline GLdouble getThetaPosition() { return theta; }
	inline GLdouble getPhiPosition() { return phi; }

	inline void setxPosition(GLfloat _xpos) { x = _xpos; }
	inline void setyPosition(GLfloat _ypos) { y = _ypos; }
	inline void setzPosition(GLfloat _zpos) { z = _zpos; }
	inline void setTheta(GLdouble _theta) { theta = _theta; }
	inline void setPhi(GLdouble _phi) { phi = _phi; }



private:
	GLfloat x,y,z;
	GLdouble theta, phi;

};
