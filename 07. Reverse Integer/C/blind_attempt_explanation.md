# Intuition
I thought to convert the int into a string, reverse it and then converted it back to an integer.

# Approach
I needed a way to convert an integer into a string. I found snprintf in the C standard library, which works similarly to printf, but I can direct the output to a variable instead of stdout. The function also returns the number of characters it printed, which is the string length of the integer.

I check if the integer is negative by checking the character in index 0, and define the maximum 32-bit integer as a string. I use the lower limit if the integer is negative and the upper limit if the integer is positive. I also check if the integer string’s length is the maximum character length a 32-bit integer can be, which is 10 characters.

I reverse the buffer into a new string called reverse. If the reverse string is 10 characters long, I compare each reverse string character with the corresponding character in the maximum 32-bit integer string.

If in any comparison, the reverse character is bigger than the max string character, you return 0, as the given integer parameter x is beyond the limits of a 32-bit integer.

If in any comparison, the reverse character is smaller than the corresponding max string character, we are sure that x is within the limits, so we prevent the if block from being run again and finish reversing the string.

Once we reverse the string completely, we convert the string back into an integer. I used strtol from the C standard library to convert the string back into an integer.

# Complexity
- Time complexity: $$O(n)$$
- Space complexity: $$O(n)$$

# Code
```c []
#define MAX_LENGTH 11

int reverse(int x) {
    char buffer[MAX_LENGTH + 1] = {0};

    int8_t len = snprintf(buffer, MAX_LENGTH + 1, "%d", x);
    buffer[len] = '\0';

    char reverse[MAX_LENGTH + 1] = {0};
    int8_t start = 0;

    if (buffer[0] == '-') {
        reverse[start++] = '-';
    }

    char* maxIntString = "2147483647";
    if (start == 1) {
        maxIntString = "2147483648";
    }
    int isMaxLength = (len - start) >= (MAX_LENGTH - 1);

    for (int8_t j = len, k = start; j >= start; --j) {
        if (buffer[j] != 0) {
            reverse[k] = buffer[j];
            if (isMaxLength) {
                if (reverse[k] < maxIntString[k - start]) {
                    isMaxLength = 0;
                } else if (reverse[k] > maxIntString[k - start]) {
                    return 0;
                }
            }

            ++k;
        }
    }
    reverse[len] = '\0';

    int32_t result = strtol(reverse, NULL, 10);

    return result;
}
```
