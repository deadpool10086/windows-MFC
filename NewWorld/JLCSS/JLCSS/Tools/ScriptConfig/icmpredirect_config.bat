@echo off
if not {%2} == {} goto paramerror
if {%1} == {?} goto helpinfo
if {%1} == {help} goto helpinfo
if {%1} == {} goto paramerror





echo Windows Registry Editor Version 5.00 > "%~dp0icmpredirect.reg"
echo [HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters] >> "%~dp0icmpredirect.reg"
if {%1} == {enable} echo "EnableICMPRedirect"=dword:00000001 >> "%~dp0icmpredirect.reg" & goto regedit
if {%1} == {disable} echo "EnableICMPRedirect"=dword:00000000 >> "%~dp0icmpredirect.reg" & goto regedit
if not {%1} == {disable} goto paramerror

:regedit
regedit /s "%~dp0icmpredirect.reg"





goto end

:helpinfo
echo 用法：%~n0 {enable^|disable}
echo 参数：enable	启用ICMP重定向功能
echo       disable	禁用ICMP重定向功能
echo 示例(启用ICMP重定向)：%~n0 enable
echo 示例(禁用ICMP重定向)：%~n0 enable
goto end

:paramerror
echo 参数错误
echo 请使用%~n0 help命令查看帮助信息

:end