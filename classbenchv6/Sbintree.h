// File: sbintree.h
// Zhouxj
// BUPTNIC
// zhouxj@buptnic.edu.cn

#ifndef __SBINTREE_H_ 
#define __SBINTREE_H_

typedef int level;

struct stnode {
	level lvl;
	struct stnode *parent;
	struct stnode *child0;
	struct stnode *child1;
	int wt_child0; // child weights
	int wt_child1; // child weights
};

class sbintree {
	struct stnode *root; // pointer to root node
	float *skew; // array of target skews for each level;
	float *p1child; // probability that a node at a given level has one child
	float *p1childleft; //left child probability that a node at a given level has one child
	float *p1childright; //right child probability that a node at a given level has one child
	float *p2child; // probability that a node at a given level has two children
	int num_stnodes; // number of tree nodes 
	int Nest; // Maximum allowed nesting
public:
	sbintree();
	~sbintree();
	void delete_node(struct stnode *me);
	int nodes(); // return number of nodes
	void read_skew(FILE*); // read in source address tree statistics
	void MappingSkew(unsigned int scale);  //map IPv4 Skew and Branch to IPv6;
	void read_config_skew(FILE* fp_in);
	void read_nest(FILE*); // read in source address tree statistics
	void print_skew(FILE*); // print average skew per level
	void print_nest(FILE*);
};

#endif
