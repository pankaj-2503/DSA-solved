#include <bits/stdc++.h>
using namespace std;
 
 class Node {
    public:
    int data;
     Node* left = NULL;
     Node* right = NULL;
    Node() {}
 
    Node(int x) { data = x; }
};
 
// Function to construct binary tree from parent array.
Node* createTree(int parent[], int n)
{
    // Create an array to store the reference
    // of all newly created nodes corresponding
    // to node value
    vector<Node*> ref;
 
    // This root represent the root of the
    // newly constructed tree
    Node* root = new Node();
 
    // Create n new tree nodes, each having
    // a value from 0 to n-1, and store them
    // in ref
    for (int i = 0; i < n; i++) {
        Node* temp = new Node(i);
        ref.push_back(temp);
    }
 
    // Traverse the parent array and build the tree
    for (int i = 0; i < n; i++) {
 
        // If the parent is -1, set the root
        // to the current node having
        // the value i which is stored in ref[i]
        if (parent[i] == -1) {
            root = ref[i];
        }
        else {
            // Check if the parent's left child
            // is NULL then map the left child
            // to its parent.
            if (ref[parent[i]]->left == NULL)
                ref[parent[i]]->left = ref[i];
            else
                ref[parent[i]]->right = ref[i];
        }
    }
 
    // Return the root of the newly constructed tree
    return root;
}
 
// Function for inorder traversal
void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
 
// Driver code
int main()
{
    int parent[] = { -1, 0, 0, 1, 1, 3, 5 };
    int n = sizeof parent / sizeof parent[0];
    Node* root = createTree(parent, n);
    cout << "Inorder Traversal of constructed tree\n";
    inorder(root);
    return 0;
}