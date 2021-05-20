// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

/*
*  Let n be some integer and randn generates uniformly from [1..n]:
*  (randn() - 1) * n + randn() generates uniformly from [1..n * n]
*  1,     2,     ..., n
*  n + 1, n + 2, ..., 2n
*  .........
*  (n - 1)n + 1, ..., n * n
*/

class Solution {
public:
    int rand10() {
        while (1) {
            int res = (rand7() - 1) * 7 + rand7(); // [1..49]
            if (res > 40) continue; // reject if [41..49]
            return 1 + (res - 1) % 10;
        }
    }
};