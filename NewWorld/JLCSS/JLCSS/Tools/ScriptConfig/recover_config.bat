@echo off
if {%1} == {?} goto helpinfo
if {%1} == {help} goto helpinfo
if not {%1} == {} goto paramerror






rem # ---------------------------------- 
rem # DHCP 分配器配置       
rem # ---------------------------------- 
netsh routing ip autodhcp uninstall > "%~dp0Log.txt"

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
rem # 路由和远程访问 配置                  
rem # ---------------------------------- 
sc stop remoteaccess >> "%~dp0Log.txt"
sc config remoteaccess start= disabled >> "%~dp0Log.txt"

rem # 路由和远程访问 配置结束





goto end

:helpinfo
echo 用法：%~n0
echo 参数：无
echo 示例：%~n0
goto end

:paramerror
echo 参数错误
echo 请使用%~n0 help命令查看帮助信息

:end