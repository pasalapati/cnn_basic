#include <stdio.h>
#include <stdlib.h>
#define IMG 7
#define CH 3
#define FIL 3


int * conv(int[][IMG][IMG],int[FIL][FIL][FIL],int ,int);
int * pool(int input[][3],int stride);

int main(){
	int n=7;
	int input[3][IMG][IMG], filter[CH][FIL][FIL];
    int lower =0, upper =2,lf=-1,uf=1;
    int i,j,k,m;
//generating random values(range 0-2)for input matrix with depth=3 and 7X7 
   
    for(i=0;i<CH;i++)
    {
        for(j=0;j<IMG;j++)
        {
            for(k=0;k<IMG;k++)
            {
               input[i][j][k] = (rand() % (upper - lower + 1)) + lower;
            }
        }
    }
      // Generating filter volume with 3X3 with depth=3
    // 3 Different filters for 3 different input volume
   for(i=0;i<CH;i++)
    {
        for(j=0;j<FIL;j++)
        {
            for(k=0;k<FIL;k++)
            {
                int num = (rand() % (uf - lf + 1)) + lf;
                filter[i][j][k]=num;
                
            }
        }
    }
    conv(input, filter, 2, 0);
	return 0;
}

int * conv(int input[][IMG][IMG],int filter[][FIL][FIL],int stride,int bias){
	int a,b,s=stride,t=0,c,i,j,k,g,h,xx;
	int out[3][3];
	for(a=0; a<CH;a++){
		for(b=0;b<IMG-1;b=b+s){
			h=0;
			t=0;
			for(c=0;c<IMG-1;c=c+s)
			{
				int sum1=0,sum2=0,sum3=0;
		        int x=0;
		        for(j=b;j<b+3;j++)
		        {
		            int y=0;
		            for(k=c;k<t+3;k++)
		            {
		            	for(xx=0;xx<3;xx++){
		                sum1=sum1+(filter[xx][x][y]*input[xx][j][k]);
		           		}
		           		y++;
		            }
		            x++;
		        }
		        out[g][h]=sum1; //Storing the sum of product of filter values and input values
		        h++;
		        t=t+s;
			}
			g++;
		}
	}
	 for(i=0;i<3;i++){
    	for(j=0;j<3;j++){
    		printf(" %d ",out[i][j]);
		}
    	printf("\n");
	}
	
	pool(out,1);
}
