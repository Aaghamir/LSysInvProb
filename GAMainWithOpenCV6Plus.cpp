/* ----------------------------------------------------------------------------
  ex5.C
  mbwall 10dec94
  Copyright 1995-1996  Massachusetts Institute of Technology

 DESCRIPTION:
   Example program for a composite genome derived from the GAGenome and
containing a 2DBinStr genome and a Bin2Dec genome.  This program uses
a steady-state GA to match a 2D pattern in the 2DBinStr part of the genome
and a sequence of numbers in the Bin2Dec part.
   In this example we derive a new genome and a new crossover object to be
used with it.  All of the operators (initialization, mutation, crossover, 
comparison, and objective) are defined as member functions but are also
override-able on any instance of the new genome.
---------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
using std::abs;
#include <ga/GARealGenome.h>
#include <ga/GAAllele.h>
#include <ga/GA1DArrayGenome.h>
#include <ga/GA2DArrayGenome.h>
#include <ga/GA3DArrayGenome.h>
#include <ga/GASStateGA.h>
#include <ga/std_stream.h>
#include <GL/freeglut.h>
#include "LSysParam.h"
#include "LSymbolsManager.h"
#include "LNodesContainer.h"
#include <ga/ga.h>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <iostream>

#include <stdlib.h>
using namespace cv;
using namespace std;


#define cout STD_COUT
#define cerr STD_CERR
#define istream STD_ISTREAM
#define ostream STD_OSTREAM
#define ifstream STD_IFSTREAM


int iterNum = 3;
int ruleNum = 1;
int axiomSize =1;
int prePredSize = 1;
//int inPredSize = 1;
int postPredSize = 1;
int sucSize = 9;


GLdouble ZSizet=1;
GLdouble RSizet=1;
GLdouble TSizet=1;
GLdouble ThetaSizet=1;
GLdouble PhiSizet=1;
void printvector(vector <LSymbols>& finalListOfSymbols);
void printlist(list <LSymbols>& finalListOfSymbols);
float stringScore(list<LSymbols>& finalStringGA, list<LSymbols>& finalString);
float imageScore(list<LSymbols>& finalStringGA, list<LSymbols>& finalString);
float comparatorRec(list<LSymbols>& finalStringGA, list<LSymbols>::iterator& iterGA, list<LSymbols>& finalString, list<LSymbols>::iterator& iter, int maxLevel);
list<LSymbols> changeFinalList(list <LSymbols>& finalListOfSymbols);

// This is the class definition for the new genome.  The default operators are
// defined as static member functions.  They can be overridden if necessary by
// anyone making an instance of this class - you don't need to derive a new
// class to change the behaviour of one or two of its operators.
class CompositeGenome : public GAGenome {
public:
  GADefineIdentity("CompositeGenome", 201);

  static void CompositeInitializer(GAGenome&);
  static int CompositeMutator(GAGenome&, float);
  static float CompositeComparator(const GAGenome&, const GAGenome&);
  static int CompositeCrossover(const GAGenome&, const GAGenome&,
				GAGenome*, GAGenome*);
public:

  CompositeGenome(GARealAlleleSet&, GARealAlleleSet&, GARealAlleleSet&, GARealAlleleSet&, GARealAlleleSet&, GAAlleleSet<char*>&, GAAlleleSet<char*>&, GAAlleleSet<char*>&, GAAlleleSet<char*>&, GAAlleleSet<char*>&, GAAlleleSet<char*>&, GAAlleleSet<char*>&, GAAlleleSet<char*>&, GAAlleleSet<char*>&,
		  GAGenome::Evaluator f=NULL, void* u=NULL);
  CompositeGenome(const CompositeGenome & orig);
  CompositeGenome& operator=(const GAGenome& g);
  virtual ~CompositeGenome();
  virtual GAGenome* clone(GAGenome::CloneMethod) const ;
  virtual void copy(const GAGenome & c);
  virtual int equal(const GAGenome& g) const;
  virtual int read(istream & is);
  virtual int write(ostream & os) const;


  GARealGenome& getDis2Axiom() const {return *dis2Axiom;}
  GARealGenome& getRad2Axiom() const {return *rad2Axiom;}
  GARealGenome& getTim2Axiom() const {return *tim2Axiom;}
  GARealGenome& getThe2Axiom() const {return *the2Axiom;}
  GARealGenome& getPhi2Axiom() const {return *phi2Axiom;}

  GA1DArrayAlleleGenome<char*>& getStr2Axiom1() const{return *str2Axiom1;}
  GA1DArrayAlleleGenome<char*>& getStr2Axiom2() const{return *str2Axiom2;}

  GA2DArrayAlleleGenome<char*>& getStr2PrePred() const {return *str2PrePred;}
  
  GA2DArrayAlleleGenome<char*>& getStr2PostPred() const {return *str2PostPred;}

  GA2DArrayAlleleGenome<char*>& getDis2Suc() const {return *dis2Suc;}
  GA2DArrayAlleleGenome<char*>& getRad2Suc() const {return *rad2Suc;}
  GA2DArrayAlleleGenome<char*>& getTim2Suc() const {return *tim2Suc;}
  GA2DArrayAlleleGenome<char*>& getThe2Suc() const {return *the2Suc;}
  GA2DArrayAlleleGenome<char*>& getPhi2Suc() const {return *phi2Suc;}
  GA2DArrayAlleleGenome<char*>& getSign2Suc() const {return *sign2Suc;}
  GA2DArrayAlleleGenome<char*>& getCType2Suc1() const {return *ctype2Suc1;}
  GA2DArrayAlleleGenome<char*>& getCType2Suc2() const {return *ctype2Suc2;}

  //inline float stringScore(list<LSymbols>& finalStringGA, list<LSymbols>& finalString);
  //inline float imageScore(list<LSymbols>& finalStringGA, list<LSymbols>& finalString);
  //inline float comparatorRec(list<LSymbols>& finalStringGA, list<LSymbols>::iterator& iterGA, list<LSymbols>& finalString, list<LSymbols>::iterator& iter, int maxLevel);

  //list<LSymbols> getGAFinalList() const {return gaFinalList;}


protected:
	GARealGenome* dis2Axiom;
	GARealGenome* rad2Axiom;
	GARealGenome* tim2Axiom;
	GARealGenome* the2Axiom;
	GARealGenome* phi2Axiom;

  GA1DArrayAlleleGenome<char*>* str2Axiom1;
  GA1DArrayAlleleGenome<char*>* str2Axiom2;

  GA2DArrayAlleleGenome<char*>* str2PrePred;

  GA2DArrayAlleleGenome<char*>* str2PostPred;

  GA2DArrayAlleleGenome<char*>* dis2Suc;
  GA2DArrayAlleleGenome<char*>* rad2Suc;
  GA2DArrayAlleleGenome<char*>* tim2Suc;
  GA2DArrayAlleleGenome<char*>* the2Suc;
  GA2DArrayAlleleGenome<char*>* phi2Suc;
  GA2DArrayAlleleGenome<char*>* sign2Suc;
  GA2DArrayAlleleGenome<char*>* ctype2Suc1;
  GA2DArrayAlleleGenome<char*>* ctype2Suc2;
  //list<LSymbols> gaFinalList;
  //list<LSymbols> targetList;
};







// Member functions for the composite genome object
CompositeGenome::
CompositeGenome( GARealAlleleSet& dis2a, GARealAlleleSet& rad2a, GARealAlleleSet& tim2a, GARealAlleleSet& the2a, GARealAlleleSet& phi2a, GAAlleleSet<char*>& funcClassType, GAAlleleSet<char*>& funcSpClassType, GAAlleleSet<char*>& contextClassType, GAAlleleSet<char*>& signClassType, GAAlleleSet<char*>& dis2s, GAAlleleSet<char*>& rad2s, GAAlleleSet<char*>& tim2s, GAAlleleSet<char*>& the2s, GAAlleleSet<char*>& phi2s,
		GAGenome::Evaluator f, void* u) :
		GAGenome( CompositeInitializer,
			 CompositeMutator,
			 CompositeComparator) {
		  evaluator(f); userData(u); crossover(CompositeCrossover);
		  dis2Axiom = new GARealGenome(axiomSize, dis2a, f, u);
		  rad2Axiom = new GARealGenome(axiomSize, rad2a, f, u);
		  tim2Axiom = new GARealGenome(axiomSize, tim2a, f, u);
		  the2Axiom = new GARealGenome(axiomSize, the2a, f, u);
		  phi2Axiom = new GARealGenome(axiomSize, phi2a, f, u);

		  str2Axiom1 = new GA1DArrayAlleleGenome<char*>(1, funcClassType, f, u);
		  str2Axiom2 = new GA1DArrayAlleleGenome<char*>(axiomSize-1, funcSpClassType, f, u);

		  str2PrePred = new GA2DArrayAlleleGenome<char*>(3*ruleNum, prePredSize, contextClassType, f, u);
		  
		  str2PostPred = new GA2DArrayAlleleGenome<char*>(3*ruleNum, postPredSize, contextClassType, f, u);

		  dis2Suc = new GA2DArrayAlleleGenome<char*>(3*ruleNum, sucSize, dis2s, f, u);
		  rad2Suc = new GA2DArrayAlleleGenome<char*>(3*ruleNum, sucSize, rad2s, f, u);
		  tim2Suc = new GA2DArrayAlleleGenome<char*>(3*ruleNum, sucSize, tim2s, f, u);
		  the2Suc = new GA2DArrayAlleleGenome<char*>(3*ruleNum, sucSize+8, the2s, f, u);
		  phi2Suc = new GA2DArrayAlleleGenome<char*>(3*ruleNum, sucSize+8, phi2s, f, u);
		  sign2Suc = new GA2DArrayAlleleGenome<char*>(3*ruleNum, 6, signClassType, f, u);
		  ctype2Suc1 = new GA2DArrayAlleleGenome<char*>(3*ruleNum, 1, funcClassType, f, u);
		  ctype2Suc2 = new GA2DArrayAlleleGenome<char*>(3*ruleNum, sucSize-1, funcSpClassType, f, u);

		  //gaFinalList=gflol;

		}

CompositeGenome::CompositeGenome(const CompositeGenome & orig) {
	
	dis2Axiom = new GARealGenome(orig.getDis2Axiom());
	rad2Axiom = new GARealGenome(orig.getRad2Axiom());
	tim2Axiom = new GARealGenome(orig.getTim2Axiom());
	the2Axiom = new GARealGenome(orig.getThe2Axiom());
	phi2Axiom = new GARealGenome(orig.getPhi2Axiom());
	str2Axiom1 = new GA1DArrayAlleleGenome<char*>(orig.getStr2Axiom1());
	str2Axiom2 = new GA1DArrayAlleleGenome<char*>(orig.getStr2Axiom2());

	str2PrePred = new GA2DArrayAlleleGenome<char*>(orig.getStr2PrePred());
	
	str2PostPred = new GA2DArrayAlleleGenome<char*>(orig.getStr2PostPred());

	dis2Suc = new GA2DArrayAlleleGenome<char*>(orig.getDis2Suc());
	rad2Suc = new GA2DArrayAlleleGenome<char*>(orig.getRad2Suc());
	tim2Suc = new GA2DArrayAlleleGenome<char*>(orig.getTim2Suc());
	the2Suc = new GA2DArrayAlleleGenome<char*>(orig.getThe2Suc());
	phi2Suc = new GA2DArrayAlleleGenome<char*>(orig.getPhi2Suc());
	sign2Suc = new GA2DArrayAlleleGenome<char*>(orig.getSign2Suc());
	ctype2Suc1 = new GA2DArrayAlleleGenome<char*>(orig.getCType2Suc1());
	ctype2Suc2 = new GA2DArrayAlleleGenome<char*>(orig.getCType2Suc2());

	//gaFinalList=orig.getGAFinalList();
	copy(orig);
}
  
CompositeGenome& 
CompositeGenome::operator=(const GAGenome& g) { copy(g); return *this; }

CompositeGenome::~CompositeGenome() {delete dis2Axiom; delete rad2Axiom; delete tim2Axiom; delete the2Axiom; delete phi2Axiom; delete str2Axiom1; delete str2Axiom2; delete str2PrePred; delete str2PostPred; delete dis2Suc; delete rad2Suc; delete tim2Suc; delete the2Suc; delete phi2Suc; delete sign2Suc; delete ctype2Suc1; delete ctype2Suc2;}

GAGenome* 
CompositeGenome::clone(GAGenome::CloneMethod) const {
  return new CompositeGenome(*this);
}

void 
CompositeGenome::copy(const GAGenome & c){
  if(&c != this && sameClass(c)){
    GAGenome::copy(c);
    CompositeGenome & bc = (CompositeGenome &)c;
	dis2Axiom->copy(*(bc.dis2Axiom));
	rad2Axiom->copy(*(bc.rad2Axiom));
	tim2Axiom->copy(*(bc.tim2Axiom));
	the2Axiom->copy(*(bc.the2Axiom));
	phi2Axiom->copy(*(bc.phi2Axiom));

    str2Axiom1->copy(*(bc.str2Axiom1));
	str2Axiom2->copy(*(bc.str2Axiom2));
	str2PrePred->copy(*(bc.str2PrePred));
	str2PostPred->copy(*(bc.str2PostPred));
	dis2Suc->copy(*(bc.dis2Suc));
	rad2Suc->copy(*(bc.rad2Suc));
	tim2Suc->copy(*(bc.tim2Suc));
	the2Suc->copy(*(bc.the2Suc));
	phi2Suc->copy(*(bc.phi2Suc));
	sign2Suc->copy(*(bc.sign2Suc));
	ctype2Suc1->copy(*(bc.ctype2Suc1));
	ctype2Suc2->copy(*(bc.ctype2Suc2));
	//gaFinalList=bc.gaFinalList;
  }
}

int 
CompositeGenome::equal(const GAGenome& g) const {
  CompositeGenome& genome = (CompositeGenome&)g;
  return ((*dis2Axiom==*genome.dis2Axiom)&&(*rad2Axiom==*genome.rad2Axiom)&&(*tim2Axiom==*genome.tim2Axiom)&&(*the2Axiom==*genome.the2Axiom)&&(*phi2Axiom==*genome.phi2Axiom)&&(*str2Axiom1 == *genome.str2Axiom1) &&(*str2Axiom2 == *genome.str2Axiom2) && (*str2PrePred == *genome.str2PrePred)&&(*str2PostPred==*genome.str2PostPred)&&(*dis2Suc==*genome.dis2Suc)&&(*rad2Suc==*genome.rad2Suc)&&(*tim2Suc==*genome.tim2Suc)&&(*the2Suc==*genome.the2Suc)&&(*phi2Suc==*genome.phi2Suc)&&(*sign2Suc==*genome.sign2Suc)&&(*ctype2Suc1==*genome.ctype2Suc1)&&(*ctype2Suc2==*genome.ctype2Suc2));
}

int 
CompositeGenome::read(istream & is) {
  is >> *dis2Axiom >> *rad2Axiom >> *tim2Axiom >> *the2Axiom >> *phi2Axiom >> *str2Axiom1 >> *str2Axiom2 >> *str2PrePred >> *str2PostPred >> *dis2Suc >> *rad2Suc >> *tim2Suc >> *the2Suc >> *phi2Suc >> *sign2Suc >> *ctype2Suc1 >> *ctype2Suc2; 
  return is.fail() ? 1 : 0; 
}

int 
CompositeGenome::write(ostream & os) const {
  
  os << "\n" << *dis2Axiom << "\n" << *rad2Axiom << "\n" << *tim2Axiom << "\n" << *the2Axiom << "\n" << *phi2Axiom << "\n"<< *str2Axiom1 << "\n"<< *str2Axiom2 << "\n"<< *str2PrePred << "\n"<< *str2PostPred << "\n"<< *dis2Suc << "\n"<< *rad2Suc << "\n"<< *tim2Suc << "\n"<< *the2Suc << "\n"<< *phi2Suc << "\n"<< *sign2Suc << "\n"<< *ctype2Suc1 << "\n" << *ctype2Suc2 << "\n";
  return os.fail() ? 1 : 0;
}




// These are the default initialization, mutation, and comparator operators for
// this genome class.  They are defined as static functions of the composite
// genome class and they're defaults for the class.  But they can be overridden
// on any instance of the genome.

// The initializer just calls the initializer for each of the genomes that are
// in the composite genome.

// I would have used simply 'Initializer', 'Mutator', etc rather than
// 'CompositeInitializer' but old versions of g++ are brain-dead and don't
// get the encapsulation properly.
void 
CompositeGenome::CompositeInitializer(GAGenome & c) {
  CompositeGenome & child = (CompositeGenome &)c;
  child.getDis2Axiom().initialize();
  child.getRad2Axiom().initialize();
  child.getTim2Axiom().initialize();
  child.getThe2Axiom().initialize();
  child.getPhi2Axiom().initialize();
  
  child.getStr2Axiom1().initialize();
  child.getStr2Axiom2().initialize();
  
  child.getStr2PrePred().initialize();
  
  child.getStr2PostPred().initialize();
  child.getDis2Suc().initialize();
  child.getRad2Suc().initialize();
  child.getTim2Suc().initialize();
  child.getThe2Suc().initialize();
  child.getPhi2Suc().initialize();
  child.getSign2Suc().initialize();
  child.getCType2Suc1().initialize();
  child.getCType2Suc2().initialize();


  child._evaluated = gaFalse;
  //cout<<"init"<<endl;
}


// The mutator just calls the mutator for each of the component genomes.
int 
CompositeGenome::CompositeMutator(GAGenome & c, float pmut) {
  CompositeGenome & child = (CompositeGenome &)c;
  int nmut = child.getDis2Axiom().mutate(pmut) + child.getRad2Axiom().mutate(pmut) + child.getTim2Axiom().mutate(pmut) + child.getThe2Axiom().mutate(pmut) + child.getPhi2Axiom().mutate(pmut) + child.getStr2Axiom1().mutate(pmut) + child.getStr2Axiom2().mutate(pmut) + child.getStr2PrePred().mutate(pmut) + child.getStr2PostPred().mutate(pmut) + child.getDis2Suc().mutate(pmut) + child.getRad2Suc().mutate(pmut) + child.getTim2Suc().mutate(pmut) + child.getThe2Suc().mutate(pmut) + child.getPhi2Suc().mutate(pmut) + child.getSign2Suc().mutate(pmut) + child.getCType2Suc1().mutate(pmut) + child.getCType2Suc2().mutate(pmut);
  if(nmut) child._evaluated = gaFalse;
  return nmut;
}

// The comparator just calls the comparators for each of the component genomes,
// then averages the score.
float 
CompositeGenome::CompositeComparator(const GAGenome& a, const GAGenome& b) {
  CompositeGenome& sis = (CompositeGenome &)a;
  CompositeGenome& bro = (CompositeGenome &)b;
  return (1/17) * (sis.getDis2Axiom().compare(bro) + sis.getRad2Axiom().compare(bro) + sis.getTim2Axiom().compare(bro) + sis.getThe2Axiom().compare(bro) + sis.getPhi2Axiom().compare(bro) + sis.getStr2Axiom1().compare(bro) + sis.getStr2Axiom2().compare(bro) + sis.getStr2PrePred().compare(bro) + sis.getStr2PostPred().compare(bro) + sis.getDis2Suc().compare(bro) + sis.getRad2Suc().compare(bro) + sis.getTim2Suc().compare(bro) + sis.getThe2Suc().compare(bro) + sis.getPhi2Suc().compare(bro) + sis.getSign2Suc().compare(bro) + sis.getCType2Suc1().compare(bro) + sis.getCType2Suc2().compare(bro));
}

// The crossover operator invokes the crossover for each of the genomes in the
// composite genome.  We use sexual crossover only, and we do not test to see
// if no crossover has been assigned.
int
CompositeGenome::
CompositeCrossover(const GAGenome& a, const GAGenome& b,
		   GAGenome* c, GAGenome* d){ 
  CompositeGenome& mom = (CompositeGenome&)a;
  CompositeGenome& dad = (CompositeGenome&)b;
  int n=0;

  GAGenome::SexualCrossover dis2axiomcross = mom.dis2Axiom->sexual();
  GAGenome::SexualCrossover rad2axiomcross = mom.rad2Axiom->sexual();
  GAGenome::SexualCrossover tim2axiomcross = mom.tim2Axiom->sexual();
  GAGenome::SexualCrossover the2axiomcross = mom.the2Axiom->sexual();
  GAGenome::SexualCrossover phi2axiomcross = mom.phi2Axiom->sexual();
  GAGenome::SexualCrossover str2axiomcross1 = mom.str2Axiom1->sexual();
  GAGenome::SexualCrossover str2axiomcross2 = mom.str2Axiom2->sexual();
  GAGenome::SexualCrossover str2prepredcross = mom.str2PrePred->sexual();
  GAGenome::SexualCrossover str2postpredcross = mom.str2PostPred->sexual();
  GAGenome::SexualCrossover dis2succross = mom.dis2Suc->sexual();
  GAGenome::SexualCrossover rad2succross = mom.rad2Suc->sexual();
  GAGenome::SexualCrossover tim2succross = mom.tim2Suc->sexual();
  GAGenome::SexualCrossover the2succross = mom.the2Suc->sexual();
  GAGenome::SexualCrossover phi2succross = mom.phi2Suc->sexual();
  GAGenome::SexualCrossover sign2succross = mom.sign2Suc->sexual();
  GAGenome::SexualCrossover ctype2succross1 = mom.ctype2Suc1->sexual();
  GAGenome::SexualCrossover ctype2succross2 = mom.ctype2Suc2->sexual();


  if(c && d){
    CompositeGenome& sis = (CompositeGenome&)*c;
    CompositeGenome& bro = (CompositeGenome&)*d;

	(*dis2axiomcross)(mom.getDis2Axiom(),dad.getDis2Axiom(), &sis.getDis2Axiom(), &bro.getDis2Axiom());
	(*rad2axiomcross)(mom.getRad2Axiom(),dad.getRad2Axiom(), &sis.getRad2Axiom(), &bro.getRad2Axiom());
	(*tim2axiomcross)(mom.getTim2Axiom(),dad.getTim2Axiom(), &sis.getTim2Axiom(), &bro.getTim2Axiom());
	(*the2axiomcross)(mom.getThe2Axiom(),dad.getThe2Axiom(), &sis.getThe2Axiom(), &bro.getThe2Axiom());
	(*phi2axiomcross)(mom.getPhi2Axiom(),dad.getPhi2Axiom(), &sis.getPhi2Axiom(), &bro.getPhi2Axiom());
    (*str2axiomcross1)(mom.getStr2Axiom1(), dad.getStr2Axiom1(), &sis.getStr2Axiom1(), &bro.getStr2Axiom1());
	(*str2axiomcross2)(mom.getStr2Axiom2(), dad.getStr2Axiom2(), &sis.getStr2Axiom2(), &bro.getStr2Axiom2());
	(*str2prepredcross)(mom.getStr2PrePred(), dad.getStr2PrePred(), &sis.getStr2PrePred(), &bro.getStr2PrePred());
	(*str2postpredcross)(mom.getStr2PostPred(), dad.getStr2PostPred(), &sis.getStr2PostPred(), &bro.getStr2PostPred());
	(*dis2succross)(mom.getDis2Suc(), dad.getDis2Suc(), &sis.getDis2Suc(), &bro.getDis2Suc());
	(*rad2succross)(mom.getRad2Suc(), dad.getRad2Suc(), &sis.getRad2Suc(), &bro.getRad2Suc());
	(*tim2succross)(mom.getTim2Suc(), dad.getTim2Suc(), &sis.getTim2Suc(), &bro.getTim2Suc());
	(*the2succross)(mom.getThe2Suc(), dad.getThe2Suc(), &sis.getThe2Suc(), &bro.getThe2Suc());
	(*phi2succross)(mom.getPhi2Suc(), dad.getPhi2Suc(), &sis.getPhi2Suc(), &bro.getPhi2Suc());
	(*sign2succross)(mom.getSign2Suc(), dad.getSign2Suc(), &sis.getSign2Suc(), &bro.getSign2Suc());
	(*ctype2succross1)(mom.getCType2Suc1(), dad.getCType2Suc1(), &sis.getCType2Suc1(), &bro.getCType2Suc1());
	(*ctype2succross2)(mom.getCType2Suc2(), dad.getCType2Suc2(), &sis.getCType2Suc2(), &bro.getCType2Suc2());

    sis._evaluated = gaFalse;
    bro._evaluated = gaFalse;
    n = 2;
  }
  else if(c){
    CompositeGenome& sis = (CompositeGenome&)*c;

	(*dis2axiomcross)(mom.getDis2Axiom(),dad.getDis2Axiom(), &sis.getDis2Axiom(), 0);
	(*rad2axiomcross)(mom.getRad2Axiom(),dad.getRad2Axiom(), &sis.getRad2Axiom(), 0);
	(*tim2axiomcross)(mom.getTim2Axiom(),dad.getTim2Axiom(), &sis.getTim2Axiom(), 0);
	(*the2axiomcross)(mom.getThe2Axiom(),dad.getThe2Axiom(), &sis.getThe2Axiom(), 0);
	(*phi2axiomcross)(mom.getPhi2Axiom(),dad.getPhi2Axiom(), &sis.getPhi2Axiom(), 0);
    (*str2axiomcross1)(mom.getStr2Axiom1(), dad.getStr2Axiom1(), &sis.getStr2Axiom1(), 0);
	(*str2axiomcross2)(mom.getStr2Axiom2(), dad.getStr2Axiom2(), &sis.getStr2Axiom2(), 0);
	(*str2prepredcross)(mom.getStr2PrePred(), dad.getStr2PrePred(), &sis.getStr2PrePred(), 0);
	(*str2postpredcross)(mom.getStr2PostPred(), dad.getStr2PostPred(), &sis.getStr2PostPred(), 0);
	(*dis2succross)(mom.getDis2Suc(), dad.getDis2Suc(), &sis.getDis2Suc(), 0);
	(*rad2succross)(mom.getRad2Suc(), dad.getRad2Suc(), &sis.getRad2Suc(), 0);
	(*tim2succross)(mom.getTim2Suc(), dad.getTim2Suc(), &sis.getTim2Suc(), 0);
	(*the2succross)(mom.getThe2Suc(), dad.getThe2Suc(), &sis.getThe2Suc(), 0);
	(*phi2succross)(mom.getPhi2Suc(), dad.getPhi2Suc(), &sis.getPhi2Suc(), 0);
	(*sign2succross)(mom.getSign2Suc(), dad.getSign2Suc(), &sis.getSign2Suc(), 0);
	(*ctype2succross1)(mom.getCType2Suc1(), dad.getCType2Suc1(), &sis.getCType2Suc1(), 0);
	(*ctype2succross2)(mom.getCType2Suc2(), dad.getCType2Suc2(), &sis.getCType2Suc2(), 0);
    
    sis._evaluated = gaFalse;
    n = 1;
  }
  else if(d){
    CompositeGenome& bro = (CompositeGenome&)*d;

	(*dis2axiomcross)(mom.getDis2Axiom(),dad.getDis2Axiom(), 0, &bro.getDis2Axiom());
	(*rad2axiomcross)(mom.getRad2Axiom(),dad.getRad2Axiom(), 0, &bro.getRad2Axiom());
	(*tim2axiomcross)(mom.getTim2Axiom(),dad.getTim2Axiom(), 0, &bro.getTim2Axiom());
	(*the2axiomcross)(mom.getThe2Axiom(),dad.getThe2Axiom(), 0, &bro.getThe2Axiom());
	(*phi2axiomcross)(mom.getPhi2Axiom(),dad.getPhi2Axiom(), 0, &bro.getPhi2Axiom());
	(*str2axiomcross1)(mom.getStr2Axiom1(), dad.getStr2Axiom1(), 0, &bro.getStr2Axiom1());
	(*str2axiomcross2)(mom.getStr2Axiom2(), dad.getStr2Axiom2(), 0, &bro.getStr2Axiom2());
	(*str2prepredcross)(mom.getStr2PrePred(), dad.getStr2PrePred(), 0, &bro.getStr2PrePred());
	(*str2postpredcross)(mom.getStr2PostPred(), dad.getStr2PostPred(), 0, &bro.getStr2PostPred());
	(*dis2succross)(mom.getDis2Suc(), dad.getDis2Suc(), 0, &bro.getDis2Suc());
	(*rad2succross)(mom.getRad2Suc(), dad.getRad2Suc(), 0, &bro.getRad2Suc());
	(*tim2succross)(mom.getTim2Suc(), dad.getTim2Suc(), 0, &bro.getTim2Suc());
	(*the2succross)(mom.getThe2Suc(), dad.getThe2Suc(), 0, &bro.getThe2Suc());
	(*phi2succross)(mom.getPhi2Suc(), dad.getPhi2Suc(), 0, &bro.getPhi2Suc());
	(*sign2succross)(mom.getSign2Suc(), dad.getSign2Suc(), 0, &bro.getSign2Suc());
	(*ctype2succross1)(mom.getCType2Suc1(), dad.getCType2Suc1(), 0, &bro.getCType2Suc1());
	(*ctype2succross2)(mom.getCType2Suc2(), dad.getCType2Suc2(), 0, &bro.getCType2Suc2());

    bro._evaluated = gaFalse;
    n = 1;
  }

  return n;
}


















// In this objective function we try to match the pattern in the 2D part of the
// genome and match the sequence of values in the binary-to-decimal part of the
// genome.  The overall score is the sum of both parts.
float
Objective(GAGenome & g) {
  CompositeGenome & genome = (CompositeGenome &)g;

  
  GARealGenome& dis2Axiom = genome.getDis2Axiom();
  GARealGenome& rad2Axiom = genome.getRad2Axiom();
  GARealGenome& tim2Axiom = genome.getTim2Axiom();
  GARealGenome& the2Axiom = genome.getThe2Axiom();
  GARealGenome& phi2Axiom = genome.getPhi2Axiom();
  GA1DArrayAlleleGenome<char*>& str2Axiom1 = genome.getStr2Axiom1();
  GA1DArrayAlleleGenome<char*>& str2Axiom2 = genome.getStr2Axiom2();
  GA2DArrayAlleleGenome<char*>& str2PrePred = genome.getStr2PrePred();
  GA2DArrayAlleleGenome<char*>& str2PostPred = genome.getStr2PostPred();
  GA2DArrayAlleleGenome<char*>& dis2Suc = genome.getDis2Suc();
  GA2DArrayAlleleGenome<char*>& rad2Suc = genome.getRad2Suc();
  GA2DArrayAlleleGenome<char*>& tim2Suc = genome.getTim2Suc();
  GA2DArrayAlleleGenome<char*>& the2Suc = genome.getThe2Suc();
  GA2DArrayAlleleGenome<char*>& phi2Suc = genome.getPhi2Suc();
  GA2DArrayAlleleGenome<char*>& sign2Suc = genome.getSign2Suc();
  GA2DArrayAlleleGenome<char*>& ctype2Suc1 = genome.getCType2Suc1();
  GA2DArrayAlleleGenome<char*>& ctype2Suc2 = genome.getCType2Suc2();


  /////////////////////////////////////////////////////////////////////////////////////
	list<LSymbols> finalString2;
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.087","0","+"));
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.087","0","+"));
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0","0","["));
	finalString2.push_back(LSymbols("0","0","0","0.436","0","+"));
	finalString2.push_back(LSymbols("6","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.087","0","+"));
	finalString2.push_back(LSymbols("6","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.087","0","+"));
	finalString2.push_back(LSymbols("6","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0","0","["));
	finalString2.push_back(LSymbols("0","0","0","0.436","0","+"));
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.174","0","+"));
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.174","0","+"));
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0","0","["));
	finalString2.push_back(LSymbols("0","0","0","0.873","0","+"));
	finalString2.push_back(LSymbols("24","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0","0","]"));
	finalString2.push_back(LSymbols("0","0","0","0","0","["));
	finalString2.push_back(LSymbols("0","0","0","0.349","0","-"));
	finalString2.push_back(LSymbols("24","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0","0","]"));
	finalString2.push_back(LSymbols("0","0","0","0","0","]"));
	finalString2.push_back(LSymbols("0","0","0","0","0","["));
	finalString2.push_back(LSymbols("0","0","0","0.261","0","-"));
	finalString2.push_back(LSymbols("24","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.523","0","+"));
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.174","0","-"));
	finalString2.push_back(LSymbols("6","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0","0","["));
	finalString2.push_back(LSymbols("0","0","0","0.290","0","+"));
	finalString2.push_back(LSymbols("8","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.436","0","+"));
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.436","0","+"));
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0","0","]"));
	finalString2.push_back(LSymbols("0","0","0","0","0","["));
	finalString2.push_back(LSymbols("0","0","0","0.436","0","-"));
	finalString2.push_back(LSymbols("24","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0","0","]"));
	finalString2.push_back(LSymbols("0","0","0","0","0","]"));
	finalString2.push_back(LSymbols("0","0","0","0","0","]"));
	finalString2.push_back(LSymbols("0","0","0","0","0","["));
	finalString2.push_back(LSymbols("0","0","0","0.174","0","-"));
	finalString2.push_back(LSymbols("24","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.262","0","+"));
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.087","0","-"));
	finalString2.push_back(LSymbols("6","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0","0","["));
	finalString2.push_back(LSymbols("0","0","0","0.145","0","+"));
	finalString2.push_back(LSymbols("8","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.218","0","+"));
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0.218","0","+"));
	finalString2.push_back(LSymbols("12","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0","0","]"));
	finalString2.push_back(LSymbols("0","0","0","0","0","["));
	finalString2.push_back(LSymbols("0","0","0","0.218","0","-"));
	finalString2.push_back(LSymbols("24","1","1","0","0","F"));
	finalString2.push_back(LSymbols("0","0","0","0","0","]"));
	finalString2.push_back(LSymbols("0","0","0","0","0","]"));
	finalString2.push_back(LSymbols("0","0","0","0","0","!"));

	//////////////////////////////////////////////////////////////////////////////////////////////////
 
  vector<LSymbols> axiom;
  axiom.push_back(LSymbols(lexical_cast<string>(dis2Axiom.gene(0)),lexical_cast<string>(rad2Axiom.gene(0)),lexical_cast<string>(tim2Axiom.gene(0)),lexical_cast<string>(the2Axiom.gene(0)),lexical_cast<string>(phi2Axiom.gene(0)),lexical_cast<string>(str2Axiom1.gene(0))));
  for (int i=1; i<axiomSize; i++)
  {
	  axiom.push_back(LSymbols(lexical_cast<string>(dis2Axiom.gene(i)),lexical_cast<string>(rad2Axiom.gene(i)),lexical_cast<string>(tim2Axiom.gene(i)),lexical_cast<string>(the2Axiom.gene(i)),lexical_cast<string>(phi2Axiom.gene(i)),lexical_cast<string>(str2Axiom2.gene(i-1))));
  }
  //printvector(axiom);
  //cout<<endl;
  vector <LSymbols> tempVector;

  vector<vector<LSymbols>> prePred;
  for (int i=0; i<3*ruleNum; i++)
  {
	  prePred.push_back(tempVector);
	  for (int j=0; j<prePredSize; j++)
	  {
		  prePred.at(i).push_back(LSymbols("z","r","t", "th", "ph",lexical_cast<string>(str2PrePred.gene(i,j))));
	  }
  }
  
  //printvector(prePred.at(0));
  //cout<<endl;

  vector<vector<LSymbols>> inPred;
  for (int i=0; i<3*ruleNum; i++)
  {
	  inPred.push_back(tempVector);
	  inPred.at(i).push_back(LSymbols("z","r","t", "th", "ph","X"));
	  inPred.push_back(tempVector);
	  inPred.at(++i).push_back(LSymbols("z","r","t", "th", "ph","B"));
	  inPred.push_back(tempVector);
	  inPred.at(++i).push_back(LSymbols("z","r","t", "th", "ph","A"));
  }

  //printvector(inPred.at(0));
  //cout<<endl;

  vector<vector<LSymbols>> postPred;
  for (int i=0; i<3*ruleNum; i++)
  {
	  postPred.push_back(tempVector);
	  for (int j=0; j<postPredSize; j++)
	  {
		  postPred.at(i).push_back(LSymbols("z","r","t", "th", "ph",lexical_cast<string>(str2PostPred.gene(i,j))));
	  }
  }
  //printvector(postPred.at(0));
  //cout<<endl;
 // ...(...)...(...)...[(+)...(...)...(...)...][(-)...(...)...(...)...]
  vector<vector<LSymbols>> suc;
  for (int i=0; i<3*ruleNum; i++)
  {
	  suc.push_back(tempVector);
	  int j=0;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,j)),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc1.gene(i,j))));
	  suc.at(i).push_back(LSymbols("0","0","0",lexical_cast<string>(the2Suc.gene(i,(j+1))), "0",sign2Suc.gene(i,j)));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,j+1)),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,j-1))));
	  suc.at(i).push_back(LSymbols("0","0","0",lexical_cast<string>(the2Suc.gene(i,(j+2))), "0",sign2Suc.gene(i,j)));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,j+2)),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,j-1))));
	  suc.at(i).push_back(LSymbols("0","0","0", "0", "0","["));
	  suc.at(i).push_back(LSymbols("0","0","0",lexical_cast<string>(the2Suc.gene(i,(j+3))), "0","+"));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+3))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0",lexical_cast<string>(the2Suc.gene(i,(j+4))), "0",sign2Suc.gene(i,(j-1))));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+4))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0",lexical_cast<string>(the2Suc.gene(i,(j+5))), "0",sign2Suc.gene(i,(j-1))));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+5))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0", "0", "0","]"));
	  suc.at(i).push_back(LSymbols("0","0","0", "0", "0","["));
	  suc.at(i).push_back(LSymbols("0","0","0", lexical_cast<string>(the2Suc.gene(i,(j+6))), "0","-"));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+6))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0", lexical_cast<string>(the2Suc.gene(i,(j+7))), "0",sign2Suc.gene(i,(j-2))));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+7))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0", lexical_cast<string>(the2Suc.gene(i,(j+8))), "0",sign2Suc.gene(i,(j-2))));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+8))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0", "0", "0","]"));
	}

  //printvector(suc.at(0));
  //cout<<endl;
  
  LSysParam gaSymbolList(axiom, prePred, inPred, postPred, suc, iterNum, ZSizet, RSizet, TSizet, ThetaSizet, PhiSizet);
  
  list<LSymbols> finalString1 = changeFinalList(gaSymbolList.getFinalSymbolList());
  
  list<LSymbols>::iterator iter1=finalString1.begin();
  list<LSymbols>::iterator iter2=finalString2.begin();
  float score = comparatorRec(finalString1,iter1,finalString2,iter2,3);

  cout<< score << endl;

  return score;
}




void printvector( vector<LSymbols>& finalListOfSymbols )
{
	if ( finalListOfSymbols.empty() ) // list is empty
		cout << "List is empty";
	else
	{
		vector<LSymbols>::iterator flos;
		flos = finalListOfSymbols.begin();
			for(flos; flos != finalListOfSymbols.end(); flos++)
			{
				cout<<(*flos).getClassType()<<"("<<(*flos).getDistance()<<","<<(*flos).getRadius()<<","<<(*flos).getTime()<<","<<(*flos).getTheta()<<","<<(*flos).getPhi()<<")";
			}
			cout <<endl;
	} 
} 

void printlist( list<LSymbols>& finalListOfSymbols )
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

void plotBest(CompositeGenome&);
///////////////////////////////////////////////////////////////////////

list<LSymbols> changeFinalList(list <LSymbols>& finalListOfSymbols)
{
	list<LSymbols>::iterator iter1;
	iter1 = finalListOfSymbols.begin();
	list<LSymbols> changedFinalList;

	for (iter1; iter1!=finalListOfSymbols.end(); iter1++)
	{
		float distance = 0;
		string radius;
		string time;
		bool check = false;
		while ((*iter1).getClassType()=="F"||(*iter1).getClassType()=="A"||(*iter1).getClassType()=="X"||(*iter1).getClassType()=="B")
		{
			check = true;
			distance+=atof((*iter1).getOfDistance().c_str());
			radius = (*iter1).getOfRadius();
			time = (*iter1).getOfTime();
			iter1++;
		}
		
		if ( check == true )
		{
			changedFinalList.push_back(LSymbols(lexical_cast<string>(distance),radius,time,"0","0","F"));
		}
		changedFinalList.push_back((*iter1));
	}
	return changedFinalList;
}
///////stringScore////////////////////////////////////////////////////////////////////////
float stringScore(list<LSymbols>& finalStringGA, list<LSymbols>& finalString)
{
	//cout << "this is in string score :" << endl;
	//printlist(finalStringGA);
	//printlist(finalString);
	float score = 0.0;
	if (finalStringGA.size()!=0&&finalString.size()!=0)
	{
		list<LSymbols>::iterator iterGA = finalStringGA.begin();
		list<LSymbols>::iterator iter = finalString.begin();

		while ((iterGA != finalStringGA.end())&&(iter != finalString.end()))
		{
			if (iterGA->getClassType() != iter->getClassType())
			{
				score +=5.0;
			}
			iter++;
			iterGA++;
		}
	}
	
	score += 5.0 * (abs((int)(finalString.size()-finalStringGA.size())));
	//cout << "string score = " << score << endl;
	return score;
}

///////////////////////////////////////////////////////////////////////////////////////
///////imageScore////////////////////////////////////////////////////////////////////////
float imageScore(list<LSymbols>& finalStringGA, list<LSymbols>& finalString)
{
	float score = 0.0;
	LNodesContainer nodeContainer1;
	LNodesContainer nodeContainer2;

	//cout << "these are in image score :" << endl;
	//printlist(finalStringGA);
	//printlist(finalString);

	LTurtle turtle1(finalStringGA, nodeContainer1);
	LTurtle turtle2(finalString, nodeContainer2);

	const int r = 150;
	Mat imgA = Mat::zeros( Size( 4*r, 4*r ), CV_8U );
	//Mat imgA = imread("targeta1.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat imgB = Mat::zeros( Size( 4*r, 4*r ), CV_8U );
	
	size_t iter1 = nodeContainer1.getEndNodes().size();
	for (size_t i=0; i<iter1;i++)
	{
		line( imgA, Point(nodeContainer1.getStartNodes()[i].getxPosition(),nodeContainer1.getStartNodes()[i].getyPosition()),  Point(nodeContainer1.getEndNodes()[i].getxPosition(),nodeContainer1.getEndNodes()[i].getyPosition()), Scalar( 255 ), 2, 1 );
	}
	
	size_t iter2 = nodeContainer2.getEndNodes().size();
	for (size_t i=0; i<iter2;i++)
	{
		line( imgB, Point(nodeContainer2.getStartNodes()[i].getxPosition(),nodeContainer2.getStartNodes()[i].getyPosition()),  Point(nodeContainer2.getEndNodes()[i].getxPosition(),nodeContainer2.getEndNodes()[i].getyPosition()), Scalar( 255 ), 2, 1 );
	}
	/*
	vector<uchar> buf1;
	char* name1 = "product1.jpg";
	imencode(name1,imgC,buf1);
	Mat imgA=imdecode(buf1,0);
	buf1.clear();

	vector<uchar> buf2;
	char* name2 = "product2.jpg";
	imencode(name2,imgD,buf2);
	Mat imgB=imdecode(buf2,0);
	buf2.clear();
	*/
	
	std::vector<KeyPoint> keypointsA, keypointsB;
	Mat descriptorsA, descriptorsB;
	std::vector<DMatch> matches;
	OrbFeatureDetector BRISKD(1500,1.2,8,1);
	OrbDescriptorExtractor extractor;
	BruteForceMatcher<HammingLUT> matcher;
	BRISKD.detect( imgA, keypointsA );
	BRISKD.detect( imgB, keypointsB );
	if (keypointsA.size()==0&&keypointsB.size()==0)
	{
		cout << "here" << endl;
		return 15;
	}
	if (keypointsA.size()==0||keypointsB.size()==0)
	{
		cout << "here" << endl;
		return 100;
	}
	extractor.compute( imgA, keypointsA, descriptorsA );
	extractor.compute( imgB, keypointsB, descriptorsB );
	matcher.match(descriptorsA, descriptorsB, matches);
	std::vector<DMatch> good_matches;
	double good_matches_sum = 0.0;

	for (size_t i = 0; i < matches.size(); i++ ) 
	{
	  //if( matches[i].distance < 50 )
		{
			good_matches.push_back(matches[i]);
			good_matches_sum += matches[i].distance;
		}
	}
	score = (float)good_matches_sum / (int)good_matches.size();

	//////////////////////////////////////////////////
	/*
	// Draw matches
	Mat imgMatch;
	drawMatches(imgA, keypointsA, imgB, keypointsB, good_matches, imgMatch);

	namedWindow("matches", CV_WINDOW_KEEPRATIO);
	imshow("matches", imgMatch);
	*/
	/*
	const char* source_window1 = "Source";
	namedWindow( source_window1, WINDOW_AUTOSIZE );
	imshow( source_window1, imgA );
	const char* source_window2 = "Target";
	namedWindow( source_window2, WINDOW_AUTOSIZE );
	imshow( source_window2, imgB );
	//imwrite("targeta10.jpg",imgA);
	
	waitKey(0);

	//////////////////////////////////////////////////
	
	cout << "image score = " << score << endl;
	*/
	return score;
}

