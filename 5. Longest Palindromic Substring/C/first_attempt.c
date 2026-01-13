#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char* longestPalindrome(char* s) {
    size_t s_len = strnlen(s, MAX_LENGTH + 1);

    int start = 0;
    int end = 0;
    int result_len = 0;

    for(int i = 0; i < s_len; ++i) {
        for(int j = i + 1; j < s_len; ++j) {
            if(s[i] == s[j]) {
                int temp_len = j - i + 1;
                int palindrome = 0;

                for(int k = i, l = j; k < s_len && l >= 0; ++k, --l) {
                    if(s[k] != s[l]) {
                        break;
                    }
                    if(k > l || k == l) { 
                        palindrome = 1;
                        break;
                    }
                }

                if(palindrome == 1 && temp_len > result_len) {
                    start = i;
                    end = j;
                    result_len = temp_len;
                }
            }
            
            if(s[j] == '\0') {
                break;
            }
        }

        if(s[i] == '\0') break;
    }
    
    char* result = calloc(s_len + 1, sizeof(char));

    if(s_len <= 1) {
        result[0] = s[0];
    }
    else {
        result = strrangecpy(result, s, start, end);
    }


    return result;
}

#define TEST_CASES 7

int main() {
    char test[TEST_CASES][MAX_LENGTH+1] = {{"babad"}, {"cbbd"}, {"a"}, {"aaaa"}, {"ac"}, {"abbcccba"}, {"321012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210123210012321001232100123210123"}};

    int i = 0;
    for(i = 0; i < TEST_CASES; ++i) {
        char* result = longestPalindrome(test[i]);
        printf("%d: %s\n", i, result);

        if(result != NULL) free(result);
    }


    return 0;
}


