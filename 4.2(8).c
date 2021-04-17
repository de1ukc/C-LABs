#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int N = 128;
int Strlen(char *s) {
    int pos = 0;
    while(s[pos] != '\0') pos++;
    return pos;
}
void Out() {
    printf("%s", "Incorrect");
    exit(0);
}
void main(void)
{
    FILE *fp;
    fp = fopen("File.txt", "r");
    if (!fp) exit(1);
    char stak[2 * N];
    int uk = 0;
    while (1){
        char *buffer = malloc(sizeof(char) * N);
        if(fgets(buffer, N, fp) == NULL) break;
        for(int i = 0; i < Strlen(buffer); i++) {
            if(buffer[i] == '(' || buffer[i] == '[' || buffer[i] == '{') {
                stak[++uk] = buffer[i];
            }
            if(buffer[i] == ')') {
                if(uk == 0 || stak[uk] != '(') Out();
                uk--;
            }
            if(buffer[i] == ']') {
                if(uk == 0 || stak[uk] != '[') Out();
                uk--;
            }
            if(buffer[i] == '}') {
                if(uk == 0 || stak[uk] != '{') Out();
                uk--;            }
        }
        free(buffer);
    }
    if(uk) Out();
    printf("%s", "Correct");
    fclose(fp);
}
