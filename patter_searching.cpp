// Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. 
// Assume n > m.
#include <iostream>
#include <cstring>
using namespace std;

void search(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    
    for (int i = 0; i <= N - M; i++) {
        int j;

        
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) 
            
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    char txt[100], pat[100];

    cout << "Enter the text: ";
    cin.getline(txt, 100);

    cout << "Enter the pattern: ";
    cin.getline(pat, 100);

    search(pat, txt);
    return 0;
}


// Examples:

// Input:  txt[] = "THIS IS A TEST TEXT"
//         pat[] = "TEST"
// Output: Pattern found at index 10

// Input:  txt[] =  "AABAACAADAABAABA"
//         pat[] =  "AABA"
// Output: Pattern found at index 0
//         Pattern found at index 9
//         Pattern found at index 12
