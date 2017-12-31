@echo off
if not {%6} == {} goto paramerror
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
rem # RIP ����                 
rem # ---------------------------------- 
netsh routing ip rip uninstall >> "%~dp0Log.txt"

rem # RIP ���ý���



rem # ---------------------------------- 
rem # DHCP �м̴�������    
rem # ---------------------------------- 
netsh routing ip relay uninstall >> "%~dp0Log.txt"

rem # DHCP �м����ý���



rem # ---------------------------------- 
rem # OSPF ����                  
rem # ---------------------------------- 
rem netsh routing ip ospf uninstall

rem # ���� OSPF Э��!
if {%1} == {routerid} netsh routing ip ospf install & netsh routing ip ospf set global routerid=%2 asborder=NO loglevel=ERROR & goto end

rem # ��ʾ�ھ��б�!
if {%1} == {showneighbor} netsh routing ip ospf show neighbor & goto end

rem # ��ʾ������Ϣ!
if {%1} == {showarea} netsh routing ip ospf show areastats & goto end

rem # ��ʾ��·״̬���ݿ���Ϣ!
if {%1} == {showlsdb} netsh routing ip ospf show lsdb & goto end

rem # �������
if {%1} == {area} netsh routing ip ospf add area areaid=%2 & netsh routing ip ospf set area areaid=%2 auth=PASSWORD stubarea=NO metric=1 sumadv=NO & netsh routing ip ospf add range areaid=%2 range=%3 %4 & goto end

rem # ��ӽӿ�!
if {%1} == {interface} netsh routing ip ospf add interface name=%2 area=%3 addr=%4 mask=%5 & netsh routing ip ospf set interface name=%2 state=enable area=%3 type=BROADCAST prio=1 transdelay=1 retrans=5 hello=10 dead=40 poll=120 metric=2 mtu=1500 & netsh routing ip ospf set interface name=%2 password=12345678 & goto end

if not {%1} == {interface} goto paramerror

rem # OSPF ���ý���

	
goto end

:helpinfo
echo �÷���%~n0 [routerid RidValue^|showneighbor^|showarea^|showlsdb^|area areaid ipaddress submask^| interface interfacename areaid ipaddress submask ]
echo ������help		-��ʾ������Ϣ
echo       routerid		-���·����ID
echo       RidValue		-·����ID��ֵ
echo       showneighbor	-��ʾ�ھ���Ϣ
echo       showarea		-��ʾ������Ϣ
echo       showlsdb		-��ʾ��·״̬���ݿ���Ϣ
echo       area		-�������
echo       areaid		-����ID
echo       ipaddress		-IP��ַ
echo       submask		-��������
echo       interface		-����½ӿ�
echo       interfacename	-�ӿ�����
    
echo ʾ��(����OSPFЭ��)		��%~n0 routerid 111.111.111.111
echo ʾ��(��ʾ�ھ��б�)		��%~n0 showneighbor
echo ʾ��(��ʾ������Ϣ)		��%~n0 showarea
echo ʾ��(��ʾ��·״̬���ݿ���Ϣ)	��%~n0 showlsdb
echo ʾ��(�������)			��%~n0 area 0.0.0.0 172.16.0.0 255.255.255.0
echo ʾ��(��ӽӿ�)			��%~n0 interface "��������" 0.0.0.0 172.16.0.1 255.255.255.0 

goto end

:paramerror
echo ��������
echo ��ʹ��%~n0 help����鿴������Ϣ

:end



