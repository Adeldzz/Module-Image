#ifndef PIXEL_H
#define PIXEL_H


#include <iostream>

using namespace std;

class Pixel {
	private :
	unsigned char r, g, b;  ///composants du pixel
	
	public : 
	
	Pixel(); ///Constructeur par defaut
	Pixel(unsigned char nr, unsigned char ng, unsigned char nb); ///contructeur de classe
	
	unsigned char getRouge() const; ///accesseur pour la couleur rouge
	unsigned char getVert() const; ///accesseur pour la couleur verte
	unsigned char getBleu() const; ///accesseur pour la couleur bleue
	
	void setRouge(unsigned char nr); ///mutateur
	void setVert(unsigned char nv); ///mutateur
	void setBleu(unsigned char nb); ///mutateur
	
};

#endif
	
	
	
	
	
	
	
