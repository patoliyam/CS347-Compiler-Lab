#include "node.h"

node *add_leaf(string name, string value)
{
    static int no = 1;
    node *temp = new node();
    temp->child[0] = NULL;
    temp->child[1] = NULL;
    temp->child[2] = NULL;
    temp->child[3] = NULL;
    temp->child[4] = NULL;
    temp->child[5] = NULL;
    temp->child[6] = NULL;
    temp->child[7] = NULL;
    temp->child[8] = NULL;
    temp->child[9] = NULL;
    temp->name=name;
    temp->node_val=value;
    temp->node_no = no * 10 + 1;
    no++;
    return temp;
}