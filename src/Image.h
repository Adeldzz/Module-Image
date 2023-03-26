#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"  
 
#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
   

class Image {
	
	private:
	
		unsigned int dimx,dimy;
		
		Pixel *tab ;

		 
	SDL_Window* Window{ nullptr };     
  	SDL_Renderer* Renderer{ nullptr };
	SDL_Surface* surface ;
	SDL_Texture* texture ;
	

		 
	const int WinWidth = 200 ; // largeur de la fenêtre
	const int WinHeight = 200; // hauteur de la fenêtre
    
	SDL_Rect fenetre{0,0,WinWidth,WinHeight};	


	public:
	
		Image(); //*constructeur par defaut
		
		Image(unsigned int dimensionX,unsigned int dimensionY); //*construccteur de classe 
		
		~Image();
		
		Pixel& getPix(unsigned int x,unsigned int y) const; //*accesseur
		
		void setPix(unsigned int x,unsigned int y , Pixel couleur); //*mutateur
		
		void dessinerRectangle(unsigned int Xmin,unsigned int Ymin,unsigned int Xmax,unsigned int Ymax, Pixel couleur);
		
		void effacer(Pixel couleur);
		
		void testRegression();
		
		void sauver(const string & filename) const;

		void ouvrir(const string & filename);

		void afficherConsole();


		void afficherInit();
		void afficherBoucle();
		void afficherDestroy();

		void afficher(); // fct afficher sous SDL

};




#endif
