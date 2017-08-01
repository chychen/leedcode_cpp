// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Returns: True
// Example 2:

// Input: 14
// Returns: False


bool isPerfectSquare(int num) {
    long long l = 0, r = num;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        long long sqmid = mid * mid;
        if (sqmid > num) r = mid - 1;
        else if (sqmid < num) l = mid + 1;
        else return true;
    }
    return false;
}