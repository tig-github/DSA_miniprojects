"""
Example showing use of Turing Machine
"""

from turingmachine import TuringMachine

if __name__ == '__main__':
    tm = TuringMachine({'a, b'}, {'q0', 'q1'}, 'af.txt', ['a','b','b','a'])
    tm.activate()
    tm2 = TuringMachine({'a, b'}, {'q0', 'q1'}, 'af.txt', ['a','b','a','a'])
    tm2.activate()