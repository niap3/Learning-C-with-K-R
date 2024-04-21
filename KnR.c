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

int main() {
    int8_t c;
    
    // replace_tab_backspace_backslash(c);
    // word_counter(c);
    // one_word_per_line(c);
    num_of_occ_of_num(c);
    

    return 0;
}
