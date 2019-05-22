from tkinter import *
import serial

exit=0
window = Tk()
window.title("COMUNICACIÓN ARDUINO")
window.geometry('800x300')
lbl = Label(window, text="Led que desea manipular")
lbl.grid(column=3, row=1)
def clicked():
    lbl2=Label(window,text=txt.get())
    print(txt.get())
    ser.write(str.encode(txt.get()))
btn = Button(window, text='Enviar', command=clicked)
btn.grid(column=1, row=1)
txt= Entry(window,width=10)
txt.grid(column=3, row=3)

window.mainloop()
