// File: dbintree.h
// Zhouxj
// BUPTNIC
// zhouxj@buptnic.edu.cn

typedef int level;

class dbintree {

	struct tnode {
		level lvl;
		struct tnode *parent;
		struct tnode *child0;
		struct tnode *child1;
		int wt_child0;
		int wt_child1;
		int valid;
	} *tnodes;

	struct tnode *root; // pointer to root node
	float *skew; // array of target skews for each level
	float *corr; // array of target correlations for each level 
	float *p1child; // probability that a node at a given level has one child
	float *p1childleft; //left child probability that a node at a given level has one child
	float *p1childright; //right child probability that a node at a given level has one child
	float *p2child; // probability that a node at a given level has two children
	int num_tnodes; // number of tree nodes 
	int Nest; // Maximum allowed nesting

public: dbintree();
		~dbintree();
		void delete_node(struct tnode *me);
		void read_skew(FILE*); // read in destination address tree statistics
		void read_config_skew(FILE* fp_in);
		void read_nest(FILE*); // read in source address tree statistics
		void read_corr(FILE*); // read in address correlation statistics
		void print_nest(FILE*); //print 
		void print_skew(FILE*); // print average skew per level
		void print_corr(FILE*); // print correlation per level
		void mappingCorr();
		void MappingSkew(unsigned int scale);  //map IPv4 Skew and Branch to IPv6;
};
