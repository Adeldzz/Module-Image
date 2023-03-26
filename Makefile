
CC = g++
BINDIR = bin
SRCDIR = src
OBJDIR = obj
CPPFLAGS = -g -Wall
LIBSDL  = -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -lSDL2_mixer
INCLUDESDL = 

all : $(BINDIR)/test $(BINDIR)/exemple $(BINDIR)/affichage

affichage : $(BINDIR)/affichage
	./$(BINDIR)/affichage

test : $(BINDIR)/test
	./$(BINDIR)/test

exemple : $(BINDIR)/exemple
	./$(BINDIR)/exemple


$(BINDIR)/affichage: $(OBJDIR)/mainAffichage.o $(OBJDIR)/Image.o $(OBJDIR)/Pixel.o
	$(CC) $(OBJDIR)/mainAffichage.o $(OBJDIR)/Image.o $(OBJDIR)/Pixel.o -o $(BINDIR)/affichage $(INCLUDESDL)  $(LIBSDL)

$(OBJDIR)/mainAffichage.o: $(SRCDIR)/mainAffichage.cpp $(SRCDIR)/Image.h 
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/mainAffichage.cpp -o $(OBJDIR)/mainAffichage.o 

$(BINDIR)/test: $(OBJDIR)/mainTest.o $(OBJDIR)/Image.o $(OBJDIR)/Pixel.o
	$(CC) $(OBJDIR)/mainTest.o $(OBJDIR)/Image.o $(OBJDIR)/Pixel.o -o $(BINDIR)/test $(INCLUDESDL)  $(LIBSDL)

$(OBJDIR)/mainTest.o: $(SRCDIR)/mainTest.cpp $(SRCDIR)/Image.h 
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/mainTest.cpp -o $(OBJDIR)/mainTest.o $(LIBSDL)

$(BINDIR)/exemple : $(OBJDIR)/mainExemple.o $(OBJDIR)/Image.o $(OBJDIR)/Pixel.o 
	$(CC) $(OBJDIR)/mainExemple.o $(OBJDIR)/Image.o $(OBJDIR)/Pixel.o -o $(BINDIR)/exemple $(INCLUDESDL)  $(LIBSDL)

$(OBJDIR)/mainExemple.o: $(SRCDIR)/mainExemple.cpp $(SRCDIR)/Image.h 
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/mainExemple.cpp -o $(OBJDIR)/mainExemple.o $(LIBSDL)

$(OBJDIR)/Image.o: $(SRCDIR)/Image.h $(SRCDIR)/Image.cpp $(SRCDIR)/Pixel.h 
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Image.cpp -o $(OBJDIR)/Image.o $(LIBSDL)
	
$(OBJDIR)/Pixel.o: $(SRCDIR)/Pixel.cpp $(SRCDIR)/Pixel.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Pixel.cpp -o $(OBJDIR)/Pixel.o

	
	
clean:
	rm ./$(BINDIR)/* ./$(OBJDIR)/*.o
