#ifndef TREES_AND_GRAPHS_RANDOMNODE_H
#define TREES_AND_GRAPHS_RANDOMNODE_H

#include <cstdlib>
#include <iostream>
class RandomNode {
public:
    int item;
    RandomNode *left, *right;

    RandomNode(int item);
    void insertRandomNode(int item);
    RandomNode* getRandomNode();
    RandomNode* getRandomNodeAtIndex(int index);

private:
    int size;
};

void destroyRandomNode(RandomNode* node);

#endif //TREES_AND_GRAPHS_RANDOMNODE_H
