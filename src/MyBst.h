/*
 * MyBst.h
 *
 */

#ifndef __MYBST_H__
#define __MYBST_H__

#include <vector>

struct Node {
    Node();
    Node(const int);
    int val;
    Node* left;
    Node* right;
};

class MyBst {
    public:
        MyBst();
        MyBst(const int);
        virtual ~MyBst();

        size_t size() const;
        void insert(const int);
        void clear();
        Node* find(const int) const;
        void inorder() const;
        void preorder() const;
        void postorder() const;
        void bfs() const;
        void levelorder() const;
        std::vector<int> serialize() const;
        void deserialize(const std::vector<int>&);
        void toDLL();
    private:
        void insert_internal(Node*&, const int);
        void inorder_internal(const Node*) const;
        void preorder_internal(const Node*) const;
        void postorder_internal(const Node*) const;
        void erase(Node*&);
        void serialize_internal(Node*, std::vector<int>&) const;
        void toDLL_internal(Node*, Node*&, Node*&);
        Node* root;
        size_t s;
        bool isDLL;
};

#endif //__MYBST_H__
