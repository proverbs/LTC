class MyLinkedList {
public:
    list<int> lt;
    /** Initialize your data structure here. */
    MyLinkedList() {
        lt.clear();
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index > (int)lt.size() - 1) return -1;
        auto it = lt.begin();
        while (index --) it ++;
        return *it;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        lt.insert(lt.begin(), val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        lt.insert(lt.end(), val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > lt.size()) return;
        auto it = lt.begin();
        while (index --) it ++;
        lt.insert(it, val);
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index > lt.size() - 1) return;
        auto it = lt.begin();
        while (index --) it ++;
        lt.erase(it);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */