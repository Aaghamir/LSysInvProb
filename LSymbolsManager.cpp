
///////////////////////////////////////////////////////////////////////////////
// LSystem LSymbolsManager.cpp
// ========
//	For creating one LSystem structure!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////

#include "LSymbolsManager.h"

#include<ctime>

LSymbolsManager::LSymbolsManager()
{
////First Case/////////////////////////////////////////////////////////////////	

	/*
	const double PI=M_PI;
	const double per=2;
	int iterator = 3;
	GLdouble ZSize=1;
	GLdouble RSize=1;
	GLdouble TSize=1;
	GLdouble ThetaSize=1;
	GLdouble PhiSize=1;


	vector<LSymbols> axiom;
	axiom.push_back(LSymbols("1","1","1","0","0","F"));
	axiom.push_back(LSymbols("0","0","0","1.57","0","-"));
	axiom.push_back(LSymbols("1","1","1","0","0","F"));
	axiom.push_back(LSymbols("0","0","0","1.57","0","-"));
	axiom.push_back(LSymbols("1","1","1","0","0","F"));
	axiom.push_back(LSymbols("0","0","0","1.57","0","-"));
	axiom.push_back(LSymbols("1","1","1","0","0","F"));

	vector <LSymbols> tempVector;

	vector<vector<LSymbols>> prePred;
	prePred.push_back(tempVector);
	prePred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> inPred;
	inPred.push_back(tempVector);
	inPred.at(0).push_back(LSymbols("1","1","1","0","0","F"));

	vector<vector<LSymbols>> postPred;
	postPred.push_back(tempVector);
	postPred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));


	vector<vector<LSymbols>> suc;
	suc.push_back(tempVector);
	suc.at(0).push_back(LSymbols("1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.57","0","-"));
	suc.at(0).push_back(LSymbols("1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.57","0","+"));
	suc.at(0).push_back(LSymbols("1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.57","0","+"));
	suc.at(0).push_back(LSymbols("1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.57","0","-"));
	suc.at(0).push_back(LSymbols("1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.57","0","-"));
	suc.at(0).push_back(LSymbols("1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.57","0","+"));
	suc.at(0).push_back(LSymbols("1","1","1","0","0","F"));

	LSysParam newSymbolList(axiom, prePred, inPred, postPred, suc, iterator, ZSize, RSize, TSize, ThetaSize, PhiSize);
	//_finlaListOfLSymbols=newSymbolList.getFinalSymbolList();
	LTurtle turtle(newSymbolList.getFinalSymbolList(), nodeContainer);
	
	*/
////////////////////////////////////////////////////////////////////////////////


////Second Case/////////////////////////////////////////////////////////////////
	
	/*
	const double PI=M_PI;
	const double per=2;
	int iterator = 2;
	GLdouble ZSize=1;
	GLdouble RSize=1;
	GLdouble TSize=1;
	GLdouble ThetaSize=1;
	GLdouble PhiSize=1;

	vector<LSymbols> axiom;
	axiom.push_back(LSymbols("0.05","1","1","0","0","F"));
	axiom.push_back(LSymbols("0","0","0","1.5708","0","+"));
	axiom.push_back(LSymbols("0.05","1","1","0","0","F"));
	axiom.push_back(LSymbols("0","0","0","1.5708","0","+"));
	axiom.push_back(LSymbols("0.05","1","1","0","0","F"));
	axiom.push_back(LSymbols("0","0","0","1.5708","0","+"));
	axiom.push_back(LSymbols("0.05","1","1","0","0","F"));

	vector <LSymbols> tempVector;

	vector<vector<LSymbols>> prePred;
	prePred.push_back(tempVector);
	prePred.push_back(tempVector);
	prePred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));
	prePred.at(1).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> inPred;
	inPred.push_back(tempVector);
	inPred.push_back(tempVector);
	inPred.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	inPred.at(1).push_back(LSymbols("0.05","1","1","0","0","f"));

	vector<vector<LSymbols>> postPred;
	postPred.push_back(tempVector);
	postPred.push_back(tempVector);
	postPred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));
	postPred.at(1).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> suc;
	suc.push_back(tempVector);
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","+"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","f"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","-"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","+"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","+"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","+"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","f"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","+"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","-"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","f"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","+"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","-"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","-"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","-"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","f"));
	suc.at(0).push_back(LSymbols("0","0","0","1.5708","0","-"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0.05","1","1","0","0","F"));
	
	suc.push_back(tempVector);
	suc.at(1).push_back(LSymbols("0.05","1","1","0","0","f"));
	suc.at(1).push_back(LSymbols("0.05","1","1","0","0","f"));
	suc.at(1).push_back(LSymbols("0.05","1","1","0","0","f"));
	suc.at(1).push_back(LSymbols("0.05","1","1","0","0","f"));
	suc.at(1).push_back(LSymbols("0.05","1","1","0","0","f"));
	suc.at(1).push_back(LSymbols("0.05","1","1","0","0","f"));


	
	LSysParam newSymbolList(axiom, prePred, inPred, postPred, suc, iterator, ZSize, RSize, TSize, ThetaSize, PhiSize);

	LTurtle turtle(newSymbolList.getFinalSymbolList(), nodeContainer);
	*/
	
	
////////////////////////////////////////////////////////////////////////////////


////Third Case//////////////////////////////////////////////////////////////////
	
	/*
	const double PI=M_PI;
	const double per=8;
	int iterator =2;
	GLdouble ZSize=1;
	GLdouble RSize=1;
	GLdouble TSize=1;
	GLdouble ThetaSize=1;
	GLdouble PhiSize=1;

	vector<LSymbols> axiom;
	axiom.push_back(LSymbols("0.1","1","1","0","0","F"));

	vector <LSymbols> tempVector;

	vector<vector<LSymbols>> prePred;
	prePred.push_back(tempVector);
	prePred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> inPred;
	inPred.push_back(tempVector);
	inPred.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));

	vector<vector<LSymbols>> postPred;
	postPred.push_back(tempVector);
	postPred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> suc;
	suc.push_back(tempVector);
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0.392699","^"));
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0.392699","^"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","["));
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","["));
	suc.at(0).push_back(LSymbols("0","0","0","0","0.392699","^"));
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","]"));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","+"));
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","]"));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","+"));
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","["));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","-"));
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","]"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0.392699","^"));
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0.392699","~"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","["));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","+"));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","+"));
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","]"));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","-"));
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","["));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","-"));
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","]"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0.392699","~"));
	suc.at(0).push_back(LSymbols("0.1","1","1","0","0","F"));

	//auto start = std::chrono::high_resolution_clock::now();
	//clock_t startTime = clock();

	LSysParam newSymbolList(axiom, prePred, inPred, postPred, suc, iterator, ZSize, RSize, TSize, ThetaSize, PhiSize);

	//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

	//auto end = std::chrono::high_resolution_clock::now();
	//auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	//cout << elapsed.count()<<endl;

	LTurtle turtle(newSymbolList.getFinalSymbolList(), nodeContainer);
	*/
	
////////////////////////////////////////////////////////////////////////////////


////4th Case////////////////////////////////////////////////////////////////////
	
	/*
	const double PI=M_PI;
	const double per=8;
	int iterator = 3;
	GLdouble ZSize=1;
	GLdouble RSize=1;
	GLdouble TSize=1;
	GLdouble ThetaSize=1;
	GLdouble PhiSize=1;

	vector<LSymbols> axiom;
	axiom.push_back(LSymbols("10","1","1","0","0","F"));

	vector <LSymbols> tempVector;

	vector<vector<LSymbols>> prePred;
	prePred.push_back(tempVector);
	prePred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> inPred;
	inPred.push_back(tempVector);
	inPred.at(0).push_back(LSymbols("10","1","1","0","0","F"));

	vector<vector<LSymbols>> postPred;
	postPred.push_back(tempVector);
	postPred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> suc;
	suc.push_back(tempVector);
	suc.at(0).push_back(LSymbols("10","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("10","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","-"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","["));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","-"));
	suc.at(0).push_back(LSymbols("10","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","+"));
	suc.at(0).push_back(LSymbols("10","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","+"));
	suc.at(0).push_back(LSymbols("10","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","]"));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","+"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","["));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","+"));
	suc.at(0).push_back(LSymbols("10","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","-"));
	suc.at(0).push_back(LSymbols("10","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0.392699","0","-"));
	suc.at(0).push_back(LSymbols("10","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","]"));

	LSysParam newSymbolList(axiom, prePred, inPred, postPred, suc, iterator, ZSize, RSize, TSize, ThetaSize, PhiSize);

	LTurtle turtle(newSymbolList.getFinalSymbolList(), nodeContainer);
	*/
	
////////////////////////////////////////////////////////////////////////////////


////5th Case////////////////////////////////////////////////////////////////////
	
	
	const double PI=M_PI;
	const double per=2.1176;
	int iterator = 3;
	GLdouble ZSize=1.5;
	GLdouble RSize=1;
	GLdouble TSize=1;
	GLdouble ThetaSize=1;
	GLdouble PhiSize=1;

	vector<LSymbols> axiom;
	axiom.push_back(LSymbols("100","1","1","0","0","A"));

	vector <LSymbols> tempVector;

	vector<vector<LSymbols>> prePred;
	prePred.push_back(tempVector);
	prePred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> inPred;
	inPred.push_back(tempVector);
	inPred.at(0).push_back(LSymbols("s","1","1","0","0","A"));

	vector<vector<LSymbols>> postPred;
	postPred.push_back(tempVector);
	postPred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> suc;
	suc.push_back(tempVector);
	suc.at(0).push_back(LSymbols("s","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","["));
	suc.at(0).push_back(LSymbols("0","0","0","85","0","+"));
	suc.at(0).push_back(LSymbols("s/Z","1","1", "0", "0","A"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","]"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","["));
	suc.at(0).push_back(LSymbols("0","0","0","85","0","-"));
	suc.at(0).push_back(LSymbols("s/Z","1","1", "0", "0","A"));
	suc.at(0).push_back(LSymbols("0","0","0","0","0","]"));

	LSysParam newSymbolList(axiom, prePred, inPred, postPred, suc, iterator, ZSize, RSize, TSize, ThetaSize, PhiSize);

	LTurtle turtle(newSymbolList.getFinalSymbolList(), nodeContainer);
	

