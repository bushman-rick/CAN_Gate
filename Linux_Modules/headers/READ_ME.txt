x86_64-linux-gnu contains the headers which have been used for the Linux modules as many of the headers used are not included within the extension by default. They are present in Linux and as such no headers where added to the netbook.

Copy/merge the file to the directory where your headers are stored for the VS Linux extension. 
Should be something like:

 "D:\Program Files\VS Enterprise 2015\VC\Linux\include\usr\include"
 or
 "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\Linux\include\usr\include"