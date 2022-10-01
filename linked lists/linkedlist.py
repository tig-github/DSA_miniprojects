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
            
    def size(self):
        temp = self.head
        size = 0
        while temp:
            temp = temp.next
            size += 1
        return size
            
    def get_start(self):
        assert self.head, "cannot get start of empty Linked List"
        return self.head.val
    
    def get_end(self):
        assert self.tail, "cannot get end of empty Linked List"
        return self.tail.val
    
    def get_at(self, i):
        assert self.head, "cannot get from empty Linked List"
        assert i < self.size() and i >= -self.size(), "invalid index"
        if i < 0:
            i = -i
            i = self.size() - i
        temp = self.head
        while i:
            temp = temp.next
            i -= 1
        return temp.val

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
            
    def remove_start(self):
        assert self.head, "cannot remove from an empty Linked List"
        if self.head == self.tail:
            self.tail = None
        self.head = self.head.next
        if self.head:
            self.head.prev = None 
        
    def remove_end(self):
        assert self.tail, "cannot remove from an empty Linked List"
        if self.tail == self.head:
            self.head = None
        self.tail = self.tail.prev
        if self.tail:
            self.tail.next = None

    # removes the ith node of linkedlist starting at 0. if no such i exists, will raise error
    def remove_at(self, i):
        assert self.head, "cannot remove from an empty Linked List"
        if i < 0:
            i = -i
            i = self.size() - i
        if i >= self.size():
            self.remove_end()
        elif i == 0:
            self.remove_start()
        else:
            temp = self.head 
            i -= 1
            while i > 0:
                temp = temp.next
                i -= 1
            temp.next = temp.next.next 
            if temp.next:
                temp.next.prev = temp
                
    def remove(self, val):
        temp = self.head
        i = 0
        while temp:
            if temp.val == val:
                self.remove_at(i)
                break
            temp = temp.next
            i += 1
    
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
    
    def __getitem__(self, i):
        return self.get_at(i)
        
    def __setitem__(self, i, val):
        assert self.head, 'cannot set item in empty Linked List'
        assert i < self.size() and i >= -self.size()
        temp = self.head
        if i < 0:
            i = -i
            i = self.size() - i
        while i:
            i -= 1
            temp = temp.next 
        temp.val = val
        
    def __delitem__(self, i):
        self.remove_at(i)
        
    # relational operators all are decided by size of linked lists only, nested linked lists not included
    def __eq__(self, ll):
        return self.size() == ll.size()
    
    def __ne__(self, ll):
        return self.size() != ll.size()
    
    def __lt__(self, ll):
        return self.size() < ll.size()
    
    def __gt__(self, ll):
        return self.size() > ll.size()
    
    def __le__(self, ll):
        return self.size() <= ll.size()
    
    def __ge__(self, ll):
        return self.size() >= ll.size()
            
    def print_list(self, chain=' -> ', end='None'):
        if not self.head:
            print(None)
        else:
            temp = self.head
            while temp:
                print(temp.val, end=chain)
                temp = temp.next
            print(end)

    def print_reverse(self, chain='<-', end='None'):
        if not self.tail:
            print(None)
        else:
            temp = self.tail
            print(end, end=' ')
            while temp:
                print(chain, temp.val, end=' ')
                temp = temp.prev