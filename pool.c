int * pool(int input[][3],int stride)
{
	int s=stride,t=0,k=0,g,x=0,y=0,a,b,max=0;
	int outpool[2][2],f=0;
	for(g=0;g<4;g++){
		int l=0;
		if(g%2==1){
			f=1;
			k=1;
			l=1;
		}
		if(g>1){
			f=1;
		}
		for(a=f;a<2+f;a++)
		{
			for(b=l;b<2+l;b++)
			{	
				if(input[a][b]>max)
				{
					outpool[x][y]=input[a][b];
					max=outpool[x][y];
				}
			}
			
		}
		y++;
		t++;
		max=0;
	}
printf("\n\n");
	for(x=0;x<2;x++)
	{
		for(y=0;y<2;y++)
		{
		
			printf(" %d ",outpool[x][y]);
		}
		printf("\n");
	}
	return outpool;
}
