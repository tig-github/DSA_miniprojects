"""
Turing Machine implemented via Doubly Linked List
"""

from linkedlist import LinkedList


# Tape represented as a Doubly Linked List
# Each listnode value will be a tuple containing the alphabet symbol and state
# A separate member function will act as the pointer, starting at the head
# Furthest left node will always be '*' and is initialized as such
class TuringMachine:
    def __init__(self, fs : set):
        self.finite_set = {'*'}.union(fs) 
        self.tape = LinkedList(); self.tape.add_start('*')
        self.pointer = self.tape.head
        pass