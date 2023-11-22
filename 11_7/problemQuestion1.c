/*checking the validity of an expression which contains the parenthesis */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char exp[50];

    while (1)
    {
        int op;
        printf("\nchoose your option\n");
        printf("1.check for new expression \n");
        printf("2.exit \n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("enter the expression  :\n");
            scanf("%s", &exp);

            int right = 0, left = 0;

            for (int i = 0; i < strlen(exp); i++)
            {
                if (exp[i] == '(')
                {
                    right++;
                }
                if (exp[i] == ')')
                {
                    left++;
                }

                if (exp[i] == '{')
                {
                    right++;
                }
                if (exp[i] == '}')
                {
                    left++;
                }

                if (exp[i] == '[')
                {
                    right++;
                }
                if (exp[i] == ']')
                {
                    left++;
                }
            }

            if (left == right)
            {
                printf("expression is correct \n");
            }

            else
            {
                printf("expresion is not correct \n");
            }
            break;
        case 2:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}
