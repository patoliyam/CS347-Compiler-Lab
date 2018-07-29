#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

struct node{
    node* child[10];
    string name;
    string node_val;
    int node_no;
};