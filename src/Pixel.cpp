#include <iostream>
#include <cassert>
#include "Pixel.h"


using namespace std;


Pixel::Pixel() : r(0), g(0), b(0){}

Pixel::Pixel(unsigned char nr,unsigned char ng,unsigned char nb) : r(nr), g(ng), b(nb)	{}


unsigned char Pixel::getRouge() const {

		return this->r;
}

unsigned char Pixel::getVert() const {

		return this->g;
}

unsigned char Pixel::getBleu() const {

		return this->b;
}

void Pixel::setRouge(unsigned char nr) {
	
		assert(nr >=0);
		this->r = nr;

}

void Pixel::setVert(unsigned char ng) {
	
		assert(ng>=0);
		this->g = ng;

}

void Pixel::setBleu(unsigned char nb) {
	
		assert(nb >=0);
		this->b = nb;

}









