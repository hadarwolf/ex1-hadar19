#include "cipher.h"
#define TWO_SIX 26
/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.


// See full documentation in header file
void cipher (char s[], int k) {
//    int length_s1 = (sizeof(s) / sizeof(s[0])) - 1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        //// Check if the character is an alphabet letter
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
//// Determine whether to wrap around for lowercase or uppercase letters
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = (char)('a' + (s[i] - 'a' + k) % TWO_SIX);
            } else {
                s[i] = (char)('A' + (s[i] - 'A' + k) % TWO_SIX);
            }
        }
    }
}

// See full documentation in header file
void decipher (char s[], int k) {

//    int length_s2 = (sizeof(s) / sizeof(s[0])) - 1;
    for (int i = 0; s[i] != '\0'; i++)
    {
        //// Check if the character is an alphabet letter
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
//// Determine whether to wrap around for lowercase or uppercase letters
            if (s[i] >= 'a' && s[i] <= 'z') {
                int new_k = (s[i] - 'a' - k) % TWO_SIX;
                if (new_k < 0) { s[i] = (char) ('z' + new_k+1); }
                s[i] = (char)('a' + (s[i] - 'a' - k +TWO_SIX) % TWO_SIX);
            } else {
                int new_k = (s[i] - 'A' - k) % TWO_SIX;
                if (new_k < 0) { s[i] = (char) ('Z' + new_k+1); }
                else {
                    s[i] = (char) ('A' + (s[i] - 'A' - k + TWO_SIX) % TWO_SIX);
                }
            }
        }
    }
}
