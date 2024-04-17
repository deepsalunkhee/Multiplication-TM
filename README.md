# Unary Multiplication Turing Machine

This Python program simulates a Turing machine capable of multiplying two unary numbers represented by strings of 1s. The program takes two unary numbers \( n \) and \( m \) as input and demonstrates the step-by-step execution of the Turing machine, printing the contents of the tape after each step.

## Usage

1. **Input**: The program prompts the user to input two unary numbers \( n \) and \( m \).
2. **Execution**: Upon receiving the input, the program simulates the Turing machine to multiply the two unary numbers.
3. **Output**: After each step, the program displays the current state of the tape, the position of the tape head, and the state of the Turing machine. Once the multiplication is completed, the final tape state and the number of tapes produced are displayed.

## Components of the Turing Machine

The Turing machine consists of the following components:

- **States (Q)**:
  - \( q_0 \): Start state
  - \( q_1, q_2, q_3, q_4, q_5, q_6 \): Intermediate states for processing
  - \( q_7 \): Accepting state

- **Alphabet (\(\Sigma\))**: 
  - Symbol for 1

- **Tape Alphabet (\(\Gamma\))**:
  - Symbols for 1 (input)
  - Additional symbols: *, =, ^ (used for multiplication process)
  - Blank symbol (⊥) for empty spaces on the tape

- **Transition Function (\(\delta\))**:
  - Defines state transitions based on the current state, the symbol on the tape, and the next symbol to write, along with the direction (left/right) to move the tape head.

## States and Transitions

The Turing machine transitions between states according to the following rules:

- **State \( q_0 \)**:
  - Reads 1, writes X, moves right.
  - Reads *, moves left to state \( q_6 \).

- **State \( q_1 \)**:
  - Reads 1, moves right to state \( q_0 \).
  - Reads *, moves right to itself.

- **State \( q_2 \)**:
  - Reads 1, writes ⊥, moves right to state \( q_1 \).
  - Reads =, moves left to state \( q_3 \).

- **State \( q_3 \)**:
  - Reads 1, moves right to state \( q_0 \).
  - Reads =, moves right to state \( q_0 \).
  - Reads ^, writes 1, moves right to state \( q_1 \).

- **State \( q_4 \)**:
  - Reads 1, writes 1, moves left to state \( q_0 \).
  - Reads =, moves left to state \( q_0 \).
  - Reads ⊥, moves right to state \( q_5 \).

- **State \( q_5 \)**:
  - Reads 1, moves left to state \( q_0 \).
  - Reads *, moves left to state \( q_0 \).
  - Reads ⊥, writes 1, moves left to state \( q_0 \).
  - Reads X, moves right to state \( q_2 \).

- **State \( q_6 \)**:
  - Reads X, writes 1, moves left to state \( q_0 \).
  - Reads ^, moves right to state \( q_1 \).

## Example Execution

For example, if \( n = 3 \) and \( m = 2 \), the program will execute the Turing machine to compute \( 3 \times 2 \), producing the following output:

