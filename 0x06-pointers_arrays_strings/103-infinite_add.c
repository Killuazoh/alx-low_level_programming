/**
 * infinite_add - Adds two numbers represented as strings
 * @n1: First number to add
 * @n2: Second number to add
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the result, or 0 if the result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int carry = 0;
    int i, j, k;

    if (len1 + len2 > size_r - 1)
        return 0;

    for (i = len1 - 1, j = len2 - 1, k = size_r - 1; i >= 0 || j >= 0; i--, j--, k--) {
        int d1 = (i >= 0) ? n1[i] - '0' : 0;
        int d2 = (j >= 0) ? n2[j] - '0' : 0;
        int sum = d1 + d2 + carry;
        r[k] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry == 1 && k >= 0)
        r[k--] = '1';

    if (k < 0 || (k == 0 && r[k] == 0))
        return 0;

    return &r[k];
}
