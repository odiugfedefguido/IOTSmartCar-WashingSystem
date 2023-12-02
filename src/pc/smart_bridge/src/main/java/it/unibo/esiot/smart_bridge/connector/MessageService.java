package it.unibo.esiot.smart_bridge.connector;

import javafx.application.Platform;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.concurrent.Service;
import javafx.concurrent.Task;
import jssc.SerialPort;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;
import jssc.SerialPortException;

import java.util.Objects;

public class MessageService extends Service<String> implements SerialPortEventListener {

    private final SerialPort serialPort;
    private String partialMessage = "";

    private final StringProperty temperatureProperty = new SimpleStringProperty();
    private final StringProperty statusProperty = new SimpleStringProperty();

    public MessageService(String port) {
        Objects.requireNonNull(port, "Port must not be null.");
        this.serialPort = new SerialPort(port);
    }

    public final StringProperty getTemperatureProperty() {
        return temperatureProperty;
    }

    public final StringProperty getStatusProperty() {
        return statusProperty;
    }

    @Override
    protected Task<String> createTask() {
        SerialPortEventListener service = this;

        return new Task<String>() {
            @Override
            protected String call() {
                try {
                    System.out.println("Start monitoring serial port " + serialPort + " at 9600 boud rate");

                    try {
                        serialPort.openPort();

                        serialPort.setParams(SerialPort.BAUDRATE_9600,
                                SerialPort.DATABITS_8,
                                SerialPort.STOPBITS_1,
                                SerialPort.PARITY_NONE);

                        serialPort.setFlowControlMode(SerialPort.FLOWCONTROL_RTSCTS_IN |
                                SerialPort.FLOWCONTROL_RTSCTS_OUT);

                        serialPort.addEventListener(event -> {
                            Platform.runLater(() -> System.out.println(event));
                        }, SerialPort.MASK_RXCHAR);
                    }
                    catch (SerialPortException ex) {
                        System.out.println("There was an error while writing string to port т: " + ex);
                    }
                } finally {
                    try {
                        serialPort.removeEventListener();
                        serialPort.closePort();
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }
                }

                return null;
            }
        };
    }

    @Override
    public void serialEvent(SerialPortEvent event) {
        System.out.println(event);
        if (event.isRXCHAR() && event.getEventValue() > 0) {
            try {
                String receivedData = serialPort.readString(event.getEventValue());
                int separatorIndex = receivedData.indexOf("\n");

                if (separatorIndex > -1) {
                    String message = partialMessage + receivedData.substring(0, separatorIndex);
                    partialMessage = receivedData.substring(separatorIndex + 1);

                    if (message.length() > 4) {
                        switch (message.substring(0, 4)) {
                            case "TEMP":
                                this.temperatureProperty.set(message.split(";")[1]);
                                break;
                            case "STAT":
                                this.statusProperty.setValue(message.split(";")[1]);
                                break;
                            case "COMP":
                                // dashboardController.increaseWashes();
                                break;
                        }
                    }
                } else {
                    partialMessage += receivedData;
                }
                System.out.print(receivedData);
            }
            catch (SerialPortException ex) {
                System.out.println("Error in receiving string from COM-port: " + ex);
            }
        }
    }

}
