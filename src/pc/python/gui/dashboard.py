from tkinter import *
from tkinter.ttk import *

from communication.serial_service import SerialService

OPEN_SANS_LARGE = ("Open Sans", 48, "bold") 
OPEN_SANS_HEADLINE = ("Open Sans", 34, "bold") 
OPEN_SANS_SMALL = ("Open Sans", 18, "normal") 

class Dashboard:
    count = 4
    
    def __init__(self, port) -> None:
        # self.arduino = SerialService(port=port)

        self.root = Tk()
        self.root.title("Smart Bridge Dashboard")

        self.temperature_var = StringVar()
        self.temperature_var.set("23,4")
        self.count_var = StringVar()
        self.status_var = StringVar()
        self.status_var.set("WASHING")

        self.create_gui()
        self.root.geometry('850x900')

        self.root.after(200, self.update)
        self.root.mainloop()

    def create_gui(self):
        (Label(self.root, text="SMART WASHING", font=OPEN_SANS_HEADLINE)
         .pack())

        row = Frame(self.root)
        self.create_frame(row, self.count_var, "washes so far", 1, 1)
        self.create_frame(row, self.temperature_var, "°C inside", 1, 2)
        row.pack()

        status_row = Frame(self.root)
        self.create_frame(status_row, self.status_var, "current status", 1, 1)
        status_row.pack()
        
    def create_frame(self, parent, variable, label, row, column):
        frame = Frame(parent, padding=40)

        (Label(frame, textvariable = variable, font=OPEN_SANS_LARGE)
         .grid(row = 1, column = 1, sticky = W, ipadx=4, ipady=4))
        (Label(frame, text =label, font=OPEN_SANS_SMALL)
         .grid(row = 2, column = 1, sticky = W, ipadx=4, ipady=4))
        
        frame.grid(row = row, column = column)
        


    def update(self):
        # TODO: Add content.
        # print(self.arduino.read())

        self.count += 1
        self.count_var.set(format(self.count, '1.0f'))

        self.root.after(200, self.update)