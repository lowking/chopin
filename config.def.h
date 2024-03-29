/* See LICENSE file for copyright and license details. */
// config.def.h

/* Author: lorenzo */
/* E-mail: lorenzo<zetatez@icloud.com> */

#include <stdbool.h>
#include <stdlib.h>

struct KFV {
    const char *key;
    bool flag;
    const char *value;
};

struct KV {
    const char *key;
    const char *value;
};

/* open rules */
static const struct KFV open_map[] = {
    /* .ext  , &    , application        */
    {".cbr"  , 1    , "zathura"          } ,
    {".cbz"  , 1    , "zathura"          } ,
    {".djvu" , 1    , "evince"           } ,
    {".epub" , 1    , "foliate"          } ,
    {".mobi" , 1    , "okularr"          } ,
    {".pdf"  , 1    , "zathura"          } ,
    {".doc"  , 1    , "wps"              } ,
    {".docm" , 1    , "wps"              } ,
    {".docx" , 1    , "wps"              } ,
    {".dot"  , 1    , "wps"              } ,
    {".dotx" , 1    , "wps"              } ,
    {".fodt" , 1    , "wps"              } ,
    {".odt"  , 1    , "wps"              } ,
    {".ott"  , 1    , "wps"              } ,
    {".rtf"  , 1    , "wps"              } ,
    {".uot"  , 1    , "wps"              } ,
    {".pptx" , 1    , "libreoffice"      } ,
    {".dbf"  , 1    , "wps"              } ,
    {".dif"  , 1    , "wps"              } ,
    {".fods" , 1    , "wps"              } ,
    {".ods"  , 1    , "wps"              } ,
    {".ots"  , 1    , "wps"              } ,
    {".slk"  , 1    , "wps"              } ,
    {".uos"  , 1    , "wps"              } ,
    {".xls"  , 1    , "wps"              } ,
    {".xlsm" , 1    , "wps"              } ,
    {".xlsx" , 1    , "wps"              } ,
    {".xlt"  , 1    , "wps"              } ,
    {".Z"    , 0    , "atool --list --"  } ,
    {".a"    , 0    , "atool --list --"  } ,
    {".ace"  , 0    , "atool --list --"  } ,
    {".alz"  , 0    , "atool --list --"  } ,
    {".arc"  , 0    , "atool --list --"  } ,
    {".arj"  , 0    , "atool --list --"  } ,
    {".bz"   , 0    , "atool --list --"  } ,
    {".bz2"  , 0    , "atool --list --"  } ,
    {".cab"  , 0    , "atool --list --"  } ,
    {".cpio" , 0    , "atool --list --"  } ,
    {".deb"  , 0    , "atool --list --"  } ,
    {".gz"   , 0    , "atool --list --"  } ,
    {".jar"  , 0    , "atool --list --"  } ,
    {".lha"  , 0    , "atool --list --"  } ,
    {".lz"   , 0    , "atool --list --"  } ,
    {".lzh"  , 0    , "atool --list --"  } ,
    {".lzma" , 0    , "atool --list --"  } ,
    {".lzo"  , 0    , "atool --list --"  } ,
    {".rpm"  , 0    , "atool --list --"  } ,
    {".rz"   , 0    , "atool --list --"  } ,
    {".t7z"  , 0    , "atool --list --"  } ,
    {".tZ"   , 0    , "atool --list --"  } ,
    {".tar"  , 0    , "atool --list --"  } ,
    {".tbz"  , 0    , "atool --list --"  } ,
    {".tbz2" , 0    , "atool --list --"  } ,
    {".tgz"  , 0    , "atool --list --"  } ,
    {".tlz"  , 0    , "atool --list --"  } ,
    {".txz"  , 0    , "atool --list --"  } ,
    {".tzo"  , 0    , "atool --list --"  } ,
    {".war"  , 0    , "atool --list --"  } ,
    {".xpi"  , 0    , "atool --list --"  } ,
    {".xz"   , 0    , "atool --list --"  } ,
    {".zip"  , 0    , "atool --list --"  } ,
    {".rar"  , 0    , "unrar -lt -p- --" } ,
    {".7z"   , 0    , "7z l -p- --"      } ,
    {".log"  , 0    , "tail -f -n 200"   } ,
    {".out"  , 0    , "tail -f -n 200"   } ,
    {".list" , 0    , "vim"              } ,
    {".json" , 0    , "vim"              }
};

/* open rules for rest */
static const struct KFV open_else_map[] = {
    /*mine     , &    , application                */
    {"image/*" , 1    , "sxiv"                     } , // sxiv , feh   , img2txt --gamma=0.5 , ..
    {"video/*" , 1    , "mpv --geometry=100%x100%" } , // mpv  , vlc   , ...
    {"audio/*" , 0    , "mpv"                      } , // mpv  , vlc   , ...
    {"text/*"  , 0    , "vim"                      } , // vim  , emacs ,
    {"inode/*" , 0    , "vim"                      }   // vim  , emacs , // inode/x-empty
};

/* exec rules */
static const struct KV exec_map[] = {
    /*.ext   , shell scripts                                                                                                                          */
    {".sh"   , "filename=%s; sh ${filename}"                                                                                                          },
    {".py"   , "filename=%s; python ${filename}"                                                                                                      },
    {".jl"   , "filename=%s; julia ${filename}"                                                                                                       },
    {".tex"  , "filename=%s; xelatex -interaction nonstopmode ${filename}; bibtex *.aux; xelatex -interaction nonstopmode ${filename}; zathura *.pdf" },
    {".c"    , "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".cpp"  , "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".go"   , "filename=%s; go run ${filename}"                                                                                                      },
    {".scala", "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".java" , "filename=%s; cd ${filename%.*}; sh build.sh"                                                                                          },
    {".rs"   , "filename=%s; cargo build && cargo run"                                                                                                },
    {".rb"   , "filename=%s; ruby ${filename}"                                                                                                        },
    {".lua"  , "filename=%s; lua ${filename}"                                                                                                         },
    {".js"   , "filename=%s; node ${filename}"                                                                                                        },
    {".ts"   , "filename=%s; tsc ${filename}"                                                                                                         },
    {".log"   , "filename=%s; vim ${filename}"                                                                                                        },
    {".out"   , "filename=%s; vim ${filename}"                                                                                                        },
    {".sql"  , "filename=%s; mysql -uroot -p < ${filename}"                                                                                           }
};

/* exec rules for rest */
static const struct KV exec_else_map[] = {
    /**   , shell scripts                  */
    {"*"  , "filename=%s; sh ${filename }" } // any excuteble file
};

/* default options for cp, mv, rm */
static const char *cp_opt           = "-fr"; // recommended "-ir"
static const char *mv_opt           = "-f";  // recommended "-i"
static const char *rm_opt           = "-fr"; // recommended "-ir"


