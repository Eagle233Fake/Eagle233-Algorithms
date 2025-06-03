#include <bits/stdc++.h>

using namespace std;

//********** Specification of replace **********
void replace(char s[], char x[], char y[]);
/* Precondition: s, x and y are three strings, 
                and s has enough memory to store modified string 
   Postcondition: replace all substring x with y in string s
*/

void replace(char ss[], char xx[], char yy[]) { //TODO: your function definition
    string s = ss;
    string x = xx;
    string y = yy;
    string a = "";

    int j = 0;
    while (j < s.size()) {
        if (s.substr(j, x.size()) == x) {
            a += y;
            j += x.size();
        } else {
            a += s[j];
            j++;
        }
    }

    strcpy(ss, a.c_str());
}

#define N 80

int main() {
    char s[3 * N + 1], x[N + 1], y[N + 1];
    scanf("%s%s%s", s, x, y);
    replace(s, x, y);
    printf("%s\n", s);
    return 0;
}