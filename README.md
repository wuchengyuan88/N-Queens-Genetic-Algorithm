# N-Queens Genetic Algorithm (C++)
N-Queens Genetic Algorithm (C++)

## Steps:
1) Initialize a population of size `pop_size` of random `N`x`N` boards.
- Each board is represented by a 1D `vector<int>` that represents the row (i-coordinate) of the queens.

2) Selection
- Select the top `sel_size` boards based on a fitness function (count no. of pairs of non-attacking queens).
- With a small probability `weak_prob` of randomly selecting a weak offspring.

3) Crossover
- From the selected boards, perform "crossover" by randomly selecting a pair of boards and a crossover location.
- For example, `[0 3 4 1 2]` and `[0 4 2 3 1]` can crossover at the index 1 to become `[0 3 2 3 1]`.

4) Mutation

- With a probability `prob`, randomly swap 2 indices on a board.
- For example, swap indices 0 and 1 for `[0 3 4 1 2]` to get `[3 0 4 1 2]`.

Repeat steps 2,3,4 until a solution is found.

## Results:

## N=8
```
Solution found:
[4 0 7 5 2 6 1 3 ]
. Q . . . . . . 
. . . . . . Q . 
. . . . Q . . . 
. . . . . . . Q 
Q . . . . . . . 
. . . Q . . . . 
. . . . . Q . . 
. . Q . . . . . 
Generation 3: f_curr=28
Time elapsed (seconds): 0.154735
```

## N=20
```
Solution found:
[19 6 9 18 4 8 16 11 1 15 2 5 3 10 0 13 17 12 14 7 ]
. . . . . . . . . . . . . . Q . . . . . 
. . . . . . . . Q . . . . . . . . . . . 
. . . . . . . . . . Q . . . . . . . . . 
. . . . . . . . . . . . Q . . . . . . . 
. . . . Q . . . . . . . . . . . . . . . 
. . . . . . . . . . . Q . . . . . . . . 
. Q . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . Q 
. . . . . Q . . . . . . . . . . . . . . 
. . Q . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . Q . . . . . . 
. . . . . . . Q . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . Q . . 
. . . . . . . . . . . . . . . Q . . . . 
. . . . . . . . . . . . . . . . . . Q . 
. . . . . . . . . Q . . . . . . . . . . 
. . . . . . Q . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . Q . . . 
. . . Q . . . . . . . . . . . . . . . . 
Q . . . . . . . . . . . . . . . . . . . 
Generation 18: f_curr=190
Time elapsed (seconds): 4.25697
```

## N=30
```
Solution found:
[20 8 15 2 21 7 25 28 16 6 0 12 27 9 23 29 5 17 1 11 26 24 4 10 18 13 3 22 19 14 ]
. . . . . . . . . . Q . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . Q . . . . . . . . . . . 
. . . Q . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . Q . . . 
. . . . . . . . . . . . . . . . . . . . . . Q . . . . . . . 
. . . . . . . . . . . . . . . . Q . . . . . . . . . . . . . 
. . . . . . . . . Q . . . . . . . . . . . . . . . . . . . . 
. . . . . Q . . . . . . . . . . . . . . . . . . . . . . . . 
. Q . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . Q . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . Q . . . . . . 
. . . . . . . . . . . . . . . . . . . Q . . . . . . . . . . 
. . . . . . . . . . . Q . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . Q . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . Q 
. . Q . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . Q . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . Q . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . Q . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . Q . 
Q . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . Q . . . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . Q . . 
. . . . . . . . . . . . . . Q . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . . Q . . . . . . . . 
. . . . . . Q . . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . . . . . . Q . . . . . . . . . 
. . . . . . . . . . . . Q . . . . . . . . . . . . . . . . . 
. . . . . . . Q . . . . . . . . . . . . . . . . . . . . . . 
. . . . . . . . . . . . . . . Q . . . . . . . . . . . . . . 
Generation 34: f_curr=435
Time elapsed (seconds): 16.0362
```

## N=40
```
Solution found:
[25 38 18 21 23 14 30 15 6 8 0 5 34 10 28 11 16 1 22 2 31 33 7 29 37 32 17 4 9 39 3 13 35 20 36 27 24 26 12 19 ]
Generation 54: f_curr=780
Time elapsed (seconds): 46.4668
```

## N=50
```
Solution found:
[46 28 12 22 17 25 44 11 15 27 9 5 8 36 47 23 21 45 4 35 31 13 37 32 49 3 19 39 7 18 2 48 16 10 34 6 38 40 33 26 30 1 43 41 0 42 14 20 24 29 ]
Generation 58: f_curr=1225
Time elapsed (seconds): 80.6354
```
