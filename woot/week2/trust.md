# Problem 2-2: Trust Circles:
Consider a social network graph of `N` people (`1 <= N <= 10^5`), numbered `1` through `N.` The graph has `M` directed edges (`N <= M <= 2 * 10^5`), each of which goes from one person to another. It is guaranteed that at each person is the origin of at least one directed edge.

We say that a person `A` trusts another person `B` if there is a directed edge from `A` to `B` in the network, or if there is a directed edge from `A` to some other person `P_1` and a directed edge from `P_1` to `B,` and so on.

A trust circle is a group (of at least one person) such that every person in the group trusts every other person. A maximal trust circle is a trust circle that is not part of any larger trust circle. Notice that it is possible for a trust circle to consist of just one person -- since there is no "every other person" to worry about in that case, the definition trivially holds.

Determine the total number of maximal trust circles in the network.

## INPUT FORMAT (input arrives from the terminal / stdin):

The first line contains `N` and `M`.

Each of the next `M` lines is of the form `A_i`, `B_i`, indicating that there is a directed edge from person `A_i` to person `B_i`. No line is repeated.

## OUTPUT FORMAT (print output to the terminal / stdout):

Print the total number of trust circles in the network.

## SAMPLE INPUT:
```
3 3
3 1
2 1
1 2
```
## SAMPLE OUTPUT:
```
2
```
## SCORING:

In test cases 2-6, each person has exactly one outgoing directed edge.
Test cases 5-9 satisfy `N <= 10^4`.
Test cases 10-20 satisfy no additional constraints.
