#!/bin/bash

#Install necessary packages
echo "Installing necessary packages"
sudo apt install ack;
sudo apt install silversearcher-ag;

#create directory ~/.vim/swapfiles

#wget my/git/hub/url/.vimrc

#curl vim plug
echo "Installing vim plug"
curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

