// Function Definition
int mult(int a, int b)
{
	int result;
	result = a * b;
	return result;
}

int factorial(int n)
{
	int result = 1;
	int i;
	for(i = 1; i <= n; i++)
		result = mult(result , i);
	return result;
}
