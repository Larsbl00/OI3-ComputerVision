#!/bin/bash

#vars
remote_id="pi"
remote_ip="169.254.152.1"
remote_image_dir="~/OI3/ComputerVision/images/"
local_image_dir="./"

#Get flags
while getopts 'r:l:i:a:' flag; 
do
    case ${flag} in 
        r) remote_image_dir=${OPTARG} ;; #Set remote image directory
        l) local_image_dir=${OPTARG} ;; #Set local image directory
        i) remote_id=${OPTARG} ;; #Set id
        a) remote_ip=${OPTARG} ;; #Set ip
        /?) echo "Unknown flag: \"${OPTARG}\"";;
    esac
done

#Functions
GET_IMAGES()
{
    send_command="scp -r $remote_id@$remote_ip:$remote_image_dir $local_image_dir"
    echo "Send command: $send_command"
    $send_command 
}

#echo vars
echo "\n-----------------------"
echo "Vars:"
echo "Remote dir: $remote_image_dir"
echo "Local dir: $local_image_dir"
echo "Remote ip: $remote_ip"
echo "Remote id: $remote_id"
echo "\n-----------------------"
echo "Functions:"
GET_IMAGES
echo "-----------------------\n"