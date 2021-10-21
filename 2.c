#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char cur;		   
	int k = 1, i, j, n, length = 0, one, h = 0, g=0;		    
	FILE* file;		    
	
	printf("Number of vertices : ");
	scanf_s("%d", &n);					
	int* flag = (int*)malloc(n * sizeof(int));
	int** a = (int**)malloc(n * sizeof(int*));		
	for (int arr = 0; arr < n; arr++)
	{
		a[arr] = (int*)malloc(sizeof(int));
	}
	cur = getchar();			
	for (i = 0; i < n; i++)
	{
		printf("%d line : ", i+1);
		cur = getchar();			
		for (j = 0; cur != '\n'; j++)	
		{
			if ((cur == '1') || (cur == '0'))	
			{
				a[i] = (int*)realloc(a[i], sizeof(int) * k);	
				(a[i])[k - 1] = (int)cur - '0';		
				++k;						
			}
			cur = getchar();	
		}
		cur = '\0';				
		length = k - 1;				
		k = 1;					
	}
	printf("\n\n");

	printf("\n   ");
	for (j = 0; j <= length - 1; j++)
	{
		printf("%3c", j + 0141);
	}
	printf("\n");
	for (j = 1; j <= (length * 4); j++)
	{
		printf(".");
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%i: ", (i + 1));
		for (j = 0; j < length; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}

	flag[0] = 1;
	for (i = 0; i < n; i++)
	{
		if (flag[i] == 1)
		{
			for (j = 0; j < n; j++)
			{	
				if (flag[j] != 1)
				{
					for (int m = 0; m < length; m++)
					{	
						if ((a[i][m] == 1) && (a[j][m] == 1))
						{
							flag[j] = 1;
							break;
						}
						else
						{
							if ((a[i][m] == 1) || (a[j][m] == 1))
							{
								flag[j] = 1;
								break;
							}
						}
					}
				}
			}
		}
	}
	for (j = 0; j < n; j++)
	{
		g = 0;
		for (int l = 0; l < length; l++)
		{
			if (a[j][l] == 0)
			{
				g++;
				if (g == length)
				{
					j = n;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (flag[i] == 1)
		{
			h++;		
		}
	}
	if ((h == n) && (g != length))
		printf("Connected\n %d");
	else printf("Not connected\n %d");

	file = fopen("file.txt", "w");	
	fprintf(file, "graph A{\n");				
	int t = -1;				
	one = 0;				
	for (j = 0; j < length; j++)			
	{
		for (i = 0; i < n; i++)				
		{
			if ((a[i][j] == 1) && (one == 0))       
			{
				fprintf(file, "%d", (i + 1));	 
				fprintf(file, " -- ");
				one++;				
				t = i;				 
			}
			else
			{
				if ((a[i][j] == 1) && (one == 1))       
				{
					fprintf(file, "%d;\n", (i + 1));	
					one++;
					}
			}
		}
		if (t != -1)
		{
			if (one == 1)				  
			{
				fprintf(file, "%d;\n", (t + 1));   
			}
		}
		one = 0;		
		t = -1;
	}
	for (i = 0; i < n; i++)
	{
		fprintf(file, "%d;\n", (i + 1));
	}
	fprintf(file, "}");
	fclose(file);		
	system("dot C:\\Users\\vladi\\Documents\\GitHub\\Dz2\\dz2\\file.txt -Tbmp -o file.bmp");
	system("rundll32  \"%ProgramFiles%\\Windows Photo Viewer\\PhotoViewer.dll\", ImageView_Fullscreen C:\\Users\\vladi\\Documents\\GitHub\\Dz2\\dz2\\file.bmp");

	for (i = 0; i < n; i++) 	
	{
		free(a[i]);
	}
	free(a);	
	return 0;
}