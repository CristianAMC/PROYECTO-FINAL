from tkinter import *
# import serial
# import csv
import matplotlib.pyplot as plt
from matplotlib import style
import matplotlib.animation as anim
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import random
import time

window = Tk()
window.title('PROYECTO FINAL')
window.geometry('900x500')
style.use('ggplot')
xar = []
yar = []
xar2 = []
yar2 = []
p=[0,1]
# ----------------------------------------------------------------------

"""ser = serial.Serial(
    port='/dev/ttyACM0',
    baudrate=9600,
    parity=serial.PARITY_ODD,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS
)
ser.isOpen()"""
# ESCLAVO1--------------------------------------------------------------

lbl = (Label(window, text="ARDUINO UNO"))
lbl.grid(column=1, row=1)
lbl11 = Label(window, text="Entrada digital", fg='blue')
lbl11.grid(column=1, row=2)

p1 = Label(window, fg='gray', width=5, relief=RIDGE, background='gray')
p1.grid(column=1, row=3)

space = Label(window, text='')
space.grid(column=1, row=4)


def clicked():
    lbl2 = Label(window, text=txt.get())
    print(txt.get())
    # ser.write(str.encode(txt.get()))


btn = Button(window, text='PWM', command=clicked)
btn.grid(column=2, row=15)

txt = Entry(window, width=10)
txt.grid(column=1, row=15)


def leds():
    pulsa = p[random.randint(0, len(p) - 1)]
    print(pulsa)
    if (pulsa == 1):
        p1 = Label(window, fg='gray', width=5, relief=RIDGE, background='green')
        p1.grid(column=1, row=3)
    else:
        p1 = Label(window, fg='gray', width=5, relief=RIDGE, background='gray')
        p1.grid(column=1, row=3)
    #lbl2 = Label(window, text=txt2.get())
    #print(txt2.get())
    # ser.write(str.encode(txt.get()))


btn2 = Button(window, text='LED que desea encender', command=leds)
btn2.grid(column=2, row=16)

txt2 = Entry(window, width=10)
txt2.grid(column=1, row=16)




time.sleep(2)
# ESCLAVO2-------------------------------------------------------------------------


fig = plt.figure(figsize=(3, 2), dpi=100)
a = fig.add_subplot(122)
a.set_ylim(0, 20)
line1, = a.plot(xar, yar, 'b')
a.set_title("Entrada Analoga")
a.set_xlabel("Segundos")
a.set_ylabel("Potenciometro")

lbl2 = Label(window, text="ARDUINO UNO 2")
lbl2.grid(column=3, row=1)
lbl12 = Label(window, text="Entrada analoga", fg='blue')
lbl12.grid(column=3, row=2)

lista = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]


def animate(i):
    xar.append(i)
    # data = ser.readline()
    # data = str(data)
    # b= data.find('log')
    # c= data.find(' b')
    datum = lista[random.randint(0, len(lista) - 1)]
    # print(data)
    #print(datum)
    yar.append(int(datum))
    line1.set_data(xar, yar)
    a.set_xlim(0, i + 1)


plotcanvas = FigureCanvasTkAgg(fig, window)
plotcanvas.get_tk_widget().grid(column=3, row=3)
ani = anim.FuncAnimation(fig, animate, interval=1000, blit=False)

# ESCLAVO3-------------------------------------------------------------------------
space10 = Label(window, text="  ")
space10.grid(column=4, row=1)

fig2 = plt.figure(figsize=(3, 2), dpi=100)
b = fig2.add_subplot(122)
b.set_ylim(0, 20)
line2, = b.plot(xar2, yar2, 'red')
b.set_title("Entrada Analoga")
b.set_xlabel("Segundos")
b.set_ylabel("Sensor MQ")

lbl3 = Label(window, text="ARDUINO MEGA")
lbl3.grid(column=5, row=1)
lbl13 = Label(window, text="Entrada analoga 2", fg='blue')
lbl13.grid(column=5, row=2)

lista2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]


def animate1(j):
    xar2.append(j)
    # data = ser.readline()
    # data = str(data)
    # b= data.find('log')
    # c= data.find(' b')
    datum1 = lista2[random.randint(0, len(lista2) - 1)]
    # print(data)
    #print(datum1)
    yar2.append(int(datum1))
    line2.set_data(xar2, yar2)
    b.set_xlim(0, j + 1)


plotcanvas = FigureCanvasTkAgg(fig2, window)
plotcanvas.get_tk_widget().grid(column=5, row=3)
ani0 = anim.FuncAnimation(fig2, animate1, interval=1000, blit=False)

window.mainloop()
