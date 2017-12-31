@echo off
if {%1} == {?} goto helpinfo
if {%1} == {help} goto helpinfo
if not {%1} == {} goto paramerror






rem # ---------------------------------- 
rem # DHCP ����������       
rem # ---------------------------------- 
netsh routing ip autodhcp uninstall > "%~dp0Log.txt"

rem # DHCP ���������ý���



rem # ---------------------------------- 
rem # DNS ��������            
rem # ---------------------------------- 
netsh routing ip dnsproxy uninstall >> "%~dp0Log.txt"

rem # DNS �������ý���



rem # ---------------------------------- 
rem # IGMP ����                 
rem # ---------------------------------- 
netsh routing ip igmp uninstall >> "%~dp0Log.txt"

rem # IGMP ���ý���



rem # ---------------------------------- 
rem # NAT ����                  
rem # ---------------------------------- 
netsh routing ip nat uninstall >> "%~dp0Log.txt"

rem # NAT ���ý���




rem # ---------------------------------- 
rem # OSPF ����                 
rem # ---------------------------------- 
netsh routing ip ospf uninstall >> "%~dp0Log.txt"

rem # OSPF ���ý���




rem # ---------------------------------- 
rem # DHCP �м̴�������    
rem # ---------------------------------- 
netsh routing ip relay uninstall >> "%~dp0Log.txt"

rem # DHCP �м����ý���



rem # ---------------------------------- 
rem # RIP ����                  
rem # ---------------------------------- 
netsh routing ip rip uninstall >> "%~dp0Log.txt"

rem # RIP ���ý���



rem # ---------------------------------- 
rem # ·�ɺ�Զ�̷��� ����                  
rem # ---------------------------------- 
sc stop remoteaccess >> "%~dp0Log.txt"
sc config remoteaccess start= disabled >> "%~dp0Log.txt"

rem # ·�ɺ�Զ�̷��� ���ý���





goto end

:helpinfo
echo �÷���%~n0
echo ��������
echo ʾ����%~n0
goto end

:paramerror
echo ��������
echo ��ʹ��%~n0 help����鿴������Ϣ

:end