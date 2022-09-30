"""
Testing suite for Doubly Linked List
"""
from linkedlist import LinkedList

def can_add_start():
    print('----------------\ncan_add_start\n----')
    l = LinkedList()
    l.add_start(2)
    l.print_list()
    print('----\nshould print 2 -> None\n----------------')

def can_add_end():
    print('----------------\ncan_add_end\n----')
    l = LinkedList()
    l.add_end(2)
    l.print_list()
    print('----\nshould print 2 -> None\n----------------')
    
def can_add_end2():
    print('----------------\ncan_add_end2\n----')
    l = LinkedList()
    l.add_end(2)
    l.add_end(3)
    l.add_end(4)
    l.add_end(5)
    l.print_list()
    print('----\nshould print 2 -> 3-> 4-> 5-> None\n----------------')
    
def can_add_at():
    print('----------------\ncan_add_at\n----')
    l = LinkedList()
    l.add_end(1)
    l.add_end(2)
    l.add_end(4)
    l.add_end(5)
    l.add_at(3, 2)
    l.print_list()
    print('----\nshould print 1 -> 2 -> 3-> 4-> 5-> None\n----------------')
    
def can_add_at2():
    print('----------------\ncan_add_at2\n----')
    l = LinkedList()
    l.add_end(1)
    l.add_at(2, 20)
    l.add_at(0, 0)
    l.print_list()
    print('----\nshould print 0 -> 1 -> 2 -> None\n----------------')
    
def can_add_at3():
    print('----------------\ncan_add_at2\n----')
    l = LinkedList()
    l.add_at(2, -2)
    l.print_list()
    print('----\nshould print 2 -> None\n----------------')
    
def can_add_at4():
    print('----------------\ncan_add_at2\n----')
    l = LinkedList()
    l.add_start(1)
    l.add_end(2)
    l.add_at(3, -1)
    l.add_at(0, -3)
    l.print_list()
    print('----\nshould print 0 -> 1 -> 2 -> 3 -> None\n----------------')
    
def can_size():
    print('----------------\ncan_size\n----')
    l = LinkedList()
    l.add_end(1)
    l.add_end(2)
    print(l.size())
    print('----\nshould print 2\n----------------')
    
def can_len():
    print('----------------\ncan_len\n----')
    l = LinkedList()
    l.add_end(1)
    l.add_end(2)
    print(len(l))
    print('----\nshould print 2\n----------------')
    
def can_bool():
    print('----------------\ncan_bool\n----')
    l1 = LinkedList()
    if not l1: 
        print('FALSE')
    l2 = LinkedList()
    l2.add_start(4)
    if l2:
        print('TRUE') 
    print('----\nshould print FALSE then TRUE\n----------------')

def can_add_lists():
    print('----------------\ncan_add_lists\n----')
    l1 = LinkedList()
    l1.add_end(1)
    l1.add_end(2)
    l2 = LinkedList()
    l2.add_end(3)
    l2.add_end(4)
    l1 += l2 
    l1.print_list()
    print('\n----\nshould print 1 -> 2 -> 3 -> 4 -> None\n----------------')
    
def can_convert_str():
    print('----------------\ncan_convert_string\n----')
    l1 = LinkedList()
    l1.add_start(1)
    l1.add_start(2)
    l1.add_start(3)
    print(str(l1))
    print('---\nshould print (3) -> (2) -> (1) -> None\n----------------')
    
def can_repr():
    print('----------------\ncan_repr\n----')
    l1 = LinkedList()
    l1.add_start(1)
    l1.add_start(2)
    l1.add_start(3)
    print((repr(l1)))
    print('---\nshould print LinkedList(<3,2,1>)\n----------------')
    
def can_contains():
    print('----------------\ncan_contains\n----')
    l = LinkedList()
    l.add_start(2)
    if 2 in l: print('TRUE')
    if 1 not in l: print('FALSE')
    print('---\nshould print TRUE then FALSE\n----------------')
    


if __name__ == '__main__':
    # can_add_start()
    # can_add_end()
    # can_add_end2()
    # can_add_at()
    # can_add_at2()
    # can_add_at3()
    # can_add_at4()
    # can_size()
    # can_len()
    # can_bool()
    # can_add_lists()
    # can_convert_str()
    # can_repr()
    can_contains()
    pass