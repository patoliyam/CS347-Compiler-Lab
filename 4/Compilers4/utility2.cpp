#include "node.h"
#include <string>

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
    temp->child[10] = NULL;
    temp->child[11] = NULL;
    temp->child[12] = NULL;
    temp->child[13] = NULL;
    temp->child[14] = NULL;
    temp->name=name;
    temp->node_val=value;
    temp->code="";
    temp->node_val_num = -1;
    temp->node_no = no * 15 + 1;
    if(temp->name == "NUM")
    {
        if(value.find(".") != std::string::npos)
        {
            temp->node_val_num = atof(value.c_str());
            temp->eletype = "float";
        }
        else
        {
            temp->node_val_num = atoi(value.c_str());
            temp->eletype = "int";
        }
    }
    else if(temp->name == "CHARACTER")
    {   
        temp->node_val_num = (int)value[1];
        temp->eletype = "char";
    }

    no++;
    return temp;
}