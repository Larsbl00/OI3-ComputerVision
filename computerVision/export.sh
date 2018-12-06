#!/bin/bash

#vars
remote_id="pi"
remote_ip="169.254.152.1"
work_dir="~/OI3/ComputerVision/"
send_dir="./" 
image_dir="./images"
is_connecting="false"


#execute
while getopts 'ca:d:r:f:' flag; 
do
    case ${flag} in 
        c) is_connecting="true" ;;
        a) remote_ip=${OPTARG} ;;
        d) remote_id=${OPTARG} ;;
        r) work_dir=${OPTARG} ;;
        f) send_dir=${OPTARG} ;;
        /?) echo "Unknown flag: \"${OPTARG}\"";;

    esac
done

SEND="scp -r $send_dir $remote_id@$remote_ip:$work_dir"
REMOVE_FILES="rm -rf $image_dir"

echo "Remote id: $remote_id"
echo "Remote ip: $remote_ip"
echo "Remote directory: $work_dir"
echo "Sending: $send_dir"
echo "Command: $SEND"
echo "Removing: \n\t$image_dir"
echo "Using: $REMOVE_FILES"

$REMOVE_FILES
$SEND 

if [ "$is_connecting" = "true" ]
then
    SSH="ssh $remote_id@$remote_ip"
    echo "SSH: $SSH"
    $SSH
fi