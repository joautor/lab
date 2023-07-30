#!/bin/bash

#Install necessary packages
echo "[INFO] Installing packages needed for vim plugins"
echo "[INF0] Installing ack"
sudo apt install ack;
echo "[INFO] Installing silversearcher-ag"
sudo apt install silversearcher-ag;

#create directory ~/.vim/swapfiles
echo "[INFO] Creating ~/.vim/swapfiles"
mkdir -p ~/.vim/swapfiles

#curl vim plug
echo "[INFO] Installing vim plug"
curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

#Download .vimrc
echo "[INFO] Downloading .vimrc"
wget https://raw.githubusercontent.com/joautor/lab/main/vim-training/.vimrc;
echo "[INFO] Required next step -> Open .vimrc file via vim and run this command :PlugInstall"



