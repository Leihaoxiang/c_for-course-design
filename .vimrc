"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"General
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
syntax on
set number
set encoding=utf-8
set ruler
set cul
set nocompatible
set autochdir
set autoread
set backspace=indent,eol,start 
set mouse=a

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"map leader
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let mapleader   = ","
let g:mapleader = ","


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"set ultisnips
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Trigger configuration. Do not use <tab> if you use
" https://github.com/Valloric/YouCompleteMe.
let g:UltiSnipsExpandTrigger="`"
let g:UltiSnipsJumpForwardTrigger="<c-b>"
let g:UltiSnipsJumpBackwardTrigger="<c-z>"

" If you want :UltiSnipsEdit to split your window.
let g:UltiSnipsEditSplit="vertical"

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Plugin
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'Valloric/YouCompleteMe'
Plugin 'davidhalter/jedi-vim'
Plugin 'taglist.vim'
Plugin 'scrooloose/nerdtree'
Plugin 'majutsushi/tagbar'
Plugin 'fholgado/minibufexpl.vim'
Plugin 'bling/vim-airline'
Plugin 'SirVer/ultisnips'
Plugin 'honza/vim-snippets'
Plugin 'scrooloose/syntastic'
call vundle#end()
filetype plugin indent on

let g:ycm_server_python_interpreter='/usr/bin/python'
let g:ycm_global_ycm_extra_conf='~/.vim/.ycm_extra_conf.py'


let g:ycm_autoclose_preview_window_after_completion=1
map <leader>g  :YcmCompleter GoToDefinitionElseDeclaration<CR>

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" space and tab and indent
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set autoindent
set smartindent
set tabstop=4    "  1 tab == 4 spaces
set shiftwidth=4 "  1 tab == 4 spaces
set expandtab    "  Use spaces instead of tabs
"" show ALL white spaces as dot
set listchars=trail:·
set list

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" set jedi
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"let g:jedi#goto_command            = "<leader>d"
let g:jedi#goto_assignments_command = "<leader>g"
let g:jedi#goto_definitions_command = "<leader>d"
let g:jedi#documentation_command    = "K"
let g:jedi#usages_command           = "<leader>n"
let g:jedi#completions_command      = "<C-Space>"
let g:jedi#rename_command           = "<leader>rname"

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"set nerdtree
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"F2开启和关闭树"
map <F2> :NERDTreeToggle<CR>
let NERDTreeChDirMode=1
""显示书签"
let NERDTreeShowBookmarks=1
"设置忽略文件类型"
let NERDTreeIgnore=['\~$', '\.pyc$', '\.swp$']
"窗口大小"
let NERDTreeWinSize=25

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"set tagbar
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let g:tagbar_ctags_bin='ctags'          "ctags程序的路径
let g:tagbar_width=25                   "窗口宽度的设置
map <F3> :Tagbar<CR>
autocmd BufReadPost *.cpp,*.c,*.h,*.hpp,*.cc,*.cxx call tagbar#autoopen()
"如果是c语言的程序的话，tagbar自动开启

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"set Minibufexpl.vim
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let g:miniBufExplMapWindowNavVim = 1   
let g:miniBufExplMapWindowNavArrows = 1   
let g:miniBufExplMapCTabSwitchBufs = 1   
let g:miniBufExplModSelTarget = 1  
let g:miniBufExplMoreThanOne=0

map <F9> :MBEbp<CR>
map <F10> :MBEbn<CR>

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"set vim-airline
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set laststatus=2

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" create new file: insert file head
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.rb,*.java,*.py exec ":call SetTitle()"
""function SetTitle
func SetTitle()
    if &filetype == 'sh'
        call setline(1,"\#!/bin/bash")
        call append(line("."), "")
    elseif &filetype == 'python'
        call setline(1,"#!/usr/bin/python3")
        call append(line("."),"# coding=utf-8")
        call append(line(".")+1, "")
    elseif &filetype == 'ruby'
        call setline(1,"#!/usr/bin/env ruby")
        call append(line("."),"# encoding: utf-8")
        call append(line(".")+1, "")
