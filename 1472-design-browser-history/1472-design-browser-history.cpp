struct DLL {
    string val;
    DLL *prev;
    DLL *next; 
    DLL(string x) : val(x), prev(nullptr), next(nullptr) {}
};

class BrowserHistory {
private:
    DLL *cur;
public:
    BrowserHistory(string homepage) {
       DLL *head = new DLL(homepage);
       cur = head;

    }
    
    void visit(string url) {
        DLL *newPage = new DLL(url);
        newPage->prev = cur;
        cur->next = newPage;
        cur = newPage;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (!cur->prev) break;
            cur = cur->prev;
        }
        return cur->val;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (!cur->next) break;
            cur = cur->next;
        }
        return cur->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */