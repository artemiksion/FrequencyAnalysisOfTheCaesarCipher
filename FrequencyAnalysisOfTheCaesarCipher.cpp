#include <stdio.h>
#include <stddef.h>

int vivedenie(FILE *a, FILE *b, int d)
{
	char alphavit[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int c, zaglav, symbol=0, proverka, i;
	if (a==NULL) return 1;
	if (b==NULL) return 2;
	if ((d<-22)||(d>4)) return 3;
	while ((c = fgetc(a)) != EOF)
    {    
    	for (i=0;i<26;i++)
    	{
    		if ((c==alphavit[i]) || (c==alphavit[i]+('A'-'a')))
    		{
    		    symbol++;
    			zaglav = d+i;
    			if (zaglav > 25)
    			   zaglav -= 26;
    			if (zaglav < 0)
    			   zaglav += 26;
    			if (c==alphavit[i])
    			{
    			   if ((proverka=fputc(alphavit[zaglav], b))==EOF ) return 4;
			    }
    			else 
    			   if ((proverka=fputc((alphavit[zaglav] + ('A'-'a')), b))==EOF) return 5;
			
			}    
		}
		if (symbol == 0)
			if ((proverka = fputc(c, b)) == EOF) return 6;
		symbol=0;
	} 
	return 0;
}

int main()
{
    FILE *file, *tekst1, *tekst2, *tekst3;
    char alphavit[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int c, max1=0, first = 4, max2=0, max3=0, i, chastota[26]={0}, ob1 = 0, ob2 = 0, ob3 = 0, zapis;
    int raznicafirst, raznicasecond, raznicathird;
    file = fopen("zashifrovan.txt", "r");
    if (file == NULL) return 1;
    while((c = fgetc(file)) != EOF)
    {   
        for (i=0;i<27;i++)
        {
	        if (c == alphavit[i])
	            chastota[i]++;
        }     
	}    
	if (fclose(file)==EOF) return 2;
      for (i=0;i<26;i++)
      {
  	      if (chastota[i] > ob1)
	      {
	      	ob3 = ob2;
	      	ob2 = ob1;
	      	ob1 = chastota[i];
	      	max3 = max2;
	    	max2 = max1;
	    	max1 = i;
          }
          if ((chastota[i] < ob1) && (chastota[i] > ob2))
          {
          	ob3 = ob2;
          	ob2 = chastota[i];
          	max3 = max2;
          	max2 = i;
		  }
		  if ((chastota[i] > ob3) && (chastota[i] < ob2))
		  {
		  	ob3 = chastota[i];
		  	max3 = i;
		  }
      }
    raznicafirst = first - max1;
    raznicasecond = first - max2;
    raznicathird = first - max3;
    file = fopen("zashifrovan.txt", "r");
    if (file == NULL) return 3;
    tekst1 = fopen("tekst1.txt", "w");
    if (tekst1 == NULL) return 4;
	zapis=vivedenie(file,tekst1,raznicafirst);
    if (zapis!=0) return 5;
	if (fclose(file)==EOF) return 6;
	if (fclose(tekst1)==EOF) return 7;
	file = fopen("zashifrovan.txt", "r");
	if (file == NULL) return 8;
	tekst2 = fopen("tekst2.txt", "w");
	if (tekst2 == NULL) return 9;
	zapis = vivedenie(file,tekst2,raznicasecond);
	if (zapis != 0) return 10;
	if (fclose(file)==EOF) return 11;
	if (fclose(tekst2)==EOF) return 12;
	file = fopen("zashifrovan.txt", "r");
	if (file == NULL) return 13;
	tekst3 = fopen("tekst3.txt", "w");
	if (tekst3 == NULL) return 14;
    zapis = vivedenie(file,tekst2,raznicathird);
    if (zapis != 0) return 15;
    if (fclose(file)==EOF) return 16;
    if (fclose(tekst3)==EOF) return 17;
    return 0;
}
