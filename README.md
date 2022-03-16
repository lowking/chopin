chopin

# chopin

## Dependencies
- vim
- wps
- libreoffice
- zathura
- evince
- foliate
- okularr
- sxiv
- mpv
- 7z
- unrar
- atool

## Installation

```bash
git clone https://github.com/zetatez/chopin.git

cd chopin
sudo make clean install

# sudo make uninstall
```

## Usage
```bash
Usage: chopin [-vhoecmr] [FILE]
  -o, --open         open a file with your default setting automatically
  -e, --exec         exec a file with your default setting automatically
  -c, --cp           cp a file
  -m, --mv           mv a file
  -r, --rm           rm a file
  -h, --help         help
  -v, --version      version
```

- open a file
	```bash
	chopin -o file
	```

- exec a script
	```bash
	chopin -e file
	```

- cp a file
	```bash
	chopin -c file
	```

- mv a file
	```bash
	chopin -m file
	```

- rm a file
	```bash
	chopin -r file
	```

## Workflow: Search and Handle
What can `chopin` do when combined with `fd` and `fzf` ?

- fd  ->  fzf ->  chopin

[fd]: find a file list -> [fzf]: interactive filter -> [chopin]: open, exec, cp, mv, rm.

## Best Practice
- Add following lines to your `~/.zshrc` and try.
```zsh
# chopin open
alias chopin-open="chopin -o \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='open>' --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s '^F' 'chopin-open\n'

# chopin exec
alias chopin-exec="chopin -e \"\$(fd -e sh -e jl -e py -e tex -e c -e cpp -e go -e scala -e java -e rs -e sql . './'|fzf --prompt='exec>'  --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s '^X' 'chopin-exec\n'

# chopin cp
alias chopin-cp="chopin -c \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='cp>'  --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s "^N" 'chopin-cp\n'

# chopin mv
alias chopin-mv="chopin -m \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='mv>' --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s "^V" 'chopin-mv\n'

# chopin rm
alias chopin-rm="chopin -r \"\$(fd --type f --hidden --exclude .git . './'|fzf --prompt='rm>' --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s "^Z" 'chopin-rm\n'

# chopin open books
alias chopin-open-book="chopin -o \"\$(fd -e pdf -e epub -e djvu -e mobi --exclude ~/go . '$HOME'|fzf --prompt='books>' --reverse --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s '^P' 'chopin-open-book\n'

# chopin open wiki
alias chopin-open-wiki="chopin -o \"\$(fd --type f --hidden --exclude .git . '$HOME/wiki'|fzf --prompt='wikis>' --preview 'bat --color=always {}' --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s '^W' 'chopin-open-wiki\n'

# chopin open media
alias chopin-open-media="chopin -o \"\$(fd -e jpg -e jpeg -e png -e gif -e bmp -e tiff -e mp3 -e flac -e mkv -e avi -e mp4 . '$HOME'|fzf --prompt='medias>' --reverse --select-1 --exit-0|sed 's/ /\\ /g')\""
bindkey -s '^A' 'chopin-open-media\n'
```

