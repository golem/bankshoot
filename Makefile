# Si clang est installé, on compile avec, c'est mieux.
CLANG_EXISTS := $(shell command -v clang >/dev/null 2>&1 && echo ok)
ifeq ($(CLANG_EXISTS), ok)
 CXX=clang++
else
 CXX=g++
endif

# La directive -isystem <dir> permet de signaler à g++ que ce dossier contient
# des headers qui ne seront pas modifiés (on ne les prend pas en compte dans 
# la génération des dépendances).
COMMON_CFLAGS=-W -Wall -isystem include/ -g

# -Wall n'est pas DU TOUT exhaustif, donc -Weverything permet à clang de fournir des
# warnings pour à peu près tout.
#COMMON_CFLAGS=-W -Weverything -isystem include/ -g -Wno-padded -Wno-weak-vtables -Wno-global-constructors -Wno-exit-time-destructors -Werror

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

LIB32 = $(wildcard lib32/*.so.1.6)
LIB32_LN = $(LIB32:.so.1.6=.so)
LIB64 = $(wildcard lib64/*.so.1.6)
LIB64_LN = $(LIB64:.so.1.6=.so)

all: $(LIB32_LN) $(LIB64_LN) $(EXEC)

# Création de liens symboliques qui peuvent être détruits par un zippage par exemple...
#peut être pas nécessaire, et certainement pas beau, mais voilà.
%.so: %.so.1.6
	ln -sf $(patsubst $(findstring lib32/, $<)$(findstring lib64/, $<)%,%,$<) $@

depend: .depend

.depend: $(SRC)
	rm -f ./.depend
	$(CXX) $(CFLAGS) -MM $^ >./.depend;
	@# Hack un peu sale pour rajouter des 'src/' où il faut dans le .depend
	sed -i 's/[a-zA-Z0-9]*\.o/src\/&/' .depend

-include .depend

bankshoot: $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

doc:
	doxygen Doxyfile

.PHONY: clean mrproper

clean:
	rm -rf src/*.o

mrproper: clean
	rm -rf $(EXEC)
	rm ./.depend
