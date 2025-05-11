#include<iostream>
using namespace std;
class node{
    public:
    string word,meaning;
    node* left;
    node* right;
    int ht;
};
class avl{
    public:
    node* root;
    avl(){
        root=NULL;
    }
    node* create(string word,string meaning){
        node * newnode = new node;
        newnode->word=word;
        newnode->meaning=meaning;
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->ht=1;
        return newnode;
    }
    int height(node* root)
    { 
        if (root == NULL){
            return 0;
        }
        else{
            return(max(height(root->left),height(root->right)) + 1);
        
        }
    }

    int get_BF(node* root)
    {
        if (root == NULL){
            return 0;
        }
        else{
            return (height(root->left) - height(root->right));
        }
    }
    node* rotate_right(node* y)
    {
        node*x = y->left;
        node* T = x->right;
        x->right = y;
        y->left = T;
        y->ht = height(y);
        x->ht = height(x);
        return x;
    }
    node* rotate_left(node* y)
    {
        node*x = y->right ;
        node*T = x->left ;
        x->left = y;
        y->right = T;
        y->ht = height(y);
        x->ht = height(x);
        return x;
    }
    node* insert(node* root, string word,string meaning){
        if(root==NULL){
            root=create(word,meaning);
        }
        else if(word<root->word){
            root->left=insert(root->left,word,meaning);
        }
        else if(word>root->word){
            root->right=insert(root->right,word,meaning);
        }
        else{
            return root;
        }
        root->ht=height(root);
        int BF = get_BF(root);
        if((BF > 1) && (word < root->left->word))
        { 
            return rotate_right(root);
        }
        if((BF > 1) && (word > root->left->word))
        { 
            root->left = rotate_left(root->left);
            return rotate_right(root);
        }
        if((BF < -1) && (word > root->right->word))
        { 
            return rotate_left(root);
        }
        if((BF < -1) && (word < root->right->word))
        { 
            root->right = rotate_right(root->right);
            return rotate_left(root);
        }
        return root;
    }
    void InorderDisplay_ascending(node *root)
    {
        if(root == NULL)
        {
            return;
        }
        else{
            cout<<root->word<<" = "<<root->meaning<<" ";
            InorderDisplay_ascending(root->left);
            InorderDisplay_ascending(root->right);
        }
    }
    void InorderDisplay_descending(node *root)
    {   if(root == NULL)
        {
            return;
        }
        else{
            InorderDisplay_descending(root->right);
            cout<<root->word<<" = "<<root->meaning<<" ";
            InorderDisplay_descending(root->left);
        }
    }
    node *MaxDataValue(node *root)
    { 
        if (root == NULL){
            return root;
        }
        else if(root->right == NULL){
            return root;
        }
        else{
            return MaxDataValue(root->right);
        }
    }

    node* deleteNode(node* root, string key) 
    { 
        if (root == NULL){
            return root;
        }
        if (key < root->word){
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->word){
            root->right = deleteNode(root->right, key);
        }
        else{
            if (root->left == NULL) { 
                node* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == NULL) 
            { 
                node* temp = root->left; 
                delete root;
                return temp;
            }
            node* temp = MaxDataValue(root->left); root->word = temp->word;
            root->meaning = temp->meaning;
            root->left = deleteNode(root->left, temp->word);
        }
    }
    void update_keyword(node *root,string word, string meaning)
    { 
        if(root->word > word){
            return update_keyword(root->left,word, meaning);
        }
        else if(root->word < word){
            return update_keyword(root->right,word, meaning);
        }
        else if(root->word == word){
            cout<<"\n Key is already present..."<<endl; 
            cout<<"\n Updating meaning..."<<endl; 
            root->meaning = meaning;
            cout<<"\n meaning updated succesfully"<<endl; return;
        }
    }






};
int main(){
    avl MyTree; 
    int ch,comp;
    string word,meaning,temp_word;
    string key;
    string temp_key;

    cout<<"1.Creating Tree(only one's)"<<endl; 
    cout<<"2.Insert Element."<<endl; 
    cout<<"3.Update keyword meaning."<<endl; 
    cout<<"4.ascending traversing"<<endl; 
    cout<<"5.descending traversing"<<endl;  
    cout<<"6.Delete node."<<endl; 
    cout<<"7.Exit."<<endl;
    while (true){
        cout<<endl<<"\n Enter your choice: "; 
        cin>>ch;
        switch(ch){ 
            case 1:
                cout<<"Enter data of root node of tree (key & meaning): "; 
                cin>>word>>meaning;
                MyTree.root = MyTree.insert(MyTree.root, word, meaning); 
                cout<<"Tree created successfully"<<endl;
                break; 
            case 2:
                cout<<"Enter new node data (key & meaning): "; 
                cin>>word>>meaning;
                MyTree.root = MyTree.insert(MyTree.root, word, meaning);   
                cout<<"Node added successfully"<<endl;
                break; 
            case 3:
                cout<<"Enter the data of node you want to update (key & new meaning): "; 
                cin>>word>>meaning;
                MyTree.update_keyword(MyTree.root, word, meaning); 
                break;
            case 4:
                cout<<"Ascending traversing:"<<endl; 
                MyTree.InorderDisplay_ascending(MyTree.root); 
                break;
            case 5:
                cout<<"Descending traversing:"<<endl; 
                MyTree.InorderDisplay_descending(MyTree.root); 
                break;
            case 6:
                cout<<"Enter the key you want to delete: "; 
                cin>>temp_word; MyTree.deleteNode(MyTree.root, temp_word); 
                cout<<"Successfully deleted "<<temp_word<<endl; 
                break;
            case 7:
                cout<<"Exiting..."<<endl; 
                exit(0);
                break;
            }
        }
    return 0;
}
