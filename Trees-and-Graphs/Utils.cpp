#include "Utils.h"
#include <limits.h>

void routeBetweenNodes(int nodeA, int nodeB, vector<vector<int>> list) {
    vector<int> visited;
    vector<int> toVisit;
    visited.push_back(nodeA);
    toVisit.push_back(nodeA);

    while (!toVisit.empty()){
        vector<int> children = list.at(toVisit.at(0));
        if(toVisit.at(0) ==nodeB) {
            cout << "Found a path!" << endl;
            return;
        }
        visited.push_back(toVisit.at(0));
        toVisit.erase(toVisit.begin());

        for(int child : children) {
            if (find(toVisit.begin(), toVisit.end(), child) == toVisit.end() &&
                find(visited.begin(), visited.end(), child) == visited.end()) {
                toVisit.push_back(child);
            }
        }
    }
    cout << "Path not found" << endl;
    return;
}

BSTNode::BSTNode(int item) {
    this->item = item;
    this->left = nullptr;
    this->right = nullptr;
}

void destroyBST(BSTNode *root) {
    if(root != nullptr) {
        destroyBST(root->left);
        destroyBST(root->right);
    }
    delete root;
}

BSTNode *createTree(vector<int> array, int start, int stop) {
    if(start > stop)
        return nullptr;
    int mid = (start + stop) / 2;
    BSTNode *newNode = new BSTNode(array.at(mid));
    newNode->left = createTree(array, start, mid - 1);
    newNode->right = createTree(array, mid + 1, stop);
    return newNode;
}

BSTNode *minimalTree (vector <int> array) {
    return createTree(array, 0, array.size() - 1);
}

void BST::inOrder(BSTNode *root) {
    if(root != nullptr) {
        inOrder(root->left);
        cout << root->item << " ";
        inOrder(root->right);
    }
}

BST::~BST () {
    destroyBST(root);
}

vector<list<BSTNode*>> BST::listOfDepths(){
    queue<BSTNode*> q;
    q.push(root);
    vector<list<BSTNode*>> array;
    while (! q.empty()) {
        int nodes = q.size();
        list<BSTNode*> l;
        while(nodes > 0) {
            BSTNode *aux = q.front();
            l.push_front(aux);
            q.pop();
            nodes--;
            if(aux->left != nullptr){
                q.push(aux->left);
            }
            if(aux->right != nullptr){
                q.push(aux->right);
            }
        }
        array.push_back(l);
    }
    return array;
}

