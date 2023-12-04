from tkinter import *
from tkinter.ttk import *

from communication.serial_service import SerialService

OPEN_SANS_LARGE = ("Open Sans", 64, "bold") 
OPEN_SANS_HEADLINE = ("Open Sans", 36, "bold") 
OPEN_SANS_SMALL = ("Open Sans", 18, "normal") 
OPEN_SANS_STATUS = ("Open Sans", 36, "bold") 

class Dashboard:
    count = 0
    
    def __init__(self, port) -> None:
        self.arduino = SerialService(port)

        self.root = Tk()
        self.root.title("Smart Bridge Dashboard")

        self.temperature_var = StringVar()
        self.temperature_var.set("23,4")
        self.count_var = StringVar()
        self.count_var.set(self.count)
        self.status_var = StringVar()
        self.status_var.set("WASHING")

        self.create_gui()
        self.root.geometry('850x900')

        self.root.after(200, self.update)
        self.root.mainloop()

    def on_button_clicked(self):
        self.arduino.write("REPAIRED\n")
        self.button['state'] = 'disabled'

    def create_gui(self):
        Label(self.root, text="SMART WASHING", font=OPEN_SANS_HEADLINE).pack()

        row = Frame(self.root)
        self.create_frame(row, self.count_var, "washes so far", 1, 1)
        self.create_frame(row, self.temperature_var, "°C inside", 1, 2)
        row.pack()

        status_row = Frame(self.root)
        self.create_frame(status_row, self.status_var, "current status", 1, 1, OPEN_SANS_STATUS)
        status_row.pack()

        self.button = Button(self.root, text="MAINTENANCE DONE", command=self.on_button_clicked)
        self.button.pack()
        self.button['state'] = 'disabled'
        
    def create_frame(self, parent, variable, label, row, column, font_size=OPEN_SANS_LARGE):
        frame = Frame(parent, padding=40)

        (Label(frame, textvariable = variable, font=font_size)
         .grid(row = 1, column = 1, sticky = W, ipadx=4, ipady=4))
        (Label(frame, text =label, font=OPEN_SANS_SMALL)
         .grid(row = 2, column = 1, sticky = W, ipadx=4, ipady=4))
        
        frame.grid(row = row, column = column)
        


    def update(self):
        message = self.arduino.read()
        parsed_message = str(message).replace('b\'', '').replace('\'', '').replace('\\r\\n', '').split(';')
        
        if (len(parsed_message) > 1 or len(parsed_message[0]) > 0):
            print(parsed_message) 

        type = parsed_message[0]
        content = ''

        if (len(parsed_message) == 2):
            type = parsed_message[0]
            content = parsed_message[1]

        if type == 'COMPLETE':
            self.count += 1
            self.count_var.set(self.count)
        elif type == 'TEMP':
            self.temperature_var.set(content)
        elif type == 'STATUS':
            self.status_var.set(content)

            if content == 'MAINTENANCE REQUIRED':
                print("Error")
                self.button['state'] = 'enabled'            
            
        self.root.after(200, self.update)