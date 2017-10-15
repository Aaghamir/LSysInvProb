///////////////////////////////////////////////////////////////////////////////
// LSystem LSysParam.h
// ========
//	For creating LSystem string in multi rules context sensitive parametric stochastic cases!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "LSymbols.h"

#include <list>
#include<boost/algorithm/string.hpp>
#include<boost/algorithm/string/split.hpp>
#include<boost/lexical_cast.hpp>
#include<boost/tokenizer.hpp>
#include <boost/smart_ptr/scoped_array.hpp>
using boost::lexical_cast;
using namespace std;
using namespace boost;

#include <iostream>
#include <algorithm> // copy algorithm
#include <iterator> // ostream_iterator
#include <vector>
#include <cstdlib>
#include <ctime>
#include "ExpressionEvaluator.h"

class LSysParam
{
public:
	LSysParam(const vector<LSymbols> &_ax, vector <vector <LSymbols>> &_prePred, vector <vector <LSymbols>> &_inPred, vector <vector <LSymbols>> &_postPred, vector <vector<LSymbols>> &_suc, const int _iter, const double _Z, const double _R, const double _T, double _Theta, double _Phi);
	~LSysParam();
	virtual void setString(const vector<LSymbols> &_ax, vector <vector <LSymbols>> &_prePred, vector <vector <LSymbols>> &_inPred, vector <vector <LSymbols>> &_postPred, vector <vector<LSymbols>> &_suc, const int _iter, const double _Z, const double _R, const double _T);
	virtual void expandListOfSymbol();
	virtual list <LSymbols> getFinalSymbolList() const;
	virtual void print(list <LSymbols>& finalListOfSymbols) const;


private:
	int iterator;
	double Z;
	double R;
	double T;
	double thetaAngle;
	double phiAngle;
	list <LSymbols> axiom;
	list <LSymbols> finalSymbolList;
	vector <vector <list <LSymbols> > > preVectorOfVectorOfListOfSymbols;
	vector <list<LSymbols>> sucVectorOfListOfSymbols;
};


