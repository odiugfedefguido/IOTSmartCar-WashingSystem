package it.unibo.esiot.smart_bridge.connector;

import it.unibo.esiot.smart_bridge.DashboardController;
import jssc.SerialPort;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;
import jssc.SerialPortException;

import java.util.Objects;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;

public class MessageService implements Runnable, SerialPortEventListener {

    private final SerialPort serialPort;
    private final BlockingQueue<String> messageBuffer;
    private final DashboardController dashboardController;

    private String partialMessage = "";

    public MessageService(String port, BlockingQueue<String> messageBuffer, DashboardController dashboardController) {
        Objects.requireNonNull(port, "Port must not be null.");
        Objects.requireNonNull(messageBuffer, "Message buffer must not be null.");
        Objects.requireNonNull(dashboardController, "Dashboard controller must not be null.");

        this.serialPort = new SerialPort(port);
        this.messageBuffer = messageBuffer;
        this.dashboardController = dashboardController;
    }

    public void shutdown() {
        try {
            serialPort.removeEventListener();
            serialPort.closePort();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    @Override
    public void run() {
        System.out.println("Start monitoring serial port " + serialPort + " at 9600 boud rate");

        try {
            serialPort.openPort();

            serialPort.setParams(SerialPort.BAUDRATE_9600,
                    SerialPort.DATABITS_8,
                    SerialPort.STOPBITS_1,
                    SerialPort.PARITY_NONE);

            serialPort.setFlowControlMode(SerialPort.FLOWCONTROL_RTSCTS_IN |
                    SerialPort.FLOWCONTROL_RTSCTS_OUT);

            serialPort.addEventListener(this, SerialPort.MASK_RXCHAR);
        }
        catch (SerialPortException ex) {
            System.out.println("There was an error while writing string to port т: " + ex);
        }

        while (true) {
            try {
                String messageToSend = messageBuffer.poll(100, TimeUnit.MILLISECONDS);
                if (messageToSend != null) {
                    // TODO: Send the message
                    System.out.println("We have to send a message.");
                }
            } catch (InterruptedException e) {
                shutdown();
                return;
            }
        }
    }

    @Override
    public void serialEvent(SerialPortEvent event) {
        if(event.isRXCHAR() && event.getEventValue() > 0) {
            try {
                String receivedData = serialPort.readString(event.getEventValue());
                int separatorIndex = receivedData.indexOf("\n");

                if (separatorIndex > -1) {
                    String message = partialMessage + receivedData.substring(0, separatorIndex);
                    partialMessage = receivedData.substring(separatorIndex + 1);

                    if (message.length() > 4) {
                        switch (message.substring(0, 4)) {
                            case "TEMP":
                                dashboardController.displayTemperature(message.split(";")[1]);
                                break;
                            case "STAT":
                                dashboardController.displayStatus(message.split(";")[1]);
                                break;
                            case "COMP":
                                dashboardController.increaseWashes();
                                break;
                        }
                    }
                } else {
                    partialMessage += receivedData;
                }
                // System.out.print(receivedData);
            }
            catch (SerialPortException ex) {
                System.out.println("Error in receiving string from COM-port: " + ex);
            }
        }
    }

}
