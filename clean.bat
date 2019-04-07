@echo Cleaning.....
@for /f %%i in ('dir /s /b *.exe') do del "%%i"
@for /f %%i in ('dir /s /b *.o') do del "%%i"
@echo Success
@pause