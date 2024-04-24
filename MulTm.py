# -*- coding: utf-8 -*-
import time

# Constant for tab
TAB = "\t"

# Tape settings
tape = ""
# Get input for n * m
try:
    n = int(input("Please input n : "))
    m = int(input("Please input m : "))
except ValueError:
    print("Oops! That was not a valid number")
    raise
print()

# Location the TM is looking at in the tape, starting at 1 as first element is a ^
pointer = 1
# Current state the TM is in, starting state is q0, thus 0
currentState = 0
# Counter tracking amount of tapes produced
counter = 1

# States dictionary, each state containing it's transitions in the form of {"W": "X,Y,Z",...}:
# "W" the input read
# "X" replace the input "W" with "X"
# "Y" the direction of travel (L,R,0 for no movement)
# "Z" add Z to transition to determine which state is traveled too

states = {
    0: {"1": "X,R,1", "*": "*,L,6"},
    1: {"1": "1,R,0", "*": "*,R,1"},
    2: {"1": "Y,R,1", "=": "=,L,3"},
    3: {"1": "1,R,0", "=": "=,R,0", "^": "1,0,1"},
    4: {"1": "1,L,0", "=": "=,L,0", "Y": "Y,R,-2"},
    5: {"1": "1,L,0", "*": "*,L,0", "Y": "1,L,0", "X": "X,R,-5"},
    6: {"X": "1,L,0", "^": "^,R,1"}
}

# Setup tape
# Initial ^ character
tape += "^"

# Adding the 0's that represent n
for x in range(n):
    tape += "1"

# Adding separator character
tape += "*"

# Adding the 0's that represent m
for x in range(m):
    tape += "1"

# Adding separator character
tape += "="

# Adding the needed amount of ^ characters to the tape
amount = m * n + 1
for x in range(amount):
    tape += "^"

# Convert tape to list for multiplication
tape = list(tape)

print("Starting " + str(n) + " * " + str(m))
print()

# Start timing just before we start producing tapes
start = time.time()

# Start multiplication
# Loop until we are in the final state, state 7
while currentState in states:

    # Find the current character we are dealing with
    currentCharacter = tape[pointer]
    # Find the correct transition for the character @ the currentState from the states dictionary
    transition = (states[currentState][currentCharacter])

    transition = transition.split(",")

    # Create string (tape) for output
    string = ''.join(tape)

    # Print index
    print(TAB * pointer + str(pointer - 1))

    # Print tape
    print(TAB.join(string))

    # Print arrow
    print(TAB.join((' ' * pointer + '\u2191')))

    # Print state
    # Make sure state is printing at correct location when pointing at 0
    if (pointer != 0):
        state = TAB.join(' ' * pointer)
        state += TAB + ("q" + str(currentState))
    elif (pointer == 0):
        state = TAB.join(' ' * pointer)
        state += ("q" + str(currentState))

    print(state)
    print()

    # Re-write rule
    tape[pointer] = transition[0]
    # Move pointer
    if transition[1] == "R":
        pointer += 1
    elif transition[1] == "L":
        pointer -= 1

    # Transition between states
    currentState += int(transition[2])

    print("Tape number : " + str(counter))
    # Increment counter for number of tapes produced
    counter += 1

    print()

# Computation completed, displaying results below
end = time.time()

# Print final tape, outside loop as in state 'q7'
# Print index
print(TAB * pointer + str(pointer - 1))

# Print tape
print(TAB.join(string))

# Print arrow
print(TAB.join((' ' * pointer + '↑')))

# Print state
# Make sure state is printing at correct location when pointing at 0
if (pointer != 0):
    state = TAB.join(' ' * pointer)
    state += TAB + ("q" + str(currentState))
elif (pointer == 0):
    state = TAB.join(' ' * pointer)
    state += ("q" + str(currentState))

print(state)
print()
print("Tape number : " + str(counter))
print()
print("Results below")
print("-------------")
print("Number of tapes produced: " + str(counter))
print("Time elapsed: " + str(end - start))