////////////////////////////////////////////////////////////////////////////////


////6th Case////////////////////////////////////////////////////////////////////
	
	/*
	const double PI=M_PI;
	const double per=2.1176;
	int iterator = 5;
	GLdouble ZSize=1.456;
	GLdouble RSize=1;
	GLdouble TSize=1;
	GLdouble ThetaSize=1;
	GLdouble PhiSize=1;

	vector<LSymbols> axiom;
	axiom.push_back(LSymbols("10","1","1","0","0","A"));

	vector <LSymbols> tempVector;

	vector<vector<LSymbols>> prePred;
	prePred.push_back(tempVector);
	prePred.push_back(tempVector);
	prePred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));
	prePred.at(1).push_back(LSymbols("0","0","0", "0", "0","?"));


	vector<vector<LSymbols>> inPred;
	inPred.push_back(tempVector);
	inPred.push_back(tempVector);
	inPred.at(0).push_back(LSymbols("10","1","1","0","0","A"));
	inPred.at(1).push_back(LSymbols("s","1","1", "0", "0","F"));


	vector<vector<LSymbols>> postPred;
	postPred.push_back(tempVector);
	postPred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));
	postPred.push_back(tempVector);
	postPred.at(1).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> suc;
	suc.push_back(tempVector);
	suc.at(0).push_back(LSymbols("20","1","1","0","0","F"));
	suc.at(0).push_back(LSymbols("0","0","0", "0", "0","["));
	suc.at(0).push_back(LSymbols("0","0","0","1.4828","0","+"));
	suc.at(0).push_back(LSymbols("10","1","1", "0", "0","A"));
	suc.at(0).push_back(LSymbols("0","0","0", "0", "0","]"));
	suc.at(0).push_back(LSymbols("0","0","0", "0", "0","["));
	suc.at(0).push_back(LSymbols("0","0","0","1.4828","0","-"));
	suc.at(0).push_back(LSymbols("10","1","1", "0", "0", "A"));
	suc.at(0).push_back(LSymbols("0","0","0", "0", "0","]"));
	suc.push_back(tempVector);
	suc.at(1).push_back(LSymbols("s*Z","1","1","0","0","F"));

	LSysParam newSymbolList(axiom, prePred, inPred, postPred, suc, iterator, ZSize, RSize, TSize, ThetaSize, PhiSize);

	LTurtle turtle(newSymbolList.getFinalSymbolList(), nodeContainer);
	*/
	
