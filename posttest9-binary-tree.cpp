#include <iostream>
using namespace std;

struct Node {
    int dataValue;
    struct Node *left, *right;
};

// Kelas Binary Tree
class BinaryTree {
private:
    struct Node *root;
public:
    BinaryTree() {root = NULL;}
    void insert(int);
    Node* getRoot();
    void inOrder(Node*);
    void preOrder(Node*);
    void postOrder(Node*);
};

Node* BinaryTree::getRoot(){
    return root;
}

// Mencetak Node dalam urutan inorder
void BinaryTree::inOrder(Node *p) { 
    if (p != NULL) {
        if(p->left) inOrder(p->left);
        cout << p->dataValue << " ";
        if(p->right) inOrder(p->right);
    }
}

// Mencetak Node dalam urutan preorder
void BinaryTree::preOrder(Node* p) {
    if(p != NULL) {
        cout << p->dataValue << " ";
        if(p->left) preOrder(p->left);
        if(p->right) preOrder(p->right);
    }
}

// Mencetak Node dalam urutan postorder
void BinaryTree::postOrder(Node* p) {
    if(p != NULL) {
        if(p->left) postOrder(p->left);
        if(p->right) postOrder(p->right);
        cout << p->dataValue << " ";
    }
}

void BinaryTree::insert(int d) {
    Node* t = new Node;
    Node* parent;
    t->dataValue = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;

    if(root == NULL) root = t;
    else {
        Node* current;
        current = root;

        while(current) {
            parent = current;
            if(t->dataValue > current->dataValue) current = current->right;
            else current = current->left;
        }

        // jika data yg dimasukkan lebih kecil maka akan dimasukkan ke LeftChild
        if(t->dataValue < parent->dataValue)
            parent->left = t;
        // sebaliknya akan dimasukkan ke RightChild
        else
            parent->right = t;
    }
}

int main() {
    BinaryTree m;
    int ch;
    for (int i = 0; i < 9; i++) {
        cout << "Masukkan node : ";
        cin >> ch;
        m.insert(ch);
    }
    cout << "\nKunjungan Inorder : ";
	m.inOrder(m.getRoot());
	cout << endl;
	cout << "Kunjungan Postorder : ";
	m.postOrder(m.getRoot());
    cout << endl;
	cout << "Kunjungan Preorder : ";
	m.preOrder(m.getRoot());
	cout << endl;
}
// m.insert('J');
    // m.insert('R');
    // m.insert('D');
    // m.insert('G');
    // m.insert('T');
    // m.insert('E');
    // m.insert('M');
    // m.insert('H');
    // m.insert('P');
    // m.insert('A');
    // m.insert('F');
    // m.insert('Q');
/*
J
R
D
G
T
E
M
H
P
A
F
Q
*/
