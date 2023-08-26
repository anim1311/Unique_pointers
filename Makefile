# Make file to build with my custom strings implementation

#CXX = g++
CXX = clang++

EXE = application
SOURCES_DIR = ./src
SOURCES = main.cpp


OBJ_DIR = ./object_files
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(notdir $(SOURCES)))))
UNAME_S := $(shell uname -s)

CXXFLAGS = -std=c++11 -I$(SOURCES_DIR)
CXXFLAGS += -g -Wall -Wformat 
LIBS = 

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(UNAME_S), Darwin) #APPLE
	ECHO_MESSAGE = "Mac OS X"
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(OS), Windows_NT)
	ECHO_MESSAGE = "MinGW"
	CFLAGS = $(CXXFLAGS)
endif

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

$(OBJ_DIR)/%.o:%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
	rm -f $(EXE) $(OBJ_DIR)/*.o