///////////////////////////////////////////////////////////////////////////////////////
//////////Splitter////////////////////////////////////////////////////////////////////////

float comparatorRec(list<LSymbols>& finalStringGA, list<LSymbols>::iterator& iterGA, list<LSymbols>& finalString, list<LSymbols>::iterator& iter, int maxLevel)
{
	list<LSymbols> tempGA;
	list<LSymbols> temp;
	list<LSymbols>::iterator iterTempGA = iterGA;
	list<LSymbols>::iterator iterTemp = iter;
	list<LSymbols> finalStringGATemp;
	list<LSymbols> finalStringTemp;
	//int penalty = 5;
	float score = 0;
	
	
	int levelOfParaGA = 0;
	int levelOfPara = 0;

	//printlist(finalStringGA);
	//printlist(finalString);
	
	// go forward until reach [ or ] or !
	while((iterGA->getClassType() != "]" || levelOfParaGA != 0) && iterGA->getClassType() != "!")
	{
		//levelOfParaGA defines to detect diffrentiant between level of two strings;
		tempGA.push_back((*iterGA));
		
		if(iterGA->getClassType() == "[")
		{
			levelOfParaGA++;
			while(iter->getClassType() != "]" && iter->getClassType() != "!")
			{
				//cout << "this is iter " << iter->getClassType() << endl;
				temp.push_back((*iter));
				if(iter->getClassType() == "[")
				{
					//this means to reach same level in two string
					score += stringScore(tempGA, temp);
					iterGA++;
					iter++;
					//call recursive
					score += comparatorRec(finalStringGA, iterGA, finalString, iter, maxLevel-1);
					iter++;

					//clear objects that must be cleared for continue
					tempGA.clear();
					temp.clear();
					break;
				}
				iter++;
			}
		}
		//give penalty for extera level in string one
		else if(iterGA->getClassType() == "]") 
		{
			score += 50;
			//cout << "score got penalty for difference of level!" << endl;
		}
		//after back from recursive function must minus level
		if(iterGA->getClassType() == "]")
			levelOfParaGA--;
		
		//if iterGA not ! must plus that
		if(iterGA->getClassType() != "!")
			iterGA++;
	}
	//if something remains in string two this part do action for it
	while((iter->getClassType() != "]" || levelOfPara != 0) && iter->getClassType() != "!")
	{
		temp.push_back((*iter));
		if(iter->getClassType() == "[")
		{
			levelOfPara++;
		}
		//this part defines to get penalty for extra level in string two
		else if(iter->getClassType() == "]")
		{
			levelOfPara--;
			score += 50;
			//cout << "score got penalty for difference of level!" << endl;
		}

		
		iter++;
	}
	
	//calculates "remaining" string score
	score += stringScore(tempGA, temp);//shak
	std::copy( iterTempGA, iterGA, std::back_inserter(finalStringGATemp) );
	std::copy( iterTemp, iter, std::back_inserter(finalStringTemp) );
	//calculates image score
	if(maxLevel > 0){
		score += imageScore(finalStringGATemp, finalStringTemp);
	}
	return score;
}

