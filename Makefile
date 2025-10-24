CC = gcc
CFLAGS = -lm

EXECUTABLE_NAME = main.exe

BUILDDIR = Build

SOURCES   = $(wildcard *.c)
OBJECTS   = $(patsubst %.c, %.o, $(SOURCES))

.PHONY = all clean start

all: print_start make_folder $(EXECUTABLE_NAME)
	@echo ====COMPILATION WAS FINISHED====

print_start:
	@echo ==COMPILATION HAS BEEN STARTED==

#____________________________MAIN________________________________
$(EXECUTABLE_NAME): $(OBJECTS)
	@$(CC) $(addprefix ./$(BUILDDIR)/, $(OBJECTS)) -o ./$(BUILDDIR)/$(EXECUTABLE_NAME) $(CFLAGS)
	@echo All files were compilated

$(OBJECTS): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o ./$(BUILDDIR)/$@

#_____________________CREAT FOLDERS_____________________________
make_folder:
	@mkdir -p $(BUILDDIR)/
	@echo Folders were created!

start:
	@./$(BUILDDIR)/$(EXECUTABLE_NAME)

#_________________________CLEAN_________________________________
clean:
	@rm -rf ./$(BUILDDIR)/
	@echo Cleaning completed!