#include "node.h"
#include <iostream>
node* add_new_node(string name, node* c0=NULL, node* c1=NULL, node* c2=NULL, node* c3=NULL, node* c4=NULL, node* c5=NULL, node* c6=NULL, node* c7=NULL, node* c8=NULL, node* c9=NULL, node* c10=NULL, node* c11=NULL, node* c12=NULL, node* c13=NULL, node* c14=NULL) {
    static int no = 1;
    node *temp;
    temp = new node();

    temp->child[0] = c0;
    temp->child[1] = c1;
    temp->child[2] = c2;
    temp->child[3] = c3;
    temp->child[4] = c4;
    temp->child[5] = c5;
    temp->child[6] = c6;
    temp->child[7] = c7;
    temp->child[8] = c8;
    temp->child[9] = c9;
    temp->child[10] = c10;
    temp->child[11] = c11;
    temp->child[12] = c12;
    temp->child[13] = c13;
    temp->child[14] = NULL;
    temp->name=name;
    temp->node_no = no * 15;
    no++;

    return temp;
}
void print_nodes_in_file(struct node* root, std::ofstream& parse_tree)
{
    if(root == NULL)
            return;
    else
    {
        parse_tree << "< " << root->name << " > : ";
        if(root->child[0] == NULL)
        {
            parse_tree << root->node_val;
        }
        for(int i=0 ; i<15 ; i++)
        {
            if(root->child[i] != NULL)
            {
                parse_tree << " <" << root->child[i]->name << "> ";
            }
            else
            {
                parse_tree << "\n";
                break;
            }
        }
        for(int i=0;i<15; i++)
        {
            if(root->child[i] != NULL)
            {
                print_nodes_in_file(root->child[i],parse_tree);
            }
        }
    }
}

void print_nodes(struct node* root, std::ofstream& parse_tree)
{
    if(root == NULL)
            return;
    else
    {
        cout << "< " << root->name << " > : ";
        parse_tree << "< " << root->name << " > : ";
        if(root->child[0] == NULL)
        {
            cout << root->node_val;
            parse_tree << root->node_val;
        }
        for(int i=0 ; i<15 ; i++)
        {
            if(root->child[i] != NULL)
            {
                cout << " <" << root->child[i]->name << "> ";
                parse_tree << " <" << root->child[i]->name << "> ";
            }
            else
            {
                cout << "\n";
                parse_tree << "\n";
                break;
            }
        }
        for(int i=0;i<15; i++)
        {
            if(root->child[i] != NULL)
            {
                print_nodes(root->child[i],parse_tree);
            }
        }
    }
}


void print_nodes_node_num(struct node* root, std::ofstream& parse_tree)
{
    if(root == NULL)
        return;
    else
    {
        cout << "Parent node " << root->node_no << "< " << root->name << " > : ";
        parse_tree << "Parent node " << root->node_no << "< " << root->name << " > : ";
        if(root->child[0] == NULL)
        {
            cout << root->node_val;
            parse_tree << root->node_val;
        }
        for(int i=0 ; i<15 ; i++)
        {
            if(root->child[i] != NULL)
            {
                cout << root->child[i]->node_no << " <" << root->child[i]->name << "> ";
                parse_tree << root->child[i]->node_no << " <" << root->child[i]->name << "> ";
            }
            else
            {
                cout << "\n";
                parse_tree << "\n";
                break;
            }
        }
        for(int i=0;i<15; i++)
        {
            if(root->child[i] != NULL)
            {
                print_nodes_node_num(root->child[i],parse_tree);
            }
        }
    }
}
