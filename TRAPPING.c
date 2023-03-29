/* 2D trapping and calclulating survival */ 
/*      and trapping Distribution        */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  M 500
#define  Nmc 100000
#define  C  0.001
#define  Npart C*M*M
#define  a 0
#define  b M
#define  p1 0.25
#define  p2 0.50
#define  p3 0.75
#define  seed 4375
int main(){
	int (*grid)[M] = malloc(sizeof(int[M][M]));  //allocate memory for grid
    int *time=malloc(Nmc*sizeof(int));
	int i,j,x,y,imc,S,time1,flag,max;
	
	double k;
	srand(seed);
	
	FILE *trapping;
	FILE *distribution;
    //open files
    trapping=fopen("trapping.txt","w");
	distribution=fopen("distribution.txt","w");
	
	// initialization grid 
	
	for (i=0; i<M; i++){
		for (j=0; j<M; j++){
			grid[i][j]=0;
		}
	}
	
	for (i=0; i<Nmc; i++){
		time[imc]=0;
	}
		
	
//	random traps in grid
	
	for (i=0; i<Npart; i++){
 
           x=a+rand()%(a-b);
           y=a+rand()%(a-b);
           grid[x][y]=-1;
    
     }



for (imc=0; imc<Nmc; imc++){
	
    time1=0;
	flag=0;
	
		x=a+rand()%(a-b) ; 
		y=a+rand()%(a-b) ;
		    
		
		while(grid[x][y]==-1){
		  x=a+rand()%(a-b) ; 
		  y=a+rand()%(a-b) ;
		} 
	
	while(flag==0){
	
	
	
	
	
			k=(double)rand() / (double)((unsigned)RAND_MAX + 1);	//start random walk 
			
				if(k<=p1) 		
				  x+=1;	
				  
				else if(k<=p2) 	
				  x-=1;
				  
				else if(k<=p3)  
				   y+=1;
				   
				 else
				    y-=1;  
					
			
				
				//non stop grid
				
		     	if (x<0)  x+=M;
				if (x>=M) x-=M;
				if (y<0)  y+=M;
				if (y>=M) y-=M;
				
				
	
		if (grid[x][y]==-1)
		   flag=1; //a new particle had trapped
		 
		 
		 time1+=1;  
		   

			 
    } 
time[imc]=time1;
 
 fprintf(trapping,"%d\t",time[imc]);  //write data

}

// make distribution

max=time[1];
for (i=0; i<Nmc; i++){
	if (time[i]>max)
	max=time[i];
}
int *Distribution=malloc(max*sizeof(int));

for (i=0; i<max; i++){

Distribution[i]=0;
}


for (i=0; i<Nmc; i++){
	Distribution[time[i]]++;
	
}
for (i=0; i<max; i++){

fprintf(distribution,"%d\n",Distribution[i]); //write data for survival distribution
}

//free memory
free(grid);
free(Distribution);
free(time);

	return 0;
}
