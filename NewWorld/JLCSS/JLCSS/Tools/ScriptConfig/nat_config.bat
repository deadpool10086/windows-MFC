@echo off
if {%1} == {?} goto helpinfo
if {%1} == {help} goto helpinfo
if not {%8} == {} goto paramerror





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
netsh routing ip igmp uninstall >> "%~dp0Log.txt"

rem # IGMP 配置结束



rem # ---------------------------------- 
rem # NAT 配置                  
rem # ---------------------------------- 
rem netsh routing ip nat uninstall
echo "OK"
rem # 启动 NAT 服务!
if {%1} == {} netsh routing ip nat install & netsh routing ip nat set global tcptimeoutmins=1440 udptimeoutmins=1 loglevel=ERROR & goto end
echo "OK"
rem # 为  "本地连接 1" 接口的 NAT 配置(专用接口连接到专用网络)
if {%2} == {private} netsh routing ip nat add interface name=%1 mode=%2 & goto end

rem # 为  "本地连接 2" 接口的 NAT 配置(公用接口连接到Internet)
if {%2} == {full} netsh routing ip nat add interface name=%1 mode=%2 & goto end

rem # 为  "本地连接 2" 接口地址池添加IP地
if {%2} == {addrpool} netsh routing ip nat add addressrange name=%1 start=%3 end=%4 mask=%5 & goto end

rem # 为  "本地连接 2" 接口添加端口映射
if {%2} == {portmap} goto natportmap
if not {%2} == {portmap} goto paramerror
:natportmap

if {%3} == {tcp} netsh routing ip nat add portmapping name=%1 proto=TCP publicip=%4 publicport=%5 privateip=%6 privateport=%7 & goto end
if {%3} == {udp} netsh routing ip nat add portmapping name=%1 proto=UDP publicip=%4 publicport=%5 privateip=%6 privateport=%7 & goto end

goto paramerror

rem # NAT 配置结束





goto end

:helpinfo
echo 用法：%~n0 [interfacename {private^|full^|addrpool beginip endip mask^|portmap {tcp^|udp} publicip publicport privateip privateport}]
echo 参数：help		-显示帮助信息
echo       interfacename	-网络连接的名称
echo       private		-此网络连接是专用接口连接到专用网络
echo       full		-此网络连接是公用接口连接到Internet
echo       addrpool		-在地址池中添加接口
echo               		-此参数只能应用在interfacename代表公用接口连接到Internet
echo       beginip		-地址池起始IP地址
echo       endip		-地址池结束IP地址
echo       mask		-接口掩码
echo       portmap		-添加端口映射
echo       tcp^|udp		-端口映射的协议
echo       publicip		-公用IP地址
echo               		-0.0.0.0代表interfacename上的所有IP地址
echo       publicport	-公共端口
echo       privateip		-私有IP地址
echo       privateport	-私有端口
echo 示例(启动NAT服务)           ：%~n0
echo 示例(专用接口连接到专用网络)：%~n0 "本地连接" private
echo 示例(公用接口连接到Internet)：%~n0 "本地连接" full
echo 示例(在公用接口地址池添加IP)：%~n0 "本地连接" addrpool 202.98.0.36 202.98.0.50 255.255.255.0
echo 示例(在公用接口添加端口映射)：%~n0 "本地连接" portmap tcp 202.98.0.45 80 172.16.0.40 8080
goto end

:paramerror
echo 参数错误
echo 请使用%~n0 help命令查看帮助信息

:end