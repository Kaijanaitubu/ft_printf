#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"  // Include your ft_printf header

void test_printf()
{
    int original_len, custom_len;

    printf("\n--- Testing \"A\" as %%c ---\n");
    original_len = printf("Original: [%c]\n", 'A');
    custom_len = ft_printf("Custom:   [%c]\n", 'A');
    printf("Lengths: original = %d, custom = %d\n", original_len, custom_len);

    printf("\n--- Testing \"Hello, World!\" as %%s ---\n");
    original_len = printf("Original: [%s]\n", "Hello, World!");
    custom_len = ft_printf("Custom:   [%s]\n", "Hello, World!");
    printf("Lengths: original = %d, custom = %d\n", original_len, custom_len);

	printf("\n--- Testing \"Hello, %%World!\" as %%s ---\n");
    original_len = printf("Original: [%s]\n", "Hello,% World!");
    custom_len = ft_printf("Custom:   [%s]\n", "Hello,% World!");
    printf("Lengths: original = %d, custom = %d\n", original_len, custom_len);

    printf("\n--- Testing Pointer Address %%p ---\n");
    int *p = malloc(sizeof(int));
    original_len = printf("Original: [%p]\n", p);
    custom_len = ft_printf("Custom:   [%p]\n", p);
    printf("Lengths: original = %d, custom = %d\n", original_len, custom_len);
    free(p);

    printf("\n--- Testing 12345 as %%d and -12345 %%i ---\n");
    original_len = printf("Original: [%d] [%i]\n", 12345, -12345);
    custom_len = ft_printf("Custom:   [%d] [%i]\n", 12345, -12345);
    printf("Lengths: original = %d, custom = %d\n", original_len, custom_len);

    printf("\n--- Testing 4294967295u as %%u ---\n");
    original_len = printf("Original: [%u]\n", 4294967295u);
    custom_len = ft_printf("Custom:   [%u]\n", 4294967295u);
    printf("Lengths: original = %d, custom = %d\n", original_len, custom_len);

    printf("\n--- Testing 255 as %%x and 255 as %%X ---\n");
    original_len = printf("Original: [%x] [%X]\n", 255, 255);
    custom_len = ft_printf("Custom:   [%x] [%X]\n", 255, 255);
    printf("Lengths: original = %d, custom = %d\n", original_len, custom_len);

    printf("\n--- Testing %%%% ---\n");
    original_len = printf("Original: [%%]\n");
    custom_len = ft_printf("Custom:   [%%]\n");
    printf("Lengths: original = %d, custom = %d\n", original_len, custom_len);
}

int main()
{
    test_printf();
    return 0;
}
