@echo off
setlocal

cl.exe /Zi /W4 /EHsc /nologo main.c png.c /Fe:main.exe
if errorlevel 1 (
	echo Build failed.
	exit /b 1
)

main.exe