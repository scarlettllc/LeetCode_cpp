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
private:
    int next_element;
    bool flag;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    flag = Iterator::hasNext();
        if (flag) {
            next_element = Iterator::next();
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return next_element;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int result = next_element;
        flag = Iterator::hasNext();
        if (flag) {
            next_element = Iterator::next();
        }
        return result;
	}
	
	bool hasNext() const {
	    return flag;
	}
};