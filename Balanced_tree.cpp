/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(node* root){
    if(root== NULL){
        return -1;
    }
        //cout << root->ht << "\n";
        return root->ht;
}
int setheight(node* root){
    if(root == NULL){
       return -1;
    }
    /*if(root->left == NULL || root->right == NULL){
        return 0;
    }*/ 
        return (1+max(height(root->left),height(root->right)));
}
node* rotate_right(node* root){
    node* temp = root->left;
    node* temp1 = temp->right;
    temp->right = root;
    root->left= temp1;
    root->ht= setheight(root);
    temp->ht=setheight(temp);
    return temp;
}

node* rotate_left(node* root){
    node* temp = root->right;
    node* temp1 = temp->left;
    temp->left = root;
    root->right= temp1;
    root->ht= setheight(root);
    temp->ht=setheight(temp);
    return temp;
}
node * insert(node * root,int val)
{  
   node* temp = new node();
   temp->val = val;
   temp->left = NULL;
   temp->right = NULL;
   //temp->ht=setheight(root);
   if(root==NULL){
       root= temp;
       root->ht= setheight(root);
       return root;
   }
       if(val <= root->val){
           temp = insert(root->left,val);
           root->left= temp;
       }
       if(val > root->val){
           temp = insert(root->right,val);
           root->right= temp;
       }
   int balanced = height(root->left) - height(root->right);
   if(balanced <-1){
       if(height(root->right->right) >= height(root->right->left)){
           root= rotate_left(root);
       }
       else{
           root->right = rotate_right(root->right);
           root = rotate_left(root);
       }
   }
   else if(balanced > 1){
       if(height(root->left->left) >= height(root->left->right)){
           root= rotate_right(root);
       }
       else{
           root->left = rotate_left(root->left);
           root= rotate_right(root);
       }
   }
   else{
       root->ht= setheight(root);
   }
    return root;
  
}

          
