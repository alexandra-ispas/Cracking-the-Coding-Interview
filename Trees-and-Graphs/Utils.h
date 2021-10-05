#ifndef TREES_AND_GRAPHS_TREE_H
#define TREES_AND_GRAPHS_TREE_H

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class BSTNode {
public:
    int item;
    BSTNode *left, *right, *parent;
    BSTNode(int item);
};

class BST {
public:
    BSTNode *root;
    BST() {
        root = nullptr;
    }
    ~BST();

    void inOrder(BSTNode *root);
    vector<list<BSTNode*>> listOfDepths();
    int checkBalanced(BSTNode *root);
    int getHeight(BSTNode *root);
    bool validateBST();
    BSTNode* successor(BSTNode* node);
    BSTNode* firstCommonAncestor(BSTNode* root, int node1, int node2);
    vector<list<int>> BSTSequences(BSTNode* root);
    void preorder(BSTNode* root, string *nodes);
    int pathsWithSum(BSTNode* root, int sum);
    int pathsWithSum2(BSTNode* root, int sum);
};

class Project {
public:
    string name;
    vector<Project*> children;
    int dependenciesNo;
    bool visited;

    Project(string name) {
        this->name = name;
        this->dependenciesNo = 0;
        this->visited = false;
    }
};

BSTNode* minimalTree(vector<int> array);
vector<string> buildOrder(vector<string> projects,
                          vector<pair<string, string>> dependencies);

bool findNode(BSTNode* root, int item);
vector<Project*> createGraphOfProjects(vector<string> projects,
                                       vector<pair<string, string>> dependencies);
void routeBetweenNodes(int nodeA, int nodeB, vector<vector<int>> list);
Project* DFSProject(Project** node);
vector<string> buildOrder2(vector<string> projects,
                           vector<pair<string, string>> dependencies);
bool checkSubtree(BST* t1, BST *t2);
#endif //TREES_AND_GRAPHS_TREE_H
