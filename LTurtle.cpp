///////////////////////////////////////////////////////////////////////////////
// LSystem LTutle.cpp
// ========
//	Turtle interpretation of LSymbols objects!
//
//  AUTHOR: Ali Aghamir (a.kharrazi@gmail.com)
// CREATED: 2013-06-01
// 
///////////////////////////////////////////////////////////////////////////////

#include "LTurtle.h"


LTurtle::LTurtle(list <LSymbols>& _finalSymbolList, LNodesContainer& nodesContain)
{
	listOfSymbols=_finalSymbolList;
	//printlist(listOfSymbols);
	execute(nodesContain);
}
LTurtle::~LTurtle()
{

}
list <LSymbols> LTurtle::getSymbols2Turtle() const
{
	return listOfSymbols;
}
GLdouble LTurtle::round(GLdouble n, double d)
{
	return floor(n * pow(10., d) + .5) / pow(10., d);
}
void LTurtle::move()
{
	node1.setxPosition(round(node1.getxPosition()+distance*sin(node1.getPhiPosition())*cos(node1.getThetaPosition()),4));
	node1.setyPosition(round(node1.getyPosition()+distance*sin(node1.getPhiPosition())*sin(node1.getThetaPosition()),4));
	node1.setzPosition(round(node1.getzPosition()+distance*cos(node1.getPhiPosition()),4));
}
void LTurtle::rotatePositive()
{
	node1.setTheta(node1.getThetaPosition()+thetaAngle);
}
void LTurtle::rotateNegative()
{
	node1.setTheta(node1.getThetaPosition()-thetaAngle);
}
void LTurtle::rotate2zPositive()
{
	node1.setPhi(node1.getPhiPosition()+phiAngle);
}
void LTurtle::rotate2zNegative()
{
	node1.setPhi(node1.getPhiPosition()-phiAngle);
}
void LTurtle::execute(LNodesContainer &nodesContain)
{
	list<LSymbols>::iterator los;
	los = listOfSymbols.begin();
	for (los; los != listOfSymbols.end(); los++)
	{
		if((*los).getClassType()=="F")
		{
			distance=atof((*los).getDistance().c_str());
			move();
			nodesContain.addEndNode(node1);
			nodesContain.addStartNode(node1);
		}
		else if((*los).getClassType()=="A")
		{
			distance=atof((*los).getDistance().c_str());
			move();
			nodesContain.addEndNode(node1);
			nodesContain.addStartNode(node1);
		}
		else if((*los).getClassType()=="X")
		{
			distance=atof((*los).getDistance().c_str());
			move();
			nodesContain.addEndNode(node1);
			nodesContain.addStartNode(node1);
		}
		else if((*los).getClassType()=="B")
		{
			distance=atof((*los).getDistance().c_str());
			move();
			nodesContain.addEndNode(node1);
			nodesContain.addStartNode(node1);
		}
		else if((*los).getClassType()=="+")
		{
			thetaAngle=atof((*los).getTheta().c_str())*3.141593/180;
			rotatePositive();
		}
		else if ((*los).getClassType()=="-")
		{
			thetaAngle=atof((*los).getTheta().c_str())*3.141593/180;
			rotateNegative();
		}
		else if ((*los).getClassType()=="~")
		{
			phiAngle=atof((*los).getPhi().c_str())*3.141593/180;
			rotate2zPositive();
		}
		else if ((*los).getClassType()=="^")
		{
			phiAngle=atof((*los).getPhi().c_str())*3.141593/180;
			rotate2zNegative();
		}
		else if ((*los).getClassType()=="[")
		{
			stackNodes.push_back(node1);
		}
		else if ((*los).getClassType()=="]")
		{
			if(stackNodes.size()>0)
			{
				nodesContain.removeStartNode();
				nodesContain.addStartNode(stackNodes.back());
				node1=stackNodes.back();
				stackNodes.pop_back();
			}
			
		}
		else if((*los).getClassType()=="f")
		{
			nodesContain.removeStartNode();
			distance=atof((*los).getDistance().c_str());
			move();
			nodesContain.addStartNode(node1);
		}
	}
	nodesContain.removeStartNode();
}

void LTurtle::printlist( list<LSymbols>& finalListOfSymbols )
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