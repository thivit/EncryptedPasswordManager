#!/bin/bash
set -e # exit immediately if command fails
sudo apt update
sudo apt install -y build-essential pkg-config qtbase5-dev
echo "Qt5 installed. Run: make to build Encrypted Password Manager."
