// File: FilterList.h
// David E. Taylor
// Applied Research Laboratory
// Department of Computer Science and Engineering
// Washington University in Saint Louis
// det3@arl.wustl.edu
//
// Class definition for FilterList

// List of filters with dynamic memory allocation
// edit by zhouxj for V6 no any guarantee
#ifndef __FILTERLIST_H_ 
#define __FILTERLIST_H_

struct FilterList_item {
	struct filter filt;
  //struct filterV6 filt;
  struct FilterList_item *prev;
  struct FilterList_item *next;
};

class FilterList {
  struct FilterList_item *first; // beginning of list
  struct FilterList_item *last;  // end of list
  int num;   // number of filters in the list
 public: FilterList();
  ~FilterList();
  void	clear();		// remove everything
  struct FilterList_item* operator()(int);    // access item
  void	insert(struct FilterList_item*, struct filter); // insert filter at prior to given item
  void	operator&=(struct filter);  // append item
  void	operator<<=(int);	    // remove initial items
  void	operator=(FilterList*);	    // copy list
  void	push(struct filter);        // prepend item
  void  print(FILE *fp);        // Print filters
  int	size();			// return size of list
 private:
 	bool addrSort(FilterList_item * lhs,FilterList_item * rhs);
};
  
#endif
