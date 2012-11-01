CC=g++

COMMON_CFLAGS=-W -Wall -Iinclude/ -g

# Le rpath permet d'encoder un chemin de recherche des librairies dans l'exécutable
# pas besoin de changer LD_LIBRARY_PATH a priori, donc
ifeq ($(shell getconf LONG_BIT),64)
 CFLAGS=$(COMMON_CFLAGS)
 LDFLAGS=-Llib64/ -lsfml-graphics -lsfml-window -lsfml-system "-Wl,-rpath,lib64/"
else
 CFLAGS=$(COMMON_CFLAGS)
 LDFLAGS=-Llib32/ -lsfml-graphics -lsfml-window -lsfml-system "-Wl,-rpath,lib32/"
endif

#CFLAGS=-W -Wall -Iinclude/
#LDFLAGS=-Llib/ -lsfml-graphics -lsfml-window -lsfml-system
EXEC=bankshoot
SRC= $(wildcard src/*.cpp)
OBJ= $(SRC:.cpp=.o)

# http://stackoverflow.com/questions/2394609/makefile-header-dependencies
#includes = $(wildcard src/*.hpp)

all: $(EXEC)

depend: .depend

.depend: $(SRC)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ >./.depend;
	@# Hack un peu sale pour rajouter des 'src/' où il faut dans le .depend
	sed -i 's/[a-zA-Z0-9]*\.o/src\/&/' .depend

-include .depend

bankshoot: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf src/*.o

mrproper: clean
	rm -rf $(EXEC)
	rm ./.depend
