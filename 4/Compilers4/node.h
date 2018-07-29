#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

struct node{
    node* child[15];
    string name;
    int node_no;
    // synthesises atributes;
    int inoffset,outoffset;
    string node_val;
    string eletype;
    string code;
    float node_val_num;
    vector<int> dimlist;
    vector<string> paramlist;
    int index;
    // vector<string> v;
};