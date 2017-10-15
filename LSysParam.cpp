///////////////////////////////////////////////////////////////////////////////
// LSystem LSysParam.cpp
// ========
//	For creating LSystem string in multi rules context sensitive parametric stochastic cases!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////

#include "LSysParam.h"

LSysParam::LSysParam(const vector<LSymbols> &_ax, vector <vector <LSymbols>> &_prePred, vector <vector <LSymbols>> &_inPred, vector <vector <LSymbols>> &_postPred, vector <vector<LSymbols>> &_suc, const int _iter, const double _Z, const double _R, const double _T, double _Theta, double _Phi)
{
	thetaAngle = _Theta;
	phiAngle = _Phi;
	//clock_t startTime = clock();
	setString (_ax, _prePred, _inPred, _postPred, _suc, _iter, _Z, _R, _T);
	//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	expandListOfSymbol();

}
LSysParam::~LSysParam()
{
}
void LSysParam::setString(const vector<LSymbols> &_ax, vector <vector <LSymbols>> &_prePred, vector <vector <LSymbols>> &_inPred, vector <vector <LSymbols>> &_postPred, vector <vector<LSymbols>> &_suc, const int _iter, const double _Z, const double _R, const double _T)
{
	Z=_Z;
	T=_T;
	R=_R;
	iterator = _iter;
	for ( size_t i=0; i!= _ax.size();i++)
	{
		if (_ax[i].getClassType()!="?")
		{
			axiom.push_back((_ax[i]));
		}
	}
	
	axiom.push_back(LSymbols("0", "0", "0", "0", "0", "!"));


	finalSymbolList=axiom;

	for (size_t ii=0; ii<_suc.size(); ii++)
	{
		list<LSymbols> tempListSymbol;
		sucVectorOfListOfSymbols.push_back(tempListSymbol);
		copy_if( _suc.at(ii).begin(), _suc.at(ii).end(), back_inserter( sucVectorOfListOfSymbols.at(ii) ), [](const LSymbols ls) {return (ls.getClassType()!="?");});
	}
	
	
	for (size_t jj=0; jj <_prePred.size(); jj++)
	{
		vector <list <LSymbols>> tempVector;
		preVectorOfVectorOfListOfSymbols.push_back(tempVector); 
		list <LSymbols> tempList;
		preVectorOfVectorOfListOfSymbols.at(jj).push_back (tempList);
		copy( _prePred.at(jj).begin(), _prePred.at(jj).end(), back_inserter( preVectorOfVectorOfListOfSymbols.at(jj).at(0) ));
		preVectorOfVectorOfListOfSymbols.at(jj).push_back (tempList);
		copy_if( _inPred.at(jj).begin(), _inPred.at(jj).end(), back_inserter( preVectorOfVectorOfListOfSymbols.at(jj).at(1) ),[](const LSymbols ls) {return (ls.getClassType()!="?");});
		preVectorOfVectorOfListOfSymbols.at(jj).push_back (tempList);
		copy( _postPred.at(jj).begin(), _postPred.at(jj).end(), back_inserter( preVectorOfVectorOfListOfSymbols.at(jj).at(2) ));
		preVectorOfVectorOfListOfSymbols.at(jj).at(2).push_back (LSymbols("0", "0", "0", "0", "0", "!"));
	}
	
}

