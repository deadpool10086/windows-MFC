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
echo �÷���%~n0 {enable^|disable}
echo ������enable	����ICMP�ض�����
echo       disable	����ICMP�ض�����
echo ʾ��(����ICMP�ض���)��%~n0 enable
echo ʾ��(����ICMP�ض���)��%~n0 enable
goto end

:paramerror
echo ��������
echo ��ʹ��%~n0 help����鿴������Ϣ

:end