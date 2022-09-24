# N-Queens Genetic Algorithm (C++)
N-Queens Genetic Algorithm (C++)

## Steps:
1) Initialize a population of size `pop_size` of random `N`x`N` boards.
- Each board is represented by a 1D `vector<int>` that represents the row (i-coordinate) of the queens.

2) Selection
- Select the top `sel_size` boards based on a fitness function (count no. of pairs of non-attacking queens).
- With a small probability `weak_prob` of randomly select a weak offspring.

3) Cross over
- From the selected boards, perform "cross over" by randomly selecting a pair of boards and a cross-over location.
- For example, `[0 3 4 1 2]` and `[0 4 2 3 1]` can cross over at the index 1 to become `[0 3 2 3 1]`.

4) Mutation

- With a probability `prob`, randomly swap 2 indices on a board.
- For example, swap indices 0 and 1 on `[0 3 4 1 2]` to get `[3 0 4 1 2]`.

Repeat steps 2,3,4 until a solution is found.

## Results:

## N=8
```
Solution found:
[4 6 3 0 2 7 5 1 ]
. . . Q . . . . 
. . . . . . . Q 
. . . . Q . . . 
. . Q . . . . . 
Q . . . . . . . 
. . . . . . Q . 
. Q . . . . . . 
. . . . . Q . . 
Generation 4: f_curr=28
Time elapsed (seconds): 0.23661
```

## N=20
```
Solution found:
[11 8 15 17 9 1 4 0 7 12 14 3 18 13 2 10 6 19 5 16 ]
. . . . . . . Q . . . . . . . . . . . . 
. . . . . Q . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . Q . . . . . 
. . . . . . . . . . . Q . . . . . . . . 
. . . . . . Q . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . Q . 
. . . . . . . . . . . . . . . . Q . . . 
. . . . . . . . Q . . . . . . . . . . . 
. Q . . . . . . . . . . . . . . . . . . 
. . . . Q . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . Q . . . . 
Q . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . Q . . . . . . . . . . 
. . . . . . . . . . . . . Q . . . . . . 
. . . . . . . . . . Q . . . . . . . . . 
. . Q . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . Q 
. . . Q . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . Q . . . . . . . 
. . . . . . . . . . . . . . . . . Q . . 
Generation 25: f_curr=190
Time elapsed (seconds): 6.24627
```

## N=30
```
Solution found:
[27 12 6 13 10 14 22 4 15 11 23 7 20 28 26 29 19 0 16 5 25 21 3 8 2 24 17 9 18 1 ]
. . . . . . . . . . . . . . . . . Q . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . Q 
. . . . . . . . . . . . . . . . . . . . . . . . Q . . . . . 
. . . . . . . . . . . . . . . . . . . . . . Q . . . . . . . 
. . . . . . . Q . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . Q . . . . . . . . . . 
. . Q . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . Q . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . Q . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . Q . . 
. . . . Q . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . Q . . . . . . . . . . . . . . . . . . . . 
. Q . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . Q . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . Q . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . Q . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . Q . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . Q . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . Q . 
. . . . . . . . . . . . . . . . Q . . . . . . . . . . . . . 
. . . . . . . . . . . . Q . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . Q . . . . . . . . 
. . . . . . Q . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . Q . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . Q . . . . 
. . . . . . . . . . . . . . . . . . . . Q . . . . . . . . . 
. . . . . . . . . . . . . . Q . . . . . . . . . . . . . . . 
Q . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . Q . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . Q . . . . . . . . . . . . . . 
Generation 28: f_curr=435
Time elapsed (seconds): 14.0781
```
