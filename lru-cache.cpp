/*linked list + hash map*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->head = new Node(0, 0);
        this->tail = new Node(0, 0);
        head->next = tail;
        tail->last = head;
        this->sz = 0;
        this->capacity = capacity;
        this->mp = new unordered_map<int, Node*>;
    }
    
    int get(int key) {
        if (mp->count(key)) {
            Node* p = (*mp)[key];
            Node* pl = p->last, *pr = p->next;
            pl->next = pr;
            pr->last = pl;
            Node* t = tail->last;
            t->next = p;
            p->last = t;
            p->next = tail;
            tail->last = p;
            return (*mp)[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp->count(key)) {
            Node* p = (*mp)[key];
            Node* pl = p->last, *pr = p->next;
            pl->next = pr;
            pr->last = pl;
            Node* t = tail->last;
            t->next = p;
            p->last = t;
            p->next = tail;
            tail->last = p;
            p->val = value; // modify value, if key exists
        } else {
            Node* p;
            if (sz == capacity) {
                p = head->next;
                head->next = p->next;
                p->next->last = head;
                mp->erase(p->key);
                delete p;
            } else {
                sz ++;
            }
            p = new Node(key, value);
            Node* t = tail->last;
            t->next = p;
            p->last = t;
            p->next = tail;
            tail->last = p;
            (*mp)[key] = p;
        }
    }
private:
    struct Node {
        int val, key;
        Node* next, *last;
        Node(int x, int y) : key(x), val(y), next(NULL), last(NULL) {}
    };
    Node* head, *tail;
    int sz, capacity;
    unordered_map<int, Node*>* mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
    LRUCache* cache = new LRUCache( 2 /* capacity */ );
    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;       // returns 1
    cache->put(3, 3);    // evicts key 2
    cout << cache->get(2) << endl;       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    cout << cache->get(1) << endl;       // returns -1 (not found)
    cout << cache->get(3) << endl;       // returns 3
    cout << cache->get(4) << endl;       // returns 4
    return 0;
}