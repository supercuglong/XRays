XRays:

Forked from : https://github.com/orkido/LViewLoL

News:
  Remove boost.python
  
  Add LUA script support
  
  ...
  
LUA Interface:
  https://github.com/pxps/XRays/blob/main/XRays/LuaExport.inc
  
  
Build:
   need VS2019
   
   x86 && build
   
   cp ${dir}/Release/XRays.exe XRays/
   
   XRays.exe
   
CN_LOL:
   Need to inject DLL into the process
   
   Fix some offset https://github.com/pxps/XRays/blob/main/XRaysSDK/cn_lol_base-addr.txt
  




