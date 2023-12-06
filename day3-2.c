#include <stdio.h>
#include <string.h>

#define MAXROW	140
#define MAXLEN	140

#define isdigit(C)	(C>='0' && C<='9')

int sum=0;
char map[MAXROW][MAXLEN];

// gets the value of the number in a position
int getnumber(int cline, int i){
	char *p = &map[cline][i];
	if (!isdigit(*p)) return 0; 
	while(isdigit(*p)) p++;
	p--;

	int v=0;
	int power=1;
	while(isdigit(*p)){
		v += power * (*p - '0');
		power *= 10;
		p--;
	}
	return v;
}

// count numbers around a certain position
// return the value of the number, or the product in case of 2 numbers are found
int countnumbers(int cline, int i, int *v){
	*v =0;
	int cnum = 0;  
	int left = (i-1)>=0 ? isdigit(map[cline][i-1]): 0;
	int center = isdigit(map[cline][i]);
	int right = (i+1)<MAXLEN ? isdigit(map[cline][i+1]): 0;

	if (left + center + right == 1){
		cnum++;
		if (left)
			*v = getnumber(cline,i-1); 
		else if (center)
			*v = getnumber(cline,i); 
		else if (right)
			*v = getnumber(cline,i+1); 
	}
	else if (left + center + right == 3){
		cnum++;
		*v = getnumber(cline,i); 
	}
	else if ( (left+center+right==2)){
		if (center==0){
			cnum+=2;
			*v = getnumber(cline,i-1) * getnumber(cline,i+1);
		}
		else {
			cnum++;
			*v = getnumber(cline,i); 
		}
	}
	return cnum;
}


int main(){
	int v1,v2,v3;
	FILE *f = fopen("input.txt","r");
	char *line = NULL;
	size_t len = 0;
	int i=0;
	while (getline(&line, &len, f) != -1){
		int l = strlen(line);
		line[l-1] = 0;
		strcpy(map[i++], line);
	}
	fclose(f);

	for(int cline=0; cline<MAXROW; cline++){ 
		int p=MAXLEN-1;
		for (int i=0; i<MAXLEN; i++){
			if ('*'!= map[cline][i]) continue;
			if (2 == countnumbers(cline-1, i,&v1) + countnumbers(cline, i,&v2) + countnumbers(cline+1, i,&v3)) 
				sum+= (v1?v1:1) * (v2?v2:1) * (v3?v3:1);
		}

	}
	printf("%d\n", sum);
}

