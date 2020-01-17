# CS 162 assignment makefile
# Fall 2019

# Log file name
LOGC=log_compile
LOGL=log_link

# Executable name
EXEC=main

# Create the course code file list.  Expansion happens now.
SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)

# Create object file variable.  Expansion happens when variable is referenced
OBJECTS= *.o

# Compiler options
CC=g++
CFLAG=-v -c -g -std=c++11 -Wall

# Make targets
all:		$(EXEC)

$(EXEC):	$(SOURCES) $(HEADERS) 
		@rm -f $(LOGC) $(LOGL)
		@$(CC) $(CFLAG) $(SOURCES) &>>$(LOGC)
		@$(CC) -o main  $(OBJECTS) &>>$(LOGL)

compile:	$(SOURCES) $(HEADERS)
		@rm -f $(LOGC)
		@$(CC) $(CFLAG) $(SOURCES) &>> $(LOGC)

clean:	 
	@rm -f $(EXEC) $(LOGC) $(LOGL) $(patsubst %.cpp,%.o,$(wildcard *.cpp))

