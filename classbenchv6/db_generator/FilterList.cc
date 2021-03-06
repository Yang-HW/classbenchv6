// File: FilterList.cc
// David E. Taylor
// Applied Research Laboratory
// Department of Computer Science and Engineering
// Washington University in Saint Louis
// det3@arl.wustl.edu
//
// Class definition for FilterList

// List of filters with dynamic memory allocation
// edit by zhouxj for V6 no any guarantee
#include "stdinc.h"
#include "FilterList.h"
#include <vector>
#include <algorithm>
using namespace std;
FilterList::FilterList() {
  first = last = NULL;
  num = 0;
}

FilterList::~FilterList() { 
  struct FilterList_item *temp;
  while (first != NULL) {
    temp = first->next;
    delete(first);
    first = temp;
  }
}

// Remove all elements from FilterList.
void FilterList::clear() {
  struct FilterList_item *temp;
  while (first != NULL) {
    temp = first->next;
    delete(first);
    first = temp;
  }
  return;
}

// Return the i-th element, where the first is 1.
struct FilterList_item* FilterList::operator()(int i) {
  if (i <= 0 || (i > num && num > 0)) {
    fprintf(stderr,"FilterList::operator(): item %d out of range, num = %d\n",i,num);
    exit(1);      
  }
  // Items are maintained in-order
  // Index i items to the "right"
  struct FilterList_item *temp;
  temp = first;
  while (--i) {
    temp = temp->next;
  }
  return temp;
}

// Insert filter prior to the given element
void FilterList::insert(struct FilterList_item *item, struct filterV6 filt) {
  struct FilterList_item *newitem;
  newitem = new struct FilterList_item;
  newitem->filt = filt;
  newitem->prev = item->prev;
  newitem->next = item;
  if (first == item) first = newitem;
  else item->prev->next = newitem;
  item->prev = newitem;
  num++;
  return;
}

// Add i to the end of the FilterList.
// Allows redundant filters to be on the list
void FilterList::operator&=(struct filterV6 filt) {
  struct FilterList_item *temp;
  temp = new struct FilterList_item;
  temp->filt = filt;
  temp->prev = last;
  temp->next = NULL;
  if (num == 0){
    first = temp;
  } else {
    last->next = temp;
  }
  last = temp;
  num++;
  return;
}

// Remove the first i filters.
void FilterList::operator<<=(int i) {
  struct FilterList_item *temp;
  while (first != NULL && i--) {
    temp = first->next;
    delete(first);
    first = temp;
    num--;
  }
  return;
}

// Assign value of right operand to left operand.
void FilterList::operator=(FilterList* L) {
  clear();
  struct FilterList_item *temp;
  for (temp = (*L)(1); temp != NULL; temp=temp->next)
    (*this) &= temp->filt;
  return;
}

// Add i to the front of the FilterList.
void FilterList::push(struct filterV6 filt) {
  struct FilterList_item *temp;
  temp = new struct FilterList_item;
  temp->filt = filt;
  temp->next = first;
  temp->prev = NULL;
  if (num == 0){
    last = temp;
  } else {
    first->prev = temp;
  }
  first = temp;
  num++;
  return;
}  
/*
// Print the contents of the FilterList.
void FilterList::print(FILE* fp) {
  InetAddress128 temp;
  struct FilterList_item *tempfilt;
  
  for (tempfilt = first; tempfilt != NULL; tempfilt = tempfilt->next){
    // Print new filter character
    fprintf(fp,"@");
    // Print source address
    temp = tempfilt->filt.sa;
    fprintf(fp, "%s\t",temp.tostring());
    // Print destination address 
    temp = tempfilt->filt.da;
    fprintf(fp, "%s\t",temp.tostring());
    // Print source port 
    fprintf(fp, "%d : %d\t",
	    tempfilt->filt.sp[0], tempfilt->filt.sp[1]);
    // Print destination port 
    fprintf(fp, "%d : %d\t",
	    tempfilt->filt.dp[0], tempfilt->filt.dp[1]);
    // Print protocol 
    if (tempfilt->filt.prot_num == 0) fprintf(fp, "0x00/0x00\t");
    else fprintf(fp, "0x%02x/0xFF\t", tempfilt->filt.prot_num);
    // Print flags
    fprintf(fp, "0x%04x/0x%04x\t",
	    tempfilt->filt.flags,tempfilt->filt.flags_mask);
    // Print ext_fields
    for (int j = 0; j < tempfilt->filt.num_ext_field; j++){
      fprintf(fp, "%d\t",
	      tempfilt->filt.ext_field[j]);
    } 
    // Print newline 
    fprintf(fp,"\n");
  }
}
*/
// Return the number of filters stored in list
int FilterList::size() {
  return num;
}

bool FilterList::addrSort(FilterList_item * lhs, FilterList_item * rhs)
{
		if (lhs->filt.sa < rhs->filt.sa)
			return true;
		return false;
}

void FilterList::print(FILE* fp)
{
	 InetAddress128 temp;
	 int maskBit = 0;
	 int productorID = 0;
   struct FilterList_item* tempfilt;
	 vector<FilterList_item* > tempVec;
   for (tempfilt = first; tempfilt != NULL; tempfilt = tempfilt->next)
   {
   		tempVec.push_back(tempfilt);
   }
   //stable_sort(tempVec.begin(),tempVec.end(),addrSort);
   for (unsigned int ix =0; ix<tempVec.size(); ++ix)
   {
   		  tempfilt = tempVec[ix];
   		  
   		  //fprintf(fp,"%d\t",randint(0,MAXFL));
   		  // Print new filter character
   		  fprintf(fp,"@");
   		  //Print FlowLable
   		  ////////////////////////////////
   		  int fl1 = randint(0,0xfffff);
   		  int fl2 = randint(0,0xfffff);
   		  if (fl1 > fl2)
   		  {
   		  	int tmpfl = fl1;
   		  	fl1 = fl2;
   		  	fl2 = tmpfl;
   		  }	
   		  fprintf(fp,"%d - %d\t",fl1,fl2);
   		  //////////////////////////////////////
    		// Print source address
    		temp = tempfilt->filt.sa;
    		fprintf(fp, "%s\t",temp.tostring());
    		// Print destination address 
    		temp = tempfilt->filt.da;
    		fprintf(fp, "%s\t",temp.tostring());
    		
    		// Print source port 
    		fprintf(fp, "%d : %d\t",
	      tempfilt->filt.sp[0], tempfilt->filt.sp[1]);
    		// Print destination port 
    		fprintf(fp, "%d : %d\t",
	    	tempfilt->filt.dp[0], tempfilt->filt.dp[1]);
   		 // Print protocol 
   		  int tmpProt =0;
   		  double tmpRand48 = drand48();
   		  if (tmpRand48<TCPPRO) tmpProt = 1;
   		  else if(tmpRand48 < UDPPRO) tmpProt = 2;
   		  else tmpProt = 0;
   		  fprintf(fp,"%d\t",tmpProt);
   		 /*
    		if (tempfilt->filt.prot_num == 0) fprintf(fp, "0x00/0x00\t");
    		else fprintf(fp, "0x%02x/0xFF\t", tempfilt->filt.prot_num);
    		// Print flags
    		fprintf(fp, "0x%04x/0x%04x\t",
	    	tempfilt->filt.flags,tempfilt->filt.flags_mask);
    		// Print ext_fields
    		for (int j = 0; j < tempfilt->filt.num_ext_field; j++){
      			fprintf(fp, "%d\t",tempfilt->filt.ext_field[j]);
   			}*/
   			// Print newline 
    		fprintf(fp,"\n");
   }
   
}	
