#include <stdio.h>
#define MAXC 12
#define MAXV 500000
int main(void){
    int c,v,count[MAXC+1]={0},order[MAXC],valid=0,invalid=0;
    printf("Number of candidates (1-%d): ",MAXC);
    if(scanf("%d",&c)!=1||c<1||c>MAXC){puts("Invalid candidate count");return 1;}
    printf("Number of votes (0-%d): ",MAXV);
    if(scanf("%d",&v)!=1||v<0||v>MAXV){puts("Invalid vote count");return 1;}
    for(int i=0;i<v;i++){int vote;if(scanf("%d",&vote)!=1){puts("Invalid input");return 1;}
        if(vote>=1&&vote<=c){count[vote]++;valid++;}else invalid++;}
    for(int i=0;i<c;i++)order[i]=i+1;
    for(int i=0;i<c-1;i++)for(int j=0;j<c-1-i;j++)
	{
        int x=order[j],y=order[j+1];if(count[x]<count[y]||(count[x]==count[y]&&x>y))
		{
            int t=order[j];
			order[j]=order[j+1];order[j+1]=t;
			}}
			
    printf("Valid votes: %d\nInvalid votes: %d\n",valid,invalid);
    puts("Candidate results (descending votes):");
    for(int i=0;i<c;i++)printf("Candidate %d: %d\n",order[i],count[order[i]]);
    int max=count[order[0]],winners=0;for(int i=1;i<=c;i++)if(count[i]==max)winners++;
    if(max==0)puts("No valid votes; no winner");
    else{printf("Winner(s):");for(int i=0;i<c;i++)if(count[order[i]]==max)printf(" %d",order[i]);printf("\n");}
    printf("Tie: %s\n",(max>0&&winners>1)?"Yes":"No");return 0;
}
