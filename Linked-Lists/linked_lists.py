import helper_linked_lists

# O(n) space and O(n) time
def remove_dups1(my_list):
    aux = []
    prev = my_list.head
    node = prev.next
    aux.append(prev.data)

    while node is not None:
        if node.data in aux:
            if node.next is None:
                prev.next = None
                node = None
            else:
                prev.next = node.next
                node = node.next
        else:
            aux.append(node.data)
            prev = node
            node = node.next
    return my_list


# O(n**2) time and O(1) space
def remove_dups2(my_list):
    first = my_list.head
    while first is not None:
        prev = first
        second = first.next
        while second is not None:
            if second.data == first.data:
                if second.next is None:
                    prev.next = None
                    second = None
                else:
                    prev.next = second.next
                    second = second.next
            else:
                prev = second
                second = second.next
        first = first.next
    return list


def kth_to_last(my_list, k):
    if k <= 0:
        return None

    node = my_list.head
    counter = 1
    prev = None
    while node is not None:
        if counter == k:
            prev = my_list.head
        elif counter > k:
            prev = prev.next
        counter += 1
        node = node.next
    return prev.data


def partition(my_list, pivot):
    prev = my_list.head
    curr = prev
    while curr is not None:
        if curr.data < pivot and curr is not my_list.head:
            # if something is smaller than the pivot, i place it in thw beginning
            aux = curr.next
            prev.next = curr.next
            curr.next = my_list.head
            my_list.head = curr
            curr = aux
        else:
            prev = curr
            curr = curr.next
    return my_list


def get_number_from_list(list):
    string = ""
    node = list.head
    while node is not None:
        string += str(node.data)
        node = node.next
    return string


def make_list_from_number(number_as_string):
    new_list = helper_linked_lists.SingleLinkedList()
    for i in range(0, len(number_as_string)):
        new_list.insert_last_in_list(int(number_as_string[i]))
    return new_list


def sum_lists_reverse_order1(list1, list2):
    result = "".join(reversed(str(int("".join(reversed(get_number_from_list(list1)))) +
                                  int("".join(reversed(get_number_from_list(list2)))))))
    return make_list_from_number(result)


def sum_in_forward_order1(list1, list2):
    result = "".join(str(int(get_number_from_list(list1)) +
                         int(get_number_from_list(list2))))
    return make_list_from_number(result)


def sum_lists_reverse_order2(list1, list2):
    carry = 0
    new_list = helper_linked_lists.SingleLinkedList()
    node1 = list1.head
    node2 = list2.head
    while node1 is not None and node2 is not None:
        value = node2.data + node1.data + carry
        new_list.insert_last_in_list(value % 10)
        carry = value // 10
        node1 = node1.next
        node2 = node2.next
    while node1 is not None:
        value = node1.data + carry
        new_list.insert_last_in_list(value % 10)
        carry = value // 10
        node1 = node1.next
    while node2 is not None:
        value = node2.data + carry
        new_list.insert_last_in_list(value % 10)
        carry = value // 10
        node2 = node2.next
    return new_list


def is_palindrome(my_list):
    if my_list.get_size() == 1:
        return True
    head = my_list.head.data
    tail = my_list.tail.data
    my_list.remove_head()
    my_list.remove_tail()
    return head == tail and is_palindrome(my_list)


def intersection(list1, list2):
    if list1.tail.data != list2.tail.data:
        return 'tails are not equal'

    size1 = list1.get_size()
    size2 = list2.get_size()
    diff = abs(size1 - size2)
    if size1 > size2:
        bigger = list1
        smaller = list2
    else:
        bigger = list2
        smaller = list1
    node1 = bigger.head
    while diff > 0:
        diff -= 1
        node1 = node1.next
    node2 = smaller.head
    inters = None
    while node1 is not None:
        if node1.data == node2.data and inters is None:
            inters = node1
        if node1.data != node2.data and inters is not None:
            inters = None
        node2 = node2.next
        node1 = node1.next
    if inters is None:
        return 'no intersection'
    else:
        return inters.data


def loop_detection(my_list):
    fast = my_list.head
    slow = my_list.head
    while True:
        slow = slow.next
        fast = fast.next.next
        if fast is None or slow is None or fast.next is None:
            return 'no loop'
        if slow.data == fast.data:
            return slow.data
