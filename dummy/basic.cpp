#include<iostream>

using namespace std;
class students{
    public:
    int age;
    int roll_no;
};

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//taking input for bst
Node* insertIntoBST(Node* &root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    //recursive call for
    if(root->data > d){
        //left recursive call
        root->left = insertIntoBST(root->left, d);
    }
    else{
        root->right = insertIntoBST(root->right, d);
    }

    return root;
}

void inputToBST(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

//inserting into bst

int main(){
    // students s1;
    // students const s2 = s1;
    // s1.roll_no = 1001;
    // s1.age = 40;
    // cout<<s2.roll_no<<" "<<s2.age<<endl;
    Node* root = NULL;
    inputToBST(root);
    cout<<root->data<<" "<<endl;

}