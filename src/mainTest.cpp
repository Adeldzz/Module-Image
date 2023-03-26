#include "Image.h"
#include <iostream>

int main () {

	Image monImage(3,2);
	Image imagemodif(4,6);
   //monImage.testRegression();
	//monImage.dessinerRectangle(0,0,10,10, Pixel(250,250,250));
	monImage.sauver("./data/monImage.ppm");
	imagemodif.ouvrir("./data/imagemodif.ppm");
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
				std::cout<<imagemodif.getPix(i,j).getBleu()<<endl;
			}
	}
	
	std::cout<<"on a réussi";
return 0;	
}
