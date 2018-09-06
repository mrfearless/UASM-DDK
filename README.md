# UASM-DDK

Driver Development Kit for x64 UASM assembler

[![](https://img.shields.io/badge/Assembler-UASM%20v2.46-green.svg?style=flat-square&logo=visual-studio-code&logoColor=white&colorB=1CC887)](http://www.terraspace.co.uk/uasm.html) [![](https://img.shields.io/badge/RadASM%20-v2.2.2.x%20-red.svg?style=flat-square&colorB=C94C1E&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABQAAAAgCAYAAAASYli2AAACcklEQVR42tWVXWiPURzHz/FyQZOiVuatuFEoKzfKSCs35EJeCqFcEEa5s2heNrXiApuXFDYveUlKSywlIRfczM0WjZvJlGKTRLb5fHvOU6fT+T/PY3bj1Kff8z8vn+f8znPO+dshihnBYv8L4awRcl2FRTarBy8bQzgEjdbabzl9nxCW2IwOFYTrsBTKEH7PET4lLLYlGpcTrkC5qxqL8HeO8CVhoQ0qRxMOw34Y5TVVIPyYI+whTLVehZ9iWgZAL1mN8G6GbArhA/TZEilqKx2HCbADXkAV0oESwhOEfdChbXOUh1ovxS+wlcH3aNvC82VX3wx7Qyl9NhEugXZEU7ixX8E6Br13nTVDPU927R3QCl0wTX2h2rUNQqUv/ATLkHUGM1hLuBF8pFipZ+zBcIZKpw1O0vjYk24mnIXxEZHGNMIBxgxJ2M2P2PF7DafhGh1/0G8Gzzv1cWASfIZn0EJ7VzpIQqWyUguulFUXiDXwApxhYE9O2ibc2PMJNbAxkp5Oyh3NGvHzQkJPrK/aANtLjNNuOAU3kf/KFTrpGsJtaIdxbu3C0gvn4Dzi3qLCI3Su4/cCnnfDBvcCv/yEW0a7o6gwWI5tJvniMwutYZbQa9elsUqzgun/JKStjKAzvAvmDXuG1M1xqerkTAyG6Cy3FREeM8k2kag6MomvcBGaefG7LOF6k1wK6SUbFl0iOpqt/v+NjYjmEva4NQpPi9K6b5JN/UiXQTg+vbF1nlc4USytPpNcok1Iuk1G0eWgS0Hnd3akXbeIbuqWvP9lXxhOW2k9cOvzMJZWUWG/Sf4/lNbbv5GEwjeSSIaof7iitPwBoSgbVud1Jo0AAAAASUVORK5CYII=)](http://www.softpedia.com/get/Programming/File-Editors/RadASM.shtml)

# UASM-DDK Setup

* Download and install [UASM](http://www.terraspace.co.uk/uasm.html)
* Download and install [UASM-with-RadASM](https://github.com/mrfearless/UASM-with-RadASM) 
* Download the latest release of [UASM-DDK](https://github.com/mrfearless/UASM-DDK/releases). The latest release can be found via the [releases](https://github.com/mrfearless/UASM-DDK/releases) section of this Github repository as
`Source code (zip)`
* Extract the contents into an existing installation of [UASM](http://www.terraspace.co.uk/uasm.html) installation (rename any folders required so that it matches the following folder structure):
```
  \UASM\bin
  \UASM\include
  \UASM\lib
  \UASM\lib\x64
```
* The UASM-DDK contains an `extra` folder, which has has a folder structure similar to a RadASM installation that uses UASM. 
	* Copy the `extra\RadASM\UASM64.ini` file into your `\RadASM\` folder overwriting any older versions. 
	* Copy the `extra\RadASM\UASM64\Templates\*.tpl` files to your `\RadASM\UASM64\Templates` folder.
* Create a new RadASM project and specify `UASM64` as the assembler. Choose `Driver64` as the project type.
* Assemble and link your new driver.
* Test-Sign your driver by using the `sign.bat` file or by choosing the Compile Resource make menu option (which does the same thing by running the `sign.bat` file)


# Additional Resources

* [RadASM IDE](http://www.softpedia.com/get/Programming/File-Editors/RadASM.shtml)
* [Masm32](http://www.masm32.com/download.htm)
* [UASM](http://www.terraspace.co.uk/uasm.html)
* [WinInc](http://www.terraspace.co.uk/WinInc209.zip)
* [UASM-with-RadASM](https://github.com/mrfearless/UASM-with-RadASM)
* [Windows SDK archive](https://developer.microsoft.com/en-us/windows/downloads/sdk-archive)
* [Visual Studio](https://visualstudio.microsoft.com/)
* [PellesC 8.00](http://www.pellesc.de/download_start.php?file=800/setup64.exe)