////////////////////////////////////////////////////////////////////////////////

////7th Case////////////////////////////////////////////////////////////////////

	/*
	const double PI=M_PI;
	const double per=2;
	int iterator = 2;
	GLdouble ZSize=1;
	GLdouble RSize=2;
	GLdouble TSize=3;
	GLdouble ThetaSize=1;
	GLdouble PhiSize=1;

	vector<LSymbols> axiom;
	axiom.push_back(LSymbols("0.1","1","1","0","0","F"));

	vector <LSymbols> tempVector;

	vector<vector<LSymbols>> prePred;
	prePred.push_back(tempVector);
	prePred.push_back(tempVector);
	prePred.at(0).push_back(LSymbols("z","r","t", "0", "0","F"));
	prePred.at(1).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> inPred;
	inPred.push_back(tempVector);
	inPred.push_back(tempVector);
	inPred.at(0).push_back(LSymbols("z","r","t", "0", "0","F"));
	inPred.at(1).push_back(LSymbols("z","r","t", "0", "0","F"));

	vector<vector<LSymbols>> postPred;
	postPred.push_back(tempVector);
	postPred.push_back(tempVector);
	postPred.at(0).push_back(LSymbols("z","r","t", "0", "0","F"));
	postPred.at(1).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> suc;
	suc.push_back(tempVector);
	suc.at(0).push_back(LSymbols("z","r","t/R","0","0","F"));
	suc.at(0).push_back(LSymbols("z","R*r","t","0","0","F"));

	suc.push_back(tempVector);
	suc.at(1).push_back(LSymbols("R*z","T*r","Z*t","0","0","F"));
	suc.at(1).push_back(LSymbols("0","0","0","1.5708","0","+"));
	suc.at(1).push_back(LSymbols("R*z","T*r","Z*t","0","0","F"));
	suc.at(1).push_back(LSymbols("R*z","T*r","Z*t","0","0","F"));
	suc.at(1).push_back(LSymbols("R*z","T*r","Z*t","0","0","F"));
	
	

	LSysParam newSymbolList(axiom, prePred, inPred, postPred, suc, iterator, ZSize, RSize, TSize, ThetaSize, PhiSize);

	LTurtle turtle(newSymbolList.getFinalSymbolList(), nodeContainer);
	*/

	////////////////////////////////////////////////////////////////////////////////

	////8th Case////////////////////////////////////////////////////////////////////

	/*
	const double PI=M_PI;
	const double per=2;
	int iterator = 1;
	GLdouble ZSize=1;
	GLdouble RSize=2;
	GLdouble TSize=3;
	GLdouble ThetaSize=0.5;
	GLdouble PhiSize=0.2;

	vector<LSymbols> axiom;
	axiom.push_back(LSymbols("0.3","1","1","0","0","F"));
	axiom.push_back(LSymbols("0","0","0","1.5708","0","+"));

	vector <LSymbols> tempVector;

	vector<vector<LSymbols>> prePred;
	prePred.push_back(tempVector);
	prePred.push_back(tempVector);
	prePred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));
	prePred.at(1).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> inPred;
	inPred.push_back(tempVector);
	inPred.push_back(tempVector);
	inPred.at(0).push_back(LSymbols("z","r","t", "0", "0","F"));
	inPred.at(1).push_back(LSymbols("z","r","t", "0", "0","F"));
	inPred.at(1).push_back(LSymbols("0","0","0","y","0","+"));

	vector<vector<LSymbols>> postPred;
	postPred.push_back(tempVector);
	postPred.push_back(tempVector);
	postPred.at(0).push_back(LSymbols("0","0","0", "y", "0","+"));
	postPred.at(1).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> suc;
	suc.push_back(tempVector);
	suc.at(0).push_back(LSymbols("z","r","t/R","0","0","F"));
	suc.at(0).push_back(LSymbols("z","R*r","t","0","0","F"));

	suc.push_back(tempVector);
	suc.at(1).push_back(LSymbols("R*z","T*r","Z*t","0","0","F"));
	suc.at(1).push_back(LSymbols("0","0","0","y+G","0","+"));
	suc.at(1).push_back(LSymbols("R*z","T*r","Z*t","0","0","F"));
	suc.at(1).push_back(LSymbols("0","0","0","y+G","0","+"));
	suc.at(1).push_back(LSymbols("0","0","0","y+G","0","+"));

	
	LSysParam newSymbolList(axiom, prePred, inPred, postPred, suc, iterator, ZSize, RSize, TSize, ThetaSize, PhiSize);
	//newSymbolList.print(newSymbolList.getFinalSymbolList());

	LTurtle turtle(newSymbolList.getFinalSymbolList(), nodeContainer);
	*/
	

