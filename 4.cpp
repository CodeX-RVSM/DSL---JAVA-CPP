#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* root, int value) {
        if (root == NULL) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root; 
    }

    void inorderTraversal(Node* root) {
    if (root == NULL)
        return;
    else {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
    int contmaxnode(Node* root) {
        if (root == NULL) 
            return 0;
        else {
            int l = contmaxnode(root->left);
            int r = contmaxnode(root->right);
            return max(l, r) + 1;
        }
    }

    int findMinValue(Node* root) {
        if (root == NULL)
            return -1;
        while (root->left != NULL) {
            root = root->left;
        }
        return root->data;
    }

    void swapLeftRight(Node* root) {
        if (root == NULL)
            return;
        swap(root->left, root->right);
        swapLeftRight(root->left);
        swapLeftRight(root->right);
    }

    bool search(Node* root, int value) {
        if (root == NULL)
            return false;
        if (root->data == value)
            return true;
        if (value < root->data)
            return search(root->left, value);
        else
            return search(root->right, value);
    }

public:
    BinaryTree() : root(NULL) {}

    void insert(int value) {
        root= insert(root, value);
    }

    void inorderTraversal() {
        return inorderTraversal(root);
    }

    int longestPathLength() {
        return contmaxnode(root);
    }

    int findMinValue() {
        return findMinValue(root);
    }

    void swapLeftRight() {
        swapLeftRight(root);
    }

    bool search(int value) {
        return search(root, value);
    }
};

int main() {
    BinaryTree tree;
    int values,vk,mk;
    cout<<"\nenter number of nodes to be inserted:"<<endl;
    cin>>vk;
    cout<<"\nenter nodes to be inserted:"<<endl;
    for (int i = 0; i < vk; ++i) {
        cin>>values;
        tree.insert(values);
    }
    cout<<"\ninorder travesaling:"<<endl;
    tree.inorderTraversal();

    cout << "\nNumber of nodes in longest path: ";
    cout << tree.longestPathLength()<< endl;
    
    cout << "Minimum value in the tree: ";
    cout << tree.findMinValue() << endl;

    cout << "Before swapping left and right pointers:" << endl;
    tree.inorderTraversal();
    
    
    tree.swapLeftRight();

    cout << "After swapping left and right pointers:" << endl;
    tree.inorderTraversal();

    cout<<"\nenter value to be searched"<<endl;
    cin>>mk;
    if(tree.search(mk)==1){
        cout<<"element is found"<<endl;
    }else{
        cout<<"element is not found"<<endl;
    }


    return 0;
}
