set ROOT=c:\ultra
set gccdir=%ROOT%\gcc
set PATH=%ROOT%\gcc\mipse\bin;%ROOT%\usr\sbin
set gccsw=-mips3 -mgp32 -mfp32 -funsigned-char -D_LANGUAGE_C -D_ULTRA64 -D__EXTENSIONS__
set n64align=on
set GCC_CELF=ON

cd assets
cd sprites
call makeme.bat
cd ..
cd stages
call makeme.bat
cd ..
cd objects
call makeme.bat
cd ..
cd ..


make