@echo off
if not {%3} == {} goto paramerror
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
rem # NAT 配置                  
rem # ---------------------------------- 
netsh routing ip nat uninstall >> "%~dp0Log.txt"

rem # NAT 配置结束



rem # ---------------------------------- 
rem # OSPF 配置                 
rem # ---------------------------------- 
netsh routing ip ospf uninstall >> "%~dp0Log.txt"

rem # OSPF 配置结束



rem # ---------------------------------- 
rem # DHCP 中继代理配置    
rem # ---------------------------------- 
netsh routing ip relay uninstall >> "%~dp0Log.txt"

rem # DHCP 中继配置结束



rem # ---------------------------------- 
rem # RIP 配置                  
rem # ---------------------------------- 
netsh routing ip rip uninstall >> "%~dp0Log.txt"

rem # RIP 配置结束



rem # ---------------------------------- 
rem # IGMP 配置                 
rem # ---------------------------------- 
rem netsh routing ip igmp uninstall

rem # 启动 IGMP 协议!
if {%1} == {} netsh routing ip igmp install & netsh routing ip igmp set global loglevel = ERROR & goto end

rem # 显示组表格!
if {%1} == {showgrouptable} netsh routing ip igmp show grouptable & goto end

rem # 为  "本地连接 1" 接口配置的 Igmp 路由
if {%2} == {route} netsh routing ip igmp delete interface name=%1 & netsh routing ip igmp add interface name=%1 igmpprototype=IGMPRTRV2 ifenabled=enable robustvar=2 startupquerycount=2 startupqueryinterval=31 genqueryinterval=125 genqueryresptime=10 lastmemquerycount=2 lastmemqueryinterval=1000 accnonrtralertpkts=YES & goto end

rem # 为  "本地连接 2" 接口配置的 Igmp 代理
if {%2} == {proxy} netsh routing ip igmp delete interface name=%1 & netsh routing ip igmp add interface name=%1 igmpprototype=IGMPPROXY ifenabled=enable & goto end

if not {%2} == {proxy} goto paramerror

rem # IGMP 配置结束





goto end

:helpinfo
echo 用法：%~n0 [interfacename {route^|proxy}^|showgrouptable]
echo 参数：help		-显示帮助信息
echo       interfacename	-网络连接的名称
echo       route^|proxy	-将接口配置为IGMP路由器^|将接口配置为IGMP代理
echo       showgrouptable	-显示组表格
echo 示例(启动IGMP协议)          ：%~n0
echo 示例(显示组表格)            ：%~n0  showgrouptable
echo 示例(将接口配置为IGMP路由器)：%~n0 "本地连接" route
echo 示例(将接口配置为IGMP代理)  ：%~n0 "本地连接" proxy
goto end

:paramerror
echo 参数错误
echo 请使用%~n0 help命令查看帮助信息

:end