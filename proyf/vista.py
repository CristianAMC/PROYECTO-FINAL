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
lbl.grid(column=1, row=2)
lbl11 = Label(window, text="Entrada digital", fg='blue')
lbl11.grid(column=1, row=3)

p1 = Label(window, fg='gray',width=5,relief=RIDGE, background='gray')
p1.grid(column=1, row=4)

space= Label(window, text='')
space.grid(column=1, row=5)

p2 = Label(window, fg='gray',width=5,relief=RIDGE, background='gray')
p2.grid(column=1, row=6)

space1= Label(window, text='')
space1.grid(column=1, row=7)

p3 = Label(window, fg='gray',width=5,relief=RIDGE, background='gray')
p3.grid(column=1, row=8)

space2= Label(window, text='')
space2.grid(column=1, row=9)

p4 = Label(window, fg='gray',width=5,relief=RIDGE, background='gray')
p4.grid(column=1, row=10)

space3= Label(window, text='')
space3.grid(column=1, row=11)

p5 = Label(window, fg='gray',width=5,relief=RIDGE, background='gray')
p5.grid(column=1, row=12)



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

lbl12 = Label(window, text="Entradas digitales", fg='blue')
lbl12.grid(column=3, row=5)

space6= Label(window, text='')
space6.grid(column=3, row=4)

p6 = Label(window, fg='gray',width=5,relief=RIDGE, background='gray')
p6.grid(column=3, row=6)

space7= Label(window, text='')
space7.grid(column=3, row=7)

p7 = Label(window, fg='gray',width=5,relief=RIDGE, background='gray')
p7.grid(column=3, row=8)

space8= Label(window, text='')
space8.grid(column=3, row=9)

def leds2():
    lbl2=Label(window,text=txt3.get())
    print(txt3.get())
    #ser.write(str.encode(txt.get()))

btn3 = Button(window, text='LED que desea encender', command=leds2)
btn3.grid(column=3, row=11)

txt3= Entry(window,width=10)
txt3.grid(column=3, row=10)


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
b.set_ylabel("Potenciometro")

line, = b.plot(xar2,yar2,'b')

plotcanvas =FigureCanvasTkAgg(fig2,window)
plotcanvas.get_tk_widget().grid(column=5, row=3)

space13= Label(window, text='Entradas digitales', fg='blue')
space13.grid(column=5, row=4)

p8 = Label(window, fg='gray',width=5,relief=RIDGE, background='gray')
p8.grid(column=5, row=5)

space11= Label(window, text='')
space11.grid(column=5, row=6)

p9 = Label(window, fg='gray',width=5,relief=RIDGE, background='gray')
p9.grid(column=5, row=7)

space12= Label(window, text='')
space12.grid(column=5, row=8)

window.mainloop()
