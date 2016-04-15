# -*- coding=utf-8 -*-
import math
import win32clipboard as w
import win32con
import string
import pyHook
import pythoncom
import os,sys

def getText():
    w.OpenClipboard()
    d = w.GetClipboardData(win32con.CF_TEXT)
    w.CloseClipboard()
    return d
 
def setText(aString):
    w.OpenClipboard()
    w.EmptyClipboard()
    w.SetClipboardData(win32con.CF_TEXT, aString)
    w.CloseClipboard()

def reverse(a):
    b=''
    for i in range(len(a)-1,-1,-1):
        b+=a[i]
    return b;

def go():
    a=getText()
    c=unicode(a,'gb2312');
    b=reverse(c)
    b=b.encode('gbk')
    setText(b)
    a=getText();
    print a

def onKeyboardEvent(event):
    if (event.Ascii==9):
        #time.sleep(3)
        go()
        return True
    else:
        return True

if __name__=='__main__':
    #print u"复制文本后，按Tab键，再粘贴输出"
    hk=pyHook.HookManager()
    hk.KeyDown=onKeyboardEvent
    hk.HookKeyboard()
    pythoncom.PumpMessages()
    os.system("pause")