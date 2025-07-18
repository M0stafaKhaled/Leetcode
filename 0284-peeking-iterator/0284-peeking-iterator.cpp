/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int pointer ; 
    vector<int>nums ;
	PeekingIterator(const vector<int>& num) : Iterator(num) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        nums = num ; 
	    pointer =0 ; 
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(pointer == nums.size()) return -1 ; 
        return nums[pointer] ; 
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(pointer == nums.size()) return -1 ; 
	     return nums[pointer++] ; 
	}
	
	bool hasNext() const {
	  return pointer != nums.size() ; 
	}
};