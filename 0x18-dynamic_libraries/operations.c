int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);


/**
 * add - Adds two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The sum of the two integers.
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - Subtracts two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The result of subtracting the second integer from the first.
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - Multiplies two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The product of the two integers.
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - Divides two integers.
 * @a: The dividend.
 * @b: The divisor.
 *
 * Return: The result of dividing the dividend by the divisor.
 *         If the divisor is 0, an error message is printed and 0 is returned.
 */
int div(int a, int b)
{
	if (b == 0)
	{
		return (0);
	}
	return (a / b);
}

/**
 * mod - Computes the remainder of the division of two integers.
 * @a: The dividend.
 * @b: The divisor.
 *
 * Return: The remainder of dividing the dividend by the divisor.
 *         If the divisor is 0, an error message is printed and 0 is returned.
 */
int mod(int a, int b)
{
	if (b == 0)
	{
		return (0);
	}
	return (a % b);
}

