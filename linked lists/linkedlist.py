"""
Doubly Linked List
"""

class ListNode:
    def __init__(self, val=None, next=None, prev=None):
        self.val = val
        self.next = next 
        self.prev = prev

class LinkedList:
    def __init__(self, ll=None):
        if ll and type(ll) == type(self):
            self.head = ll.head
            self.tail = ll.tail 
        else:
            self.head = None
            self.tail = None

    def add_end(self, val):
        if self.tail:
            temp = self.tail
            self.tail.next = ListNode(val, None, temp)
            self.tail = self.tail.next
        else:
            self.tail = ListNode(val)
            self.head = self.tail
    
    def add_start(self, val):
        if self.head:
            temp = self.head
            self.head = ListNode(val, temp)
            temp.prev = self.head
        else:
            self.head = ListNode(val)
            self.tail = self.head
            
    # adds to ith node of linkedlist starting at 0. if no such i exists, will add to end
    def add_at(self, val, i):
        if not self.head:
            self.add_start(val)
            return
        if i < 0:
            i = -i - 1
            i = self.size() - i
        if i >= self.size():
            self.add_end(val)
        elif i == 0:
            self.add_start(val)
        else:
            temp = self.head 
            i -= 1
            while i > 0:
                temp = temp.next
                i -= 1
            temp2 = temp.next
            temp.next = ListNode(val, temp2, temp)
            temp2.prev = temp
        
    def size(self):
        temp = self.head
        size = 0
        while temp:
            temp = temp.next
            size += 1
        return size
    
    def __add__(self, ll):
        assert type(ll) == type(self), 'Linked Lists may only be added to other Linked Lists'
        if self.tail:
            self.tail.next = ll.head
            ll.head.prev = self.tail
            self.tail = ll.tail
        else:
            self.head = ll.head
            self.tail = ll.tail
        return self
    
    def __len__(self):
        return self.size()
    
    def __bool__(self):
        return bool(self.size())
    
    def __str__(self):
        ll_str = ''
        temp = self.head
        while temp:
            ll_str += f'({temp.val}) -> '
            temp = temp.next
        ll_str += ' None'
        return ll_str
    
    def __repr__(self):
        ll_repr = 'LinkedList(<'
        temp = self.head
        while temp:
            ll_repr += f'{temp.val}'
            if temp.next: ll_repr += ','
            temp = temp.next
        ll_repr += '>)'
        return ll_repr
    
    def __contains__(self, val):
        temp = self.head
        while temp:
            if temp.val == val:
                return True 
            temp = temp.next
        return False
            
    def print_list(self):
        if not self.head:
            print(None)
        else:
            temp = self.head
            while temp:
                print(temp.val, end=' -> ')
                temp = temp.next
            print('None')

    def print_reverse(self):
        if not self.tail:
            print(None)
        else:
            temp = self.tail
            print('None', end=' ')
            while temp:
                print('<-', temp.val, end=' ')
                temp = temp.prev
