//Created  by Juode

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char choice, str1[100], str2[100];
	printf("Enter your choice\nl -> Length\nc -> Compare\na -> Concatenate\n");
	scanf("%s", &choice);
	getchar();
    printf("Enter a string : ");
    scanf("%[^\n]s", str1);
    printf("String is : %s\n", str1);

	switch(choice) {
		case 'l':
			printf("Length of the string is %ld", strlen(str1));
			break;
		case 'c':
			printf("Enter another string : ");
			scanf("%s", str2);
			int value = strcmp(str1, str2);
			if (value == 0)
				printf("Equal");
			else
				printf("Not Equal");
			break;
		case 'a':
            printf("Enter another string : ");
			scanf("%s", str2);
			strcat(str1, str2);
			printf("After concatenation : %s", str1);
			break;
        default:
			printf("Invalid Choice.");
	}

	return 0;
}

