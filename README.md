##  Intuition

This problem follows **Dynamic Programming (Form 2: Ending at index i)**.

At every index `i`, the wiggle subsequence can end in two possible states:

- `dir = 1` → Last difference was **positive (UP)**
- `dir = 0` → Last difference was **negative (DOWN)**

So for each index, we calculate:

- Longest wiggle subsequence ending at `i` with last move UP
- Longest wiggle subsequence ending at `i` with last move DOWN

---

## Approach

We define a recursive function:

rec(i, dir)


It returns the maximum wiggle subsequence length **ending at index `i`** with direction `dir`.

### Case 1: dir = 1 (UP)

If the last move is upward:

nums[j] < nums[i]


Then:

rec(i, 1) = max(rec(j, 0) + 1)


Because before an UP move, the sequence must have been DOWN.

---

### Case 2: dir = 0 (DOWN)

If the last move is downward:

nums[j] > nums[i]


Then:

rec(i, 0) = max(rec(j, 1) + 1)


Because before a DOWN move, the sequence must have been UP.

---

### Base Case

Every element alone is a valid wiggle subsequence of length `1`.

---

##  Complexity Analysis

### Time Complexity

For each index `i`, we check all `j < i`.

O(n²)


---

### Space Complexity

We use a DP table:

dp[n][2]


So space complexity is:

O(n)
