#include "cips.h"

int main()
{
	FILE *fp;
	int i, j;
	unsigned char FileHeader[14];
	unsigned char InfoHeader[40];
	unsigned char rgbQuad[ClrUsed*4];
	unsigned char imArray[Height][Width];

	char fileName_IN[]	= "lena_in.bmp";

	unsigned char temp;
	int dataOffset;
	
	read_bmpHeader(fileName_IN, FileHeader, InfoHeader, rgbQuad); 
	
	dataOffset = 14 + 40 + ClrUsed*4;
	
	fp = fopen(fileName_IN, "rb");   
	fseek(fp, dataOffset, SEEK_SET);
	
	for (i = 0; i < Height; i++)
	{
		for (j = 0; j < Width; j++)
		{
			fread(&temp, 1, 1, fp);
			imArray[i][j] = temp;
		}	
	}
	
	printf("\n  BMP File Header\n");
	for (i = 0; i < 14; i++){
		printf("%d: %d\n", i+1, FileHeader[i]);
	}
    
	printf("\n  BMP Information Header\n");
	for (i = 0; i < 40; i++){
		printf("%d: %d\n", i+1, InfoHeader[i]);
	}
	
    printf("\n  Color Map\n");
	for (i = 0; i < 256; i++){
		printf("%d: \t", i);
		for (j = 0; j < 4; j++){
		printf("%d\t", rgbQuad[i*4+j]);
		}
		printf("\n");		
	}

	return 0;
}

