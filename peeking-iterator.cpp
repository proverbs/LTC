// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int pnext;
    bool fg_pnext;
    bool phasnext;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    fg_pnext = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (fg_pnext) return pnext;
        else {
            phasnext = Iterator::hasNext();
            pnext = next();
            fg_pnext = true;
            return pnext;
        }
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (fg_pnext) {
            fg_pnext = false;
            return pnext;
        } else {
            return Iterator::next();
        }
	}

	bool hasNext() const {
	    if (fg_pnext) return phasnext;
        else return Iterator::hasNext();
	}
};