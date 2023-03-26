 
#include <iostream>
#include <cassert>
#include <string.h>
#include <fstream>

#include "Image.h" 
#include "Pixel.h"

 
   



using namespace std ; 



Image::Image() : dimx(0),dimy(0),tab(nullptr) {};  ///définition constructeur par défaut
  


Image::Image(unsigned int dimensionX, unsigned int dimensionY) : dimx(dimensionX), dimy(dimensionY) {  ///Défintion du constructeur de la classe
	
	assert(dimensionX >= 0);
	assert(dimensionY >=0);
	tab= new Pixel[dimx * dimy];
	
	}
 


Image::~Image() {  /// défintion du destructeur
	
	dimx=0;
	dimy=0;
	delete [] tab;
	
	}  

 

Pixel& Image::getPix(unsigned int x, unsigned int y) const  {
	
	assert(x <= dimx && y <= dimy);
	return tab[y * dimx + x	];
	
	
	
	}


void Image::setPix(unsigned int x, unsigned int y, Pixel  couleur) {
	
	assert(x < dimx && y < dimy);
	tab[y * dimx + y]=couleur;
	
	}





void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel  couleur) {
	
	
	assert(Xmin <= Xmax);
	assert(Xmin < dimx);
	assert(Xmax < dimx);
	assert(Ymin <= Ymax);
	assert(Ymin < dimy);
	assert(Ymax < dimy);
	
	for (unsigned int i = Xmin; i <= Xmax; i++) {
		
		for (unsigned int j = Ymin; j <= Ymax; j++) {
			
		 	setPix(i, j, couleur);
		}
	}

	
}







void Image::effacer(Pixel  couleur) {
	
	
		dessinerRectangle(0, 0, dimx - 1, dimy - 1, couleur);
	
	}



void Image::testRegression() {
	
	
	///Vérification des constructeurs
	assert(dimx >=0);
	assert(dimy >=0);

	Image monIm (10, 10);
	Pixel monPix (31, 68, 50);

	assert(monIm.dimx == 10 && monIm.dimy == 10);

	///Vérification des get
	assert(monPix.getRouge() == 31);
	assert(monPix.getVert() == 68);
	assert(monPix.getBleu() == 50);

	///Vérification des set
	monPix.setRouge(78);
	monPix.setVert(12);
	monPix.setBleu(104);

	assert(monPix.getRouge() == 78);
	assert(monPix.getVert() == 12);
	assert(monPix.getBleu() == 104);

	///Vérification de setPix et getPix
	monIm.setPix(3, 4, monPix);

	assert(monIm.getPix(3, 4).getRouge() == 78);
	assert(monIm.getPix(3, 4).getVert() == 12);
	assert(monIm.getPix(3, 4).getBleu() == 104);

	///Vérification de dessinerimageRect
	monIm.dessinerRectangle(0, 0, 5, 5, monPix);
	
	for(unsigned int i = 0; i < 5; i++) {
		for(unsigned int j = 0; j < 5; j++) {
			assert(monIm.getPix(i, j).getRouge() == 78);
			assert(monIm.getPix(i, j).getVert() == 12);
			assert(monIm.getPix(i, j).getBleu() == 104);
		}
	}

	///Vérification de effacer
	monIm.effacer(monPix);

	for(unsigned int i = 0; i < monIm.dimx; i++) {
		for(unsigned int j = 0; j < monIm.dimy; j++) {
			assert(monIm.getPix(i, j).getRouge() == 78);
			assert(monIm.getPix(i, j).getVert() == 12);
			assert(monIm.getPix(i, j).getBleu() == 104);
		}
	}
}


    
    

void Image::sauver(const string & filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << filename.c_str() << endl;
    fichier << dimx << " " << dimy << endl;
   
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}


void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	char r,g,b;
	string mot;
	//dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);
	if (tab != NULL) delete [] tab;
	tab = new Pixel [dimx*dimy];
    for(unsigned int x=0; x<dimx; x++)
        for(unsigned int y=0; y<dimy; y++) {
            fichier >> r >> g >> b;
            getPix(x,y).setRouge(r);
            getPix(x,y).setVert(g);
            getPix(x,y).setBleu(b);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}




void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}


void Image::afficherInit(){


		
	 if (SDL_Init(SDL_INIT_VIDEO) < 0){
        cout<<"erreur lors de l'initialisation de la SDL:"<<SDL_GetError()<<endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0){
        cout<<"erreur lors de l'initialisation de la SDL:"<<SDL_GetError()<<endl;
        SDL_Quit();
        exit(1);
        }
    
    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    
	if (!(IMG_Init(imgFlags)& imgFlags)){
        cout<<"erreur lors de l'initialisation de la SDL:"<<SDL_GetError()<<endl;
        SDL_Quit();
        exit(1); 
    }
   
	
	Window = SDL_CreateWindow("Module Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WinWidth, WinHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (Window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

	
	
	sauver("./data/ImageAafficher.ppm");
    surface = IMG_Load("./data/ImageAafficher.ppm");

    Renderer = SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);
    texture = SDL_CreateTextureFromSurface(Renderer,surface);

    SDL_SetRenderDrawColor(Renderer, 128, 128, 128, 128);
    SDL_RenderClear(Renderer);
    
		
   

    SDL_RenderCopy(Renderer,texture,NULL,&fenetre);
    SDL_RenderPresent(Renderer);
	


}

void Image::afficherBoucle(){
	
	SDL_Event events;
	
    
   

    bool isOpen{ true };

    while (isOpen)
    {
         while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = false;
                break;

			case SDL_KEYDOWN:
				if (events.key.keysym.sym == SDLK_ESCAPE){
				isOpen = false;
				}

				if (events.key.keysym.sym == SDLK_g){
				fenetre.x += 10;
				fenetre.y += 10;
				fenetre.w -= 20;
				fenetre.h -= 20;
				}

				if (events.key.keysym.sym == SDLK_t){
				
				fenetre.x -= 10;
				fenetre.y -= 10;
				fenetre.w += 20;
				fenetre.h += 20;
				
				}

				break;

            }
	
		
	}

	SDL_RenderPresent(Renderer);
	}

}

void Image::afficherDestroy(){

	SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
	SDL_DestroyTexture(texture);
    SDL_Quit();
}

void Image::afficher(){

	afficherInit();
	afficherBoucle();
	afficherDestroy(); 
   
}	