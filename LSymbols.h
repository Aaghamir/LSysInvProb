///////////////////////////////////////////////////////////////////////////////
// LSystem LSymbols.h
// ========
//	For creating symbols!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////


#pragma once

#include<boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

#include <utility>

class LSymbols
{
public:
	LSymbols(const string& _d, const string& _r, const string& _t, const string& _theta, const string& _phi, const string& _classType);

	LSymbols(const LSymbols& Ls)
	{
		classType=Ls.classType;
		distance=Ls.distance;
		radius=Ls.radius;
		time=Ls.time;
		theta=Ls.theta;
		phi=Ls.phi;
	}
	LSymbols(const LSymbols&& Ls)
	{
		classType=std::move(Ls.classType);
		distance=std::move(Ls.distance);
		radius=std::move(Ls.radius);
		time=std::move(Ls.time);
		theta=std::move(Ls.theta);
		phi=std::move(Ls.phi);
	}

	LSymbols& operator=(const LSymbols& Ls)
	{
		if(&Ls!=this)
		{
			classType=Ls.classType;
			distance=Ls.distance;
			radius=Ls.radius;
			time=Ls.time;
			theta=Ls.theta;
			phi=Ls.phi;
		}
		return *this;
	}
	LSymbols& operator=(const LSymbols&& Ls)
	{
		if(&Ls!=this)
		{
			classType=std::move(Ls.classType);
			distance=std::move(Ls.distance);
			radius=std::move(Ls.radius);
			time=std::move(Ls.time);
			theta=std::move(Ls.theta);
			phi=std::move(Ls.phi);
		}
		return *this;
	}

	~LSymbols();


	string getDistance() const;
	string getRadius() const;
	string getTime() const;
	string getTheta() const;
	string getPhi() const;
	string getClassType() const;

	string getOfDistance() const;
	string getOfRadius() const;
	string getOfTime() const;
	string getOfTheta() const;
	string getOfPhi() const;
	string getOfClassType() const;

	void setDistance(const string& _d);
	void setRadius(const string& _r);
	void setTime(const string& _t);
	void setTheta(const string& _theta);
	void setPhi(const string& _phi);

private:
	string classType;
	string distance;
	string radius;
	string time;
	string theta;
	string phi;

};

