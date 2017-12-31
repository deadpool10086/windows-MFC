@echo off
if not {%4} == {} goto paramerror
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
rem netsh routing ip rip uninstall

rem # ���� Rip Э��!
if {%1} == {} netsh routing ip rip install & netsh routing ip rip set global loglevel=ERROR mintrig=5 peermode=disable & goto end

rem # ��ʾ�ھ��б�!
if {%1} == {showneighbor} netsh routing ip rip show neighbor & goto end

rem # Ϊ "�������� 1" �ӿ�����(����/����) Rip Э��!
if {%2} == {enable} netsh routing ip rip delete interface name=%1 & netsh routing ip rip add interface name=%1 & netsh routing ip rip set interface name=%1 metric=1 updatemode=PERIODIC announce=RIP1COMPAT accept=RIP1COMPAT expire=180 remove=120 update=30 authmode=AUTHNONE tag=0 unicast=disable accfiltmode=disable annfiltmode=disable & netsh routing ip rip set flags name=%1 flag=SplitHorizon,PoisonReverse,TriggeredUpdates,CleanupUpdates,NoSubnetSummary & goto end
if {%2} == {disable} netsh routing ip rip delete interface name=%1 & goto end

rem # Ϊ "�������� 1" �ӿ��������ڹ�����!
if {%2} == {updatetime} netsh routing ip rip set interface name=%1 update=%3 & goto end

rem # Ϊ "�������� 1" �ӿ�����·�ɹ���ʱ��!
if {%2} == {expiretime} netsh routing ip rip set interface name=%1 expire=%3 & goto end

rem # Ϊ "�������� 1" �ӿ���������!
if {%2} == {password} netsh routing ip rip set interface name=%1 authmode=authsimplepassword password=%3 & goto end

rem # Ϊ "�������� 1" �ӿ�����·ˮƽ�ָ�/������ת!
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

rem # RIP ���ý���





goto end

:helpinfo
echo �÷���%~n0 [interfacename {{enable^|disable}^|{updatetime^|expiretime} times^|{splithorizon^|poisonreverse} {enable^|disable}}^|showneighbor^|password pswvalue]
echo ������help		-��ʾ������Ϣ
echo       interfacename	-�������ӵ�����
echo       showneighbor	-��ʾ�ھ��б�
echo       updatetime	-�������ڹ���ʱ��
echo       expiretime	-����·�ɹ���ʱ��
echo       times		-ʱ��ֵ(��λ��)
echo       splithorizon	-ˮƽ�ָ�
echo       poisonreverse	-������ת
echo       enable		-ʹ��Ч
echo       disable		-ʹ����
echo       password		-���������֤
echo       pswvalue		-����      
echo ʾ��(����RIPЭ��)		��%~n0
echo ʾ��(��ʾ�ھ��б�)		��%~n0 showneighbor
echo ʾ��(��ĳ�ӿ���ʹ��RIPЭ��)	��%~n0 "�������� 1" enable
echo ʾ��(��ĳ�ӿ��Ͻ���RIPЭ��)	��%~n0 "�������� 1" disable
echo ʾ��(����ĳ�ӿ��ϵ����ڹ�����)��%~n0 "�������� 1" updatetime 30
echo ʾ��(����ĳ�ӿ��ϵ�·�ɹ���ʱ��)��%~n0 "�������� 1" expiretime 180
echo ʾ��(��ĳ�ӿ��ϵ�����ˮƽ�ָ�)	��%~n0 "�������� 1" splithorizon enable
echo ʾ��(��ĳ�ӿ��ϵĽ���ˮƽ�ָ�)	��%~n0 "�������� 1" splithorizon disable
echo ʾ��(��ĳ�ӿ��ϵ����ö�����ת)	��%~n0 "�������� 1" poisonreverse enable
echo ʾ��(��ĳ�ӿ��ϵĽ��ö�����ת)	��%~n0 "�������� 1" poisonreverse disable
echo ʾ��(��ĳ�ӿ������������֤)	��%~n0 "�������� 1" password 1234
goto end

:paramerror
echo ��������
echo ��ʹ��%~n0 help����鿴������Ϣ

:end