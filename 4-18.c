#include <stdio.h>
#include <string.h>

int main() {
    char c_s[256] = {0};
    char s[1000] = "asgjsadjglsdjaglas";

    int i = 0, count = 0;
    for(i = 0; i <strlen(s); i++) {
        c_s[s[i]] += 1;
    }
    for(i = 0; i < 256; i++){
        if(c_s[i] != 0) {
            count ++;
            printf("%c--->%d\n", i, c_s[i]);
        }
    }
    printf("there are %d chars\n", count);
    return 0;
}
