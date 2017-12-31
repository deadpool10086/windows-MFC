@echo "clean file script !"
attrib -h -s -r +a .\resource\files\*
ren .\resource\files\player.htm  player._
ren .\resource\files\index.htm  index._
del .\resource\files\*.htm*
ren .\resource\files\player._ player.htm
ren .\resource\files\index._ index.htm

attrib -h -s -r +a .\resource\upload\*
del /F /Q .\resource\upload\* 

del .\config\UpdateList
del .\config\TimeDiff

@echo "clean is successed !"
pause
@echo .



