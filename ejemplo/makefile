CC=gcc
OBJPATH=/home/alse1/TAREAS/obj/
SRCPATH=/home/alse1/TAREAS/src
LIBPATH=/home/alse1/TAREAS/lib

all: ejemplo.bin
ejemplo.bin: $(OBJPATH)principal.o $(OBJPATH)operaciones.o
	$(CC) -o ejemplo.bin $(OBJPATH)principal.o $(OBJPATH)operaciones.o
$(OBJPATH)principal.o: $(SRCPATH)/principal.c
	$(CC) -c $(SRCPATH)/principal.c -o $(OBJPATH)principal.o -I $(LIBPATH)
$(OBJPATH)operaciones.o: $(SRCPATH)/operaciones.c
	$(CC) -c $(SRCPATH)/operaciones.c -o $(OBJPATH)operaciones.o -I ./lib
clean: 
	rm -f $(OBJPATH)principal.o ./obj/operaciones.o ejemplo.bin
