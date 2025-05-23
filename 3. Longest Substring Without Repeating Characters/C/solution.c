#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50000

int lengthOfLongestSubstring(char* s) {
    if(s == NULL) { 
        return -1;  // when s is NULL
    }
    int s_len = strnlen(s, MAX_STR_LEN);
    
    //printf("string length: %d\n\n", s_len);

    if(s_len < 0 || s_len > 50000) {
        return -2;  // when s length is too small or big
    }

    char best_str[50000] = {0};
    char temp_str[50000] = {0};
    
    //int best_str_index = 0;
    int temp_str_index = 0;
    int starting_index = 0;

    int temp_str_len = 0;
    int best_str_len = 0;
    
    if(s_len == 1) {
        return 1;
    }

    for(int i = 0; i < s_len; ++i) {
        printf("current best: %s\n", best_str);
        printf("temp: %s\n", temp_str);
        temp_str_len = strnlen(temp_str, MAX_STR_LEN);
        best_str_len = strnlen(best_str, MAX_STR_LEN);
        for(int j = 0; j < temp_str_len; ++j) {
            //printf("comparing: \n");
            //printf("temp_str[%d] = %c\n", j, temp_str[j]);
            //printf("s[%d] = %c\n\n", i, s[i]);

            if(temp_str[j] == s[i] || s[i] == '\0') {
                //printf("temp_str length: %d\n", temp_str_len);
                //printf("best_str length: %d\n", best_str_len);

                if(temp_str_len > best_str_len) {
                    strncpy(best_str, temp_str, MAX_STR_LEN);
                }
                memset(temp_str, 0, sizeof(temp_str));
                temp_str_index = 0;
                i = starting_index;
                ++starting_index;
                break;
            }

        }
        temp_str[temp_str_index] = s[i];

        ++temp_str_index;
    }

    // if(strnlen(best_str, MAX_STR_LEN) == 0 || strnlen(temp_str, MAX_STR_LEN) > strnlen(best_str, MAX_STR_LEN)) {
    if(best_str_len == 0 || temp_str > best_str) {
        strncpy(best_str, temp_str, MAX_STR_LEN);
    }
    
    printf("final temp_str: %s\n", temp_str);
    printf("final best_str: %s\n", best_str);

    return strnlen(best_str, MAX_STR_LEN);
}


int main(void) {
    //char* test_str = "abcabcbb";
    char* test_str = "dvdf";
    int result = lengthOfLongestSubstring(test_str);

    printf("test_str: \"%s\"\n", test_str);
    printf("result: %d\n", result);


    return 0;
}
