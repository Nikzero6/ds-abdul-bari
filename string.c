#include <stdio.h>
#include <malloc.h>

int length(char s[])
{
    int i = 0;

    for (i = 0; s[i] != '\0'; i++)
        ;

    return i;
}

void toggleCase(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] += 32;
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] -= 32;
        }
    }
}

int *vowels(char *s)
{

    char vowel[] = "aeiouAEIOU";
    int vowel_count = 0;
    int const_count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {

        int flag = 0;

        for (int j = 0; vowel[j] != '\0'; j++)
        {
            if (s[i] == vowel[j])
            {
                vowel_count++;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            const_count++;
        }
    }

    int *arr = (int *)malloc(2 * sizeof(int));

    arr[0] = vowel_count;
    arr[1] = const_count;

    return arr;
}

int count_words(char *s)
{

    int word = 1;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' && s[i - 1] != ' ')
            word++;
    }

    return word;
}

void reverse(char *s)
{

    int j = length(s) - 1;

    for (int i = 0; i < j; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int compare(char *s1, char *s2)
{
    int i = 0;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
    }

    if (s1[i] == '\0' && s2[i] == '\0')
        return 0;
    else if (s1[i] == '\0')
        return -1;
    else
        return 1;
}

void pallindrome(char *s)
{

    int j = length(s) - 1;
    int flag = 0;
    for (int i = 0; i < j; i++, j--)
    {
        if ((s[i] != s[j]) && (s[i] != (s[j] + 32)) && (s[i] != (s[j] - 32)))
        {
            printf("Not a pallinfrome.");
            flag = 1;
            break;
        }
    }
    if (!flag)
        printf("Pallindrome");
}

void duplicate_hash(char *s)
{

    int H[123] = {0};

    for (int i = 0; s[i] != '\0'; i++)
    {

        if (s[i] >= 65 && s[i] <= 90 && H[s[i]] == 0)
        {
            H[s[i] + 32]++;
        }
        else if (H[s[i]] == 0)
            H[s[i]]++;
        else
            printf("%c", s[i]);
    }
}

void duplicate_bits(char *s)
{

    long long int H = 0, x = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            x = 1;
            x <<= s[i] - 48;

            if (H & x)
            {
                printf("%c", s[i]);
            }
            else
            {
                H |= x;
            }
        }
        else if (s[i] >= 65 && s[i] <= 90)
        {
            x = 1;
            x <<= s[i] - 55;

            if (H & x)
            {
                printf("%c", s[i]);
            }
            else
            {
                H |= x;
            }
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            x = 1;
            x <<= s[i] - 87;

            if (H & x)
            {
                printf("%c", s[i]);
            }
            else
            {
                H |= x;
            }
        }
    }
}

void anagram(char *s1, char *s2)
{

    int H[123] = {0};

    for (int i = 0; s1[i] != '\0'; i++)
    {
        H[s1[i]]++;
    }
    for (int i = 0; s2[i] != '\0'; i++)
    {
        H[s2[i]]--;
        if (H[s2[i]] < 0)
            printf("Not an Anagram");
    }
    int flag = 0;
    for (int i = 0; i < 123; i++)
    {
        if (H[i] > 0)
        {
            printf("Not an Anagram");
            flag = 1;
            break;
        }
    }

    if (!flag)
        printf("Anagram");
}

void perm_recursive(char *s, int k)
{

    static int A[10] = {0};
    static char res[10];

    if (s[k] == '\0')
    {
        res[k] = '\0';
        printf("%s\n", res);
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (A[i] == 0)
        {
            A[i]++;
            res[k] = s[i];
            perm_recursive(s, k + 1);
            A[i] = 0;
        }
    }
}

void swap(char *s, int l, int i)
{
    char temp = s[l];
    s[l] = s[i];
    s[i] = temp;
}

void perm_swap(char *s, int l, int h)
{

    if (l == h)
        printf("%s\n", s);

    for (int i = l; i <= h; i++)
    {
        swap(s, l, i);
        perm_swap(s, l + 1, h);
        swap(s, l, i);
    }
}

int main()
{

    char name[] = "Nikhil";

    //length
    // printf("%d", length(name));

    //toggle case
    // toggleCase(name);
    // printf("%s", name);

    //vowel + const count
    // printf("vowels: %d and consonants: %d", vowels(name)[0], vowels(name)[1]);

    char sentence[] = "Hello I am Nikhil.";

    //no. of words
    // printf("%d", count_words(sentence));

    //reverse
    // reverse(name);
    // printf("%s", name);

    //compare
    // char first[] = "painting";
    // char second[] = "painter";

    // printf("%d", compare(first, second));

    //pallindrome
    // char s[] = "Nitin";
    // pallindrome(s);

    //duplicates
    //using hashtable
    // char ff[] = "Nitin6689";
    // duplicate_hash(ff);

    //using bits
    // char ff[] = "Nitin6689";
    // duplicate_bits(ff);

    //Anagram
    // char ff[] = "medicaal";
    // char ss[] = "decimal";
    // anagram(ff, ss);

    //permutations
    char A[] = "ABC";
    // perm_recursive(A, 0);
    perm_swap(A, 0, 2);
    return 0;
}