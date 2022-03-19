#include<iostream>
using namespace std;

class AVLTree {
    struct node {
        int data;
        node* left;
        node* right;
        int height;
    };

    node* root;

    node* insert(int x, node* t) {
        if(t == NULL) {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        } else if(x < t->data) {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2) {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = leftRightRotate(t);
            }
        } else if(x > t->data) {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2) {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = rightLeftRotate(t);
            }
        } else if( x == t->data) return t;
        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

    // fungsi untuk right rotate
    node* singleRightRotate(node* &t) {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

    // fungsi untuk left rotate
    node* singleLeftRotate(node* &t) {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

    // fungsi untuk right-left rotate
    node* rightLeftRotate(node* &t) {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    // fungsi untuk left-right rotate
    node* leftRightRotate(node* &t) {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    int height(node* t) {
        return (t == NULL ? -1 : t->height);
    }

    int getBalance(node* t) {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    void preorder(node* t) {
        if(t == NULL)
            return;
        cout << t->data << " ";
        inorder(t->left);
        inorder(t->right);
    }

    void postorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        inorder(t->right);
        cout << t->data << " ";
    }

public:
    AVLTree() {
        root = NULL;
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void display() {
        cout << "Preorder  : ";
        preorder(root);
        cout << endl;
        cout << "Inorder   : ";
        inorder(root);
        cout << endl;
        cout << "Postorder : ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    int n, value;
    cout << "++======================++\n";
    cout << "||        AVL Tree      ||\n";
    cout << "++======================++\n\n";
    cout << "Masukkan banyak node yang akan ditambahkan : ";
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cout << "Node ke-" << i+1 << " yang dimasukkan : ";
        cin >> value;
        tree.insert(value);
    }
    cout << "\nTraverse Tree secara Preorder, Inorder, dan Postorder : \n";
    tree.display();
    return 0;    
}