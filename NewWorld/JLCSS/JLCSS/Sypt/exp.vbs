'+--------------------------------------------------+
'|			JLCSS ʵ��ƽ̨�����ű�					|
'|													|
'|			���ļ��������޸ģ�					|
'|													|
'|			2008-10-17								|
'+--------------------------------------------------+
Set sh= WScript.CreateObject("WScript.Shell")
Public Function GetCurDir
	curDir = WScript.ScriptFullName
	For i = Len(curDir) To 0 Step -1 
		If Mid(curDir,i,1)="\" Then
			Exit For 
		End If
	Next
	GetCurDir=Left( curDir, i )
End Function

Sub DispMsg 
	WScript.Echo "��ƽ̨��Ҫ1.5�汾����Java Runtime Environment֧��," _
	&vbCRLF&"����ȷ��װJava Runtime Environment !"&vbCRLF& "������" _
	&GetCurDir&"JDKĿ¼���ҵ��ð�װ�ļ���"
	WScript.Quit -1
End Sub

Dim JreHome,CurrentVersion,JavaHome
On Error Resume Next
JavaHome = sh.ExpandEnvironmentStrings( "%JAVA_HOME%" )
CurrentVersion = sh.RegRead("HKLM\SOFTWARE\JavaSoft\Java Runtime Environment\CurrentVersion")
If Err.number <> 0 And ""=JavaHome Then
	DispMsg()
Else
	JreHome = sh.RegRead( "HKLM\SOFTWARE\JavaSoft\Java Runtime Environment\"_
	& CurrentVersion & "\JavaHome" )
	If Err.number <> 0 And "%JAVA_HOME%"=JavaHome Then
		DispMsg()
	ElseIf Err.number=0 Then 
		sh.Run  """"&JreHome&"\bin\javaw.exe""  -jar win.jar local"
	ElseIf "%JAVA_HOME%"<>JavaHome Then
		If Right( JavaHome, 1 )<>"\" Then
			JavaHome = JavaHome & "\"
		End If 
		sh.Run """" & JavaHome &"bin\javaw.exe"" -jar win.jar local"
	End if
End If 