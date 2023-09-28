# Problem 2-1: From Everywhere To Everywhere:
## Problem
Farmer John has N farms (`2 <= N <= 750`) numbered `1` through `N`, and connected by
`M` one-directional roads (1 <= M <= 3 * 10^5). The `i`-th of these roads connects farms `Ai`
and Bi (`1 <= Ai , Bi <= N`), and takes `Ci` units of energy to use (`-10^9 <= Ci <= 10^9`).
Notice that the cost can be negative -- perhaps a road is so beautiful that traveling along
it is energizing rather than exhausting!
For any ordered pair of farms, there is at most one road directly connecting the first to
the second. It is guaranteed that each farm is reachable from each other farm via some
sequence of roads.
Bessie has gotten a bunch of her friends together. Each friend is given an ordered pair of
two different farms: a start and a goal. For any possible combination of start and goal,
exactly one friend has that combination. Each friend will take the path from their start
farm to their goal farm that minimizes the total cost of their path
(the sum of all the `Ci` values of the roads in the path).
It is guaranteed that there is no way for a cow to get an arbitrarily negative total cost.

Determine the sum of these total costs, for all cows.

### INPUT FORMAT (input arrives from the terminal / stdin):

The first line contains `N` and `M`.
Each of the next `M` lines contains `Ai`, `Bi`, and `Ci`.

### OUTPUT FORMAT (print output to the terminal / stdout):

Print one line with the sum of the total costs for all cows.

### SAMPLE INPUT:
```
4 6
1 4 3
4 2 -4
3 1 5
4 3 1
2 3 2
3 2 6
```


### SAMPLE OUTPUT:
```
36
```
## CUSTOM INPUT:
```
4 5
1 2 1
2 4 1
4 3 1
3 1 -1
4 2 1
```