int
main(int argc, char *argv[])
{
  cout << "suc: ...(...)...(...)...[(+)...(...)...(...)...][(-)...(...)...(...)...]" << endl;
// See if we've been given a seed to use (for testing purposes).  When you
// specify a random seed, the evolution will be exactly the same each time
// you use that seed number.
  for(int ii=1; ii<argc; ii++) {
    if(strcmp(argv[ii++],"seed") == 0) {
      GARandomSeed((unsigned int)atoi(argv[ii]));
    }
  }

  GAParameterList params;
  GASteadyStateGA::registerDefaultParameters(params);
  //GASimpleGA::registerDefaultParameters(params);

  GASigmaTruncationScaling scaling;
  //params.set(gaNpReplacement, 0.5);
  params.set(gaNscoreFilename, "bog.dat");
  //params.set(gaNflushFrequency, 10);
  params.set(gaNnGenerations, 1);
  params.set(gaNpopulationSize,10);
  params.parse(argc, argv, gaFalse);

// Now create the GA and run it.  First a genome, then the GA.

  GARealAlleleSet dis2a;
  //dis2a.add(10);
  //dis2a.add(15);
  //dis2a.add(25);
  dis2a.add(24);
  //dis2a.add(50);
  //dis2a.add(75);
  //dis2a.add(100);
  //dis2a.add(125);
  //dis2a.add(150);

  GARealAlleleSet rad2a;
  //rad2a.add(0.9);
  rad2a.add(1.0);
  //rad2a.add(1.1);

  GARealAlleleSet tim2a;
  //tim2a.add(0.9);
  tim2a.add(1.0);
  //tim2a.add(1.1);

  GARealAlleleSet the2a;
  the2a.add(0.087);
  //the2a.add(0.52);
  //the2a.add(0.42);
  //the2a.add(0.32);
  //the2a.add(0.62);
  //the2a.add(0.72);
  //the2a.add(0.82);
  //the2a.add(0.92);
  //the2a.add(1.02);
  //the2a.add(1.12);
  //the2a.add(1.22);
  //the2a.add(1.32);
  //the2a.add(1.42);
  //the2a.add(1.52);

  GARealAlleleSet phi2a;
  phi2a.add(0.0);
  //phi2a.add(0.1);
  //phi2a.add(0.2);

  
  char* a1[]={"F","A","X","B"};
  GAAlleleSet<char*> funcClassType(4,a1);
  char* a2[]={"?","F","A","X","B"};
  GAAlleleSet<char*> funcSpClassType(4,a2);
  //char* a3[]={"?","+","-","]","]"};
  char* a3[]={"?"};
  GAAlleleSet<char*> contextClassType(1,a3);
  char* a4[]={"?","+","-"};
  GAAlleleSet<char*> signClassType(3,a4);
  char* b[]={"z","z/2","z/3","z/4"};
  GAAlleleSet<char*> dis2s(4,b);
  char* c[]={"r"};
  GAAlleleSet<char*> rad2s(1,c);
  char* d[]={"t"};
  GAAlleleSet<char*> tim2s(1,d);
  char* e[]={"th","th*2","th*3","th*5","th*5/2","th*3/2","th*2","th/2"};
  GAAlleleSet<char*> the2s(8,e);
  char* f[]={"ph"};
  GAAlleleSet<char*> phi2s(1,f);

  
  CompositeGenome genome(dis2a, rad2a, tim2a, the2a, phi2a, funcClassType, funcSpClassType, contextClassType, signClassType, dis2s, rad2s, tim2s, the2s, phi2s, Objective,NULL);
  GASteadyStateGA ga(genome);
  //GASimpleGA ga(genome);

  ga.parameters(params);
  ga.pReplacement(0.8);
  ga.pMutation(0.30);
  ga.minimize();
  //ga.scaling(scaling);
  //ga.parameters(argc,argv);
  ga.evolve();

  genome = ga.statistics().bestIndividual();
  plotBest(genome);
  cout << "\nthe ga generated:\n" << genome << "\n";

// Don't forget to free up the memory we allocated.

  waitKey(0);
  return 0;
}

