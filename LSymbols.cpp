///////////////////////////////////////////////////////////////////////////////
// LSystem LSymbols.cpp
// ========
//	For creating symbols!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////

#include "LSymbols.h"

LSymbols::LSymbols(const string& _d, const string& _r, const string& _t, const string& _theta, const string& _phi, const string& _classType)
{
	classType=_classType;
	setDistance(_d);
	setRadius(_r);
	setTime(_t);
	setTheta(_theta);
	setPhi(_phi);
}

LSymbols::~LSymbols()
{

}

void LSymbols::setDistance(const string& _d)
{
	distance=_d;
}
void LSymbols::setRadius(const string& _r) 
{
	radius=_r;
}
void LSymbols::setTime(const string& _t) 
{
	time=_t;
}
void LSymbols::setTheta(const string& _theta) 
{
	theta=_theta;
}
void LSymbols::setPhi(const string& _phi) 
{
	phi=_phi;
}
string LSymbols::getClassType() const
{
	return classType;
}

string LSymbols::getDistance() const
{

	if (classType=="f"||classType=="A"||classType=="F"||classType=="X"||classType=="B")
	{
		return distance;
	}
	else if (classType=="!"||classType=="]"||classType=="["||classType=="?"||classType=="S"||classType=="-"||classType=="+"||classType=="^"||classType=="~")
	{
		return "0";
	}

}
string LSymbols::getRadius() const
{

	if (classType=="f"||classType=="A"||classType=="F"||classType=="X"||classType=="B")
	{
		return radius;
	}
	else if (classType=="!"||classType=="]"||classType=="["||classType=="?"||classType=="S"||classType=="-"||classType=="+"||classType=="^"||classType=="~")
	{
		return "0";
	}

}
string LSymbols::getTime() const
{

	if (classType=="f"||classType=="A"||classType=="F"||classType=="X"||classType=="B")
	{
		return time;
	}
	else if (classType=="!"||classType=="]"||classType=="["||classType=="?"||classType=="S"||classType=="-"||classType=="+"||classType=="^"||classType=="~")
	{
		return "0";
	}

}
string LSymbols::getTheta() const
{

	if (classType=="+"||classType=="-")
	{
		return theta;
	}
	else if (classType=="!"||classType=="]"||classType=="["||classType=="?"||classType=="S"||classType=="A"||classType=="F"||classType=="X"||classType=="B"||classType=="f"||classType=="^"||classType=="~")
	{
		return "0";
	}
}
string LSymbols::getPhi() const
{

	if (classType=="^"||classType=="~")
	{
		return phi;
	}
	else if (classType=="!"||classType=="]"||classType=="["||classType=="?"||classType=="S"||classType=="A"||classType=="F"||classType=="X"||classType=="B"||classType=="f"||classType=="+"||classType=="-")
	{
		return "0";
	}

}

string LSymbols::getOfDistance() const
{
	return distance;
}
string LSymbols::getOfRadius() const
{
	return radius;
}
string LSymbols::getOfTime() const
{
	return time;
}
string LSymbols::getOfTheta() const
{
	return theta;
}
string LSymbols::getOfPhi() const
{
	return phi;
}
