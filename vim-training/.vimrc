call plug#begin('~/.vim/plugged')
Plug 'scrooloose/nerdtree'
Plug 'ctrlpvim/ctrlp.vim'
Plug 'mileszs/ack.vim'
Plug 'rking/ag.vim'
Plug 'bling/vim-airline'
Plug 'kshenoy/vim-signature'
Plug 'ervandew/supertab'
Plug 'majutsushi/tagbar'
Plug 'scrooloose/syntastic'
" Plug 'valloric/YouCompleteMe'
Plug 'Shougo/vimproc.vim'
Plug 'plasticboy/vim-markdown'
call plug#end()

" Nerd Tree plugin configuration
let g:NERDTreeDirArrowExpandable = '+'
let g:NERDTreeDirArrowCollapsible = '~'
map <C-o> : NERDTreeToggle<CR>

" ctrlP plugin configuration
let g:ctrlp_working_path_mode = 'ra' 
let g:ctrlp_root_markers = ['.ctrlp']
let g:ctrlp_max_files=0
let g:ctrlp_custom_ignore = {
  \ 'dir':  '\v[\/]\.(git|hg|svn)$|(node_modules|REL.BIN)$|C_Test.*(tmp|logs)$',
  \ 'file': '\v\.(exe|so|dll|o)$',
  \ 'link': 'some_bad_symbolic_links',
  \ }


set expandtab
set shiftwidth=4
set softtabstop=4
set tabstop=4
set autoindent
set smartindent

set number
set rnu             " Line number relative to current cursor position
highlight LineNr ctermfg=darkgray
set colorcolumn=110
highlight ColorColumn ctermbg=black

set list listchars=tab:>-,trail:.,extends:>
set list

set hlsearch
set laststatus=2

set syntax=on
syntax enable
set background=dark

set directory=~/.vim/swapfiles/
set backupdir=~/.vim/swapfiles/
set nowrap

set foldmethod=syntax
set foldlevel=99
highlight Folded ctermbg=black

