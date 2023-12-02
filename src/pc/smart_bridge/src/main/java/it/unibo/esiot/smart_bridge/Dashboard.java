package it.unibo.esiot.smart_bridge;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.util.Callback;
import jssc.SerialPortList;

import java.io.IOException;

public class Dashboard extends Application {

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(Dashboard.class.getResource("dashboard-view.fxml"));

        fxmlLoader.setControllerFactory((Callback<Class<?>, Object>) controllerClass -> {
            return new DashboardController(getParameters().getRaw().get(0));
        });

        Scene scene = new Scene(fxmlLoader.load(), 530, 660);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        if (args.length > 0) {
             launch(args);
        } else {
            /* detect serial ports */
            System.out.println("Error. Pass the serial port as an argument.");
            System.out.println("Available ports:");
            for (String portName : SerialPortList.getPortNames()) {
                System.out.println("- " + portName);
            }
        }
    }
}
