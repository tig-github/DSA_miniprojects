# venus supports the following
# https://github.com/kvakil/venus/wiki


.data
label: .asciiz "testlabel\n"



.text

# a0 holds size of stack (currently static)
# allocates space (where?) based on size for stack (for now item size fixed to 4 bytes)
init:  addi $sp, $sp, -4
       sw $ra, 0($sp)


       lw $ra, 0($sp)
       addi $sp, $sp, 4
       jr $ra 


# a0 holds item to push
# checks if item is valid to push to stack
# returns error if stack is full (for now, later stack will be dynamic)
push: addi $sp, $sp, -4
       sw $ra, 0($sp)


       lw $ra, 0($sp)
       addi $sp, $sp, 4
       jr $ra 


# pops element at top of stack, returns it
pop: addi $sp, $sp, -4
       sw $ra, 0($sp)


       lw $ra, 0($sp)
       addi $sp, $sp, 4
       jr $ra 


# returns element at top of stack
peek: addi $sp, $sp, -4
       sw $ra, 0($sp)


       lw $ra, 0($sp)
       addi $sp, $sp, 4
       jr $ra 

