"""
Turing Machine implemented via Doubly Linked List
If the pointer goes left of the start, it will create a * node
"""

from linkedlist import LinkedList


# Tape represented as a Doubly Linked List
# Each listnode value will contain a symbol from the alphabet
# A separate class member will act as the pointer, starting at the head
# Furthest right node will always be '*' and is initialized as such
# Activation function taken in by file
class TuringMachine:
    def __init__(self, alpha : set, state : set, af, input : list):
        self.alphabet = {'*'}.union(alpha) 
        self.state = {'acc', 'rej', 'q0'}.union(state)
        self.tape = self.init_tape(input)
        self.pointer = [self.tape.head, 'q0']
        self.activation_function = self.read_af(af)
    
    # initializes tape based on input
    def init_tape(self, input : list):
        tape = LinkedList()
        for element in input:
            tape.add_end(element)
        tape.add_end('*')
        return tape
        
    # reads the activation function from a file
    def read_af(self, af):
        with open(af) as activation_function:
            function = {}
            for line in activation_function:
                if line and line[0] != '#':
                    line = line.split(" ")
                    if line[0] in self.state:
                        function[(line[0],line[1])] = (line[2].strip('(').strip(','), line[3].strip(','), line[4].strip(')'))
        return function
    
    # preforms all steps in activation function
    def activate(self):
        print(f"<{self.pointer[0].val}, {self.pointer[1]}>")
        while self.pointer[1] != 'qrej' and self.pointer[1] != 'qacc':
            self.step()
            self.print_turing_machine()
        if self.pointer[1] == 'qacc': print('Turing Machine in accepted state')
        else: print("Turing Machine in rejected state")
    
    # preforms one step in activation function
    def step(self):
        state = self.pointer[1]
        symbol = self.pointer[0].val
        if state in {'qacc', 'qrej'}: 
            print('Turing Machine has already computed this input')
            return
        current_function = self.activation_function[(state, symbol)]
        self.pointer[1] = current_function[0]
        self.pointer[0].val = current_function[1]
        if current_function[2] == 'L':
            if not self.pointer[0].prev:
                self.tape.add_start('*')
            self.pointer[0] = self.pointer[0].prev 
        else:
            if not self.pointer[0].next:
                self.tape.add_end('*')
            self.pointer[0] = self.pointer[0].next
            
    def print_turing_machine(self):
        self.tape.print_list(chain=' | ', end='...')
        print(f"<{self.pointer[0].val}, {self.pointer[1]}>")