'''
Please input n : 3
Please input m : 2

Starting 3 * 2

        0
^       1       1       1       *       1       1       =       ^       ^       ^       ^       ^       ^       ^
        ↑
        q0

Tape number : 1

                1
^       X       1       1       *       1       1       =       ^       ^       ^       ^       ^       ^       ^
                ↑
                q1

Tape number : 2

                        2
^       X       1       1       *       1       1       =       ^       ^       ^       ^       ^       ^       ^
                        ↑
                        q1

Tape number : 3

                                3
^       X       1       1       *       1       1       =       ^       ^       ^       ^       ^       ^       ^
                                ↑
                                q1

Tape number : 4

                                        4
^       X       1       1       *       1       1       =       ^       ^       ^       ^       ^       ^       ^
                                        ↑
                                        q2

Tape number : 5

                                                5
^       X       1       1       *       ⊥       1       =       ^       ^       ^       ^       ^       ^       ^
                                                ↑
                                                q3

Tape number : 6

                                                        6
^       X       1       1       *       ⊥       1       =       ^       ^       ^       ^       ^       ^       ^
                                                        ↑
                                                        q3

Tape number : 7

                                                                7
^       X       1       1       *       ⊥       1       =       ^       ^       ^       ^       ^       ^       ^
                                                                ↑
                                                                q3

Tape number : 8

                                                                7
^       X       1       1       *       ⊥       1       =       1       ^       ^       ^       ^       ^       ^
                                                                ↑
                                                                q4

Tape number : 9

                                                        6
^       X       1       1       *       ⊥       1       =       1       ^       ^       ^       ^       ^       ^
                                                        ↑
                                                        q4

Tape number : 10

                                                5
^       X       1       1       *       ⊥       1       =       1       ^       ^       ^       ^       ^       ^
                                                ↑
                                                q4

Tape number : 11

                                        4
^       X       1       1       *       ⊥       1       =       1       ^       ^       ^       ^       ^       ^
                                        ↑
                                        q4

Tape number : 12

                                                5
^       X       1       1       *       ⊥       1       =       1       ^       ^       ^       ^       ^       ^
                                                ↑
                                                q2

Tape number : 13

                                                        6
^       X       1       1       *       ⊥       ⊥       =       1       ^       ^       ^       ^       ^       ^
                                                        ↑
                                                        q3

Tape number : 14

                                                                7
^       X       1       1       *       ⊥       ⊥       =       1       ^       ^       ^       ^       ^       ^
                                                                ↑
                                                                q3

Tape number : 15

                                                                        8
^       X       1       1       *       ⊥       ⊥       =       1       ^       ^       ^       ^       ^       ^
                                                                        ↑
                                                                        q3

Tape number : 16

                                                                        8
^       X       1       1       *       ⊥       ⊥       =       1       1       ^       ^       ^       ^       ^
                                                                        ↑
                                                                        q4

Tape number : 17

                                                                7
^       X       1       1       *       ⊥       ⊥       =       1       1       ^       ^       ^       ^       ^
                                                                ↑
                                                                q4

Tape number : 18

                                                        6
^       X       1       1       *       ⊥       ⊥       =       1       1       ^       ^       ^       ^       ^
                                                        ↑
                                                        q4

Tape number : 19

                                                5
^       X       1       1       *       ⊥       ⊥       =       1       1       ^       ^       ^       ^       ^
                                                ↑
                                                q4

Tape number : 20

                                                        6
^       X       1       1       *       ⊥       ⊥       =       1       1       ^       ^       ^       ^       ^
                                                        ↑
                                                        q2

Tape number : 21

                                                5
^       X       1       1       *       ⊥       ⊥       =       1       1       ^       ^       ^       ^       ^
                                                ↑
                                                q5

Tape number : 22

                                        4
^       X       1       1       *       ⊥       1       =       1       1       ^       ^       ^       ^       ^
                                        ↑
                                        q5

Tape number : 23

                                3
^       X       1       1       *       1       1       =       1       1       ^       ^       ^       ^       ^
                                ↑
                                q5

Tape number : 24

                        2
^       X       1       1       *       1       1       =       1       1       ^       ^       ^       ^       ^
                        ↑
                        q5

Tape number : 25

                1
^       X       1       1       *       1       1       =       1       1       ^       ^       ^       ^       ^
                ↑
                q5

Tape number : 26

        0
^       X       1       1       *       1       1       =       1       1       ^       ^       ^       ^       ^
        ↑
        q5

Tape number : 27

                1
^       X       1       1       *       1       1       =       1       1       ^       ^       ^       ^       ^
                ↑
                q0

Tape number : 28

                        2
^       X       X       1       *       1       1       =       1       1       ^       ^       ^       ^       ^
                        ↑
                        q1

Tape number : 29

                                3
^       X       X       1       *       1       1       =       1       1       ^       ^       ^       ^       ^
                                ↑
                                q1

Tape number : 30

                                        4
^       X       X       1       *       1       1       =       1       1       ^       ^       ^       ^       ^
                                        ↑
                                        q2

Tape number : 31

                                                5
^       X       X       1       *       ⊥       1       =       1       1       ^       ^       ^       ^       ^
                                                ↑
                                                q3

Tape number : 32

                                                        6
^       X       X       1       *       ⊥       1       =       1       1       ^       ^       ^       ^       ^
                                                        ↑
                                                        q3

Tape number : 33

                                                                7
^       X       X       1       *       ⊥       1       =       1       1       ^       ^       ^       ^       ^
                                                                ↑
                                                                q3

Tape number : 34

                                                                        8
^       X       X       1       *       ⊥       1       =       1       1       ^       ^       ^       ^       ^
                                                                        ↑
                                                                        q3

Tape number : 35

                                                                                9
^       X       X       1       *       ⊥       1       =       1       1       ^       ^       ^       ^       ^
                                                                                ↑
                                                                                q3

Tape number : 36

                                                                                9
^       X       X       1       *       ⊥       1       =       1       1       1       ^       ^       ^       ^
                                                                                ↑
                                                                                q4

Tape number : 37

                                                                        8
^       X       X       1       *       ⊥       1       =       1       1       1       ^       ^       ^       ^
                                                                        ↑
                                                                        q4

Tape number : 38

                                                                7
^       X       X       1       *       ⊥       1       =       1       1       1       ^       ^       ^       ^
                                                                ↑
                                                                q4

Tape number : 39

                                                        6
^       X       X       1       *       ⊥       1       =       1       1       1       ^       ^       ^       ^
                                                        ↑
                                                        q4

Tape number : 40

                                                5
^       X       X       1       *       ⊥       1       =       1       1       1       ^       ^       ^       ^
                                                ↑
                                                q4

Tape number : 41

                                        4
^       X       X       1       *       ⊥       1       =       1       1       1       ^       ^       ^       ^
                                        ↑
                                        q4

Tape number : 42

                                                5
^       X       X       1       *       ⊥       1       =       1       1       1       ^       ^       ^       ^
                                                ↑
                                                q2

Tape number : 43

                                                        6
^       X       X       1       *       ⊥       ⊥       =       1       1       1       ^       ^       ^       ^
                                                        ↑
                                                        q3

Tape number : 44

                                                                7
^       X       X       1       *       ⊥       ⊥       =       1       1       1       ^       ^       ^       ^
                                                                ↑
                                                                q3

Tape number : 45

                                                                        8
^       X       X       1       *       ⊥       ⊥       =       1       1       1       ^       ^       ^       ^
                                                                        ↑
                                                                        q3

Tape number : 46

                                                                                9
^       X       X       1       *       ⊥       ⊥       =       1       1       1       ^       ^       ^       ^
                                                                                ↑
                                                                                q3

Tape number : 47

                                                                                        10
^       X       X       1       *       ⊥       ⊥       =       1       1       1       ^       ^       ^       ^
                                                                                        ↑
                                                                                        q3

Tape number : 48

                                                                                        10
^       X       X       1       *       ⊥       ⊥       =       1       1       1       1       ^       ^       ^
                                                                                        ↑
                                                                                        q4

Tape number : 49

                                                                                9
^       X       X       1       *       ⊥       ⊥       =       1       1       1       1       ^       ^       ^
                                                                                ↑
                                                                                q4

Tape number : 50

                                                                        8
^       X       X       1       *       ⊥       ⊥       =       1       1       1       1       ^       ^       ^
                                                                        ↑
                                                                        q4

Tape number : 51

                                                                7
^       X       X       1       *       ⊥       ⊥       =       1       1       1       1       ^       ^       ^
                                                                ↑
                                                                q4

Tape number : 52

                                                        6
^       X       X       1       *       ⊥       ⊥       =       1       1       1       1       ^       ^       ^
                                                        ↑
                                                        q4

Tape number : 53

                                                5
^       X       X       1       *       ⊥       ⊥       =       1       1       1       1       ^       ^       ^
                                                ↑
                                                q4

Tape number : 54

                                                        6
^       X       X       1       *       ⊥       ⊥       =       1       1       1       1       ^       ^       ^
                                                        ↑
                                                        q2

Tape number : 55

                                                5
^       X       X       1       *       ⊥       ⊥       =       1       1       1       1       ^       ^       ^
                                                ↑
                                                q5

Tape number : 56

                                        4
^       X       X       1       *       ⊥       1       =       1       1       1       1       ^       ^       ^
                                        ↑
                                        q5

Tape number : 57

                                3
^       X       X       1       *       1       1       =       1       1       1       1       ^       ^       ^
                                ↑
                                q5

Tape number : 58

                        2
^       X       X       1       *       1       1       =       1       1       1       1       ^       ^       ^
                        ↑
                        q5

Tape number : 59

                1
^       X       X       1       *       1       1       =       1       1       1       1       ^       ^       ^
                ↑
                q5

Tape number : 60

                        2
^       X       X       1       *       1       1       =       1       1       1       1       ^       ^       ^
                        ↑
                        q0

Tape number : 61

                                3
^       X       X       X       *       1       1       =       1       1       1       1       ^       ^       ^
                                ↑
                                q1

Tape number : 62

                                        4
^       X       X       X       *       1       1       =       1       1       1       1       ^       ^       ^
                                        ↑
                                        q2

Tape number : 63

                                                5
^       X       X       X       *       ⊥       1       =       1       1       1       1       ^       ^       ^
                                                ↑
                                                q3

Tape number : 64

                                                        6
^       X       X       X       *       ⊥       1       =       1       1       1       1       ^       ^       ^
                                                        ↑
                                                        q3

Tape number : 65

                                                                7
^       X       X       X       *       ⊥       1       =       1       1       1       1       ^       ^       ^
                                                                ↑
                                                                q3

Tape number : 66

                                                                        8
^       X       X       X       *       ⊥       1       =       1       1       1       1       ^       ^       ^
                                                                        ↑
                                                                        q3

Tape number : 67

                                                                                9
^       X       X       X       *       ⊥       1       =       1       1       1       1       ^       ^       ^
                                                                                ↑
                                                                                q3

Tape number : 68

                                                                                        10
^       X       X       X       *       ⊥       1       =       1       1       1       1       ^       ^       ^
                                                                                        ↑
                                                                                        q3

Tape number : 69

                                                                                                11
^       X       X       X       *       ⊥       1       =       1       1       1       1       ^       ^       ^
                                                                                                ↑
                                                                                                q3

Tape number : 70

                                                                                                11
^       X       X       X       *       ⊥       1       =       1       1       1       1       1       ^       ^
                                                                                                ↑
                                                                                                q4

Tape number : 71

                                                                                        10
^       X       X       X       *       ⊥       1       =       1       1       1       1       1       ^       ^
                                                                                        ↑
                                                                                        q4

Tape number : 72

                                                                                9
^       X       X       X       *       ⊥       1       =       1       1       1       1       1       ^       ^
                                                                                ↑
                                                                                q4

Tape number : 73

                                                                        8
^       X       X       X       *       ⊥       1       =       1       1       1       1       1       ^       ^
                                                                        ↑
                                                                        q4

Tape number : 74

                                                                7
^       X       X       X       *       ⊥       1       =       1       1       1       1       1       ^       ^
                                                                ↑
                                                                q4

Tape number : 75

                                                        6
^       X       X       X       *       ⊥       1       =       1       1       1       1       1       ^       ^
                                                        ↑
                                                        q4

Tape number : 76

                                                5
^       X       X       X       *       ⊥       1       =       1       1       1       1       1       ^       ^
                                                ↑
                                                q4

Tape number : 77

                                        4
^       X       X       X       *       ⊥       1       =       1       1       1       1       1       ^       ^
                                        ↑
                                        q4

Tape number : 78

                                                5
^       X       X       X       *       ⊥       1       =       1       1       1       1       1       ^       ^
                                                ↑
                                                q2

Tape number : 79

                                                        6
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       ^       ^
                                                        ↑
                                                        q3

Tape number : 80

                                                                7
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       ^       ^
                                                                ↑
                                                                q3

Tape number : 81

                                                                        8
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       ^       ^
                                                                        ↑
                                                                        q3

Tape number : 82

                                                                                9
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       ^       ^
                                                                                ↑
                                                                                q3

Tape number : 83

                                                                                        10
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       ^       ^
                                                                                        ↑
                                                                                        q3

Tape number : 84

                                                                                                11
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       ^       ^
                                                                                                ↑
                                                                                                q3

Tape number : 85

                                                                                                        12
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       ^       ^
                                                                                                        ↑
                                                                                                        q3

Tape number : 86

                                                                                                        12
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       1       ^
                                                                                                        ↑
                                                                                                        q4

Tape number : 87

                                                                                                11
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       1       ^
                                                                                                ↑
                                                                                                q4

Tape number : 88

                                                                                        10
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       1       ^
                                                                                        ↑
                                                                                        q4

Tape number : 89

                                                                                9
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       1       ^
                                                                                ↑
                                                                                q4

Tape number : 90

                                                                        8
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       1       ^
                                                                        ↑
                                                                        q4

Tape number : 91

                                                                7
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       1       ^
                                                                ↑
                                                                q4

Tape number : 92

                                                        6
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       1       ^
                                                        ↑
                                                        q4

Tape number : 93

                                                5
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       1       ^
                                                ↑
                                                q4

Tape number : 94

                                                        6
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       1       ^
                                                        ↑
                                                        q2

Tape number : 95

                                                5
^       X       X       X       *       ⊥       ⊥       =       1       1       1       1       1       1       ^
                                                ↑
                                                q5

Tape number : 96

                                        4
^       X       X       X       *       ⊥       1       =       1       1       1       1       1       1       ^
                                        ↑
                                        q5

Tape number : 97

                                3
^       X       X       X       *       1       1       =       1       1       1       1       1       1       ^
                                ↑
                                q5

Tape number : 98

                        2
^       X       X       X       *       1       1       =       1       1       1       1       1       1       ^
                        ↑
                        q5

Tape number : 99

                                3
^       X       X       X       *       1       1       =       1       1       1       1       1       1       ^
                                ↑
                                q0

Tape number : 100

                        2
^       X       X       X       *       1       1       =       1       1       1       1       1       1       ^
                        ↑
                        q6

Tape number : 101

                1
^       X       X       1       *       1       1       =       1       1       1       1       1       1       ^
                ↑
                q6

Tape number : 102

        0
^       X       1       1       *       1       1       =       1       1       1       1       1       1       ^
        ↑
        q6

Tape number : 103

-1
^       1       1       1       *       1       1       =       1       1       1       1       1       1       ^
↑
q6

Tape number : 104

        0
^       1       1       1       *       1       1       =       1       1       1       1       1       1       ^
        ↑
        q7

Tape number : 105

Results below
-------------
Number of tapes produced: 105
Time elapsed: 0.18830537796020508

'''