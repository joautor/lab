#!/bin/bash
cd ~
#Install necessary packages
echo "[INFO] Installing packages needed for vim plugins"

echo "[INF0] Installing ack ..."
sudo apt install ack -y

echo "[INFO] Installing silversearcher-ag ..."
sudo apt install silversearcher-ag -y

echo "[INFO] Installing curl ..."
sudo apt install curl -y

echo "[INFO] Installing wget ..."
sudo apt install wget -y

# Setup swap directory
SWAP_DIR=~/.vim/swapfiles
if [[ ! -d ${SWAP_DIR} ]]; then
    echo "[INFO] Creating ${SWAP_DIR} ..."
    mkdir -p ${SWAP_DIR}
else
    echo "[INFO] ${SWAP_DIR} already exists"
fi

#Install vim plug
VIM_PLUG_LOCATION=~/.vim/autoload/plug.vim
if [ ! -f ${VIM_PLUG_LOCATION} ]; then
    echo "[INFO] Installing vim plug ..."
    curl -fLo ${VIM_PLUG_LOCATION} --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
    if [ $? -ne 0]; then
        echo "[ERROR] Failed to install vim plug."
        exit 1
    fi
else
    echo "[INFO] vim plug is already installed."
fi

#Setup .vimrc
if [ -f .vimrc ]; then
    echo "[WARNING] .vimrc file already exists. This will be overwritten."
    read -p "Do you wish to continue? (y/n): " confirm
    if [ $confirm != "y" ]; then
        exit 1
    fi
    echo "[INFO] removing existing .vimrc ..."
    rm .vimrc
fi
echo "[INFO] Downloading remote .vimrc ..."
wget https://raw.githubusercontent.com/joautor/lab/main/vim-training/.vimrc
if [ $? -ne 0 ]; then
    echo "[ERROR] unable to download .vimrc"
    exit 1
fi

echo "[INFO] Installing vim plugins..."
vim +'PlugInstall --sync' +qa

cd -
echo "[INFO] Setup completed."

