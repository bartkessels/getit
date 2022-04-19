# Add extra argument to locate the vcpkg cmake location in the Github pipeline and to include the boost libraries
Invoke-Expression "cmake . -G Ninja -DCMAKE_TOOLCHAIN_FILE=C:\vcpkg\scripts\buildsystems\vcpkg.cmake -DBoost_INCLUDE_DIR=C:\vcpkg\x64-windows-static\include"
Invoke-Expression "ninja GetIt"
Invoke-Expression "windeployqt ./bin/GetIt.exe"

Invoke-Expression "7z a -tzip getit.zip ./bin/GetIt.exe"
