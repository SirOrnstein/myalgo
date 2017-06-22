
#include <iostream>
#include <queue>
#include "MyBst.h"

using namespace std;

Node::Node(): val(0), left(nullptr), right(nullptr) {}
Node::Node(const int v): val(v), left(nullptr), right(nullptr) {}

MyBst::MyBst(): root(nullptr), s(0), isDLL(false) { }

MyBst::MyBst(const int v): root(new Node(v)), s(1), isDLL(false) {}

MyBst::~MyBst() {
    clear();
}

size_t MyBst::size() const {
    return s;
}

void MyBst::insert(const int v) {
    insert_internal(root, v);
    ++s;
}

void MyBst::insert_internal(Node*& n, const int v) {
    if (n == nullptr) {
        n = new Node(v);
        return;
    }
    if (v < n->val) {
        insert_internal(n->left, v);
    } else {
        insert_internal(n->right, v);
    }
}

void MyBst::erase(Node*& n) {
    if (isDLL) {
        while (root != nullptr) {
            Node* t = root;
            root = root->right;
            delete t;
            --s;
        }
    } else {
        if (n != nullptr) {
            erase(n->left);
            erase(n->right);
            --s;
            delete n;
            n = nullptr;
        }
    }
}

void MyBst::clear() {
    erase(root);
}

void MyBst::inorder() const {
    cout << "\nInorder: " << endl;
    inorder_internal(root); 
    cout << "\n";
}

void MyBst::inorder_internal(const Node* n) const {
    if (n != nullptr) {
        inorder_internal(n->left);
        cout << n->val << " ";
        inorder_internal(n->right);
    }
}

void MyBst::preorder() const {
    cout << "\npreorder: " << endl;
    preorder_internal(root); 
    cout << "\n";
}

void MyBst::preorder_internal(const Node* n) const {
    if (n != nullptr) {
        cout << n->val << " ";
        preorder_internal(n->left);
        preorder_internal(n->right);
    }
}

void MyBst::postorder() const {
    cout << "\npostorder: " << endl;
    postorder_internal(root); 
    cout << "\n";
}

void MyBst::postorder_internal(const Node* n) const {
    if (n != nullptr) {
        postorder_internal(n->left);
        postorder_internal(n->right);
        cout << n->val << " ";
    }
}

void MyBst::bfs() const {
    cout << "\nbfs: " << endl;
    if (root != nullptr) {
        queue<Node*> level;
        level.push(root);

        while(!level.empty()) {
            Node* t = level.front();
            if (t->left != nullptr)
                level.push(t->left);
            if (t->right != nullptr)
                level.push(t->right);
            cout << t->val << " ";
            level.pop();
        }
    }
    cout << "\n";
}

void MyBst::levelorder() const {
    cout << "\nlevelorder: " << endl;
    if (root != nullptr) {
        queue<Node*> level;
        level.push(root);
        size_t lc = 1;
        while(!level.empty()) {
            size_t nlc = 0;
            while (lc-- > 0) {
                Node* t = level.front();
                if (t->left != nullptr) {
                    level.push(t->left);
                    ++nlc;
                }
                if (t->right != nullptr) {
                    level.push(t->right);
                    ++nlc;
                }
                cout << t->val << " ";
                level.pop();
            }
            cout << "\n";
            lc = nlc;
        }
    }
    cout << "\n";
}

vector<int> MyBst::serialize() const {
    vector<int> result;
    serialize_internal(root, result);
    return result;
}

void MyBst::serialize_internal(Node* n, vector<int>& result) const {
    if (n != nullptr) {
        result.push_back(n->val);
        serialize_internal(n->left, result);
        serialize_internal(n->right, result);
    }
}

void MyBst::deserialize(const vector<int>& input) {
    clear();
    for (const auto i : input)
        insert(i);
}

void MyBst::toDLL() {
    Node* head = nullptr;
    Node* prev = nullptr;
    toDLL_internal(root, head, prev);

    Node* n = head;
    while (n != nullptr) {
        cout << n->val << " ";
        n = n->right;
    }
    root = head;
    isDLL = true;
    cout << endl;
}

void MyBst::toDLL_internal(Node* n, Node*& head, Node*& prev) {
    if (n == nullptr)
        return;

    toDLL_internal(n->left, head, prev);

    if (prev == nullptr)
        head = n;
    else {
        n->left = prev;
        prev->right = n;
    }
    prev = n;

    toDLL_internal(n->right, head, prev);
}
