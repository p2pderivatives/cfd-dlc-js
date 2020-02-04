@echo off
cd ..
call :search_lint include\cfdjs ..\..
call :search_lint src ..

exit /b

:search_lint
cd %1
for %%A in (*.h) do (
    call python %2\tools\cpplint\cpplint.py --quiet %%A
)
for %%A in (*.cpp) do (
    call python %2\tools\cpplint\cpplint.py --quiet %%A
)
cd %2
exit /b
