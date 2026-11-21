#include <stdio.h>
#include <string.h>
#define MAX 500
#define LEN 30
void trim(char s[]){size_t n=strlen(s);if(n&&s[n-1]=='\n')s[n-1]='\0';}
int main(void){
    char names[MAX][LEN],key[LEN];int n;
    printf("Number of names (1-%d): ",MAX);
    if(scanf("%d",&n)!=1||n<1||n>MAX){puts("Invalid count");return 1;}
    int ch;while((ch=getchar())!='\n'&&ch!=EOF){}
    for(int i=0;i<n;i++){printf("Name %d: ",i+1);if(!fgets(names[i],LEN,stdin)){puts("Input error");return 1;}trim(names[i]);}
    for(int i=0;i<n-1;i++)for(int j=0;j<n-1-i;j++)if(strcmp(names[j],names[j+1])>0)
	{
        char temp[LEN];strcpy(temp,names[j]);strcpy(names[j],names[j+1]);strcpy(names[j+1],temp);
	}
    puts("Sorted names:");for(int i=0;i<n;i++)puts(names[i]);
    puts("Duplicates:");int found=0;for(int i=1;i<n;i++)if(strcmp(names[i],names[i-1])==0)
	{
	puts(names[i]);found=1;
	}
    if(!found)puts("None");
    printf("Search name: ");if(!fgets(key,LEN,stdin))return 1;trim(key);
    int low=0,high=n-1,pos=-1;while(low<=high){int mid=low+(high-low)/2,c=strcmp(names[mid],key);
        if(c==0){pos=mid;break;}if(c<0)low=mid+1;else high=mid-1;}
    if(pos>=0)printf("Found at sorted index %d\n",pos);else puts("Name not found");return 0;
}
