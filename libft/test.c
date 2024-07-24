/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:35:16 by alramire          #+#    #+#             */
/*   Updated: 2024/05/06 12:17:50 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void test_ft_strrchr(void) {
    printf("=== Testing ft_strrchr ===\n");

    struct {
        const char *str;
        int ch;
        const char *expected;
    } testCases[] = {
        {"Hello, world!", 'w', "world!"},
        {"Hello, world!", 'H', "Hello, world!"},
        {"Repeat, repeat, repeat", 'p', "peat, repeat"},
        {"No occurrence", 'x', NULL},
        {"End of string\0x", 'x', "x"},
        {"", 'a', NULL}, // Testing empty string
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    int passed = 0;

    for (int i = 0; i < numTests; i++) {
        const char *result = ft_strrchr(testCases[i].str, testCases[i].ch);
        if ((result == testCases[i].expected) || (result && testCases[i].expected && strcmp(result, testCases[i].expected) == 0)) {
            printf("\x1B[32mTest %d passed.\n", i + 1); // Green for success
            passed++;
        } else {
            printf("\x1B[31mTest %d failed: ft_strrchr(\"%s\", '%c') expected \"%s\", got \"%s\"\n",
                   i + 1, testCases[i].str, testCases[i].ch, testCases[i].expected, result ? result : "NULL"); // Red for failure
        }
    }

    printf("\x1B[0m"); // Reset to default color
    printf("Passed %d out of %d tests.\n\n\n", passed, numTests);
}

// Note: You'll need to define ft_strrchr somewhere in your codebase for this to work.
void test_ft_itoa(int n, const char* expected) {
    char* result = ft_itoa(n);
    if (strcmp(result, expected) == 0) {
        printf("PASS: %d -> %s\n", n, result);
    } else {
        printf("FAIL: %d -> %s (expected %s)\n", n, result, expected);
    }
    free(result); // Don't forget to free the memory allocated by ft_itoa
}

int main() {
    // Test cases
    test_ft_itoa(0, "0");
    test_ft_itoa(123, "123");
    test_ft_itoa(-123, "-123");
    test_ft_itoa(2147483647, "2147483647"); // INT_MAX
    test_ft_itoa(-2147483648, "-2147483648"); // INT_MIN
	test_ft_strrchr();

    // Add more test cases as needed

    return 0;
}

/* int main()
{

	char *s1, *s2, *result;

    // Test with two non-empty strings
    s1 = "Hello, ";
    s2 = "World!";
    result = ft_strjoin(s1, s2);
    printf("Test 1 result: %s\n", result);
    free(result); // Remember to free the memory

    // Test with an empty string and a non-empty string
    s1 = "";
    s2 = "World!";
    result = ft_strjoin(s1, s2);
    printf("Test 2 result: %s\n", result);
    free(result); // Remember to free the memory

    // Test with two empty strings
    s1 = "";
    s2 = "";
    result = ft_strjoin(s1, s2);
    printf("Test 3 result: %s\n", result);
    free(result); // Remember to free the memory

    return 0;
 */



/*
    // Test Case 1: Convert a basic positive number
    char *str1 = "42";
    if (ft_atoi(str1) == 42) {
        printf("\033[0;32m[PASS]\033[0m Correct conversion for '42'\n");
    } else {
        printf("\033[0;31m[FAIL]\033[0m Expected 42, got %d\n", ft_atoi(str1));
    }

    // Test Case 2: Convert a basic negative number
    char *str2 = "-42";
    if (ft_atoi(str2) == -42) {
        printf("\033[0;32m[PASS]\033[0m Correct conversion for '-42'\n");
    } else {
        printf("\033[0;31m[FAIL]\033[0m Expected -42, got %d\n", ft_atoi(str2));
    }

    // Test Case 3: Convert a string with leading spaces
    char *str3 = "   123";
    if (ft_atoi(str3) == 123) {
        printf("\033[0;32m[PASS]\033[0m Correct conversion for '   123'\n");
    } else {
        printf("\033[0;31m[FAIL]\033[0m Expected 123, got %d\n", ft_atoi(str3));
    }

    // Test Case 4: Convert a string with plus sign
    char *str4 = "+456";
    if (ft_atoi(str4) == 456) {
        printf("\033[0;32m[PASS]\033[0m Correct conversion for '+456'\n");
    } else {
        printf("\033[0;31m[FAIL]\033[0m Expected 456, got %d\n", ft_atoi(str4));
    }

    // Test Case 5: Convert a string with non-numeric characters at the end
    char *str5 = "789abc";
    if (ft_atoi(str5) == 789) {
        printf("\033[0;32m[PASS]\033[0m Correct conversion for '789abc'\n");
    } else {
        printf("\033[0;31m[FAIL]\033[0m Expected 789, got %d\n", ft_atoi(str5));
    }

    // Test Case 6: Convert a string that does not start with a number
    char *str6 = "abc123";
    if (ft_atoi(str6) == 0) {
        printf("\033[0;32m[PASS]\033[0m Correct conversion for 'abc123' (expected 0)\n");
    } else {
        printf("\033[0;31m[FAIL]\033[0m Expected 0, got %d\n", ft_atoi(str6));
    }

    // Add more test cases as needed...

    printf("\n\n\n"); // 3 blank lines at the end
 */

/*     char c;
    char result;

    c = 'a';
    result = ft_isalnum(c);
    printf("The result is for %d is %d\n", c, result);


    c = '2';
    result = ft_isalnum(c);
    printf("The result is for %d is %d\n", c, result);


    c = '*';
    result = ft_isalnum(c);
    printf("The result is for %d is %d\n", c, result);
    return 0;

	char dest[10];

    printf("Return value: %zu\n", ft_strlcpy(dest, "Hello", sizeof(dest)));
    printf("Destination: %s\n", dest);

    printf("Return value: %zu\n", ft_strlcpy(dest, "Hello, world!", sizeof(dest)));
    printf("Destination: %s\n", dest);

    return 0;

}*/
