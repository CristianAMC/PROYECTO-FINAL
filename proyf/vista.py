from tkinter import *
import serial
import csv
import matplotlib.pyplot as plt
from matplotlib import style
import matplotlib.animation as anim
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import serial


window = Tk()
window.title('PROYECTO FINAL')
window.geometry('900x500')
#style.use('ggplot')

#ESCLAVO1--------------------------------------------------------------

lbl = (Label(window, text="ARDUINO UNO"))
lbl.grid(column=1, row=1)
lbl11 = Label(window, text="Entrada digital", fg='blue')
lbl11.grid(column=1, row=2)

p1 = Label(window, fg='gray',width=5,relief=RIDGE, background='gray')
p1.grid(column=1, row=3)

space= Label(window, text='')
space.grid(column=1, row=4)

def clicked():
    lbl2=Label(window,text=txt.get())
    print(txt.get())
    #ser.write(str.encode(txt.get()))

btn = Button(window, text='PWM', command=clicked)
btn.grid(column=2, row=15)

txt= Entry(window,width=10)
txt.grid(column=1, row=15)

def leds():
    lbl2=Label(window,text=txt2.get())
    print(txt2.get())
    #ser.write(str.encode(txt.get()))

btn2 = Button(window, text='LED que desea encender', command=leds)
btn2.grid(column=2, row=16)

txt2= Entry(window,width=10)
txt2.grid(column=1, row=16)


#ESCLAVO2-------------------------------------------------------------------------

xar=[]
yar=[]
fig= plt.figure(figsize=(3,2), dpi=100)

lbl2 = Label(window, text="ARDUINO UNO 2")
lbl2.grid(column=3, row=1)
lbl12 = Label(window, text="Entrada analoga", fg='blue')
lbl12.grid(column=3, row=2)

style.use('ggplot')
xar=[]
yar=[]


a = fig.add_subplot(122)

a.set_ylim(0,1100)
a.set_title("Entrada Analoga")
a.set_xlabel("Segundos")
a.set_ylabel("Potenciometro")

line, = a.plot(xar,yar,'b')


plotcanvas =FigureCanvasTkAgg(fig,window)
plotcanvas.get_tk_widget().grid(column=3, row=3)




#ESCLAVO3-------------------------------------------------------------------------
space10 = Label(window, text="  ")
space10.grid(column=4, row=1)


lbl3 = Label(window, text="ARDUINO MEGA")
lbl3.grid(column=5, row=1)
lbl13 = Label(window, text="Entrada analoga 2", fg='blue')
lbl13.grid(column=5, row=2)

xar2=[]
yar2=[]
fig2= plt.figure(figsize=(3,2), dpi=100)

b = fig2.add_subplot(122)

b.set_ylim(0,1100)
b.set_title("Entrada Analoga")
b.set_xlabel("Segundos")
b.set_ylabel("Sensor MQ")

line, = b.plot(xar2,yar2,'b')

plotcanvas =FigureCanvasTkAgg(fig2,window)
plotcanvas.get_tk_widget().grid(column=5, row=3)

window.mainloop()
