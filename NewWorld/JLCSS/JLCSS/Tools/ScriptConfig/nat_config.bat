@echo off
if {%1} == {?} goto helpinfo
if {%1} == {help} goto helpinfo
if not {%8} == {} goto paramerror





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
netsh routing ip igmp uninstall >> "%~dp0Log.txt"

rem # IGMP ���ý���



rem # ---------------------------------- 
rem # NAT ����                  
rem # ---------------------------------- 
rem netsh routing ip nat uninstall
echo "OK"
rem # ���� NAT ����!
if {%1} == {} netsh routing ip nat install & netsh routing ip nat set global tcptimeoutmins=1440 udptimeoutmins=1 loglevel=ERROR & goto end
echo "OK"
rem # Ϊ  "�������� 1" �ӿڵ� NAT ����(ר�ýӿ����ӵ�ר������)
if {%2} == {private} netsh routing ip nat add interface name=%1 mode=%2 & goto end

rem # Ϊ  "�������� 2" �ӿڵ� NAT ����(���ýӿ����ӵ�Internet)
if {%2} == {full} netsh routing ip nat add interface name=%1 mode=%2 & goto end

rem # Ϊ  "�������� 2" �ӿڵ�ַ�����IP��
if {%2} == {addrpool} netsh routing ip nat add addressrange name=%1 start=%3 end=%4 mask=%5 & goto end

rem # Ϊ  "�������� 2" �ӿ���Ӷ˿�ӳ��
if {%2} == {portmap} goto natportmap
if not {%2} == {portmap} goto paramerror
:natportmap

if {%3} == {tcp} netsh routing ip nat add portmapping name=%1 proto=TCP publicip=%4 publicport=%5 privateip=%6 privateport=%7 & goto end
if {%3} == {udp} netsh routing ip nat add portmapping name=%1 proto=UDP publicip=%4 publicport=%5 privateip=%6 privateport=%7 & goto end

goto paramerror

rem # NAT ���ý���





goto end

:helpinfo
echo �÷���%~n0 [interfacename {private^|full^|addrpool beginip endip mask^|portmap {tcp^|udp} publicip publicport privateip privateport}]
echo ������help		-��ʾ������Ϣ
echo       interfacename	-�������ӵ�����
echo       private		-������������ר�ýӿ����ӵ�ר������
echo       full		-�����������ǹ��ýӿ����ӵ�Internet
echo       addrpool		-�ڵ�ַ������ӽӿ�
echo               		-�˲���ֻ��Ӧ����interfacename�����ýӿ����ӵ�Internet
echo       beginip		-��ַ����ʼIP��ַ
echo       endip		-��ַ�ؽ���IP��ַ
echo       mask		-�ӿ�����
echo       portmap		-��Ӷ˿�ӳ��
echo       tcp^|udp		-�˿�ӳ���Э��
echo       publicip		-����IP��ַ
echo               		-0.0.0.0����interfacename�ϵ�����IP��ַ
echo       publicport	-�����˿�
echo       privateip		-˽��IP��ַ
echo       privateport	-˽�ж˿�
echo ʾ��(����NAT����)           ��%~n0
echo ʾ��(ר�ýӿ����ӵ�ר������)��%~n0 "��������" private
echo ʾ��(���ýӿ����ӵ�Internet)��%~n0 "��������" full
echo ʾ��(�ڹ��ýӿڵ�ַ�����IP)��%~n0 "��������" addrpool 202.98.0.36 202.98.0.50 255.255.255.0
echo ʾ��(�ڹ��ýӿ���Ӷ˿�ӳ��)��%~n0 "��������" portmap tcp 202.98.0.45 80 172.16.0.40 8080
goto end

:paramerror
echo ��������
echo ��ʹ��%~n0 help����鿴������Ϣ

:end