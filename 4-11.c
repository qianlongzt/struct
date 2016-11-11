#include <stdio.h>
#include <string.h>

int main() {
    char c_s[256] = {0},s_r[256] = {}, c_t[256] = {0};
    char s[] = "asdfghkfllzxcbb resyre !@!            @#$%^&*()cvmewqtrtwruyetoryp";
    char t[] = "zcxnvm";
    char r[1000] = {0};

    int i = 0, j = 0;

    for(i = 0; i <strlen(t); i++) {
        c_t[t[i]]  = 1;
    }
    for(i = 0,j = 0; i <strlen(s); i++) {
        if(0 == c_t[s[i]] && s_r[s[i]] == 0) {
            printf("%c---->%d\n", s[i], i + 1);
            s_r[s[i]] = 1;
            r[j] =  s[i];
            j++;
        }
    }
    printf("\n");
    printf("%s\n", r);

    return 0;
}
