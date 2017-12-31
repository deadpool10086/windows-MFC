@echo off
if not {%6} == {} goto paramerror
if {%1} == {?} goto helpinfo
if {%1} == {help} goto helpinfo





rem # ---------------------------------- 
rem # 路由和远程访问 配置                  
rem # ---------------------------------- 
sc config remoteaccess start= demand > "%~dp0Log.txt"
sc start remoteaccess >> "%~dp0Log.txt"

rem # 路由和远程访问 配置结束



rem # ---------------------------------- 
rem # DHCP 分配器配置       
rem # ---------------------------------- 
netsh routing ip autodhcp uninstall >> "%~dp0Log.txt"

rem # DHCP 分配器配置结束



rem # ---------------------------------- 
rem # DNS 代理配置            
rem # ---------------------------------- 
netsh routing ip dnsproxy uninstall >> "%~dp0Log.txt"

rem # DNS 代理配置结束



rem # ---------------------------------- 
rem # IGMP 配置                 
rem # ---------------------------------- 
netsh routing ip igmp uninstall >> "%~dp0Log.txt"

rem # IGMP 配置结束



rem # ---------------------------------- 
rem # NAT 配置                  
rem # ---------------------------------- 
netsh routing ip nat uninstall >> "%~dp0Log.txt"

rem # NAT 配置结束



rem # ---------------------------------- 
rem # RIP 配置                 
rem # ---------------------------------- 
netsh routing ip rip uninstall >> "%~dp0Log.txt"

rem # RIP 配置结束



rem # ---------------------------------- 
rem # DHCP 中继代理配置    
rem # ---------------------------------- 
netsh routing ip relay uninstall >> "%~dp0Log.txt"

rem # DHCP 中继配置结束



rem # ---------------------------------- 
rem # OSPF 配置                  
rem # ---------------------------------- 
rem netsh routing ip ospf uninstall

rem # 启动 OSPF 协议!
if {%1} == {routerid} netsh routing ip ospf install & netsh routing ip ospf set global routerid=%2 asborder=NO loglevel=ERROR & goto end

rem # 显示邻居列表!
if {%1} == {showneighbor} netsh routing ip ospf show neighbor & goto end

rem # 显示区域信息!
if {%1} == {showarea} netsh routing ip ospf show areastats & goto end

rem # 显示链路状态数据库信息!
if {%1} == {showlsdb} netsh routing ip ospf show lsdb & goto end

rem # 添加区域！
if {%1} == {area} netsh routing ip ospf add area areaid=%2 & netsh routing ip ospf set area areaid=%2 auth=PASSWORD stubarea=NO metric=1 sumadv=NO & netsh routing ip ospf add range areaid=%2 range=%3 %4 & goto end

rem # 添加接口!
if {%1} == {interface} netsh routing ip ospf add interface name=%2 area=%3 addr=%4 mask=%5 & netsh routing ip ospf set interface name=%2 state=enable area=%3 type=BROADCAST prio=1 transdelay=1 retrans=5 hello=10 dead=40 poll=120 metric=2 mtu=1500 & netsh routing ip ospf set interface name=%2 password=12345678 & goto end

if not {%1} == {interface} goto paramerror

rem # OSPF 配置结束

	
goto end

:helpinfo
echo 用法：%~n0 [routerid RidValue^|showneighbor^|showarea^|showlsdb^|area areaid ipaddress submask^| interface interfacename areaid ipaddress submask ]
echo 参数：help		-显示帮助信息
echo       routerid		-添加路由器ID
echo       RidValue		-路由器ID的值
echo       showneighbor	-显示邻居信息
echo       showarea		-显示区域信息
echo       showlsdb		-显示链路状态数据库信息
echo       area		-添加区域
echo       areaid		-区域ID
echo       ipaddress		-IP地址
echo       submask		-子网掩码
echo       interface		-添加新接口
echo       interfacename	-接口名称
    
echo 示例(启动OSPF协议)		：%~n0 routerid 111.111.111.111
echo 示例(显示邻居列表)		：%~n0 showneighbor
echo 示例(显示区域信息)		：%~n0 showarea
echo 示例(显示链路状态数据库信息)	：%~n0 showlsdb
echo 示例(添加区域)			：%~n0 area 0.0.0.0 172.16.0.0 255.255.255.0
echo 示例(添加接口)			：%~n0 interface "本地连接" 0.0.0.0 172.16.0.1 255.255.255.0 

goto end

:paramerror
echo 参数错误
echo 请使用%~n0 help命令查看帮助信息

:end



