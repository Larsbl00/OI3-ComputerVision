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
	git clone https://github.com/cedricve/raspicam .
	cd raspicam
	mkdir build
	cd build
	cmake ..
	make
	make install
	ldconfig

installOpenCV:
	apt-get update
	apt-get install build-essential cmake libgtk2.0-dev pkg-config \
									python-numpy python-dev libavcodec-dev libavformat-dev \
									libswscale-dev libjpeg-dev libpng12-dev libtiff5-dev \
									libjasper-dev libopencv-dev checkinstall pkg-config \
									yasm libjpeg-dev libjasper-dev libavcodec-dev \
									libavformat-dev libswscale-dev libdc1394-22-dev \
									libxine2 libgstreamer0.10-dev  libv4l-dev \
									libgstreamer-plugins-base0.10-dev python-dev \
									python-numpy libtbb-dev libqt4-dev libgtk2.0-dev \
									libmp3lame-dev libopencore-amrnb-dev \
									libopencore-amrwb-dev libtheora-dev libvorbis-dev \
									libxvidcore-dev x264 v4l-utils
	wget https://github.com/opencv/opencv/archive/2.4.13.5.zip -O opencv-2.4.13.5.zip
	unzip opencv-2.4.13.5.zip
	cd opencv-2.4.13.5
	mkdir release
	cd release
	cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
	make all
	make install
	cd ../../
	rm -rf ./opencv-2.4.13.5
	rm -rf ./opencv-2.4.13.5.zip
	pkg-config --modversion opencv