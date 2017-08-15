//In-order by recursion (L-N-R)
void order(node* n)     //Pass the root node to this function
{
     if(t->left!=NULL)
     {
        order(t->left);
     }
     cout<<t->info;
     if(t->right!=NULL)
     {
        order(t->right);
     }
}

//Pre-order by recursion (N-L-R)
void order(node* n)     //Pass the root node to this function
{
     cout<<t->info;
     if(t->left!=NULL)
     {
        order(t->left);
     }
     if(t->right!=NULL)
     {
        order(t->right);
     }
}

//Post-order by recursion (L-R-N)
void order(node* n)     //Pass the root node to this function
{
     if(t->left!=NULL)
     {
        order(t->left);
     }
     if(t->right!=NULL)
     {
        order(t->right);
     }
     cout<<t->info;
}
