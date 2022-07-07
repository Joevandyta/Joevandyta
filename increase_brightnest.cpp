#include <stdio.h>

int main()
{
	
	FILE* fl; 
	FILE* flOut;
	//make variable to do fille operation
	unsigned char unbright;
	//unsigned char is to store value from the photo
	int bright;
	int intensity=100;
	//intensity is a constanta 
	//value this constanta will added
	//to make the photo more bright 
	fl = fopen("kucingvv.bmp", "rb");
	// make vaiable, then Open photo File using read parameter
	// this is used as the source photo file

	flOut = fopen("bright.bmp", "wb");
	//enter file name above
	//make variable to store value, and make a new/replace a photo file
	//this will be the result of bright photo

	for (int i=0; i<54; i++){
		fread(&unbright, 1, 1, fl);
		fwrite(&unbright, 1, 1, flOut);
	} //make padding
	
	while (fread(&unbright, 1, 1, fl)){
		//do while looping and take value from source photo
		
		bright = unbright + intensity;
		//enter value to bright based on unbright add by intensity
		//to make new photo more bright

		if (bright > 255){
			bright = 255;
		} //this is to make the photo max color is 255
		//255 is decimal value of white color in RGB

		fwrite(&bright, 1, 1, flOut);
		//input value of bright into the new photo file
	}
	
	
	
	fclose(fl); //close the file
	fclose(flOut); //close the file

	return 0;
}
