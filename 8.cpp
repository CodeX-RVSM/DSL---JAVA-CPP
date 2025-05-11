#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    string key;
    string value;
    Node* left;
    Node* right;

    Node(string k, string v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursively(Node* node, string key, string value) {
        if (node == nullptr) {
            return new Node(key, value);
        }
        if (key < node->key) {
            node->left = insertRecursively(node->left, key, value);
        } else if (key > node->key) {
            node->right = insertRecursively(node->right, key, value);
        } else { // Update value if key already exists
            node->value = value;
        }
        return node;
    }

    Node* searchRecursively(Node* node, string key) {
        if (node == nullptr || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return searchRecursively(node->left, key);
        } else {
            return searchRecursively(node->right, key);
        }
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteRecursively(Node* node, string key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (key < node->key) {
            node->left = deleteRecursively(node->left, key);
        } else if (key > node->key) {
            node->right = deleteRecursively(node->right, key);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = deleteRecursively(node->right, temp->key);
        }
        return node;
    }

    void inorderTraversalRecursively(Node* node) {
        if (node != nullptr) {
            inorderTraversalRecursively(node->left);
            cout << "(" << node->key << ", " << node->value << ") ";
            inorderTraversalRecursively(node->right);
        }
    }

    void reverseInorderTraversalRecursively(Node* node) {
        if (node != nullptr) {
            reverseInorderTraversalRecursively(node->right);
            cout << "(" << node->key << ", " << node->value << ") ";
            reverseInorderTraversalRecursively(node->left);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(string key, string value) {
        root = insertRecursively(root, key, value);
    }

    string search(string key) {
        Node* result = searchRecursively(root, key);
        return (result != nullptr) ? result->value : "Key not found";
    }

    void remove(string key) {
        root = deleteRecursively(root, key);
    }

    void displayAscending() {
        inorderTraversalRecursively(root);
        cout << endl;
    }

    void displayDescending() {
        reverseInorderTraversalRecursively(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    string word, meaning;
    int a,ch;

    cout<<"\n\t***** data Information *****";
	cout << "\n\t--MENU--";
	cout<<"\n\t1. Insert word meaning\n\t2.Add new word meaning pair\n\t3. Displaying data in ascending order:\n\t4. Displaying data in decending order:\n\t5. Search\n\t6.Remove\n\t7. Exit";
	do
	  {
		cout<<"\n\tEnter Your Choice : ";
		cin>>ch;
		switch(ch)
		  {
			case 1: 
                cout << "\tEnter how many word meanings to enter:" << endl;
                cin >> a;
                for (int i = 0; i < a; i++) {
                    cout << "\tEnter Word:" << endl;
                    cin >> word;
                    cout << "\tEnter meaning:" << endl;
                    cin >> meaning;
                    bst.insert(word, meaning);
                    }
				break;
            case 2:
                cout<<"\tenter word to be added:";
                cin>>word;
                cout<<"\tenter its meaning:";
                cin>>meaning;
                bst.insert(word, meaning);
                break;
			case 3:	
                cout << "\tDisplaying data in ascending order:" << endl;
                bst.displayAscending();
				break;
			case 4: 
                cout << "\tDisplaying data in descending order:" << endl;
                bst.displayDescending();
				break;
			case 5: 
                cout<<"\n\tenter word to be find:"<<endl;
                cin>>word;
                cout << "Meaning: " << bst.search(word) << endl;
				break;
            case 6:
                cout<<"\n\tenter word to be removed:"<<endl;
                cin>>word;
                bst.remove(word);
                cout << "\tDisplaying data in ascending order:" << endl;
                bst.displayAscending();
				break;
		  }
	
	  }while(ch != 7);

    return 0;
}
