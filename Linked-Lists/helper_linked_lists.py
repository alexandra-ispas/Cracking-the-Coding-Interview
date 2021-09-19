class SNode:
    def __init__(self, data):
        self.data = data
        self.next = None


class DNode:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def is_empty(self):
        return self.tail is None and self.head is None

    def print_list(self):
        if self.head is None:
            print('[]')
        else:
            print('[', end=" ")
            value = self.head
            while value is not None:
                print(value.data, end=" ")
                value = value.next
            print(']')


class SingleLinkedList(LinkedList):
    def insert_first_in_list(self, data):
        node = SNode(data)
        if self.is_empty():
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head = node

    def insert_last_in_list(self, data):
        node = SNode(data)
        if self.is_empty():
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            self.tail = node

    def delete_middle_node(self, node):
        if node == self.head or node == self.head:
            return None
        node.data = node.next.data
        aux = node.next.next
        node.next = aux

    def get_size(self):
        node = self.head
        counter = 0
        while node is not None:
            counter += 1
            node = node.next
        return counter

    def remove_head(self):
        aux = self.head
        self.head = aux.next

    def remove_tail(self):
        node = self.head
        prev = node
        while node is not self.tail:
            prev = node
            node = node.next
        prev.next = None
        self.tail = prev

class DoubleLinkedList(LinkedList):
    def insert_first_in_list(self, data):
        node = DNode(data)
        if self.is_empty():
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node

    def insert_last_in_list(self, data):
        node = DNode(data)
        if self.is_empty():
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node