////////////////////////////////////////////////////////////////////////////////
////9th Case////////////////////////////////////////////////////////////////////

	/*
	const double PI=M_PI;
	const double per=2;
	int iterator = 1;
	GLdouble ZSize=1;
	GLdouble RSize=1;
	GLdouble TSize=1;
	GLdouble ThetaSize=1;
	GLdouble PhiSize=1;

	vector<LSymbols> axiom;
	axiom.push_back(LSymbols("0.3","1","1","0","0","F"));

	vector <LSymbols> tempVector;

	vector<vector<LSymbols>> prePred;
	prePred.push_back(tempVector);
	prePred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> inPred;
	inPred.push_back(tempVector);
	inPred.at(0).push_back(LSymbols("z","r","t", "0", "0","F"));

	vector<vector<LSymbols>> postPred;
	postPred.push_back(tempVector);
	postPred.at(0).push_back(LSymbols("0","0","0", "0", "0","?"));

	vector<vector<LSymbols>> suc;
	suc.push_back(tempVector);
	suc.at(0).push_back(LSymbols("z","r","t/R","0","0","F"));
	suc.at(0).push_back(LSymbols("z","R*r","t","0","0","F"));


	
	LSysParam newSymbolList(axiom, prePred, inPred, postPred, suc, iterator, ZSize, RSize, TSize, ThetaSize, PhiSize);
	//newSymbolList.print(newSymbolList.getFinalSymbolList());
	_finlaListOfLSymbols=newSymbolList.getFinalSymbolList();
	LTurtle turtle(newSymbolList.getFinalSymbolList(), nodeContainer);
	*/
	

////////////////////////////////////////////////////////////////////////////////
}
LSymbolsManager::~LSymbolsManager()
{

}