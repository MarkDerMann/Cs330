import copy

from collections.abc import (Iterator, Iterable)

class LinkedList(Iterable):
    """
    The LinkedList (LL) is a wrapper for three items.
     - Head pointer
     - Tail pointer
     - Node counter (cardinality)

    Only the head pointer is necessary, the latter three items are
    included for convenience.

    In this version, the LinkedList has been converted to a proper class
    """

    class Node(object):
        """
        The Node class is the atom--smallest base component--of a Linked List.
        An array element can viewed as its analog.

        For simplicity in this example, the Node will store an integers as
        data. In a later example, methods for generalizing this--through use of
        templates--will be utilized.
        """

        def __init__(self, data=0, next=None):
            self.data = data
            self.next = next

    class Iterator(Iterator):
        """
        A special purpose Linked List Iterator
        """

        def __init__(self, node):
            self.current_node = node

        def __next__(self):
            if self.current_node is None:
                raise StopIteration

            next_val = (self.current_node).data

            self.current_node = self.current_node.next

            return next_val

    def __init__(self):
        """
        Construct an empty Linked List
        """

        self.__head = None
        self.__tail = None
        self.__nodes = 0

    def append(self, to_add):
        """
        Add a Node at the end of the list
        """

        # Store the "to_add" data within the node
        new_node = LinkedList.Node(data=to_add)

        # Handle the case where the first node is added
        if self.__head is None:
            self.__head = new_node
            self.__tail = new_node

        else:
            (self.__tail).next = new_node
            self.__tail = new_node

        self.__nodes += 1

    def __len__(self):
        return self.__nodes

    def __iter__(self):
        return LinkedList.Iterator(self.__head)

    def __str__(self):
        """
        Iterate through the LinkedList and print each individual Node
        with an index.
        """

        return "\n".join(["Node # {:>4} - {:>4}".format(index, data)
                          for index, data in enumerate(self)])
