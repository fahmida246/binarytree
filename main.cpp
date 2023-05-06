#include <iostream>
#include<queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(node *root)
{
    cout<<"enter data"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1)
    {
        return 0;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if(temp== NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);

            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int incnt(node *root,int &cnt)
{

    if(root==NULL)
    {
        return 0;
    }
    incnt(root->left,cnt);
    if(root->left==NULL && root->right == NULL)
    {
        cnt++;
    }
    incnt(root->right,cnt);

}
int noofleaf(node *root)
{
    int cnt=0;
    incnt(root,cnt);
    return cnt;
}
int countHeight(node *root)
{
    if(root==0)
    {
        return 0;
    }
    int left = countHeight(root->left);
    int right = countHeight(root->right);
    int ans = max(left,right)+1;
    return ans;
}
int diameter(node *root)
{
    if(root ==0)
    {
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = countHeight(root->left)+countHeight(root->right)+1;
    int ans = max(op1,max(op2,op3));
    return ans;
}

int isbalanced(node *root)
{
    if(root ==0)
    {
        return 1;
    }
    int left = isbalanced(root->left);
    int right = isbalanced(root->right);
    int op3 = abs(countHeight(root->left)-countHeight(root->right))<=1;
    if(left && right&& op3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isIdentical(node *r1, node *r2){
    if(r1 == NULL && r2 == NULL){
        return 1;
    }
    if(r1 == NULL && r2 != NULL){
        return 0;
    }
    if(r1 != NULL && r2 == NULL){
        return 0;
    }
    int left = isIdentical(r1->left,r2->left);
    int right = isIdentical(r1->right,r2->right);
    int value = r1->data == r2->data;
    if(left && right && value){
        return 1;
    }
    else{
        return 0;
    }
}
void inorder(node* root)
{
    //base case
    if(root == NULL)
    {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root)
{
    //base case
    if(root == NULL)
    {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root)
{
    //base case
    if(root == NULL)
    {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    int    cot = noofleaf(root);
    cout<<cot;
    int    h = countHeight(root);
    cout<<h;
    int d = diameter(root);
    cout<<d;
    int b =isbalanced(root);
    cout<<b;
    int c = isIdentical(root,root);
    cout<<c;
    cout << "inorder traversal is:  ";
    inorder(root);
    cout << endl << "preorder traversal is:  ";
    preorder(root);
    cout << endl << "postorder traversal is:  ";
    postorder(root);

    // cout << "Hello world!" << endl;
    return 0;
}
