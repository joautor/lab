call plug#begin('~/.vim/plugged')
Plug 'scrooloose/nerdtree'
Plug 'tpope/vim-surround'
Plug 'ctrlpvim/ctrlp.vim'
Plug 'mileszs/ack.vim'
Plug 'rking/ag.vim'
Plug 'bling/vim-airline'
Plug 'bling/vim-bufferline'
Plug 'kshenoy/vim-signature'
Plug 'altercation/vim-colors-solarized'
Plug 'ervandew/supertab'
Plug 'majutsushi/tagbar'
Plug 'scrooloose/syntastic'
" Plug 'valloric/YouCompleteMe'    "Requires vim version 8.2.3559+
Plug 'Shougo/vimproc.vim'
Plug 'plasticboy/vim-markdown'
Plug 'junegunn/fzf', { 'do': { -> fzf#install() }}
Plug 'junegunn/fzf.vim'
Plug 'bfrg/vim-cpp-modern'
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

" Syntastic plugin configuration
:let g:syntastic_cpp_compiler_options = ' -std=c++11 -stdlib=libc++'

"vim-airline configuration
let g:airline#extensions#tabline#enabled = 1

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
highlight ColorColumn ctermbg=black ctermfg=white

set list listchars=tab:>-,trail:.,extends:>
set list

set hlsearch
set laststatus=2

set syntax=on
syntax enable
set background=dark
hi Comment ctermfg=darkgray

set directory=~/.vim/swapfiles/
set backupdir=~/.vim/swapfiles/
set nowrap

set foldmethod=syntax
set foldlevel=99
highlight Folded ctermbg=black

"bfrg/vim-cpp-modern configuration

" Disable function highlighting (affects both C and C++ files)
let g:cpp_function_highlight = 1     "0

" Enable highlighting of C++11 attributes
let g:cpp_attributes_highlight = 1

" Highlight struct/class member variables (affects both C and C++ files)
let g:cpp_member_highlight = 1

" Put all standard C and C++ keywords under Vim's highlight group 'Statement'
" (affects both C and C++ files)
let g:cpp_simple_highlight = 1


function EnTab()
    set noexpandtab " Pressing tab will insert tab char
endfunction

function NoTab()
    set expandtab   " Pressing tab will insert spaces instead of tab
endfunction
