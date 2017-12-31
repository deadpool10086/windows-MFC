'+--------------------------------------------------+
'|			JLCSS 实验平台启动脚本					|
'|													|
'|			该文件不允许被修改！					|
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
	WScript.Echo "该平台需要1.5版本以上Java Runtime Environment支持," _
	&vbCRLF&"请正确安装Java Runtime Environment !"&vbCRLF& "可以在" _
	&GetCurDir&"JDK目录下找到该安装文件。"
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