void LSysParam::expandListOfSymbol()
{


	list<LSymbols>::iterator iter1;
	list<LSymbols>::iterator predIt;

	list<LSymbols>::iterator printIt;
	list<LSymbols>::iterator endIter;



	list<LSymbols>::iterator iter2;

	list<LSymbols>::iterator memoryIter;
	list<LSymbols>::iterator memoryDelIt;


	for (int i=0; i<iterator; i++)
	{
		iter1=finalSymbolList.begin();
		endIter=finalSymbolList.end();

		for (iter1; iter1!=endIter; iter1++)
		{
			vector <int> resultIndexFire;
			for (size_t j=0; j<preVectorOfVectorOfListOfSymbols.size(); j++)
			{
				bool temp = true;
				memoryIter = iter1;

				for (size_t k=0; k < preVectorOfVectorOfListOfSymbols.at(j).size(); k++)
				{
					iter2 = preVectorOfVectorOfListOfSymbols.at(j).at(k).begin();

					for(iter2; iter2 != preVectorOfVectorOfListOfSymbols.at(j).at(k).end(); iter2++)
					{
						if ((*iter2).getClassType()=="?")
						{
							continue;
						}

						if ((*iter2).getClassType()=="!")
						{
							resultIndexFire.push_back(j);
							temp = false;
							break;
						}
						if ((*memoryIter).getClassType()!=(*iter2).getClassType())
						{
							temp = false;
							break;
						}
						memoryIter++;
					}
					if (temp==false)
					{
						break;
					}
				}
			}
			if (resultIndexFire.size()==0)
			{
				continue;
			}

			srand(time(0));
			int resultChoose = resultIndexFire.at(rand()%(resultIndexFire.size()));

			predIt = preVectorOfVectorOfListOfSymbols.at(resultChoose).at(0).begin();

			for (predIt; predIt != preVectorOfVectorOfListOfSymbols.at(resultChoose).at(0).end(); predIt++)
			{
				if ((*predIt).getClassType()!="?")
				{
					iter1++;
				}
			}
			list <LSymbols> memorySucList;

			list<LSymbols>::iterator memorySucIt;

			memorySucList.insert ( memorySucList.begin(), sucVectorOfListOfSymbols.at(resultChoose).begin(), sucVectorOfListOfSymbols.at(resultChoose).end());

			predIt = preVectorOfVectorOfListOfSymbols.at(resultChoose).at(1).begin();
			for (predIt; predIt != preVectorOfVectorOfListOfSymbols.at(resultChoose).at(1).end(); predIt++)
			{
				if ((*predIt).getClassType()!="?")
				{
					memorySucIt = memorySucList.begin();
					for (memorySucIt; memorySucIt!=memorySucList.end(); memorySucIt++)
					{
						string memoryDisString = (*memorySucIt).getOfDistance();
						string memoryRadString = (*memorySucIt).getOfRadius();
						string memoryTimString = (*memorySucIt).getOfTime();
						string memoryThetaString = (*memorySucIt).getOfTheta();
						string memoryPhiString = (*memorySucIt).getOfPhi();

						replace_all(memoryDisString, (*predIt).getOfDistance(), (*iter1).getOfDistance());
						replace_all(memoryDisString, (*predIt).getOfRadius(), (*iter1).getOfRadius());
						replace_all(memoryDisString, (*predIt).getOfTime(), (*iter1).getOfTime());
						replace_all(memoryDisString, "Z", lexical_cast<string>(Z));
						replace_all(memoryDisString, "R", lexical_cast<string>(R));
						replace_all(memoryDisString, "T", lexical_cast<string>(T));

						double resultl;
						string resultString;
						int err;
						err = ExpressionEvaluator::calculateDouble(memoryDisString,resultl);
						if (err != ExpressionEvaluator::eval_ok)
						{
							resultString = memoryDisString;
						}
						else
						{
							resultString = lexical_cast<string>(resultl);
						}
						(*memorySucIt).setDistance(resultString);

						replace_all(memoryRadString, (*predIt).getOfDistance(), (*iter1).getOfDistance());
						replace_all(memoryRadString, (*predIt).getOfRadius(), (*iter1).getOfRadius());
						replace_all(memoryRadString, (*predIt).getOfTime(), (*iter1).getOfTime());
						replace_all(memoryRadString, "Z", lexical_cast<string>(Z));
						replace_all(memoryRadString, "R", lexical_cast<string>(R));
						replace_all(memoryRadString, "T", lexical_cast<string>(T));

						err = ExpressionEvaluator::calculateDouble(memoryRadString,resultl);
						if (err != ExpressionEvaluator::eval_ok)
						{
							resultString = memoryRadString;
						}
						else
						{
							resultString = lexical_cast<string>(resultl);
						}

						(*memorySucIt).setRadius(resultString);

						replace_all(memoryTimString, (*predIt).getOfDistance(), (*iter1).getOfDistance());
						replace_all(memoryTimString, (*predIt).getOfRadius(), (*iter1).getOfRadius());
						replace_all(memoryTimString, (*predIt).getOfTime(), (*iter1).getOfTime());
						replace_all(memoryTimString, "Z", lexical_cast<string>(Z));
						replace_all(memoryTimString, "R", lexical_cast<string>(R));
						replace_all(memoryTimString, "T", lexical_cast<string>(T));

						err = ExpressionEvaluator::calculateDouble(memoryTimString,resultl);
						if (err != ExpressionEvaluator::eval_ok)
						{
							resultString = memoryTimString;
						}
						else
						{
							resultString = lexical_cast<string>(resultl);
						}

						(*memorySucIt).setTime(resultString);

						replace_all(memoryThetaString, (*predIt).getOfTheta(), (*iter1).getOfTheta());
						replace_all(memoryThetaString, "G", lexical_cast<string>(thetaAngle));

						err = ExpressionEvaluator::calculateDouble(memoryThetaString,resultl);

						if (err != ExpressionEvaluator::eval_ok)
						{
							resultString = memoryThetaString;
						}
						else
						{
							resultString = lexical_cast<string>(resultl);
						}


						(*memorySucIt).setTheta(resultString);

						replace_all(memoryPhiString, (*predIt).getOfPhi(), (*iter1).getOfPhi());
						replace_all(memoryPhiString, "P", lexical_cast<string>(phiAngle));

						err = ExpressionEvaluator::calculateDouble(memoryPhiString,resultl);

						if (err != ExpressionEvaluator::eval_ok)
						{
							resultString = memoryPhiString;
						}
						else
						{
							resultString = lexical_cast<string>(resultl);
						}

						(*memorySucIt).setPhi(resultString);
					}
					memoryDelIt = iter1;
					memoryDelIt++;

					finalSymbolList.erase(iter1);
					iter1 = memoryDelIt;
				}
				

			}
			finalSymbolList.insert(iter1, memorySucList.begin(), memorySucList.end());
			iter1--;
			memorySucList.clear();
		}
	}
	/*
	list<LSymbols>::iterator iter5;
	iter5 = finalSymbolList.begin();
	for (iter5; iter5 != finalSymbolList.end(); iter5++)
	{
		cout << (*iter5).getClassType() << "(" << (*iter5).getDistance() << " " <<(*iter5).getPhi() << ") ";
	}
	cout << endl;
	*/
}
list<LSymbols> LSysParam::getFinalSymbolList() const
{
	return finalSymbolList;
}
void LSysParam::print( list<LSymbols>& finalListOfSymbols ) const
{
	if ( finalListOfSymbols.empty() ) // list is empty
		cout << "List is empty";
	else
	{
		list<LSymbols>::iterator flos;
		flos = finalListOfSymbols.begin();
		for(flos; flos != finalListOfSymbols.end(); flos++)
		{
			cout<<(*flos).getClassType()<<"("<<(*flos).getDistance()<<","<<(*flos).getRadius()<<","<<(*flos).getTime()<<","<<(*flos).getTheta()<<","<<(*flos).getPhi()<<")";
		}
		cout <<endl;
	} 
} 

