# venus supports the following
# https://github.com/kvakil/venus/wiki


.data
label: .asciiz "testlabel\n"



.text

# a0 holds size of stack (currently static)
# allocates space based on size in number of items (4 bytes only for now)
# returns memory location in a0 of stack
# metadata (size) stored in first 8 bytes of stack as header tag
# tag is of form:           [ SIZE (4 bytes) | NUM_ELEMENTS (4 bytes) ] 
init:  addi sp, sp, -4
       sw ra, 0(sp)
       slli a1, a0, 2 # memory alignment
       addi a1, a1, 8 #store an extra cell, as first is the tag
       li a0, 9
       ecall
       sw a1, 0(a0)
       sw x0, 4(a0)
       lw ra, 0(sp)
       addi sp, sp, 4
       jr ra 


# a0 holds pointer to stack
# a1 holds item
# checks if item is valid to push to stack
# returns error if stack is full (for now, later stack will be dynamic)
push: addi sp, sp, -4
       sw ra, 0(sp)


       lw ra, 0(sp)
       addi sp, sp, 4
       jr ra 


# a0 holds pointer to stack
# pops element at top of stack, returns it
pop: addi sp, sp, -4
       sw ra, 0(sp)


       lw ra, 0(sp)
       addi sp, sp, 4
       jr ra 


# a0 holds pointer to stack
# returns element at top of stack
peek: addi sp, sp, -4
       sw ra, 0(sp)


       lw ra, 0(sp)
       addi sp, sp, 4
       jr ra 


# a0 holds pointer to stack
# deallocates heap space and destroys stack
deallocate: addi sp, sp, -4
       sw ra, 0(sp)

       lw ra, 0(sp)
       addi sp, sp, 4
       jr ra 