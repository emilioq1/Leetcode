/* With this attempt, I used everything at my disposal. (internet, ai, leetcode solutions) */

/* I used Manacher's Algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max(A, B) ((A) > (B) ? (A) : (B))
#define min(A, B) ((A) < (B) ? (A) : (B))

#define MAX_LENGTH 1000

char* strrangecpy(char* dest, char* src, size_t start, size_t end) {
    size_t s_len = strnlen(src, MAX_LENGTH + 1);

    if(start < 0 || start > s_len) return NULL;
    if(end < 0 || end > s_len) return NULL;
    if(start > end) return NULL;

    size_t j = 0;
    for(size_t i = start; i < end + 1; ++i, ++j) {
        dest[j] = src[i];
    }

    dest[j] = '\0';

    return dest;
    
}

char* createManacherString(char* s) {
    size_t s_len = strnlen(s, MAX_LENGTH + 1);

    char* manacher = calloc((s_len * 2) + 3, sizeof(char));
    manacher[0] = '@';

    int j = 0; 
    int i = 1;
    for(; s[j] != '\0'; ++i) {
        if(i % 2 != 0) {
            manacher[i] = '#';
        } 
        else {
            manacher[i] = s[j];
            ++j;
        }
    }
    manacher[i++] = '#';
    manacher[i++] = '$';
    manacher[i] = '\0';

    return manacher;
}

int getLongest(int* p, int cen, int odd) {
    // map original index to transformed string index
    int pos = 2 * cen + 2 + !odd;

    //printf("getLongest: %d\n", p[pos]);

    return p[pos];
}


char* longestPalindrome(char* s) {
    size_t len = strnlen(s, MAX_LENGTH + 1);

    char* manacher = createManacherString(s);
    size_t ms_len = strnlen(manacher, MAX_LENGTH+1);
    int l = 0, r = 0;

    int* p = calloc(MAX_LENGTH + 1, sizeof(int));

    for(int i = 1; i < ms_len - 1; ++i) {
        // mirror of i around center (l + r) /2
        int mirror = l + r - i;

        // initialize p[i] based on its mirror if within bounds
        if(i < r) {
            p[i] = min(r - i, p[mirror]);
        }

        // expand palindrome centered at i
        while(manacher[i + 1 + p[i]] == manacher[i - 1 - p[i]]) {
            ++p[i];
        }

        // update [l, r] if the palindrome expands beyond current r
        if(i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    printf("manacher: %s\n", manacher);
    for(int i = 0; i < ms_len; ++i) {
        //printf("manacher[%d]: %c\n", i, manacher[i]);
        printf("p[%d]: %d\n", i, p[i]);
    }

    // maximum length found so far
    int maxLen = 1;

    // starting index of longest palindrome
    int bestStart = 0;

    for(int i = 0; i < len; i++) {
        // check for odd-length palindrome centered at i
        int oddLen = getLongest(p, i, 1);
        if(oddLen > maxLen) {
            maxLen = oddLen;
            bestStart = i - maxLen / 2;
        }

        // check for even-length palindrome centered
        // between i and i+1
        int evenLen = getLongest(p, i, 0);
        if(evenLen > maxLen) {
            maxLen = evenLen;
            bestStart = i - maxLen / 2 + 1;
        }
    }

    free(p);
    free(manacher);

    char* result = calloc(MAX_LENGTH + 1, sizeof(char));
    strrangecpy(result, s, bestStart, maxLen);

    return result;
}

#define TEST_CASES 7

int main() {
    char test[TEST_CASES][MAX_LENGTH+1] = {{"babad"}, {"cbbd"}, {"a"}, {"aaaa"}, {"ac"}, {"abbcccba"}, {"321012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210123210012321001232100123210123"}};

    int i = 0;
    for(i = 0; i < 6; ++i) {
        char* result = longestPalindrome(test[i]);
        printf("%d: %s\n", i, result);

        if(result != NULL) free(result);
    }


    return 0;
}


