#!/bin/bash

#Install necessary packages
echo "Installing necessary packages"
sudo apt install ack;
sudo apt install silversearcher-ag;

#create directory ~/.vim/swapfiles
mkdir .vim
mkdir ~/.vim/swapfiles

#curl vim plug
echo "Installing vim plug"
curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

#Download .vimrc
wget https://raw.githubusercontent.com/joautor/lab/main/vim-training/.vimrc;



