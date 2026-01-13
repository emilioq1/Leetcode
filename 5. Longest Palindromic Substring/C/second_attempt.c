/* With this attempt, I used everything at my disposal. (internet, ai, leetcode solutions) */

/* I used Manacher's Algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(A, B) ((A) > (B) ? (A) : (B))
#define min(A, B) ((A) < (B) ? (A) : (B))

#define MAX_LENGTH 1000


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

    int* p = calloc(ms_len + 1, sizeof(int));
    int longest_index = 0;

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

        if(p[i] > p[longest_index]) {
            longest_index = i;
        }
    }

    int start = (longest_index - p[longest_index]) / 2;
    int length = p[longest_index];

    //printf("manacher: %s\n", manacher);
    //printf("manacher: ");
    //for(int i = 0; i < ms_len; ++i) {
    //    printf("%d", i);
    //}
    //printf("\n");

    //for(int i = 0; i < ms_len; ++i) {
    //    //printf("manacher[%d]: %c\n", i, manacher[i]);
    //    printf("p[%d]: %d\n", i, p[i]);
    //}
    //printf("longest_index: %d\n", longest_index);
    //printf("p[longest_index]: %d\n", p[longest_index]);

    free(p);
    free(manacher);

    char* result = calloc(MAX_LENGTH + 1, sizeof(char));
    //strrangecpy(result, s, bestStart, maxLen);
    strncpy(result, s+start, length);

    return result;
}

#define TEST_CASES 7

int main() {
    char test[TEST_CASES][MAX_LENGTH+1] = {{"babad"}, {"cbbd"}, {"a"}, {"aaaa"}, {"ac"}, {"abbcccba"}, {"321012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210123210012321001232100123210123"}};

    int i = 0;
    for(i = 0; i < TEST_CASES; ++i) {
        printf("raw: %d: %s\n", i, test[i]);
        char* result = longestPalindrome(test[i]);
        printf("result: %d: %s\n", i, result);

        if(result != NULL) free(result);
    }


    return 0;
}