int BST::getHeight (BSTNode *root) {
    if(root == nullptr) {
        return -1;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int BST::checkBalanced (BSTNode *root) {
    if(root == nullptr) {
        return 0;
    }
    int leftSize = checkBalanced(root->left);
    int rightSize = checkBalanced(root->right);

    if(abs(leftSize - rightSize) > 1) {
        cout << "Not balanced" << endl;
    }
    return max(leftSize, rightSize) + 1;
}

bool validateBSTHelper(BSTNode *root, int min, int max) {
    if(root == nullptr)
        return true;
    return (root->item >= min && root->item <= max) &&
            validateBSTHelper(root->left, min, root->item) &&
            validateBSTHelper(root->right, root->item, max);
}

bool BST::validateBST () {
    return validateBSTHelper(root, INT_MIN, INT_MAX);
}

BSTNode* successor(BSTNode* node) {
    if(node->right != nullptr) {
        node = node->right;
        BSTNode *prev;
        while(node != nullptr) {
            prev = node;
            node = node->left;
        }
        return prev;
    } else {
        BSTNode *parent = node->parent;
        while(parent != nullptr && parent->left != node) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

bool findNode(BSTNode* root, int item) {
    if(root == nullptr)
        return false;
    return (root->item == item || findNode(root->left, item) ||
            findNode(root->right, item));
}

BSTNode* BST::firstCommonAncestor (BSTNode* root, int node1, int node2) {
    if(root == nullptr || !findNode(root, node1) || !findNode(root, node2))
        return nullptr;
    if(root->item == node1 || root->item == node2)
        return root;
    BSTNode* left =  firstCommonAncestor (root->left, node1, node2);
    BSTNode* right =  firstCommonAncestor (root->right, node1, node2);
    if(left != nullptr && right != nullptr)
        return root;
    if(left != nullptr)
        return left;
    if(right != nullptr)
        return right;
    return nullptr;
}

void weaveLists(list<int> left, list<int> right,
                vector<list<int>>* results, list<int> prefix) {
    if(left.empty() || right.empty()) {
        list<int> result;
        result.assign(prefix.begin(), prefix.end());
        result.insert(result.end(), left.begin(),  left.end());
        result.insert(result.end(), right.begin(),  right.end());
        (*results).push_back(result);
        return;
    }

    int leftFirst = left.front();
    left.pop_front();
    prefix.push_back(leftFirst);
    weaveLists(left, right, results, prefix);
    prefix.pop_back();
    left.push_front(leftFirst);

    int rightFirst = right.front();
    right.pop_front();
    prefix.push_back(rightFirst);
    weaveLists(left, right, results, prefix);
    prefix.pop_back();
    right.push_front(rightFirst);
}

vector<list<int>> BST::BSTSequences (BSTNode *node) {
    vector<list<int>> result;
    list<int> prefix;
    if(node == nullptr) {
        result.push_back(prefix);
        return result;
    }
    prefix.push_back(node->item);
    vector<list<int>> left = BSTSequences(node->left);
    vector<list<int>> right = BSTSequences(node->right);

    for(list<int> l : left) {
        for(list<int> r : right) {
            vector<list<int>> weaved;
            weaveLists(l, r, &weaved, prefix);
            result.insert(result.end(), weaved.begin(), weaved.end());
        }
    }
    return result;
}

Project* getProject(vector<Project*> projects, string name) {
    for(Project* p : projects) {
        if(p->name == name) {
            return p;
        }
    }
    return nullptr;
}

vector<Project*> createGraphOfProjects(vector<string> projects,
                                       vector<pair<string, string>> dependencies){
    vector<Project*> projectsStructures;
    for(string p : projects){
        Project* proj = new Project(p);
        projectsStructures.push_back(proj);
    }

    for(pair<string, string> dep : dependencies) {
        Project* project = getProject(projectsStructures, dep.first);
        if(project != nullptr) {
            Project* child = getProject(projectsStructures, dep.second);
            child->dependenciesNo++;
            project->children.push_back(child);
        }
    }
    return projectsStructures;
}

vector<string> buildOrder(vector<string> projects,
                       vector<pair<string, string>> dependencies) {

    vector<Project*> projectsStructures = createGraphOfProjects(projects, dependencies);
    int idx = 0;
    vector<string> order;
    while (idx < projectsStructures.size()) {
        if(projectsStructures.at(idx)->dependenciesNo == 0) {
            order.push_back(projectsStructures.at(idx)->name);
            for(Project* child : projectsStructures.at(idx)->children) {
                child->dependenciesNo--;
            }
            Project *aux = projectsStructures.at(idx);
            projectsStructures.erase(projectsStructures.begin() + idx);
            delete aux;
            idx = -1;
        }
        idx++;
    }
    return order;
}

Project* DFSProject(Project** node) {
    cout << "iterator= " << (*node)->name << endl;
    if((*node)->children.empty() && !(*node)->visited) {
        (*node)->visited = true;
        return (*node);
    }
    for(Project* child : (*node)->children) {
        if(! child->visited) {
            return DFSProject(&child);
        }
    }
    if(! (*node)->visited){
        (*node)->visited = true;
        return (*node);
    }
    return nullptr;
}

vector<string> buildOrder2(vector<string> projects,
                           vector<pair<string, string>> dependencies){

    vector<Project*> projectsStructures = createGraphOfProjects(projects, dependencies);
    vector<string> order;
    vector<Project*> copy = projectsStructures;
    while (!projectsStructures.empty()) {
        Project* p = projectsStructures.at(0);
        Project* aux = DFSProject(&p);
        while(aux != nullptr) {
            order.push_back(aux->name);
            projectsStructures.erase(find(projectsStructures.begin(),
                                          projectsStructures.end(), aux));
            if(p != nullptr)
                aux = DFSProject(&p);
        }
    }
    for(Project *p : copy) {
        delete p;
    }
    reverse(order.begin(), order.end());
    return order;
}

void BST::preorder (BSTNode *root, string *nodes) {
    if(root != nullptr) {
        (*nodes) += to_string(root->item);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    } else {
        (*nodes) += "*";
    }
}

bool checkSubtree(BST* t1, BST* t2) {
    string tree1Preorder = "";
    string tree2Preorder = "";
    t1->preorder(t1->root, &tree1Preorder);
    t2->preorder(t2->root, &tree2Preorder);
    return tree1Preorder.find(tree2Preorder) != string :: npos;
}

int pathsWithSumHelper(BSTNode* node, int sum, int currentSum) {
    if(node == nullptr) {
        return 0;
    }
    currentSum += node->item;
    return pathsWithSumHelper(node->right, sum, currentSum) +
           pathsWithSumHelper(node->left, sum, currentSum) +
           (currentSum == sum ? 1 : 0);
}

int BST::pathsWithSum (BSTNode *root, int sum) {
    if(root == nullptr){
        return 0;
    }
    int currentSum = 0;
    return pathsWithSumHelper(root, sum, currentSum) +
            pathsWithSum(root->left, sum) +
            pathsWithSum(root->right, sum);
}

int pathsWithSumHelper2(BSTNode* node, int sum, map<int, int> map, int currentSum) {
    if(node == nullptr) return 0;

    currentSum += node->item;
    int diff =  currentSum - sum;
    int numberOfPaths = map[diff];
    map[diff]++;

    numberOfPaths += (pathsWithSumHelper2(node->left, sum, map, currentSum) +
            pathsWithSumHelper2(node->right, sum, map, currentSum) +
            (currentSum == sum ? 1 : 0));
    map[diff]--;
    return numberOfPaths;
}

int BST::pathsWithSum2 (BSTNode *root, int sum) {
    map<int, int> myMap;
    return pathsWithSumHelper2(root, sum, myMap, 0);
}