## Configuration
```c
// see config.def.h

struct KV {
    char *key;
    char *value;
};

/* open rules */
static const struct KV open_map[] = {
    {".cbr"    , "zathura"},
    {".cbz"    , "zathura"},
    {".djvu"   , "evince"},
    {".epub"   , "foliate"},
    {".mobi"   , "okularr"},
    {".pdf"    , "zathura"},
    {".doc"    , "wps"},
    {".docm"   , "wps"},
    {".docx"   , "wps"},
    {".dot"    , "wps"},
    {".dotx"   , "wps"},
    {".fodt"   , "wps"},
    {".odt"    , "wps"},
    {".ott"    , "wps"},
    {".rtf"    , "wps"},
    {".uot"    , "wps"},
    {".pptx"   , "libreoffice"},
    {".dbf"    , "wps"},
    {".dif"    , "wps"},
    {".fods"   , "wps"},
    {".ods"    , "wps"},
    {".ots"    , "wps"},
    {".slk"    , "wps"},
    {".uos"    , "wps"},
    {".xls"    , "wps"},
    {".xlsm"   , "wps"},
    {".xlsx"   , "wps"},
    {".xlt"    , "wps"},
    {".Z"      , "atool --list --"},
    {".a"      , "atool --list --"},
    {".ace"    , "atool --list --"},
    {".alz"    , "atool --list --"},
    {".arc"    , "atool --list --"},
    {".arj"    , "atool --list --"},
    {".bz"     , "atool --list --"},
    {".bz2"    , "atool --list --"},
    {".cab"    , "atool --list --"},
    {".cpio"   , "atool --list --"},
    {".deb"    , "atool --list --"},
    {".gz"     , "atool --list --"},
    {".jar"    , "atool --list --"},
    {".lha"    , "atool --list --"},
    {".lz"     , "atool --list --"},
    {".lzh"    , "atool --list --"},
    {".lzma"   , "atool --list --"},
    {".lzo"    , "atool --list --"},
    {".rpm"    , "atool --list --"},
    {".rz"     , "atool --list --"},
    {".t7z"    , "atool --list --"},
    {".tZ"     , "atool --list --"},
    {".tar"    , "atool --list --"},
    {".tbz"    , "atool --list --"},
    {".tbz2"   , "atool --list --"},
    {".tgz"    , "atool --list --"},
    {".tlz"    , "atool --list --"},
    {".txz"    , "atool --list --"},
    {".tzo"    , "atool --list --"},
    {".war"    , "atool --list --"},
    {".xpi"    , "atool --list --"},
    {".xz"     , "atool --list --"},
    {".zip"    , "atool --list --"},
    {".rar"    , "unrar -lt -p- --"},
    {".7z"     , "7z l -p- --"},
    {".json"   , "vim"},
    {NULL      , NULL}
};

/* open rules for rest */
static const struct KV open_else_map[] = {
    {"image/*" , "sxiv"}                     , // sxiv , feh   , img2txt --gamma=0.5 , ..
    {"video/*" , "mpv --geometry=100%x100%"} , // mpv  , vlc   , ...
    {"audio/*" , "mpv"}                      , // mpv  , vlc   , ...
    {"text/*"  , "vim"}                      , // vim  , emacs ,
    {"inode/*" , "vim"}                      , // vim  , emacs ,                             // inode/x-empty
    {NULL      , NULL}
};

/* exec rules */
static const struct KV exec_map[] = {
    {".sh"    , "filename=%s; sh ${filename}"},
    {".py"    , "filename=%s; python ${filename}"},
    {".jl"    , "filename=%s; julia ${filename}"},
    {".tex"   , "filename=%s; xelatex -interaction nonstopmode ${filename}; bibtex ${filename%.*}.aux; xelatex -interaction nonstopmode ${filename}; zathura ${filename%.*}.pdf"},
    {".c"     , "filename=%s; cd ${filename%.*}; sh build.sh"},
    {".c+ "   , "filename=%s; cd ${filename%.*}; sh build.sh"},
    {".go"    , "filename=%s; go run ${filename}"},
    {".scala" , "filename=%s; scala ${filename}"},
    {".java"  , "filename=%s; javac ${filename}; java ${filename%.*}"},
    {".rs"    , "filename=%s; cargo build && cargo run"},
    {".rb"    , "filename=%s; ruby ${filename}"},
    {".lua"   , "filename=%s; lua ${filename}"},
    {".js"    , "filename=%s; node ${filename}"},
    {".ts"    , "filename=%s; tsc ${filename}"},
    {".sql"   , "filename=%s; mysql -uroot -p < ${filename}"},
    {NULL     , NULL}
};

/* exec rules for rest */
static const struct KV exec_else_map[] = {
    {"*"      , "filename=%s; sh ${filename}"},  // any excuteble file
    {NULL     , NULL}
};

/* default options for cp, mv, rm */
static const char *cp_opt           = "-fr"; // recommended "-ir"
static const char *mv_opt           = "-f";  // recommended "-i"
static const char *rm_opt           = "-fr"; // recommended "-ir"
```

## LICENSE

MIT.

