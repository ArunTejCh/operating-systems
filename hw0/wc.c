#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define IN 1
#define OUT 0

void wc(FILE *infile,char *inname);

int main (int argc, char *argv[]) {
	char *file_name;
	FILE *fp;

	file_name = argv[1];
	printf("going to open file %s for reading\n",file_name);
	fp = fopen(file_name,"r");
	
	
	wc(fp,file_name);
	return 0;
}

void wc(FILE *infile, char *inname){
	char ch;
	int nl,nw,nc;
	nl = nw = nc = 0;
	int pos = OUT;

	if(infile == NULL){
                perror("Error while opening the file.\n");
                exit(EXIT_FAILURE);
        }

        while((ch = fgetc(infile)) != EOF){
		nc++;
		if(ch == '\n' || ch == '\t' || ch == ' '){
			
			if(ch == '\n'){
				nl++;
			}
			
			if(pos == IN){
				nw++;
				pos = OUT;
				putchar('\n');
			}
		}else{
			pos = IN;
			putchar(ch);
		}
        }

        fclose(infile);
	
	printf("%d\t%d\t%d\t%s\n",nl,nw,nc,inname);
}
