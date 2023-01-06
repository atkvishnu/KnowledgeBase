set nocompatible

set encoding=utf-8

set autowrite

set tabstop=4

set mouse+=a

syntax on

set term=screen-256color
set t_ut=
set background=dark

set number

set ruler

set showmatch

set norelativenumber

set hlsearch
set incsearch
set linebreak


" Install DoxygenToolkit from http://www.vim.org/scripts/script.php?script_id=987
let g:DoxygenToolkit_authorName="Kumar Vishnu <kumarvishnu@logiq.ai>"


" Polyglot Individual language packs can be disabled from here!
" let g:polyglot_disabled = ['markdown']

" Specify a directory for plugins
" only load plugins if Plug detected
" github.com/junegunn/vim-plug
call plug#begin()

" A small sensible vim config.
Plug 'tpope/vim-sensible'

" Polyglot is a collection of language packs for Vim
Plug 'sheerun/vim-polyglot'
" vim-pandoc provides pandoc document converter, allows us to work with documents written in its markdown variant
Plug 'vim-pandoc/vim-pandoc'
" NERDTree is a file system explorer for the Vim editor  https://vimawesome.com/plugin/nerdtree-red
Plug 'scrooloose/nerdtree'
" Lean & mean status/tabline   https://vimawesome.com/plugin/vim-airline-superman
Plug 'vim-airline/vim-airline'
" Seamless navigation between tmux panes and vim splits
" Plug 'christoomey/vim-tmux-navigator'
" fuzzy finder  https://vimawesome.com/plugin/fzf
Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plug 'wakatime/vim-wakatime'
Plug 'morhetz/gruvbox'

Plug 'junegunn/goyo.vim', { 'for': 'markdown' }

" Using a tagged release; wildcard allowed (requires git 1.9.2 or above)
Plug 'fatih/vim-go', { 'tag': '*' }

" Plugin options
Plug 'nsf/gocode', { 'tag': 'v.20150303', 'rtp': 'vim' }


call plug#end()

autocmd vimenter * ++nested colorscheme gruvbox
autocmd! User goyo.vim echom 'Goyo is now loaded!'

" Use a line cursor within insert mode and a block cursor everywhere else.
" "
" " Reference chart of values:
" "   Ps = 0  -> blinking block.
" "   Ps = 1  -> blinking block (default).
" "   Ps = 2  -> steady block.
" "   Ps = 3  -> blinking underline.
" "   Ps = 4  -> steady underline.
" "   Ps = 5  -> blinking bar (xterm).
" "   Ps = 6  -> steady bar (xterm).
let &t_SI = "\e[5 q"
let &t_EI = "\e[1 q"

let mapleader = ","

nnoremap <leader>n :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTree<CR>
nnoremap <C-t> :NERDTreeToggle<CR>
nnoremap <C-f> :NERDTreeFind<CR>

nmap <F8> :TagbarToggle<CR>


au BufLeave ~/.vimrc :source ~/.vimrc


" stop complaints about switching buffer with changes
set hidden

set nowrap


