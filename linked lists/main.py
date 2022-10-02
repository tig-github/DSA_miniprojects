"""
Example showing use of Turing Machine
Files must be written to the standards specified in af.txt
Activation Functions allow user inputted rulesets, but note their alphabets and states must match what is passed into the Turing Machine
States 'qacc', 'qrej', and 'q0' do not have to be directly inputted into the Turing Machine
"""

from turingmachine import TuringMachine

if __name__ == '__main__':
    tm = TuringMachine({'a, b'}, {'q0', 'q1'}, 'af.txt', ['a','b','b','a'])
    tm.activate()
    tm2 = TuringMachine({'a, b'}, {'q0', 'q1'}, 'af.txt', ['a','b','a','a'])
    tm2.activate()
    # # if it is preferable to see individual steps, use .step() and print afterwards
    # tm3 = TuringMachine({'a, b'}, {'q0', 'q1'}, 'af.txt', ['b','b','a','a'])
    # tm3.step()
    # tm3.print_turing_machine()
    # # similar to a generator, it will continually step from where it left off
    # tm3.step()
    # tm3.print_turing_machine()