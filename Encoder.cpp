#include <stdio.h>
#include <stddef.h>

int main()
{
	long long int i, raznica, alph, symbol=0;
    FILE *file, *angl;
    char c, alphavit[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    scanf("%i", &raznica);
    file = fopen("zashifrovan.txt", "w");
    if (file == NULL)
        return 1;
    angl = fopen("angl tekst.txt", "r");
    if (angl == NULL)
        return 2;
    	while ((c = fgetc(angl)) != EOF)
    	{
		    for (i=0;i<26;i++)
		    {
		    	if ((c == alphavit[i]) || (c == (alphavit[i] + 'A' - 'a')))
		    	{
		    		symbol++;
		    		alph = i+raznica;
		    		if (alph > 25)
		    		    alph -= 26;
		    		if (alph < 0)
		    		    alph += 26;
		    		if (c == alphavit[i])
		    		    fputc((int)alphavit[alph], file);
		    		else
		    		    fputc((int)alphavit[alph]+('A'-'a'), file);
				}
			}
	        if (symbol == 0)
	            fputc((int)c, file);
	        symbol = 0;
	    }
    fclose(file);
    fclose(angl);
    return 0;
}
