display_quote_block()
{
  echo ""
  echo "#################################################"
  echo "##" $1 
  echo "#################################################"
  echo ""
}

update_system()
{
  display_quote_block UPDATE_SYSTEM

  #Update system.
  sudo apt-get update

  display_quote_block UPGRADE_SYSTEM

  #Upgrade system.
  sudo apt-get upgrade
}

install_raspicam()
{
  display_quote_block INSTALLING_RASPICAM
  sudo apt-get update
	git clone https://github.com/cedricve/raspicam .
	cd raspicam
	mkdir build
	cd build
	cmake ..
	make
	sudo make install
	sudo ldconfig
}

install_open_cv()
{
  display_quote_block INSTALLING_OPENCV
	sudo apt-get update
	sudo apt-get install build-essential
	sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
	sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libdc1394-22-dev
	wget https://github.com/opencv/opencv/archive/2.4.13.5.zip -O opencv-2.4.13.5.zip
	unzip opencv-2.4.13.5.zip
	cd opencv-2.4.13.5
	mkdir release
	cd release
	cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
	make all
	sudo make install
	cd ../../
	rm -rf ./opencv-2.4.13.5
	rm -rf ./opencv-2.4.13.5.zip
	pkg-config --modversion opencv
}

############################
##                        ##
##    INSTALL SEQUENCE    ##
##                        ##
############################

#update/upgrade system
update_system

#install open cv
install_open_cv

#install raspicam
install_raspicam