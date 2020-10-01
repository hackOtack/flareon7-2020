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
