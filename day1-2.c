#include <stdio.h>
#include <string.h>

int findnumber(char *numbers[], int lens[], size_t len, char *p){
	for (int i=0; i<len; i++){
		if (strncmp(numbers[i],p,lens[i])==0)
			return i;
	}
	return -1;
}

int main(){
	FILE *f;
	int sum=0;

	f = fopen("input.txt","r");
	char *line = NULL;
	size_t len = 0;

	char *numbers[] = { "one" ,"two" ,"three" ,"four" ,"five" ,"six" ,"seven" ,"eight" ,"nine" };
	int lens[] = { 3,3,5,4,4,3,5,5,4};

	while (getline(&line, &len, f) != -1){
		char last,first=0;
		
		for(char *p=line; *p!=0;){
			int index;
			
			if (*p==13){
				continue;
			}
			else if (*p>='0' && *p<='9'){
				if (first==0) first=*p-'0';
				last = *p-'0';
			} else if (*p==10){
				if (!first || !last) break;
				sum += (first)*10 + (last);
				first=last=0;
			} else if ((index=findnumber(numbers,lens,9,p))>=0){
				int n = index+1;
				if (first==0) first=n;
				last = n;
			}
			p++;
		}
	}

	fclose(f);

	printf("%d\n", sum);
}

