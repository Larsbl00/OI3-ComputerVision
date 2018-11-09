#Project
PROJECT_NAME = ComputerVision

#Build
BUILD_DIR = ./build

#Compiler
CXX = g++

#Flags
CFLAGS = -Wall -Werror -ggdb -O0 -std=c++11 -lpthread -lraspicam -lraspicam_cv -lopencv_core -lopencv_highgui 

#Sources
SRC_DIR = ./src

SOURCES = $(SRC_DIR)/main.cpp

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

#Install deps
installAll: installOpenCV installRaspicam

installRaspicam:
	sudo git clone https://github.com/cedricve/raspicam .
	cd raspicam
	sudo mkdir build
	cd build
	sudo cmake ..
	sudo make
	sudo make install
	sudo ldconfig

installOpenCV:
	sudo apt-get update
	sudo apt-get install build-essential
	sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
	sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libdc1394-22-dev
	sudo wget https://github.com/opencv/opencv/archive/2.4.13.5.zip -O opencv-2.4.13.5.zip
	sudo unzip opencv-2.4.13.5.zip
	sudo cd opencv-2.4.13.5
	sudo mkdir release
	cd release
	sudo cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
	sudo make all
	sudo make install
	cd ../../
	sudo rm -rf ./opencv-2.4.13.5
	sudo rm -rf ./opencv-2.4.13.5.zip
	sudo pkg-config --modversion opencv