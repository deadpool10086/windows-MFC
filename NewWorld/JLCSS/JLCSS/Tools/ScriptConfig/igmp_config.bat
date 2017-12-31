@echo off
if not {%3} == {} goto paramerror
if {%1} == {?} goto helpinfo
if {%1} == {help} goto helpinfo





rem # ---------------------------------- 
rem # ·�ɺ�Զ�̷��� ����                  
rem # ---------------------------------- 
sc config remoteaccess start= demand > "%~dp0Log.txt"
sc start remoteaccess >> "%~dp0Log.txt"

rem # ·�ɺ�Զ�̷��� ���ý���



rem # ---------------------------------- 
rem # DHCP ����������       
rem # ---------------------------------- 
netsh routing ip autodhcp uninstall >> "%~dp0Log.txt"

rem # DHCP ���������ý���



rem # ---------------------------------- 
rem # DNS ��������            
rem # ---------------------------------- 
netsh routing ip dnsproxy uninstall >> "%~dp0Log.txt"

rem # DNS �������ý���



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
rem # IGMP ����                 
rem # ---------------------------------- 
rem netsh routing ip igmp uninstall

rem # ���� IGMP Э��!
if {%1} == {} netsh routing ip igmp install & netsh routing ip igmp set global loglevel = ERROR & goto end

rem # ��ʾ����!
if {%1} == {showgrouptable} netsh routing ip igmp show grouptable & goto end

rem # Ϊ  "�������� 1" �ӿ����õ� Igmp ·��
if {%2} == {route} netsh routing ip igmp delete interface name=%1 & netsh routing ip igmp add interface name=%1 igmpprototype=IGMPRTRV2 ifenabled=enable robustvar=2 startupquerycount=2 startupqueryinterval=31 genqueryinterval=125 genqueryresptime=10 lastmemquerycount=2 lastmemqueryinterval=1000 accnonrtralertpkts=YES & goto end

rem # Ϊ  "�������� 2" �ӿ����õ� Igmp ����
if {%2} == {proxy} netsh routing ip igmp delete interface name=%1 & netsh routing ip igmp add interface name=%1 igmpprototype=IGMPPROXY ifenabled=enable & goto end

if not {%2} == {proxy} goto paramerror

rem # IGMP ���ý���





goto end

:helpinfo
echo �÷���%~n0 [interfacename {route^|proxy}^|showgrouptable]
echo ������help		-��ʾ������Ϣ
echo       interfacename	-�������ӵ�����
echo       route^|proxy	-���ӿ�����ΪIGMP·����^|���ӿ�����ΪIGMP����
echo       showgrouptable	-��ʾ����
echo ʾ��(����IGMPЭ��)          ��%~n0
echo ʾ��(��ʾ����)            ��%~n0  showgrouptable
echo ʾ��(���ӿ�����ΪIGMP·����)��%~n0 "��������" route
echo ʾ��(���ӿ�����ΪIGMP����)  ��%~n0 "��������" proxy
goto end

:paramerror
echo ��������
echo ��ʹ��%~n0 help����鿴������Ϣ

:end