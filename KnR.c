//? Write a program to count chars in i/p.
// #include <stdio.h>

// main() {
//     double nc;
//     for (nc = 0; getchar() != EOF; ++nc)
//         ;
//     printf("%.0f\n", nc);
// }

//* unix ctrl d and windows ctrl z(^Z) for EOF here. otherwise wont work properly. means, word(enter)^Z(enter) the you get the answer

//? Exercise 1-8. Write a program to count blanks, tabs, and newlines.
// #include <stdio.h>

// int main() {
//     int nl = 0, ns = 0, nt = 0, c;

//     c = getchar();
//     while (c != EOF) {
//         if (c == '\n') nl++;
//         else if (c == ' ') ns++;
//         else if (c == '\t') nt++;
//         c = getchar();
//     }

//     printf("\\n = %d, \\t = %d, \" \" = %d", nl, nt, ns);
//     // printf("%c", 65);

//     return 0;
// }

//? Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

// # include <stdio.h>

// int main() {
//     int c, prevChar = 0; //init prevChar with any value 

//     while ((c = getchar()) != EOF) {
//         if (!(prevChar == ' ' && c == ' ')) {
//             putchar(c);
//         }
//         prevChar = c;
//     }

//     return 0;
// }

//* if (!(prevChar == ' ' && c == ' ')) is not same as if (prevChar != ' ' && c != ' ')


# include <stdio.h>
# include <stdint.h>
# include <math.h>

//? Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
void replace_tab_backspace_backslash(int8_t c) {
    while ((c = getchar()) != EOF) {
        if (c == '\t') printf("\\t");
        else if (c == '\b') printf("\\b");
        else if (c == '\\') printf("\\");
        else putchar(c);
    }
}
//* in this the backspace thing doesnt work since in cmd (windows) when we press backspace the input is getting edited from the input buffer itself.

void word_counter(int8_t c) {
    int nw, nc, nl;
    nw = nc = nl = 0;

    while ((c = getchar()) != EOF) {
        nc++;
        if (c == ' ' || c == '\t') nw++;
        if (c == '\n') {
            nw++;
            nl++;
        }
    }
    
    printf("w = %d, l = %d, c = %d", nw, nl, nc);
}

void num_of_occ_of_num (int8_t c) {
    int arr[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            arr[c - '0']++;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d", arr[i]);
    }
}

//? Exercise 1-12. Write a program that prints its input one word per line.
void one_word_per_line (int8_t c) {
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            putchar('\n');
            continue;
        }
        putchar(c);
    }
}

//? Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
void histogram_of_words(int8_t c) {
    int arr[10], num_letter = 0;

    for (int i = 0; i < 10; i++) {
        arr[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            arr[num_letter]++;
            num_letter = 0;
        }
        else {
            num_letter++;
        }
    }

    for (int i = 1; i < 10; i++) {
        printf("%d -> %d |", i, arr[i]);
        for (int j = 0; j < arr[i]; j++) {
            printf("-");
        }
        printf("\n");
    }
}

//? Power
int power(int base, int n) {
    int p = 1;
    for (; n > 0; --n)
        p = p * base;
    return p;
}

void longest_line(int c) {
    int longest_index = 0, longest_length = 0;
    int curr_count = 0, char_count  = 0;

    char lines[100];
    int i = 0;
    while((c = getchar()) != EOF) {
        
        //0 0 0 0
        //twice is best
        //0 0 14 14
        //0 14 14 14
        //0 14 0 14
        //OT9 forever
        //0 14 12 26

        lines[i] = c; i++;

        char_count++;
        curr_count++;

        if (c == '\n') {
            printf("%d ", char_count);
            printf("%d\n", curr_count);
            if (curr_count > longest_length) {
                longest_length = curr_count;
                longest_index = char_count - curr_count;
            }
            curr_count = 0;
        }
    }

    printf("longest index = %d, longest length = %d\n", longest_index, longest_length);

    for (i = longest_index; i < longest_length; i++) {
        printf("%c", lines[i]);
    }
}

int main() {
    int8_t c;
    
    // replace_tab_backspace_backslash(c);
    // word_counter(c);
    // one_word_per_line(c);
    // num_of_occ_of_num(c);
    // histogram_of_words(c);
    
    // printf("%d", (int)pow(16, .5));
    //* here, printf("%d", pow(16, .5)); this gives 0 as output. casting it to int as shown above will fix the problem. this is because pow() returns and takes double. so when used %d for double, there will be unexpected results. casting like this would cause errors nearing INT_MAX though so maybe just use printf("%f", pow(16, .5)) [see that i have changed %d to %f].also if num is 2, we can do 1 << power to get result. i.e, 2^3 == 1 << 3. 
    // printf("%d", power(3, 2));

    // longest_line(c);
    

    return 0;
}
