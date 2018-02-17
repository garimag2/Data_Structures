struct node{
    long long data;
    node* next= NULL;
};
void insert(node* root,long long b){
    node* temp = new node();
    temp ->data = b;
    if(root == NULL){
        root = temp;
        return;
    }
    node* current= root;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next= temp;
}
void pop(node* root){
    if(root == NULL){
        return;
    }
    node* current = root;
    while(current->next->next!=NULL){
        current=current->next;
    }
    delete(current->next->next);
    current->next=NULL;
}
int max_print(node* root,long long value){
    if(root == NULL){
        return value;
    }
    //cout <<"root->data: "<< root->data << " " <<"v: " << value << " ";
    if(value > root->data){
        return max_print(root->next,value);
    }
    else{
        return max_print(root->next,root->data);
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n;
    cin >> n;
    node* root = new node;
    node* temp = root;
    long long value= numeric_limits<long long>::min();
    long long val=0;
    for(long long i=0;i<n;i++){
        int a;
        long long b;
        cin >> a;
        if(a==1){
            cin >>b;
            insert(root,b);
        }
        if(a==2){
            pop(root);
        }
        if(a==3){
            val = max_print(temp, value);
            if(val > INT16_MIN){
                //cout << endl;
                cout << val <<endl;
            }
        } 
    }
    return 0;
}
