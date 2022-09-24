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
