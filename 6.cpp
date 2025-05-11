#include <iostream> 
#include <stack> 
using namespace std;

class node
    {
        public: 
            node *left;
            node *right; 
            char ch;
    };

bool isOperator(char c)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            return true;
        }
        return false;
    }


node *newNode(char c)
    {
        node *temp = new node; 
        temp->left = NULL; 
        temp->right = NULL; 
        temp->ch = c;
        return temp;
    }


node *createTree(string expression)
    {
        node *t; 
        node *t1; 
        node *t2;
        stack<node *> st;
        for (int i = expression.length() - 1; i >= 0; i--)
        {
            cout<<expression[i]<<"\t"; 
            if (!isOperator(expression[i]))
            {
                t = newNode(expression[i]); 
                st.push(t);
            }
            else
            {
                t = newNode(expression[i]); 
                t1 = st.top();
                st.pop();
                t2 = st.top();
                st.pop();
                t->left = t1;
                t->right = t2; 
                st.push(t);
            }
        }
        t = st.top(); 
        return t;
    }

void inorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            inorder(root->left);
            cout << root->ch << "\t"; 
            inorder(root->right);
        }
    }


void delete_tree(node *root)
    {
        if (root == NULL){
            return;
        }
        else{
            cout<<"Deleting :- "<<root->ch<<endl; 
            delete_tree(root->left); 
            delete_tree(root->right);
            delete root;
        }
    }
int main()
    {
        string expression; node *root_node;
        cout << "\nEnter the Prefix Expression:- "; 
        cin >> expression;
        root_node = createTree(expression);
        cout << "\nTree Created successfully" << endl; 
        cout << "\n Inorder Traversing:- " << endl; 
        inorder(root_node);
        cout<<"\n\nDeleting Tree.	"<<endl;
        delete_tree(root_node); 
        cout<<"\nDeleted Successfully"<<endl; 
        return 0;
    }

