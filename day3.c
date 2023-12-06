#include <stdio.h>
#include <string.h>

#define MAXROW 140
#define MAXLEN 140

int getnextnumber(char *line, int p, int *number, int *len){
	while (p>=0 && (line[p]<'0' || line[p]>'9')) p--;
	int found=p;
	*len=*number=0;
	for (int power=1;p>=0 && (line[p]>='0' && line[p]<='9'); power*=10, p--, (*len)++)
		*number = *number + power * (line[p]-'0');
	return found;
}

int issymbolaround(char *line,int p,int len){
	for(int i=p; i<=p+len+1; i++){
		if (i<0 || i>=MAXROW) continue;
		if ((line[i]<'0' || line[i]>'9') && line[i]!='.')
			return 1;
	}
	return 0;
}

int main(){
	int sum=0;
	char map[MAXROW][MAXLEN];

	// read file
	FILE *f = fopen("input.txt","r");  
	char *line = NULL;
	size_t len = 0;
	int i=0;
	while (getline(&line, &len, f) != -1){
		line[strlen(line)-1] = 0; // remove newline char 
		strcpy(map[i++], line);
	}
	fclose(f);

	// process
	for(int cline=0; cline<MAXROW; cline++){ 
		int p=MAXLEN;

		int number,len;
		while( (p=getnextnumber(map[cline],p,&number,&len)) >= 0){
			p-=len;
			for (int l=cline-1; l<=cline+1; l++){
				if (l<0 || l>=MAXROW) continue;
				if(issymbolaround(map[l],p,len)){
					sum += number;
					break;
				}
			}
		}
	}

	printf("%d\n", sum);
}

