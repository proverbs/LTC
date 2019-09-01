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

/**
 * A better version
 * 
*/
class LRUCache {
private:
    
    class ListNode {
    public:
        ListNode *last, *next;
        int val, key;
        ListNode(int key, int val) : key(key), val(val), last(NULL), next(NULL) {}
    };
    
    unordered_map<int, ListNode*> key2node;
    int cap;
    ListNode *head, *tail;
    
    void remove_from_list(ListNode *p) {
        ListNode *plast = p->last;
        ListNode *pnext = p->next;
        plast->next = pnext;
        pnext->last = plast;
    }
    
    void add_to_list(ListNode *p) {
        ListNode *q = head->next;
        head->next = p;
        p->next = q;
        q->last = p;
        p->last = head;
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);
        head->next = tail;
        tail->last = head;
    }
    
    int get(int key) {
        int res = -1;
        if (key2node.count(key)) {
            ListNode *p = key2node[key];
            remove_from_list(p);
            add_to_list(p);
            res = p->val;
        }
        return res;
    }
    
    void put(int key, int value) {
        if (key2node.count(key)) {
            ListNode *p = key2node[key];
            remove_from_list(p);
            add_to_list(p);
            head->next->val = value;
        } else {
            if (key2node.size() == cap) {
                ListNode *p = tail->last;
                remove_from_list(p);
                key2node.erase(p->key);
                delete p;
            }
            ListNode *q = new ListNode(key, value);
            add_to_list(q);
            key2node[key] = q;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
