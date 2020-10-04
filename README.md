# flareon7-2020

Notes and code for FlareOn7 2020


Challenge 2:
- Padded the UPX file with 0 to adjust the raw sie 
- Unpacked it with PE explorer (final-imp-E-2.exe)
- fixed the IAT in the extracted executable  http://r0x0r.vishalmishra.in/2013/07/rebuilding-import-table.html?m=1 
- Used LibPeConv to load the PE and execute the deobfuscation function  (main.cpp)

Challenge 3:
- Wrote a game bot to play and win
- used OpenCV and pyautogui python libs 
- very useful writeups/code:
  - https://medium.com/analytics-vidhya/automate-chrome-dino-game-using-python-pyautogui-and-pil-eeb839005ccf
  - https://www.tautvidas.com/blog/2018/02/automating-basic-tasks-in-games-with-opencv-and-python/

Challenge 5:
- Reversed only TKApp.dll and wrote a simple .Net file to get the flag
- Flag will be saved as an image
- Needed to extrac the runtime.dll resource from the TKApp dll using dnspy
- Challenge5.sln/Challenge5.cs

Challenge 6:
- Exe2Aut.exe to extract autoit script
- Wrote c# code to deobfuscate the script. https://lifeinhex.com/deobfuscating-autoit-scripts/ was a good start. 
- Debugged the script using AutoIt Debugger and Scite. Found the first decryption key and used a sha-256 form of it as the second decrypton key used to decrypt a hardcoded binary array. Result then is used to construct an image with the flag. 
- Final Qrcode was generated by compiling the script back to Exe 
- Tools used:
  - https://www.autoitscript.com/wiki/FAQ#How_can_I_debug_my_script.3F  
  - https://www.autoitscript.com/site/autoit-script-editor/
  - http://www.thefoolonthehill.net/drupal/AutoIt%20Debugger
