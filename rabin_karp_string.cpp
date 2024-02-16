Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. 
Assume that n > m.

Examples:

Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
        Enter the prime number = 5
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12

#include<stdio.h>
#include<string.h>
#define d 256

void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d \n", i);
        }
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    char txt[100], pat[100];
    int q;

    printf("Enter the text: ");
    scanf("%[^\n]%*c", txt);

    printf("Enter the pattern: ");
    scanf("%s", pat);

    printf("Enter the prime number: ");
    scanf("%d", &q);

    search(pat, txt, q);

    return 0;
}




Input:  txt[] = "acfsskgyh"
        pat[] = "skg"
        Enter the prime number = 5
Output: Pattern found at index 4
