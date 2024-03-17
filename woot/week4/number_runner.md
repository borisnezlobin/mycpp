# Problem 4-1: Number Runner:
Bessie is playing a video game with the following rules.

The player must move through a list of `N` integer values `(1 <= N <= 10^5)`, in order, encountering each of them once. Each value is positive or negative, and has magnitude in the range `[1, 10^9]`.

The player starts off with `0` points, and in "John mode". Up to `K` times during the game `(1 <= K <= 1000)`, the player can switch modes: if they are in John mode, they go into "Nhoj mode", and vice versa. (It is possible that the player may never switch.)

When the player is in John mode, all values encountered are added to the score. This means positive values help, and negative values hurt.

When the player is in Nhoj mode, all values encountered are subtracted from the score. This means negative values help, and positive values hurt.

It is allowable for a player's score to be negative at one or more point(s) during the game.

Determine the maximum score that the player can obtain.

### INPUT FORMAT (input arrives from the terminal / stdin):

The first line contains `N` and `K`.
The second line contains the `N` integer values used in the game.

### OUTPUT FORMAT (print output to the terminal / stdout):

Print one line with the maximum score the player can obtain.

## SAMPLE INPUT:

```
7 1
3 -1 -4 1 5 -9 -2
```


## SAMPLE OUTPUT:
```
15
```

## SCORING:

Test cases 2-4 satisfy `N <= 1000`.
Test cases 7 and 10-14 satisfy `N <= 10000`.
Test cases 2-7 satisfy `K = 1`.
Test cases 2-10 satisfy `K <= 10`.
Test cases 15-20 satisfy no additional constraints.

# Solution Approach
Store a one-dimensional array of numbers with length `K`, initialized to negative infinity -- call it `arr`. One-by-one, go through the numbers. At every number, we want to see if we can "bump" the score in every entry in the array. For the input of `-10 -20 30 -40 50`, `K = 3`:

When considering `-10`:
| `arr` | `new_arr` |
| ----- | --------- |
| 0(+)  | -10(+)    |
| -     | 10(-)     |
| -     | -         |
| -     | -         |


When considering `-20`:
| `arr`  | `new_arr` |
| :----- | --------- |
| -10(+) | -30(+)    |
| 10(-)  | 30(-)     |
| -      | -10(+)    |
| -      | -         |

When considering `30`:
| `arr`  | `new_arr` |
| :----- | --------- |
| -30(+) | 0(+)      |
| 30(-)  | 0(-)      |
| -10(+) | 60(+)     |
| -      | -40(-)    |

When considering `-40`:
| `arr`  | `new_arr` |
| :----- | --------- |
| 0(+)   | -40(+)    |
| 0(-)   | 40(+/-)   |
| 60(+)  | 20(+)     |
| -40(-) | 0(-)      |

When considering `50`:
| `arr`   | `new_arr` |
| :------ | --------- |
| -40(+)  | 10(+)     |
| 40(+/-) | 10(+)     |
| 20(+)   | 70(+)     |
| 0(-)    | -30(-)    |
