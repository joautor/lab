let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/Desktop/playground/c++/others
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +13 foo.cpp
badd +8 ~/Desktop/playground/shell-scripting/account.sh
badd +1 ~/Desktop/playground/shell-scripting/functions.sh
badd +0 ~/Desktop/playground/shell-scripting/listMe.sh
badd +1 ~/Desktop/playground/python-stuff/sample.py
badd +9 ~/Desktop/playground/shell-scripting/mergeEm.sh
argglobal
silent! argdel *
$argadd foo.cpp
edit foo.cpp
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 102 + 102) / 204)
exe 'vert 2resize ' . ((&columns * 101 + 102) / 204)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 6 - ((5 * winheight(0) + 26) / 53)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
6
normal! 0
lcd ~/Desktop/playground/c++/others
wincmd w
argglobal
if bufexists('~/Desktop/playground/shell-scripting/mergeEm.sh') | buffer ~/Desktop/playground/shell-scripting/mergeEm.sh | else | edit ~/Desktop/playground/shell-scripting/mergeEm.sh | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 3 - ((2 * winheight(0) + 26) / 53)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
3
normal! 0
lcd ~/Desktop/playground/c++/others
wincmd w
exe 'vert 1resize ' . ((&columns * 102 + 102) / 204)
exe 'vert 2resize ' . ((&columns * 101 + 102) / 204)
tabnext 1
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOc
set winminheight=1 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
