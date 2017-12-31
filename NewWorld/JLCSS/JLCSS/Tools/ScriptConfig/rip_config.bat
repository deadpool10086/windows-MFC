@echo off
if not {%4} == {} goto paramerror
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
rem netsh routing ip rip uninstall

rem # 启动 Rip 协议!
if {%1} == {} netsh routing ip rip install & netsh routing ip rip set global loglevel=ERROR mintrig=5 peermode=disable & goto end

rem # 显示邻居列表!
if {%1} == {showneighbor} netsh routing ip rip show neighbor & goto end

rem # 为 "本地连接 1" 接口配置(启动/禁用) Rip 协议!
if {%2} == {enable} netsh routing ip rip delete interface name=%1 & netsh routing ip rip add interface name=%1 & netsh routing ip rip set interface name=%1 metric=1 updatemode=PERIODIC announce=RIP1COMPAT accept=RIP1COMPAT expire=180 remove=120 update=30 authmode=AUTHNONE tag=0 unicast=disable accfiltmode=disable annfiltmode=disable & netsh routing ip rip set flags name=%1 flag=SplitHorizon,PoisonReverse,TriggeredUpdates,CleanupUpdates,NoSubnetSummary & goto end
if {%2} == {disable} netsh routing ip rip delete interface name=%1 & goto end

rem # 为 "本地连接 1" 接口设置周期公告间隔!
if {%2} == {updatetime} netsh routing ip rip set interface name=%1 update=%3 & goto end

rem # 为 "本地连接 1" 接口设置路由过期时间!
if {%2} == {expiretime} netsh routing ip rip set interface name=%1 expire=%3 & goto end

rem # 为 "本地连接 1" 接口设置密码!
if {%2} == {password} netsh routing ip rip set interface name=%1 authmode=authsimplepassword password=%3 & goto end

rem # 为 "本地连接 1" 接口设置路水平分割/毒性逆转!
if {%2} == {splithorizon} goto splhor
if {%2} == {poisonreverse} goto poirev
if not {%2} == {poisonreverse} goto paramerror

:splhor
if {%3} == {enable} netsh routing ip rip set flags name=%1 flag=clear & netsh routing ip rip set flags name=%1 flag=SplitHorizon,PoisonReverse,TriggeredUpdates,CleanupUpdates,NoSubnetSummary & goto end
if {%3} == {disable} netsh routing ip rip set flags name=%1 flag=clear & netsh routing ip rip set flags name=%1 flag=TriggeredUpdates,CleanupUpdates,NoSubnetSummary & goto end
if not {%3} == {disable} goto paramerror

:poirev
if {%3} == {enable} netsh routing ip rip set flags name=%1 flag=clear & netsh routing ip rip set flags name=%1 flag=SplitHorizon,PoisonReverse,TriggeredUpdates,CleanupUpdates,NoSubnetSummary & goto end
if {%3} == {disable} netsh routing ip rip set flags name=%1 flag=clear & netsh routing ip rip set flags name=%1 flag=SplitHorizon,TriggeredUpdates,CleanupUpdates,NoSubnetSummary & goto end
if not {%3} == {disable} goto paramerror

rem # RIP 配置结束





goto end

:helpinfo
echo 用法：%~n0 [interfacename {{enable^|disable}^|{updatetime^|expiretime} times^|{splithorizon^|poisonreverse} {enable^|disable}}^|showneighbor^|password pswvalue]
echo 参数：help		-显示帮助信息
echo       interfacename	-网络连接的名称
echo       showneighbor	-显示邻居列表
echo       updatetime	-设置周期公告时间
echo       expiretime	-设置路由过期时间
echo       times		-时间值(单位秒)
echo       splithorizon	-水平分割
echo       poisonreverse	-毒性逆转
echo       enable		-使生效
echo       disable		-使禁用
echo       password		-启用身份验证
echo       pswvalue		-密码      
echo 示例(启动RIP协议)		：%~n0
echo 示例(显示邻居列表)		：%~n0 showneighbor
echo 示例(在某接口上使用RIP协议)	：%~n0 "本地连接 1" enable
echo 示例(在某接口上禁用RIP协议)	：%~n0 "本地连接 1" disable
echo 示例(设置某接口上的周期公告间隔)：%~n0 "本地连接 1" updatetime 30
echo 示例(设置某接口上的路由过期时间)：%~n0 "本地连接 1" expiretime 180
echo 示例(在某接口上的启用水平分割)	：%~n0 "本地连接 1" splithorizon enable
echo 示例(在某接口上的禁用水平分割)	：%~n0 "本地连接 1" splithorizon disable
echo 示例(在某接口上的启用毒性逆转)	：%~n0 "本地连接 1" poisonreverse enable
echo 示例(在某接口上的禁用毒性逆转)	：%~n0 "本地连接 1" poisonreverse disable
echo 示例(在某接口上启用身份验证)	：%~n0 "本地连接 1" password 1234
goto end

:paramerror
echo 参数错误
echo 请使用%~n0 help命令查看帮助信息

:end