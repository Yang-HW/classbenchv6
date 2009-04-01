// File: PrefixList.h
// Zhouxj
// BUPTNIC
// zhouxj@buptnic.edu.cn
//
// Class definition for PrefixList

#ifndef _PREFIXLIST_H_
#define _PREFIXLIST_H_


struct prefix {
	float prob;
	//float sprob[33];
	float sprob[ADDRLEN+1];
};

class PrefixList {
	int N; // PrefixList of N prefixes
	struct prefix** prefixes; // array of prefix structs
	int cdist; // flag signaling if cummulative distribution has been computed
	void read_type(int type,FILE *fp,FILE *fpOut,map<int,vector<mappingVal> > globle) ; // Read prefix information from input file *fp, type = t
public: PrefixList();
		~PrefixList();
		void read(FILE* fp,FILE *fpOut,map<int,vector<mappingVal> > globle); // Read prefix information from input file *fp
		void print(int type, FILE*); // Print prefix distribution
};

#endif