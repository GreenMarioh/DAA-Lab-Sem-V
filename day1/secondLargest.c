#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	int n;
	FILE *fp;
	fp = fopen("abc.txt", "r");
	if (fp == NULL)
	{
		printf("Error while reading the file\n");
		return 1;
	}
	fscanf(fp, "%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		if (fscanf(fp, "%d", &arr[i]) != 1)
		{
			printf("Reached End of File,no numbers ahead\nExiting the program");
			fclose(fp);
			return 1;
		}
	}

	int fl = INT_MIN;
	int sl = INT_MIN;
	int fs = INT_MAX;
	int ss = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		int a = arr[i];
		if (a > fl)
		{
			sl = fl;
			fl = a;
		}
		else if (a < fl && a > sl)
		{
			sl = a;
		}
		if (a < fs)
		{
			ss = fs;
			fs = a;
		}
		else if (a > fs && a < ss)
		{
			ss = a;
		}
	}

	if (sl == INT_MIN)
		printf("Second Largest Element does not exist\n");
	else
		printf("Second Largest Element is: %d\n", sl);

	if (ss == INT_MAX)
		printf("Second Smallest Element does not exist\n");
	else
		printf("Second Smallest Element is: %d\n", ss);
}
