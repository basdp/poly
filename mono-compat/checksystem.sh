#!/bin/bash -e

#Check mono version
s=`mono --version`;
a=( $s );

mono_version=`echo ${a[4]}`;
mono_version_major=`echo $mono_version | awk -F"." '{print $1}'`
mono_version_minor=`echo $mono_version | awk -F"." '{print $2}'`
mono_version_build=`echo $mono_version | awk -F"." '{print $3}'`

if [ $mono_version_major -eq 3 -a $mono_version_minor -ge 2 ]
then
	:
else
	if [ $mono_version_major -ge 4 ]
	then
		:
	else
		echo "You do not have mono 3.2 or higher! (you currently have $mono_version in your PATH)";
		exit;
	fi
fi

