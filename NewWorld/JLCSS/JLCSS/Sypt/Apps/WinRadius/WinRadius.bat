@echo off

if exist D:\JLCSS\winTable-expPts\WinRadius.mdb (
    goto DBE
) else (
    goto DBNE
)

:DBNE

if exist D:\JLCSS\WinRadius\WinRadius.mdb (
    copy D:\JLCSS\WinRadius\WinRadius.mdb D:\JLCSS\winTable-expPts\WinRadius.mdb
) else (
    echo WinRadius.mdb NOT Exist! > D:\JLCSS\WinRadius\Log.txt
    echo Can not start WinRadius.exe! >> D:\JLCSS\WinRadius\Log.txt
    notepad D:\JLCSS\WinRadius\Log.txt
    goto END
)

:DBE

    D:\JLCSS\WinRadius\WinRadius.exe

:END

@echo on