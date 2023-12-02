#include <stdio.h>

int main(){
	FILE *f;
	int sum=0;
	char c,last,first=0;

	f = fopen("input.txt","r");

	while (EOF!=(c=fgetc(f))){
		if (c==13) continue;
		if (c==10){
			if (!first || !last) break;
			int value = (first-'0')*10 + (last-'0');
			sum += value;
			first=last=0;
		} else if (c>='0' && c<='9'){
			if (first==0) first=c;
			last = c;
		}
	}
	fclose(f);

	printf("%d\n", sum);
}

