@echo off
cl -O2 handmade.cpp user32.lib gdi32.lib
del *.obj *.lib *.ilk *.pdb