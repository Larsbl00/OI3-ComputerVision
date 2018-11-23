#Project
PROJECT_NAME = ComputerVision

#Build
BUILD_DIR = ./build

#Compiler
CXX = g++

#Flags
CFLAGS = -Wall -Werror -ggdb -O0 -std=c++11 -lpthread \
	-I/usr/local/include/ -lraspicam -lraspicam_cv -lopencv_core \
	-lopencv_imgcodecs -lopencv_objdetect

#Sources
SRC_DIR = ./src

SOURCES = 	$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/RaspiCamera.cpp

#Objects
OBJ_DIR = ./obj

OBJECTS = $(subst $(SRC_DIR),$(OBJ_DIR),$(SOURCES:.cpp=.o))

#Phony
.PHONY: all $(PROJECT_NAME)Clean create_dirs

#All
all: $(PROJECT_NAME)

#Build
$(PROJECT_NAME): create_dirs $(OBJECTS)
	$(CXX) $(CFLAGS) $(OBJECTS) -o $(BUILD_DIR)/$@

#Dirs
create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BUILD_DIR)

#Clean
clean: $(PROJECT_NAME)Clean

$(PROJECT_NAME)Clean:
	@rm -fr $(OBJ_DIR)
	@rm -fr $(BUILD_DIR)

#Targets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) $< -c -o $@