void plotBest(CompositeGenome& genome)
{
  GARealGenome& dis2Axiom = genome.getDis2Axiom();
  GARealGenome& rad2Axiom = genome.getRad2Axiom();
  GARealGenome& tim2Axiom = genome.getTim2Axiom();
  GARealGenome& the2Axiom = genome.getThe2Axiom();
  GARealGenome& phi2Axiom = genome.getPhi2Axiom();
  GA1DArrayAlleleGenome<char*>& str2Axiom1 = genome.getStr2Axiom1();
  GA1DArrayAlleleGenome<char*>& str2Axiom2 = genome.getStr2Axiom2();
  GA2DArrayAlleleGenome<char*>& str2PrePred = genome.getStr2PrePred();
  GA2DArrayAlleleGenome<char*>& str2PostPred = genome.getStr2PostPred();
  GA2DArrayAlleleGenome<char*>& dis2Suc = genome.getDis2Suc();
  GA2DArrayAlleleGenome<char*>& rad2Suc = genome.getRad2Suc();
  GA2DArrayAlleleGenome<char*>& tim2Suc = genome.getTim2Suc();
  GA2DArrayAlleleGenome<char*>& the2Suc = genome.getThe2Suc();
  GA2DArrayAlleleGenome<char*>& phi2Suc = genome.getPhi2Suc();
  GA2DArrayAlleleGenome<char*>& sign2Suc = genome.getSign2Suc();
  GA2DArrayAlleleGenome<char*>& ctype2Suc1 = genome.getCType2Suc1();
  GA2DArrayAlleleGenome<char*>& ctype2Suc2 = genome.getCType2Suc2();

 
  vector<LSymbols> axiom;
  cout << "best axiom:" << endl;
  axiom.push_back(LSymbols(lexical_cast<string>(dis2Axiom.gene(0)),lexical_cast<string>(rad2Axiom.gene(0)),lexical_cast<string>(tim2Axiom.gene(0)),lexical_cast<string>(the2Axiom.gene(0)),lexical_cast<string>(phi2Axiom.gene(0)),lexical_cast<string>(str2Axiom1.gene(0))));
  for (int i=1; i<axiomSize; i++)
  {
	  axiom.push_back(LSymbols(lexical_cast<string>(dis2Axiom.gene(i)),lexical_cast<string>(rad2Axiom.gene(i)),lexical_cast<string>(tim2Axiom.gene(i)),lexical_cast<string>(the2Axiom.gene(i)),lexical_cast<string>(phi2Axiom.gene(i)),lexical_cast<string>(str2Axiom2.gene(i-1))));
  }
  printvector(axiom);
  //cout<<endl;
  vector <LSymbols> tempVector;
  cout << "best prePred:" << endl;
  vector<vector<LSymbols>> prePred;
  for (int i=0; i<3*ruleNum; i++)
  {
	  prePred.push_back(tempVector);
	  for (int j=0; j<prePredSize; j++)
	  {
		  prePred.at(i).push_back(LSymbols("z","r","t", "th", "ph",lexical_cast<string>(str2PrePred.gene(i,j))));
		  printvector(prePred.at(i));
		  cout<<endl;
	  }
  }
  
  //printvector(prePred.at(0));
  //cout<<endl;
    cout << "best inPred: " << endl;
  vector<vector<LSymbols>> inPred;
  for (int i=0; i<3*ruleNum; i++)
  {
	  inPred.push_back(tempVector);
	  inPred.at(i).push_back(LSymbols("z","r","t", "th", "ph","X"));
	  printvector(inPred.at(i));
	  cout<<endl;
	  inPred.push_back(tempVector);
	  inPred.at(++i).push_back(LSymbols("z","r","t", "th", "ph","B"));
	  printvector(inPred.at(i));
	  cout<<endl;
	  inPred.push_back(tempVector);
	  inPred.at(++i).push_back(LSymbols("z","r","t", "th", "ph","A"));
	  printvector(inPred.at(i));
	  cout<<endl;
  }

  //printvector(inPred.at(0));
  //cout<<endl;
    cout << "best postPred:" << endl;
  vector<vector<LSymbols>> postPred;
  for (int i=0; i<3*ruleNum; i++)
  {
	  postPred.push_back(tempVector);
	  for (int j=0; j<postPredSize; j++)
	  {
		  postPred.at(i).push_back(LSymbols("z","r","t", "th", "ph",lexical_cast<string>(str2PostPred.gene(i,j))));
		  printvector(postPred.at(i));
		  cout<<endl;
	  }
  }

  //printvector(postPred.at(0));
  //cout<<endl;
 // ...(...)...(...)...[(...)...(...)...(...)...](...,(...),...)[(...)...(...)...(...)...]...(...)...
  cout << "best suc:" << endl;
  vector<vector<LSymbols>> suc;

  for (int i=0; i<3*ruleNum; i++)
  {
	  suc.push_back(tempVector);
	  int j=0;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,j)),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc1.gene(i,j))));
	  suc.at(i).push_back(LSymbols("0","0","0",lexical_cast<string>(the2Suc.gene(i,(j+1))), "0",sign2Suc.gene(i,j)));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,j+1)),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,j-1))));
	  suc.at(i).push_back(LSymbols("0","0","0",lexical_cast<string>(the2Suc.gene(i,(j+2))), "0",sign2Suc.gene(i,j)));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,j+2)),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,j-1))));
	  suc.at(i).push_back(LSymbols("0","0","0", "0", "0","["));
	  suc.at(i).push_back(LSymbols("0","0","0",lexical_cast<string>(the2Suc.gene(i,(j+3))), "0","+"));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+3))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0",lexical_cast<string>(the2Suc.gene(i,(j+4))), "0",sign2Suc.gene(i,(j-1))));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+4))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0",lexical_cast<string>(the2Suc.gene(i,(j+5))), "0",sign2Suc.gene(i,(j-1))));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+5))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0", "0", "0","]"));
	  suc.at(i).push_back(LSymbols("0","0","0", "0", "0","["));
	  suc.at(i).push_back(LSymbols("0","0","0", lexical_cast<string>(the2Suc.gene(i,(j+6))), "0","-"));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+6))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0", lexical_cast<string>(the2Suc.gene(i,(j+7))), "0",sign2Suc.gene(i,(j-2))));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+7))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0", lexical_cast<string>(the2Suc.gene(i,(j+8))), "0",sign2Suc.gene(i,(j-2))));
	  j++;
	  suc.at(i).push_back(LSymbols(lexical_cast<string>(dis2Suc.gene(i,j)),lexical_cast<string>(rad2Suc.gene(i,j)),lexical_cast<string>(tim2Suc.gene(i,j)), lexical_cast<string>(the2Suc.gene(i,(j+8))),lexical_cast<string>(phi2Suc.gene(i,j)),lexical_cast<string>(ctype2Suc2.gene(i,(j-1)))));
	  suc.at(i).push_back(LSymbols("0","0","0", "0", "0","]"));
	  printvector(suc.at(i));
	  cout<<endl;
  }

  //printvector(suc.at(0));
  //cout<<endl;
	LSysParam gaSymbolList(axiom, prePred, inPred, postPred, suc, iterNum, ZSizet, RSizet, TSizet, ThetaSizet, PhiSizet);
	LNodesContainer nodeContainer;
	LTurtle turtle(gaSymbolList.getFinalSymbolList(), nodeContainer);
	cout<<"Ga Final List" << endl;
	list<LSymbols> gaFinalSymbolList = gaSymbolList.getFinalSymbolList();
	printlist(gaFinalSymbolList);
	cout<<endl;
	const int r = 150;
	Mat best = Mat::zeros( Size( 4*r, 4*r ), CV_8UC1 );
	size_t iter = nodeContainer.getEndNodes().size();
	for (size_t i=0; i<iter;i++)
	{
		line( best, Point(nodeContainer.getStartNodes()[i].getxPosition(),nodeContainer.getStartNodes()[i].getyPosition()),  Point(nodeContainer.getEndNodes()[i].getxPosition(),nodeContainer.getEndNodes()[i].getyPosition()), Scalar( 255 ), 2, 1 );
	}

	namedWindow( "Best", WINDOW_AUTOSIZE );
	imshow( "Best", best );
}
