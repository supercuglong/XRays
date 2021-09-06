不要拿去盈利。


XRAYS:

Forked from : https://github.com/orkido/LViewLoL

NEWS:

  Remove boost.python
  
  Add LUA script support
  
  ...
  
LUA INTERFACE:

  https://github.com/pxps/XRays/blob/main/XRays/LuaExport.inc
  
  
BUILD:

   need VS2019
   
   x86 && build
   
   cp ${dir}/Release/XRays.exe XRays/
   
   XRays.exe
   
LOL_CN:

   Need to inject DLL into the process
   
   Fix some offset https://github.com/pxps/XRays/blob/main/XRaysSDK/cn_lol_base-addr.txt
  




