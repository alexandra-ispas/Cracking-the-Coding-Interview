#include "RandomNode.h"


RandomNode::RandomNode (int item) {
    this->item = item;
    this->left = nullptr;
    this->right = nullptr;
    this->size = 0;
}

void RandomNode::insertRandomNode (int data) {
    if(item <= data) {
        if(left == nullptr) {
            left = new RandomNode(data);
        } else {
            left->insertRandomNode(data);
        }
    } else {
        if(right == nullptr) {
            right = new RandomNode(data);
        } else {
            right->insertRandomNode(data);
        }
    }
    size++;
}

RandomNode* RandomNode::getRandomNode () {
    int index = rand() % size;
    std::cout << "the index is: " << index << std::endl;
    std::cout << "size : " << size << std::endl;
    return getRandomNodeAtIndex(index);
}

RandomNode* RandomNode::getRandomNodeAtIndex(int index) {
    int leftSize = 0;
    if(left != nullptr) {
        leftSize = left->size;
    }
    std::cout << "leftsize: " << leftSize << std::endl;
    if(index < leftSize) {
        return left->getRandomNodeAtIndex(index);
    } else if (index == leftSize) {
        return  this;
    } else {
        return right->getRandomNodeAtIndex(index - leftSize - 1);
    }
}