"    elseif &filetype == 'mkd'
"        call setline(1,"<head><meta charset=\"UTF-8\"></head>")
    else
        call setline(1, "/*************************************************************************") 
        call append(line("."), " > File Name: ".expand("%"))
        call append(line(".")+1, " > Author: ")
        call append(line(".")+2, " > Mail: ")
        call append(line(".")+3, " > Created Time: ".strftime("%c"))
        call append(line(".")+4, " ************************************************************************/") 
        call append(line(".")+5, "")
    endif
 
    if expand("%:e") == 'cpp'
        call append(line(".")+6, "#include<iostream>")
        call append(line(".")+7, "using namespace std;")
        call append(line(".")+8, "")
    endif
 
    if &filetype == 'c'
        call append(line(".")+6, "#include<stdio.h>")
        call append(line(".")+7, "")
    endif
 
    
    if expand("%:e") == 'h'
        call append(line(".")+6, "#ifndef _".toupper(expand("%:r"))."_H")
        call append(line(".")+7, "#define _".toupper(expand("%:r"))."_H")
        call append(line(".")+8, "#endif")
    endif

    if &filetype == 'java'
        call append(line(".")+6,"public class ".expand("%:r"))
        call append(line(".")+7,"")
    endif
 "after creating new file, go to the end of the file
 endfunc
 autocmd BufNewFile * normal G



 """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 " F5 compile and run
 """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
 map <F5> :call CompileRunGcc()<CR>
 func! CompileRunGcc()
  exec "w"
 if &filetype == 'c'
     exec "!g++ % -o %<"
     exec "!time ./%<"
 elseif &filetype == 'cpp'
     exec "!g++ % -o %<"
     exec "!time ./%<"
 elseif &filetype == 'java'
     exec "!javac %"
     exec "!time java %<"
 elseif &filetype == 'sh'
     exec "!time bash %"
 elseif &filetype == 'python'
     exec "!time python %"
 elseif &filetype == 'html'
     exec "!firefox % &"
 elseif &filetype == 'go'
"        exec "!go build %<"
     exec "!time go run %"
"    elseif &filetype == 'mkd'
"        exec "!~/.vim/markdown.pl % > %.html &"
"        exec "!firefox %.html &"
endif
endfunc

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => YouCompleteMe  代码自动补全
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" youcompleteme  默认tab  s-tab 和自动补全冲突
" let g:ycm_key_list_select_completion=['<c-n>']
" let g:ycm_key_list_select_completion = ['<Down>']
" let g:ycm_key_list_previous_completion=['<c-p>']
" let g:ycm_key_list_previous_completion = ['<Up>']
let g:ycm_confirm_extra_conf=0      " 关闭加载.ycm_extra_conf.py提示
let g:ycm_complete_in_comments = 1  "在注释输入中也能补全
let g:ycm_complete_in_strings = 1   "在字符串输入中也能补全
let g:ycm_collect_identifiers_from_tags_files=1                 " 开启 YCM 基于标签引擎
let g:ycm_collect_identifiers_from_comments_and_strings = 1   "注释和字符串中的文字也会被收入补全
let g:ycm_seed_identifiers_with_syntax=1   "语言关键字补全, 不过python关键字都很短，所以，需要的自己打开
let g:ycm_collect_identifiers_from_tags_files = 1
let g:ycm_min_num_of_chars_for_completion=1                     " 从第2个键入字符就开始罗列匹配项
" 引入，可以补全系统，以及python的第三方包 针对新老版本YCM做了兼容
" old version
if !empty(glob("~/.vim/bundle/YouCompleteMe/cpp/ycm/.ycm_extra_conf.py"))
    let g:ycm_global_ycm_extra_conf = "~/.vim/bundle/YouCompleteMe/cpp/ycm/.ycm_extra_conf.py"
endif
" new version
if !empty(glob("~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py"))
    let g:ycm_global_ycm_extra_conf = "~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py"
endif

"mapping
nmap <leader>gd :YcmDiags<CR>
nnoremap <leader>gl :YcmCompleter GoToDeclaration<CR>           " 跳转到申明处
nnoremap <leader>gf :YcmCompleter GoToDefinition<CR>            " 跳转到定义处
nnoremap <leader>gg :YcmCompleter GoToDefinitionElseDeclaration<CR>

" 直接触发自动补全
let g:ycm_key_invoke_completion = '<C-Space>'
" 黑名单,不启用
let g:ycm_filetype_blacklist = {
      \ 'tagbar' : 1,
      \ 'gitcommit' : 1,
      \}  
