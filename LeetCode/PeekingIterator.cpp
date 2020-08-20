/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
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
    bool has_next;
    int ans;
    // const vector<int> *ar;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        has_next = Iterator::hasNext();
        ans = Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return ans;       
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int tmp = ans;
        has_next = Iterator::hasNext();
        if(has_next) ans = Iterator::next();
        return tmp;
	    
	}
	
	bool hasNext() const {
	    return has_next;
	}
};