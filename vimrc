set noesckeys tabstop=2 shiftwidth=2 expandtab smartindent cindent clipboard+=unnamedplus relativenumber number title background=dark
vnoremap <C-r> "hy:$s/<C-r>h//gc<left><left><left>
nnoremap <cr> :noh<CR><CR>:<backspace>
autocmd BufNewFile *.cpp 0r ~/template.cpp
let &t_SI = "\<Esc>[5 q"
